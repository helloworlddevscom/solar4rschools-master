<?php

class LocusEnergyGenerationProvider implements GenerationProvider
{

  protected $site_components;


  protected $locus_vars = array(
    'ac_power_measured' => 'W',
    'ac_energy_measured' => 'Wh',
    'irradiance' => 'POAI',
    'temperature_ambient' => 'TmpAmb',
    'temperature_panel' => 'TmpBOM'
  );


  /**
   * Dynamically queries for bin data for one or more fields.
   *
   * @param Entity $site
   *   Site entity.
   * @param array $presets
   *   Variable preset objects.
   * @param DateTime $start
   *   Start date and time for the query.
   * @param DateTime $end
   *   End date and time for the query.
   *
   * @return array
   *   Format:
   *   array(
   *     // For each field
   *     array(
   *       'name' => 'Field/Variable Name',
   *       'type' => 'area', // Chart type: line, area, column, etc.
   *       'data' => array(
   *         array(
   *           UNIX timestamp,
   *           Raw scalar value,
   *         ),
   *         array(
   *           UNIX timestamp,
   *           Raw scalar value,
   *         ),
   *         ...
   *       ),
   *     ),
   *     ...
   *   )
   */
  public function queryBin(Entity $site, array $presets, DateTime $start, DateTime $end, $bin = 'hour')
  {
    module_load_include('inc', 'locus_energy', 'service');

    $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'locus_energy'));
    $locus_site_id = $site->field_locus_energy_site_id->value();

    $variable_units = $this->getVariableUnits();

    $data = array();
    foreach ($presets as $preset) {

      $now = new DateTime();

      if ($end > $now && ($now->format('U') - $start->format('U') < 129600)) {
        $bin = 'hour';
      }

      $bin_map = array(
        'min15' => 'hourly',
        'hour' => 'hourly',
        'day' => 'daily',
        'month' => 'monthly',
        'year' => 'yearly'
      );

      $interval = $bin_map[$bin];

      $field = $this->locus_vars[$preset->units] . '_' . strtolower($preset->function);

      $site_data = $this->getSiteData($locus_site_id, [$field], $start, $end, $interval);
      $aggregate_data = array();
      foreach (array_keys($site_data) as $index) {
        $aggregate_data[$index] = array();
        $aggregate_data[$index][0] = $site_data[$index]->data_timestamp;
        $value = intval($site_data[$index]->{$field}) / 1000;
        if ($value <= 0) {
          $value = 0;
        }
        $aggregate_data[$index][1] = $value;
      }

      $data[] = array(
        'name' => $preset->alias,
        'type' => $preset->chart_type,
        'description' => $preset->description,
        'data' => $aggregate_data,
        'units' => $variable_units[$preset->units]['label'],
      );
    }

    return $data;
  }


  /**
   * Query locus_api_data table for site data previously pulled from Locus API.
   *
   * @param $site_id
   * @param array $fields
   * @param DateTime $start
   * @param DateTime $end
   * @param $granularity
   * @return mixed
   */
  public function getSiteData($site_id, array $fields, DateTime $start, DateTime $end, $granularity)
  {

    $start_timestamp = $start->getTimestamp();
    $end_timestamp = $end->getTimestamp();

    $fields[] = 'data_timestamp';

    $granularity_key = LocusEnergyService::get()->getGranularityKey($granularity);

    $data_query = db_select('locus_api_data', 'l');
    $data_stmt = $data_query
      ->fields('l', $fields)
      ->condition('site_id', $site_id, '=')
      ->condition('granularity', $granularity_key, '=')
      ->condition('data_timestamp', $start_timestamp, '>=')
      ->condition('data_timestamp', $end_timestamp, '<=')
      ->orderBy('data_timestamp', 'ASC')
      ->execute();
    $data = $data_stmt->fetchAll(PDO::FETCH_OBJ);

    return $data;
  }


  /**
   * Dynamically query a single device.
   */
  public function queryBinDevice($device_id, array $variables, DateTime $date_start, DateTime $date_end, $options = array())
  {
    throw new Exception('unimplemented');
  }


  /**
   * Get bin data from API response.
   */
  public function getBinData(stdClass $response)
  {
    throw new Exception('unimplemented');
  }


  /**
   * Get value in the provider's device name field.
   */
  public function getDeviceName(EntityMetadataWrapper $device)
  {
    throw new Exception('unimplemented');
  }


  /**
   * Dynamically queries for summaries for one or all of the provider's sites.
   *
   * @param object $site
   *   (optional) Omit this parameter to get summary data for all generation
   *   sites.
   *
   * @return array
   *   Instant summaries contain: An array with these keys and values:
   *   - // Current cell temperature, in Fahrenheit.
   *     'cell_temperature' => <value, degrees F>,
   *   - // Lifetime generation energy, in kilowatt hours.
   *     'generation' => <value, kWh>,
   *   - // Current irradiance, in Watts per square meter.
   *     'irradiance' => <value, W/m^2>,
   *   - // Current power output, in Watts.
   *     'power' => <value, W>,
   *   - // Current ambient temperature, in Fahrenheit.
   *     'temperature' => <value, degrees F>,
   */
  public function queryInstantSummary($site = NULL)
  {

    $summaries = array();

    if ($site) {
      $sites = array($site);
    }
    else {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'generation_site')
        ->entityCondition('bundle', 'locus_energy');
      $result = $query->execute();
      $sites = entity_load('generation_site', array_keys($result));
    }

    foreach ($sites as $site) {
      $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'locus_energy'));
      $summaries[$site->id->value()] = array();

      $locus_site_id = $site->field_locus_energy_site_id->value();

      // For locus lifetime totals query with a really early date and a future date
      $twenty_years_back = time() - (60 * 60 * 24 * 365 * 20);

      $start = new DateTime();

      $start->setTimestamp($twenty_years_back);

      $one_year_in_future = time() + (60 * 60 * 24 * 365);

      $end = new DateTime();

      $end->setTimestamp($one_year_in_future);

      $data = $this->getSiteData($locus_site_id, ['Wh_sum'], $start, $end, 'yearly');
      $total_energy = 0;

      foreach ($data as $year_data) {
        if (property_exists($year_data, 'Wh_sum')) {
          $total_energy += $year_data->Wh_sum;
        }
      }

      $summaries[$site->id->value()]['generation'] = (float)$total_energy / 1000;

      $start = generation_new_datetime_local(time() - (60 * 60 * 10 ));

      $end = generation_new_datetime_local(time());

      $data = $this->getSiteData($locus_site_id, ['W_max'], $start, $end, 'hourly');

      $interval_readings = array_reverse($data);
      foreach ($interval_readings as $interval_reading) {
        if(property_exists($interval_reading, 'W_max')) {
          $summaries[$site->id->value()]['power'] = $interval_reading->W_max;
          break;
        }
      }
    }

    return reset($summaries);
  }


  public function celsiusToFahrenheit($celsius) {
    return $celsius * 9 / 5+32;
  }


  /**
   * Dynamically queries for windowed data.
   *
   * Queries one or all of the provider's generation sites.
   *
   * @param \Entity|object $site
   *   Give NULL for this parameter to get windowed data for all generation
   *   sites.
   *
   * @param \DateTime $start
   * @param \DateTime $end
   * @return array Format:
   * Format:
   * array(
   * // Cell temperature, in Fahrenheit.
   * 'cell_temperature' => <value, degrees F>,
   * // Generation energy, in kilowatt hours.
   * 'generation' => <value, kWh>,
   * // Irradiance, in Watts per square meter.
   * 'irradiance' => <value, W/m^2>,
   * // Power output, in Watts.
   * 'power' => <value, W>,
   * // Ambient temperature, in Fahrenheit.
   * 'temperature' => <value, degrees F>,
   * )
   */
  public function queryWindowSummary(Entity $site, DateTime $start, DateTime $end)
  {
    $total_energy = 0;

    $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'locus_energy'));
    $locus_site_id = $site->field_locus_energy_site_id->value();

    $start_timestamp = $start->getTimeStamp();

    if ($start_timestamp == 0) {
      $start = $this->getInstallDate($site->raw());
      $start_timestamp = $start->getTimestamp();
    }

    $end_timestamp = $end->getTimeStamp();

    $diff = $end_timestamp - $start_timestamp;

    if ($diff < 86400 * 2) {
      $interval = 'hourly';
    } else {
      $LocusEnergyService = LocusEnergyService::get();
      $start = $LocusEnergyService->roundDateTimeHour($start);
      $end = $LocusEnergyService->roundDateTimeHour($end);

      if(31536000  <= $diff && $diff <= 31622400) {
        $interval = 'monthly';
      } else if( $diff > 31622400 ) {
        $interval = 'yearly';
      } else {
        $interval = 'daily';
      }
    }

    $data = $this->getSiteData($locus_site_id, ['Wh_sum'], $start, $end, $interval);

    foreach ($data as $data_interval) {
      if (property_exists($data_interval, 'Wh_sum')) {
        $total_energy = $total_energy + $data_interval->Wh_sum;
      }
    }

    $total_energy = $total_energy / 1000; // Data is in watt-hours, divide by 1000 to convert to kWh

    $data = array(
      'generation' => $total_energy
    );

    return $data;
  }


  /**
   * Requests all sites from data provider and creates entities for new sites.
   *
   * Called periodically from within a cron job; this will generally be a
   * pretty slow method.
   */
  public function updateSites()
  {

    $LocusEnergyService = LocusEnergyService::get();

    if (!$LocusEnergyService->cronEnabled()) {
      return;
    }

    // Override generation_cron() to only call Locus API with this method once per month.
    $last_time = variable_get('locus_generation_last_site_update', 0);
    $curr_datetime = new DateTime();
    $difference = $curr_datetime->getTimestamp() - $last_time;

    $auto_update = (bool) variable_get('locus_energy_auto_update_available_sites', TRUE);

    // 30 days.
    if ($difference >= 2592000 && $auto_update) {
      variable_set('locus_generation_last_site_update', $curr_datetime->getTimestamp());
    }
    else {
      return;
    }

    $sites = $LocusEnergyService->getAllSites();
    $active_site_ids = array();

    foreach ($sites as $locusSite) {
      // Add it to the list of active site ids
      $active_site_ids[] = $locusSite->id;
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'generation_site')
        ->entityCondition('bundle', 'locus_energy')
        ->fieldCondition('field_locus_energy_site_id', 'value', $locusSite->id, '=')
        ->execute();

      if (isset($result['generation_site'])) {
        $site = current(entity_load('generation_site', array_keys($result['generation_site'])));
        $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'locus_energy'));
      } else {
        $site = entity_create('generation_site', array('type' => 'locus_energy'));
        $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'locus_energy'));
        $site->field_locus_energy_site_id = $locusSite->id;
        LocusEnergyService::get()->getSiteDetails($locusSite);
        $site->status = 1;
      }

      $site->title = $locusSite->name;
      if (isset($locusSite->latitude) && isset($locusSite->longitude)) {
        $site->field_geolocation = array(
          'lat' => (string)$locusSite->latitude,
          'lon' => (string)$locusSite->longitude);
      }
      if (isset($locusSite->installInfo)) {
        if (isset($locusSite->installInfo->installDate)) {
          $site->field_locus_install_date = strtotime((string)$locusSite->installInfo->installDate);
        }
      }

      $site->save();
    }

    // Find list of sites to unpublish
    if (count($active_site_ids)) {
      // Get any published Locus Energy sites that were not in the response
      $site_query = db_select('eck_generation_site', 's')
        ->condition('s.type', 'locus_energy')
        ->condition('s.status', 1)
        ->fields('s', array('id', 'title'));
      $site_query->innerJoin('field_data_field_locus_energy_site_id', 'i', 's.id = i.entity_id');
      $site_query
        ->fields('i', array('field_locus_energy_site_id_value'))
        ->condition('i', $active_site_ids, 'NOT IN');
      $sites = $site_query->execute();
      foreach ($sites as $site) {
        db_update('eck_generation_site')
          ->fields(array('status' => 0))
          ->condition('id', $site->id)
          ->execute();
        watchdog('locus_energy', 'Site unpublished because it is no longer available from the Locus Energy API (@id) @title Site id @siteid', array(
          '@id' => $site->id,
          '@title' => $site->title,
          '@siteid' => $site->field_locus_energy_site_id_value,
        ), WATCHDOG_NOTICE);
      }
    }
  }


  /**
   * Updates a given site or inserts it if unknown.
   *
   * The site is represented by the object $location, as defined by the
   * given provider's API (or internally).
   */
  public function updateSite(stdClass $location)
  {
    return;
  }


  /**
   * Returns installation date of the given site.
   *
   * @param object $site
   *   Site entity.
   *
   * @return DateTime
   *   Date when the site was installed.
   */
  public function getInstallDate(Entity $site)
  {

    $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'locus_energy'));
    $installDate = $site->field_locus_install_date->value();

    if ($installDate) {
      if ($installDate instanceof DateTime) {
        return $installDate;
      } else {
        $date = new DateTime();
        $date->setTimestamp($installDate);
        return $date;
      }
    }
    else {
      return new GenerationLifetimeStartDateTime();
    }
  }


  /**
   * Retrieves all variable functions; optionally filters to a variable.
   *
   * @return array
   *   Array of function ids (keys) and function display names (values).
   */
  public function getVariableFunctions($variable = NULL)
  {
    return array(
      'Avg'  => t('Avg'),
      'Max' => t('Max'),
      'Sum' => t('Sum'),
    );
  }


  /**
   * Retrieves all variable units applicable to this provider.
   *
   * @return array
   *   Array of units arrays, keyed by unit machine name. Example unit array:
   *     'kilowatt-hours' => array('label' => 'kWh),
   *     ...
   *   );
   */
  public function getVariableUnits()
  {

    return array(
      "ac_power_measured" => array('label' => 'kW'),
      "ac_energy_measured" => array('label' => 'kWh'),
      "irradiance" => array('label' => 'W/m²'),
      "temperature_ambient" => array('label' => '°F'),
      "temperature_panel" => array('label' => '°F'),
    );
  }


  /**
   * Returns all variables applicable to this provider.
   *
   * @return array
   *   Array of variable objects, keyed by variable id.
   */
  public function getVariables()
  {

    return array(
      "ac_power_measured" => 'AC Power',
      "ac_energy_measured" => 'AC Energy',
      "irradiance" => 'Irradiance',
      "temperature_ambient" => 'Ambient Temp',
      "temperature_panel" => 'Module Temp'
    );
  }


  /**
   * Returns all variables applicable to a specific site.
   *
   * Results may vary from getVariables() method's.
   */
  public function getSiteVariables(Entity $site)
  {

    return array(
      "ac_power_measured" => array(
        'variable' => 'ac_power_measured',
        'unit' => 'W'
      ),
      "ac_energy_measured" => array(
        'variable' => 'ac_energy_measured',
        'unit' => 'Wh'
      )
    );
  }


  /**
   * Returns all devices specific to a given site entity.
   */
  public function getSiteDevices(Entity $site)
  {
    // TODO: Implement getSiteDevices() method.
  }
}

