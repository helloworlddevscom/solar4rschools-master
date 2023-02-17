<?php

/**
 * @file
 * DECK Monitoring provider class.
 */

class DeckMonitoringGenerationProvider implements GenerationProvider {

  /**
   * Queries the DECK API.
   */
  protected function queryAPI($method, $parameters) {
    $api_url = 'http://application.deckmonitoring.com/';
    $parameters['token'] = variable_get('deck_monitoring_api_key', '');

    // Clean-up data_types.
    if (isset($parameters['data_types'])) {
      $parameters['data_types'] = str_replace(' ', '_', $parameters['data_types']);
    }

    $options = array(
      'query' => $parameters,
      'external' => TRUE,
      // We don't want any purl providers modifying this url. If purl isn't
      // enabled, url() won't care about this extra option.
      'purl' => array('disabled' => TRUE),
    );

    $url = url($api_url . $method . '.json', $options);
    $result = drupal_http_request($url);

    $result->success = ($result->code == 200) && ($result->data !== FALSE);
    if (!$result->success) {
      if ($result->data === FALSE) {
        $error = 'DECK Monitoring API returned no data for @method, parameters @param. Response: HTTP @code (@status)';
      }
      else {
        $error = 'DECK Monitoring API error for @method, parameters @param. Response: HTTP @code (@status) @error';
      }
    }

    if (isset($error)) {
      $args = array(
        '@method' => $method,
        '@param'  => drupal_http_build_query($parameters),
        '@code'   => $result->code,
        '@status' => $result->status_message,
        '@error'  => $result->data,
      );
      watchdog('deck_monitoring', $error, $args, WATCHDOG_ERROR);
    }

    $result->data = json_decode($result->data);
    return $result;
  }

  /**
   * Clean and format data returned from `data/graph`.
   *
   * @param object $result
   *   The data component of the return from
   *   DeckMonitoringGenerationProvider::queryAPI().
   * @param object $site
   *   The site entity.
   * @param array $preset_by_variable
   *   An array of presets, keyed by DECK variable name.
   *
   * @return array
   *   Array compatible with the structure returned by
   *   GenerationProvider::queryBin().
   */
  protected function formatBinData(stdClass $result, $site, array $preset_by_variable, DateTime $date_start, DateTime $date_end) {
    $data = array();
    foreach ($result->dataSets as $data_set) {
      // DECK sometimes likes to return the wrong data; e.g., irradiance
      // when you ask for cell temperature. So defensively check and move on
      // if we get a wonky result.
      if (!isset($preset_by_variable[$data_set->data_type_label])) {
        continue;
      }

      $preset = $preset_by_variable[$data_set->data_type_label];
      $series = array();
      $series['name'] = $preset->alias;
      $series['type'] = $preset->chart_type;
      $series['description'] = $preset->description;
      $series['units'] = $data_set->data_type_unit;
      $series['data'] = array();
      $last_datetime = NULL;
      foreach ($data_set->series as $point) {
        $datetime = generation_new_datetime_site($site, $point[0]);
        $series['data'][] = array(
          (float) $datetime->format('U'),
          (float) $point[1],
        );
        $last_datetime = $datetime;
      }

      // DECK won't return any data for times in the future, so we "pad" the
      // result if DECK didn't return the full data range. This is because
      // we want "Today" data views to show midnight to midnight (i.e. always
      // partly in the future).
      // So far this only (needs to) support 'hour' intervals.
      if ($result->interval === 'hour') {
        if (!$last_datetime) {
          $last_datetime = clone $date_start;
          $last_datetime->modify('-1 hour');
        }

        $diff = $last_datetime->diff($date_end);
        $hours = (int) $diff->format('%h');
        while ($hours-- > 0) {
          $last_datetime->modify('+1 hour');
          $series['data'][] = array(
            (float) $last_datetime->format('U'),
            NULL,
          );
        }
      }

      $data[] = $series;
    }
    return $data;
  }

  /**
   * Implements GenerationProvider::queryBin().
   *
   * DECK's API doesn't support specifying bin size, so $bin is ignored.
   */
  public function queryBin(Entity $site, array $presets, DateTime $date_start, DateTime $date_end, $bin = 'hour') {
    module_load_include('inc', 'generation');
    $all_variables = _generation_get_variables();

    $data = FALSE;
    $preset_by_variable = array();
    $query_variables = array();
    $device_presets = array();
    foreach ($presets as $preset) {
      // Presets with device IDs are queried separately.
      if (!empty($preset->device_id)) {
        $device_presets[$preset->preset_id] = $preset;
        continue;
      }
      if (isset($all_variables[$preset->variable_id])) {
        $variable = $all_variables[$preset->variable_id];
        $query_variables[] = $variable->name;
        $preset_by_variable[$variable->name] = $preset;
      }
    }

    // We don't have a way of getting the start date/time of a DECK location,
    // so we just use a date which should be before any location device started
    // recording generation data.
    if ($date_start instanceof GenerationLifetimeStartDateTime) {
      $date_start = generation_new_datetime_local('2004-01-01');
    }

    // Query location-level data.
    $wrapper = entity_metadata_wrapper('generation_site', $site);
    $result = $this->queryAPI('data/graph', array(
      'target_type' => 'location',
      'target_id'   => $wrapper->deck_lid->value(),
      'range'       => 'custom',
      'range_start' => $date_start->format('c'),
      'range_end'   => $date_end->format('c'),
      'data_types'  => implode(',', $query_variables),
    ));

    if ($result->success) {
      $result = $result->data;
      $data = $this->formatBinData($result, $site, $preset_by_variable, $date_start, $date_end);
    }

    // If there are any device-level requests, perform those.
    if (!empty($device_presets)) {
      $device_queries = $preset_by_variable = $query_variables = array();
      foreach ($device_presets as $preset) {
        // Bundle additional queries by device.
        $device_queries[$preset->device_id][$preset->preset_id] = $preset;
        $variable = $all_variables[$preset->variable_id];
        $preset_by_variable[$preset->device_id][$variable->name] = $preset;
        $query_variables[$preset->device_id][] = $variable->name;
      }

      // Query each device.
      foreach ($device_queries as $device_id => $presets) {
        $result = $this->queryBinDevice($device_id, $presets, $date_start, $date_end);

        if ($result->success) {
          $data = array_merge($data, $this->formatBinData($result->data, $site, $preset_by_variable[$device_id], $date_start, $date_end));
        }
      }
    }

    return $data;
  }

  /**
   * Query a specific device.
   *
   * @return object
   *   Result from self::queryApi().
   */
  public function queryBinDevice($device_id, array $variables, DateTime $date_start, DateTime $date_end, $options = array()) {
    // Variables are overloaded here.
    $deck_variables = array();
    foreach ($variables as $preset) {
      $deck_variables[] = generation_variable_load($preset->variable_id)->name;
    }
    return $this->queryAPI('data/graph', array(
      'target_type' => 'node',
      'target_id' => $device_id,
      'range' => 'custom',
      'range_start' => $date_start->format('c'),
      'range_end'   => $date_end->format('c'),
      'data_types'  => implode(',', $deck_variables),
    ));
  }

  /**
   * Implements GenerationProvider::queryInstantSummary().
   */
  public function queryInstantSummary($site = NULL) {
    $site_key = isset($site->id) ? $site->id : NULL;
    $summaries = &drupal_static(__FUNCTION__);

    if (!isset($summaries[$site_key])) {
      // DECK doesn't support global/aggregate queries, so we have to query
      // every single location individually for those. Ouch.
      $wrapped_sites = $site ? array(entity_metadata_wrapper('generation_site', $site)) : $this->loadAllSitesWrapped();

      $summaries[$site_key] = array();
      $summary = array();
      foreach ($wrapped_sites as $wrapper) {
        $result = $this->queryAPI('data/latest', array(
          'target_type' => 'location',
          'target_id' => $wrapper->deck_lid->value(),
        ));
        if (!$result->success) {
          // If the site's latest data isn't found, disable it.
          if ($result->code == '404') {
            $wrapper->status->set(0);
            $wrapper->save();
          }
          continue;
        }

        // When we're doing an aggregate query, it doesn't make sense to sum
        // data of certain types; so we whitelist by data_type.
        $summable_data_types = array(
          'current',
          'dc current',
          'dc power',
          'generation',
          'generation today',
          'irradiance',
          'power',
          'predicted power',
        );
        foreach ($result->data as $field) {
          // Replace spaces with underscores in data type names.
          $data_type = str_replace(' ', '_', $field->data_type);
          if (!$site && !in_array($data_type, $summable_data_types)) {
            continue;
          }

          $this->normalizeUnits($field);

          if (!isset($summary[$data_type])) {
            $summary[$data_type] = 0.0;
          }

          $summary[$data_type] += $field->value;
        }

        $fields = field_info_instances('generation_site', $wrapper->getBundle());

        foreach ($fields as $key => $value) {
          // Get all values for fields on the site and return them here as well.
          if (isset($wrapper->{$key})) {
            $summary[$key] = $wrapper->{$key}->value();
          }
        }
      }

      if (!empty($summary)) {
        $summaries[$site_key] = $summary;
      }
    }

    return empty($summaries[$site_key]) ? FALSE : $summaries[$site_key];
  }

  /**
   * {@inheritdoc}
   */
  public function getBinData(stdClass $response) {
    return isset($response->data->dataSets) ? $response->data->dataSets : array();
  }

  /**
   * Implements GenerationProvider::queryWindowSummary().
   */
  public function queryWindowSummary(Entity $site, DateTime $date_start, DateTime $date_end) {
    $summary = array();

    if ($date_start instanceof GenerationLifetimeStartDateTime) {
      // Instant summaries return lifetime generation, so use that instead of
      // the hacky approach below for the lifetime case.
      // @todo: This is bad if we ever need a window summary starting at the
      // lifetime start but not ending at 'now'.
      if ($instant_summary = $this->queryInstantSummary($site)) {
        $summary['generation'] = $instant_summary['generation'];
        return $summary;
      }
      return FALSE;
    }

    $site_wrapper = entity_metadata_wrapper($site->entityType(), $site);
    // Since the DECK API doesn't implement a window request, we'll simulate
    // it (that is, hack together a value) using a bin request.
    $result = $this->queryAPI('data/graph', array(
      'target_type' => 'location',
      'target_id'   => $site_wrapper->deck_lid->value(),
      'range'       => 'custom',
      'range_start' => $date_start->format('c'),
      'range_end'   => $date_end->format('c'),
      'data_types'  => 'generation',
    ));

    if ($result->success && isset($result->data->dataSets[0])) {
      $summary['generation'] = 0.0;
      foreach ($result->data->dataSets[0]->series as $point) {
        $summary['generation'] += $point[1];
      }
    }
    if (empty($summary)) {
      return FALSE;
    }
    return $summary;
  }

  /**
   * Get value in the provider's device name field.
   */
  public function getDeviceName(EntityMetadataWrapper $device) {
    return isset($device->deck_name) ? $device->deck_name->value() : '';
  }

  /**
   * Get DECK Monitoring locations from JSON API.
   *
   * @return array
   *   Array of DECK Monitoring location objects or FALSE on failure.
   */
  protected function getLocations() {
    $api_key = variable_get('deck_monitoring_api_key', '');
    $url = "http://application.deckmonitoring.com/locations.json?token=" . $api_key;
    $http_result = drupal_http_request($url);
    if ($http_result->code == 200) {
      $data = $http_result->data;
      if ($data === FALSE) {
        watchdog('deck_monitoring', 'No data when trying to get locations from DECK API', array(), WATCHDOG_ERROR);
        return FALSE;
      }
      return json_decode($data);
    }
    // Any response but 200 is an error.
    $msg = 'Unable to get locations from DECK API - got HTTP @code response';
    watchdog('deck_monitoring', $msg, array('@code' => $http_result->code), WATCHDOG_ERROR);
    return FALSE;
  }

  /**
   * Implements GenerationProvider::getInstallDate().
   */
  public function getInstallDate(Entity $site) {
    return new GenerationLifetimeStartDateTime();
  }

  /**
   * Implements GenerationProvider::getVariables().
   */
  public function getVariables() {
    return array(
      'temperature' => 'Temperature',
      'cell temperature' => 'Temperature',
      'generation' => 'Energy',
      'irradiance' => 'Irradiance',
      'power' => 'Power',
    );
  }

  /**
   * Implements GenerationProvider::getSiteVariables().
   */
  public function getSiteVariables(Entity $site) {
    $site_wrapper = entity_metadata_wrapper($site->entityType(), $site);
    $result = $this->queryAPI('data/latest', array(
      'target_type' => 'location',
      'target_id' => $site_wrapper->deck_lid->value(),
    ));
    $variables = array();
    if ($result->success) {
      foreach ($result->data as $row) {
        $variables[$row->data_type] = array(
          'variable' => $row->data_type,
          'unit' => $row->unit,
        );
      }
    }
    return $variables;
  }

  /**
   * Implements GenerationProvider::getSiteDevices().
   */
  public function getSiteDevices(Entity $site) {
    $wrapper = entity_metadata_wrapper('generation_site', $site);
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'deck_device')
      ->entityCondition('bundle', 'device')
      ->propertyCondition('deck_lid', $wrapper->deck_lid->value())
      ->execute();

    return entity_load_wrapped('deck_device', array_keys($results['deck_device']), 'device');
  }

  /**
   * Implements GenerationProvider::getVariableFunctions().
   */
  public function getVariableFunctions($variable = NULL) {
    return array(
      'neutral' => t('Avg/Diff (whatever DECK returns)'),
    );
  }

  /**
   * Implements GenerationProvider::getVariableUnits().
   */
  public function getVariableUnits($variable = NULL) {
    // DECK API doesn't allow telling it what units to give data back in, so
    // these (so far) are only for show (if we wanted to support watts or
    // megawatts, we'd need to add scaling logic).
    return array(
      'fahrenheit' => array('label' => '°F'),
      'gallons' => array('label' => 'gallons'),
      'kilowatts' => array('label' => 'kW'),
      'kilowatt-hours' => array('label' => 'kWh'),
      'kilowatts-per-meter-sq' => array('label' => 'kW/m²'),
    );
  }

  /**
   * Implements GenerationProvider::updateSites().
   */
  public function updateSites() {
    // Let's only get more items if we've got none left queued up to process.
    $queue = DrupalQueue::get('generation_site_update');
    $queue_count = $queue->numberOfItems();

    if ($queue_count || !($data = $this->getLocations())) {
      return;
    }

    foreach ($data as $location) {
      $queue->createItem(array(get_class() => $location));
    }
  }

  /**
   * Implements GenerationProvider::updateSite().
   */
  public function updateSite(stdClass $location) {
    if (isset($location->id)) {
      module_load_include('inc', 'generation');
      module_load_include('inc', 'deck_monitoring', 'deck_monitoring.timezones');

      $query = new EntityFieldQuery();
      $results = $query
        ->entityCondition('entity_type', 'generation_site')
        ->entityCondition('bundle', 'deck')
        ->fieldCondition('deck_lid', 'value', $location->id)
        ->execute();

      $site_id = is_array($results['generation_site']) ? key($results['generation_site']) : FALSE;

      // See whether we already know of this location, or if it's a new one.
      if ($site_id) {
        $site = entity_load_single('generation_site', $site_id);
        $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'deck'));
      }
      else {
        $site = entity_create('generation_site', array('type' => 'deck'));
        $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'deck'));
        $site->deck_lid = $location->id;
      }
      $site->title = $location->name;
      $site->field_geolocation = array('lat' => $location->lat, 'lon' => $location->lon);
      $site->field_timezone = _deck_monitoring_map_rails_timezone($location->timezone);
      $site->field_school_system_size = $location->system_size;
      $this->saveDevices($location);
      $site->save();

      if (!$site_id) {
        $this->configureNewSite($site->raw());
        watchdog('deck_monitoring', 'Created new DECK Monitoring Location: !name', array('!name' => $site->title->value()), WATCHDOG_INFO);
      }
    }
  }

  /**
   * Returns array of our sites, wrapped, keyed by DECK location ID.
   */
  public function loadAllSitesWrapped() {
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'generation_site')
      ->entityCondition('bundle', 'deck')
      ->propertyCondition('status', 1)
      ->execute();

    $sites = array();
    if (!empty($results['generation_site'])) {
      $entities = entity_load_wrapped('generation_site', array_keys($results['generation_site']), 'deck');
      foreach ($entities as $wrapper) {
        $sites[$wrapper->deck_lid->value()] = $wrapper;
      }
    }
    return $sites;
  }

  /**
   * Helper function to normalize units. This is currently only used for power, to convert from kW to W.
   *
   * @todo There might perhaps be a better place to do this?
   *
   * @param object &$field
   *   Raw field data returned from the API.
   */
  private function normalizeUnits(stdClass &$field) {
    switch ($field->data_type) {
      case 'power':
        if ($field->unit === 'kW') {
          $field->unit = 'W';
          $field->value = 1000 * $field->value;
        }
        break;
    }
  }

  /**
   * Sets up a new site with default configuration.
   *
   * @todo Decouple this from generation_charts and explore_data. This will be
   * a bit tricky because it's dependent on provider.
   */
  protected function configureNewSite($site) {
    if (module_exists('generation_charts')) {
      return;
    }

    $explore_presets = array();

    // Add default charts presets.
    if ($generation_pid = _generation_find_preset_id($site, 'generation', 'variable_name')) {
      $periods = array('day', 'week', 'month', 'year', 'lifetime');
      generation_charts_add_site_presets($site, array($generation_pid), $periods);
      $explore_presets[] = $generation_pid;
    }
    if ($power_pid = _generation_find_preset_id($site, 'power', 'variable_name')) {
      generation_charts_add_site_presets($site, array($power_pid), array('day'));
      $explore_presets[] = $power_pid;
    }

    if (!empty($explore_presets) && module_exists('explore_data')) {
      explore_data_add_site_presets($site, $explore_presets);
    }
  }

  /**
   * Store device data (as returned by locations.json).
   */
  protected function saveDevices($location) {
    if (!empty($location->devices)) {
      foreach ($location->devices as $device) {
        $query = new EntityFieldQuery();
        $results = $query
          ->entityCondition('entity_type', 'deck_device')
          ->entityCondition('bundle', 'device')
          ->propertyCondition('deck_did', $device->id)
          ->execute();
        $entity = entity_load_or_create_wrapped($results, 'deck_device', 'device');
        $entity->deck_lid = $location->id;
        $entity->deck_did = $device->id;
        $entity->deck_name = $device->name;
        $entity->deck_dkid = $device->data_key_id;
        $entity->save();
      }
    }
  }
}
