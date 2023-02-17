<?php
/**
 * @file
 * PowerOneGenerationProvider class.
 */

class PowerOneGenerationProvider implements GenerationProvider {

  /**
   * Authenticates with Power-One's REST API.
   */
  public function authenticate() {
    // Cache authentication for up to 30 minutes.
    $token_lifetime = 30 * 60;
    $time = REQUEST_TIME;
    $cid = 'power-one-authentication-token';

    $cache = cache_get($cid);
    if ($cache && ($cache->expire > $time)) {
      return $cache->data;
    }

    $username = variable_get('power_one_api_username', '');
    $password = variable_get('power_one_api_password', '');
    $api_key = variable_get('power_one_api_key', '');
    if (!($username && $password && $api_key)) {
      return FALSE;
    }
    $parameters = array(
      'userId' => $username,
      'password' => $password,
      'fspApiKey' => $api_key,
    );
    $result = $this->directQueryAPI('accounts/ClientLogin', $parameters, 'POST');
    if ($result->success) {
      list($auth, $auth_token) = explode('=', $result->data, 2);
      assert($auth === 'Auth');

      // Trim off the trailing newline character.
      $auth_token = rtrim($auth_token);

      cache_set($cid, $auth_token, 'cache', $time + $token_lifetime);
      return $auth_token;
    }
    return FALSE;
  }

  /**
   * Performs a REST API query, authenticating first if necessary.
   */
  protected function queryAPI($path, array $parameters, $method = 'GET') {
    // Cache token from authenticate() for during the current request.
    static $auth_token;
    if (!$auth_token) {
      $auth_token = $this->authenticate();
    }
    return $this->directQueryAPI($path, $parameters, $method, $auth_token);
  }

  /**
   * Performs a REST API query.
   *
   * @param string $path
   *   API query URL path, relative to API base URL.
   * @param array $parameters
   *   Associative array of parameters for Power-One.
   * @param string $method
   *   HTTP method ('GET' or 'POST').
   * @param string $token
   *   (optional) Authentication token.
   *
   * @return object
   *   Raw HTTP request response from drupal_http_request(), with an extra
   *   member, 'success' set to TRUE (for HTTP 200 response) or FALSE.
   *
   * @see PowerOneGenerationProvider::authenticate()
   */
  protected function directQueryAPI($path, array $parameters, $method = 'GET', $token = NULL) {
    $api_url = 'https://platform.fatspaniel.net/' . $path;

    $url_options = array(
      'absolute' => TRUE,
      'external' => TRUE,
    );
    $headers = array();
    $data = NULL;

    // Add our credentials if any.
    if ($token) {
      $headers['Authorization'] = 'ClientLogin auth=' . $token;
    }

    if ($method === 'GET') {
      $url_options['query'] = $parameters;
    }
    elseif ($method === 'POST') {
      $headers = array('Content-Type' => 'application/x-www-form-urlencoded');
      $data = drupal_http_build_query($parameters);
    }

    $url = url($api_url, $url_options);
    $result = drupal_http_request($url, array(
      'headers' => $headers,
      'method' => $method,
      'data' => $data,
    ));

    $result->success = $result->code == 200;
    if (!$result->success) {
      $message = 'Power-One REST error for @method @path. Response: HTTP @code (@status) @error';
      $args = array(
        '@method' => $method,
        '@path' => $path,
        '@code' => isset($result->code) ? $result->code : NULL,
        '@status' => isset($result->status_message) ? $result->status_message : NULL,
        '@error' => isset($result->data) ? $result->data : NULL,
      );
      watchdog('power_one', $message, $args, WATCHDOG_ERROR);
    }
    return $result;
  }

  /**
   * Implements GenerationProvider::queryBin().
   */
  public function queryBin(Entity $site, array $presets, DateTime $date_start, DateTime $date_end, $bin = 'hour') {
    $all_variables = $this->getVariables();

    $data = array();
    $query_fields = array();
    $device_presets = $site_presets = array();
    foreach ($presets as $preset) {
      // Presets with device IDs are queried separately.
      if (!empty($preset->device_id)) {
        $device_presets[$preset->preset_id] = $preset;
        continue;
      }

      $variable = generation_variable_load($preset->variable_id);
      $query_fields[] = array(
        'field' => $variable->name,
        'label' => $preset->alias,
        'function' => $preset->function,
        'units' => $preset->units,
      );
      $site_presets[] = $preset;
    }

    // Map Generation module's bins to Power-One bins.
    $bin_map = array(
      'min15' => 'Min15',
      'hour'  => 'Hour',
      'day'   => 'Day',
      'week'  => 'Week',
      'month' => 'Month',
    );

    $options = array(
      'type' => 'binsRequest',
      'binSize' => $bin_map[$bin],
      'endFixed' => $date_end->format('c'),
    );
    $this->setStartDate($options, $date_start);

    //
    // Query Power-One for data.
    //
    $site = entity_metadata_wrapper('generation_site', $site);
    $result = $this->getMonitoredInfoCommon($site->pow_eid->value(), $options, $query_fields);
    if ($result->success) {
      $data = $this->formatBinData($this->getBinData($result), $site_presets);
    }

    // Query any per-device presets.
    if (!empty($device_presets)) {
      foreach ($device_presets as $preset_id => $preset) {
        // The devices ID is the entity ID Power One is expecting.
        $result = $this->queryBinDevice($preset->device_id, array($preset), $date_start, $date_end, $options);
        if (is_object($result)) {
          $data = array_merge($data, $this->formatBinData($result->fields, array($preset)));
        }
      }
    }

    return $data;
  }

  /**
   * {@inheritdoc}
   */
  public function getBinData(stdClass $response) {
    return $response->fields;
  }

  /**
   * {@inheritdoc}
   */
  public function queryBinDevice($device_id, array $variables, DateTime $date_start, DateTime $date_end, $options = array()) {
    $query_fields = array();
    foreach ($variables as $preset) {
      $query_fields[] = array(
        'field' => generation_variable_load($preset->variable_id)->name,
        'label' => $preset->alias,
        'function' => $preset->function,
        'units' => $preset->units,
      );
    }

    // Set some defaults.
    $options += array(
      'type' => 'binsRequest',
      'binSize' => 'Day',
      'endFixed' => $date_end->format('c'),
    );

    $this->setStartDate($options, $date_start);

    return $this->getMonitoredInfoCommon($device_id, $options, $query_fields);
  }

  /**
   * Format data returned from `self::getMonitoredInfoCommon()`.
   */
  protected function formatBinData(array $fields, array $presets) {
    $all_units = $this->getVariableUnits();

    $index = 0;
    $data = array(
      '',
    );
    foreach ($fields as $field) {
      $is_temperature = strpos($field->field, 'Temp') !== FALSE;
      $preset = $presets[$index];

      $data[$index] = array(
        'name' => $preset->alias,
        'type' => $preset->chart_type,
        'units' => $all_units[$preset->units]['label'],
        'description' => $preset->description,
        'data' => array(),
      );

      foreach ($field->values as $point) {
        // Each sample is an object with these members:
        // - @start: UNIX timestamp.
        // - @value: Measured value.
        $value = isset($point->{'@value'}) ? (float) $point->{'@value'} : 0.0;

        $data[$index]['data'][] = array(
          (float) $point->{'@start'},
          // Don't accept negative values for non-temperature data.
          $is_temperature ? $value : max($value, 0.0),
        );
      }
      $index++;
    }
    return $data;
  }

  /**
   * Does the work for queryInstantSummary() and queryWindowSummary().
   */
  protected function querySummary($type, $site, DateTime $date_start = NULL, DateTime $date_end = NULL) {
    $query_data = &drupal_static(__FUNCTION__);

    if (!isset($query_data[$type])) {

      if ($site) {
        $site = entity_metadata_wrapper('generation_site', $site);
        $pow_eid = $site->pow_eid->value();
      }
      else {
        // Use the special customer (global) Power-One entity ID that encompasses
        // all sites.
        $pow_eid = variable_get('power_one_global_eid', 0);
      }

      if ($type == 'instant') {
        assert(is_null($date_start));
        assert(is_null($date_end));

        // Query instantaneous summary data.
        $options = array('type' => 'instantRequest');

        // GenerationEnergy doesn't really make sense for an instant request, but
        // the Power-One API will return lifetime energy generated, which can be
        // useful.
        //
        // Set each 'label' to the array key that the Generation API uses for the
        // value. The Power-One API ignores 'label' and spits it back to us.
        $query_fields = array(
          array(
            'field' => 'CellTemp',
            'label' => 'cell_temperature',
            'units' => 'fahrenheit',
          ),
          array(
            'field' => 'GenerationEnergy',
            'label' => 'generation',
            'units' => 'kilowatt-hours',
          ),
          array(
            'field' => 'Irradiance',
            'label' => 'irradiance',
            'units' => 'watts-per-meter-sq',
          ),
          array(
            'field' => 'GenerationPower',
            'label' => 'power',
            'units' => 'watts',
          ),
          array(
            'field' => 'AmbientTemp',
            'label' => 'temperature',
            'units' => 'fahrenheit',
          ),
          array(
            'field' => 'WindDirection',
            'label' => 'wind_direction',
            'units' => 'degrees-north',
          ),
          array(
            'field' => 'WindSpeed',
            'label' => 'wind_speed',
            'units' => 'miles-per-hour',
          ),
        );
      }
      else {
        assert($type == 'window');
        assert(is_object($date_start));
        assert(is_object($date_end));

        $options = array(
          'type' => 'windowRequest',
          'endFixed' => $date_end->format('c'),
        );
        if ($date_start instanceof GenerationLifetimeStartDateTime) {
          $options['startRelative'] = 'first-recorded';
        }
        else {
          $options['startFixed'] = $date_start->format('c');
        }

        $query_fields = array(
          array(
            'field' => 'GenerationEnergy',
            'label' => 'generation',
            'units' => 'kilowatt-hours',
            'function' => 'Diff',
          ),
        );
      }

      $data = array();
      $result = $this->getMonitoredInfoCommon($pow_eid, $options, $query_fields);
      if ($result->success) {
        foreach ($result->fields as $field) {
          if (isset($field->value)) {
            $value = (float) $field->value;

            $is_temperature = strpos($field->field, 'Temp') !== FALSE;

            // If it's not a temperature, don't accept negative values. Corrupt
            // data at Power-One can happen and can cause negative values.
            $data[$field->label] = $is_temperature ? $value : max($value, 0.0);
          }
          else {
            $data[$field->label] = NULL;
          }
        }
      }

      if (isset($site)) {
        $fields = field_info_instances('generation_site', $site->getBundle());

        foreach ($fields as $key => $value) {
          // Get all values for fields on the site and return them here as well.
          if (isset($site->{$key})) {
            $data[$key] = $site->{$key}->value();
          }
        }
      }

      $query_data[$type] = $data;
    }

    return empty($data) ? FALSE : $data;
  }

  /**
   * Implements GenerationProvider::queryInstantSummary().
   */
  public function queryInstantSummary($site = NULL) {
    return $this->querySummary('instant', $site);
  }

  /**
   * Implements GenerationProvider::queryWindowSummary().
   */
  public function queryWindowSummary(Entity $site, DateTime $date_start, DateTime $date_end) {
    return $this->querySummary('window', $site, $date_start, $date_end);
  }

  /**
   * Calls getMonitoredInfo for multiple fields with common options.
   *
   * @param int $pow_eid
   *   Power-One entity ID for the request.
   * @param array $options
   *   Query options, some of which are sent to the API as is, and some of
   *   which are prefixed and duplicated to be sent per-field.
   * @param array $fields
   *   Key-unimportant array of field arrays, each of which contains an array
   *   of field information, with the API field name in a 'field' element, and
   *   any other API options in other elements.
   *
   * @return object
   *   API return value object.
   */
  public function getMonitoredInfoCommon($pow_eid, $options, $fields) {
    $path = 'rest/v1/info/' . $pow_eid . '.json';

    // The API requires us to send these options with *every* field.
    // So we look through the sent options and pull out any of these that are
    // there, so we can include them with every field.
    $options_per_field = array(
      'type',
      'binSize',
      'atRelative',
      'atFixed',
      'startRelative',
      'endRelative',
      'startFixed',
      'endFixed',
      'relativeBase',
    );

    // After this loop, the options left over will be passed root-level to
    // the API, rather than being duplicated (and prefixed) for each field.
    foreach ($options_per_field as $option_name) {
      if (isset($options[$option_name])) {
        $field_options[$option_name] = $options[$option_name];
        unset($options[$option_name]);
      }
    }

    $index = 1;
    foreach ($fields as $field) {
      $prefix = 'field.' . $index++;

      $field = $field + $field_options;
      $options[$prefix] = $field['field'];
      unset($field['field']);

      foreach ($field as $key => $value) {
        $options[$prefix . '.' . $key] = $value;
      }
    }

    $results = $this->queryAPI($path, $options);
    $data = json_decode($results->data);
    if (isset($data->getMonitoredInfoResponse)) {
      $data = $data->getMonitoredInfoResponse;
    }

    if (isset($data->status)) {
      if ($data->status === 'SUCCESS' || $data->status === 'PARTIAL_FAILURE') {
        $data->success = TRUE;
        return $data;
      }
    }

    return $results;
  }

  /**
   * Implements GenerationProvider::getInstallDate().
   */
  public function getInstallDate(Entity $site) {
    $wrapper = entity_metadata_wrapper('generation_site', $site);
    $value = field_get_items('generation_site', $site, 'pow_install_date');

    if (isset($value[0]['value'])) {
      return new DateTime($value[0]['value']);
    }
    else {
      return new GenerationLifetimeStartDateTime();
    }
  }


  /**
   * Get value in the provider's device name field.
   */
  public function getDeviceName(EntityMetadataWrapper $device) {
    return isset($device->pow_name) ? $device->pow_name->value() : '';
  }

  /**
   * Implements GenerationProvider::getVariables().
   */
  public function getVariables() {
    module_load_include('inc', 'power_one');
    return _power_one_field_data_types();
  }

  /**
   * Implements GenerationProvider::getSiteVariables().
   */
  public function getSiteVariables(Entity $site) {
    // Not yet implemented for PowerOne.
    return array();
  }

  /**
   * Implements GenerationProvider::getSiteDevices().
   */
  public function getSiteDevices(Entity $site) {
    $devices = $this->loadSiteDetails($site->id);

    return isset($devices->devices) ? $devices->devices : array();
  }

  /**
   * Implements GenerationProvider::getVariableFunctions().
   */
  public function getVariableFunctions($variable = NULL) {
    return array(
      'Avg'  => t('Avg'),
      'Diff' => t('Diff'),
      'Max'  => t('Max'),
      'Min'  => t('Min'),
      'Last' => t('Last'),
    );
  }

  /**
   * Implements GenerationProvider::getVariableUnits().
   */
  public function getVariableUnits($variable = NULL) {
    module_load_include('inc', 'power_one');
    return _power_one_variable_units($variable);
  }

  /**
   * Implements GenerationProvider::updateSites().
   */
  public function updateSites() {
    $eid = variable_get('power_one_global_eid', 0);

    $query = db_select('field_data_pow_eid', 'fdpe')
      ->fields('fdpe', array('entity_id', 'pow_eid_value'))
      ->execute();
    $sites_in_drupal = $query->fetchAllAssoc('pow_eid_value');

    $all = $this->getSitesByCustomerId($eid);
    $sites_in_pow = $all['descendants'];

    if(is_array($sites_in_pow)) {
      $count = 0;

      foreach ($sites_in_pow as $site_in_pow) {
        $pow_eid = $site_in_pow['entityId'];
        // Check if node exists.
        if (isset($sites_in_drupal[$pow_eid])) {
          // Load existing node from database.
          $site_in_drupal = entity_load_single('generation_site', $sites_in_drupal[$pow_eid]->entity_id);
          $site_in_drupal = entity_metadata_wrapper('generation_site', $site_in_drupal);
        }
        else {
          // No existing node, create basic node structure.
          $site_in_drupal = entity_create('generation_site', array('type' => 'power_one'));
          $site_in_drupal = entity_metadata_wrapper('generation_site', $site_in_drupal, array('bundle' => 'power_one'));
          $site_in_drupal->pow_eid = $pow_eid;
        }
        $this->updateSiteKnown($site_in_drupal, $site_in_pow);
        $this->updateSiteLogger($site_in_drupal);

        $count++;
      }
      drupal_set_message(t('Updated %count descendant Power-One Site records.', array('%count' => $count)));
    } else {
      watchdog('power_one', 'Error in updateSites: ' . gettype($sites_in_pow), array('sites_in_pow' => $sites_in_pow), WATCHDOG_ERROR);
    }
  }


  /**
   * Implements GenerationProvider::updateSite().
   */
  public function updateSite(stdClass $location) {
    // Updating a single site takes all the 15 seconds, so we're not
    // implementing cron queue at this time.
    return;
  }

  /**
   * Updates a site's fields.
   *
   * @param EntityMetadataWrapper $site_in_drupal
   *   The entity meta wrapper of the site.
   * @param array $site_in_pow
   *   An array of values directly from Power One.
   */
  public function updateSiteKnown(EntityMetadataWrapper $site_in_drupal, $site_in_pow = array()) {

    if (empty($site_in_pow)) {
      $query = $this->buildAssetInfoQuery('Site', 'entityId', $site_in_drupal->pow_eid->value(), '=');
      $result_query = $this->buildAssetInfoResultQuery('Site', 'detailLevel', "'All'");
      $site_in_pow = $this->getAssetInfo($query, $result_query);
    }

    $site_in_drupal->title->set($site_in_pow['name']);

    $site_in_drupal->pow_install_date->set(strtotime($site_in_pow['installDate']));
    $site_in_drupal->pow_system_size_units->set($site_in_pow['installedCapacities'][0]['unit']);
    $site_in_drupal->field_school_system_size->set($site_in_pow['systemSize']);
    $site_in_drupal->field_timezone->set($this->timezoneCleanup($site_in_pow['timeZone']));

    $location = $site_in_pow['location'][0];
    $site_in_drupal->field_geolocation = array('lat' => $location['latitude'], 'lon' => $location['longitude']);

    $site_in_drupal->save();
  }

  /**
   * Updates a site and all its descendent data.
   *
   * @param int $site
   *   The entity id of the site.
   */
  public function updateSiteLogger(EntityMetadataWrapper $site) {
    $site_id = $site->getIdentifier();
    $children_in_drupal = $this->loadSiteDetails($site_id);
    $data = $this->getDeviceBySiteId($site->pow_eid->value(), 'All', 'All', TRUE);
    $children_in_pow = $data['descendants'];

    foreach ($children_in_pow as $logger_in_pow) {
      $pow_eid = $logger_in_pow['entityId'];
      if (isset($children_in_drupal->loggers[$pow_eid])) {
        // Load existing node from database.
        $logger_in_drupal = $children_in_drupal->loggers[$pow_eid];
      }
      else {
        // No existing node, create basic node structure.
        $logger_in_drupal = entity_create('pow_logger', array('type' => 'logger'));
        $logger_in_drupal = entity_metadata_wrapper('pow_logger', $logger_in_drupal, array('bundle' => 'logger'));
        $logger_in_drupal->pow_eid = $pow_eid;
      }

      $logger_in_drupal->pow_name->set($logger_in_pow['meta'][0]['displayName']);
      $logger_in_drupal->pow_lid->set($logger_in_pow['loggerId']);
      $logger_in_drupal->pow_is_active->set($logger_in_pow['active'] == 'true');
      $logger_in_drupal->pow_mac_address->set($logger_in_pow['macAddress']);
      $logger_in_drupal->pow_model->set($logger_in_pow['model']);
      $logger_in_drupal->pow_manufacturer->set($logger_in_pow['manufacturer']);
      $logger_in_drupal->pow_site->set($site_id);

      $vocabulary = taxonomy_vocabulary_machine_name_load('power_one_device_categories');

      $category = taxonomy_get_term_by_name($logger_in_pow['categories'], 'power_one_device_categories');

      if (empty($category)) {
        $term = array(
          'vid' => $vocabulary->vid,
          'name' => $logger_in_pow['categories'],
          'vocabulary_machine_name' => 'power_one_device_categories',
        );
        $category_id = taxonomy_term_save((object) $term);
      }
      else {
        $category_id = current($category)->tid;
      }

      $logger_in_drupal->field_categories->set($category_id);

      $logger_in_drupal->save();

      if(empty($logger_in_pow['descendants'])) {
        $errMsg = 'Descendants is not defined';
        watchdog('power_one', $errMsg, $logger_in_pow, WATCHDOG_WARNING);
        drupal_set_message('Power One Generation: ' . $errMsg, 'warning');
        continue;
      }

      foreach ($logger_in_pow['descendants'] as $device_in_pow) {
        if (isset($children_in_drupal->devices[$pow_eid])) {
          // Load existing node from database.
          $device_in_drupal = $children_in_drupal->devices[$pow_eid];
        }
        else {
          // No existing node, create basic node structure.
          $device_in_drupal = entity_create('pow_device', array('type' => 'device'));
          $device_in_drupal = entity_metadata_wrapper('pow_device', $device_in_drupal, array('bundle' => 'device'));
          $device_in_drupal->pow_eid = $device_in_pow['entityId'];
        }

        $device_in_drupal->pow_logger_eid->set($logger_in_drupal->pow_eid->value());
        if (isset($device_in_pow['meta'][0]['displayName'])) {
          $device_in_drupal->pow_name->set($device_in_pow['meta'][0]['displayName']);
        }
        if (isset($device_in_pow['deviceTypeEntityId'])) {
          $device_in_drupal->pow_device_id->set($device_in_pow['deviceTypeEntityId']);
        }

        if (isset($device_in_pow['deviceTypeId'])) {
          $device_in_drupal->pow_device_type_id->set($device_in_pow['deviceTypeId']);
        }

        if (isset($device_in_pow['deviceNumber'])) {
          $device_in_drupal->pow_device_number->set($device_in_pow['deviceNumber']);
        }

        $device_in_drupal->pow_is_active->set(isset($device_in_pow['active']) && $device_in_pow['active'] == 'true');

        if (isset($device_in_pow['manufacturer'])) {
          $device_in_drupal->pow_manufacturer->set($device_in_pow['manufacturer']);
        }
        $device_in_drupal->pow_site->set($site_id);

        if (isset($device_in_pow['categories'])) {
          $category = taxonomy_get_term_by_name($device_in_pow['categories'], 'power_one_device_categories');

          if (empty($category)) {
            $term = array(
              'vid' => $vocabulary->vid,
              'name' => $device_in_pow['categories'],
              'vocabulary_machine_name' => 'power_one_device_categories',
            );
            $category_id = taxonomy_term_save((object) $term);
          }
          else {
            $category_id = current($category)->tid;
          }

          $device_in_drupal->field_categories->set($category_id);
        }
        $device_in_drupal->save();
      }
    }
  }

  /**
   * Set the start date.
   *
   * @param array $options
   *   Options array.
   * @param DateTime $date_start
   *   Starting date.
   */
  protected function setStartDate(&$options, DateTime $date_start) {
    if ($date_start instanceof GenerationLifetimeStartDateTime) {
      $options['startRelative'] = 'first-recorded';
    }
    else {
      $options['startFixed'] = $date_start->format('c');
    }
  }

  /**
   * Obtains site info for a given customer ID.
   *
   * Old function was fat_spaniel_get_sites_by_customer_id.
   *
   * @param int $id
   *   Power-One customer entity ID.
   * @param string $detail
   *   Customer result detail level.
   * @param string $site_detail
   *   Site result detail level.
   *
   * @return array
   *   Power-One asset info result array containing descendant site detail.
   */
  private function getSitesByCustomerId($id, $detail = 'All', $site_detail = 'All') {
    $query = $this->buildAssetInfoQuery('Customer', 'entityId', $id, '=');
    $result_query = $this->buildAssetInfoResultQuery('Customer', 'detailLevel', "'" . $detail . "'");
    $site_result_query = $this->buildAssetInfoResultQuery('Site', 'detailLevel', "'" . $site_detail . "'");
    return $this->getAssetInfo($query, $result_query . '/' . $site_result_query);
  }

  /**
   * Builds a query segment for use in getAssetInfo().
   *
   * Was _power_one_build_asset_info_query.
   *
   * @param string $type
   *   Asset type, can be one of:
   *     - Customer
   *     - Site
   *     - Logger
   *     - Device
   * @param string $property
   *   Property name.
   * @param string $value
   *   Value for right-hand-side.
   * @param string $op
   *   Comparison operator, can be one of:
   *     - =
   *     - <
   *     - >
   *     - !=
   *
   * @return string
   *   Formatted query segment.
   */
  private function buildAssetInfoQuery($type, $property, $value, $op = '=') {
    return $type . '[' . $property . ']' . $op . $value;
  }

  /**
   * Builds a result query segment for use in get_asset_info().
   *
   *  Was _power_one_build_asset_info_result_query.
   *
   * @param string $type
   *   Asset type, can be one of:
   * @param string $function
   *   Can be one of:
   *     - detailLevel
   *     - fields
   * @param varied $value
   *   Argument depends on $function
   *
   * @return string
   *   Formated resultQuery segment
   */
  private function buildAssetInfoResultQuery($type, $function, $value) {
    return $type . '[' . $function . '(' . $value . ')]';
  }

  /**
   * Retrieve asset information.
   *
   * Was power_one_get_asset_info.
   *
   * @param string $query
   *   Query that specifies the assets for which information is required.
   * @param string $result_query
   *   Query that specifies the type, the hierarchy, and the amount of detail of
   *   the result assets.
   * @param mixed $limit
   *   Limit.
   */
  private function getAssetInfo($query, $result_query, $limit = FALSE) {
    $token = $this->authenticate();
    $params = array(
      'query' => $query,
      'resultQuery' => $result_query,
    );
    if ($limit !== FALSE) {
      $params['limit'] = $limit;
    }

    $query_result = $this->directQueryAPI('rest/v1/asset', $params, 'GET', $token);

    if ($query_result->success && $query_result->data) {
      $result = $this->xml2array($query_result->data);

      if ($result) {
        switch ($result['status']) {
          case POWER_ONE_GET_ASSET_INFO_RESPONSE_SUCCESS:
            return $result['assets'][0];

          case POWER_ONE_GET_ASSET_INFO_RESPONSE_NONE:
          default:
            watchdog('power_one', 'asset error:<pre>!error</pre><pre>Params: !params</pre><pre>Result: !result</pre>',
              array(
                '!error' => $result['#error'],
                '!params' => print_r($params, TRUE),
                '!result' => print_r($result, TRUE),
              ));
            return FALSE;
        }
      }
    }
  }

  /**
   * Was power_one_get_devices_by_site_id().
   */
  private function getDeviceBySiteId($id, $detail = 'All', $site_detail = 'All', $get_loggers = FALSE) {
    $query = $this->buildAssetInfoQuery('Site', 'entityId', $id, '=');
    $result_query = $this->buildAssetInfoResultQuery('Site', 'detailLevel', "'" . $detail . "'");
    $site_result_query = $this->buildAssetInfoResultQuery('Device', 'detailLevel', "'" . $site_detail . "'");
    if ($get_loggers) {
      $logger_result_query = '/' . $this->buildAssetInfoResultQuery('Logger', 'detailLevel', "'" . $site_detail . "'");
    }
    return $this->getAssetInfo($query, $result_query  . $logger_result_query . '/' . $site_result_query);
  }

  /**
   * Converts CamelCase to underscore.
   *
   * Was _power_one_to_underscore.
   */
  private function toUnderscore($word) {
    static $words = array();
    if (!isset($words[$word])) {
      $pattern = array(
        '/[^A-Z^a-z^0-9^\/]+/',
        '/([a-z\d])([A-Z])/',
        '/([A-Z]+)([A-Z][a-z])/',
      );
      $replacement = array('_', '\1_\2', '\1_\2');
      $words[$word] = strtolower(preg_replace($pattern, $replacement, $word));
    }
    return $words[$word];
  }

  /**
   * Obtains logger, device and category details.
   *
   * Was _power_one_node_load_site_details.
   *
   * @param int $site_id
   *   Power-One Site site object.
   */
  private function loadSiteDetails($site_id) {
    $details = new stdClass();

    // Loggers.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'pow_logger')
      ->entityCondition('bundle', 'logger')
      ->fieldCondition('pow_site', 'target_id', $site_id);
    if ($results = $query->execute()) {
      foreach ($results['pow_logger'] as $result) {
        $logger = entity_load_single('pow_logger', $result->id);
        $wrapper = entity_metadata_wrapper('pow_logger', $logger);
        $details->loggers[$logger->pow_eid] = $wrapper;
      }
    }

    // Devices.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'pow_device')
      ->entityCondition('bundle', 'device')
      ->fieldCondition('pow_site', 'target_id', $site_id);
    if ($results = $query->execute()) {
      foreach ($results['pow_device'] as $result) {
        $device = entity_load_single('pow_device', $result->id);
        $wrapper = entity_metadata_wrapper('pow_device', $device);
        $details->devices[$device->pow_eid] = $wrapper;
      }
    }

    return $details;
  }

  /**
   * Function to turn xml into an associateive array.
   *
   * Taken from http://www.php.net/manual/en/class.simplexmliterator.php.
   *
   * @param string $fname
   *   The XML string.
   *
   * @return array
   *   The associative array.
   */
  private function xml2array($fname) {
    $sxi = new SimpleXmlIterator($fname);
    return $this->sxiToArray($sxi);
  }

  /**
   * Helper function to recurse over XML.
   * 
   * @param SimpleXMLIterator $sxi
   *   The iterator
   *
   * @return array
   *   An associative array.
   */
  private function sxiToArray($sxi) {
    $a = array();
    for ($sxi->rewind(); $sxi->valid(); $sxi->next()) {
      if (!array_key_exists($sxi->key(), $a)) {
        $a[$sxi->key()] = array();
      }
      if ($sxi->hasChildren()) {
        $a[$sxi->key()][] = $this->sxiToArray($sxi->current());
      }
      else {
        $a[$sxi->key()] = strval($sxi->current());
      }
    }
    return $a;
  }

  /**
   * Information from Power One comes in an old format.
   */
  private function timezoneCleanup($old) {
    module_load_include('inc', 'date_api', 'date_api.admin');
    return _date_timezone_replacement($old);
  }
}
