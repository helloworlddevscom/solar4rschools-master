<?php

class TigoEnergyGenerationProvider implements GenerationProvider {

  /**
   * @inheritDoc
   */
  public function queryBin(Entity $site, array $presets, DateTime $start, DateTime $end, $bin = 'hour') {
    $all_units = $this->getVariableUnits();
    $return_data = array();

    foreach ($presets as $preset) {
      $return_data[] = array(
          'name' => $preset->alias,
          'type' => $preset->chart_type,
          'description' => $preset->description,
          'data' => $this->aggregateEnergy($site, $presets, $start, $end, $bin, $preset->alias),
          'units' => $all_units[$preset->units]['label'],
      );
    }

    return $return_data;
  }

  /**
   * @inheritDoc
   */
  protected function aggregateEnergy(Entity $site, array $presets, DateTime $start, DateTime $end, $bin = 'hour', $aggregate = NULL) {
    $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'tigo_energy'));
    $sysid = $site->field_tigo_sysid->value();
    $tz = $site->field_timezone->value();

    // Quick hack to double-check *same*-day values. The form seems to submit 2 days, which causes failure in the
    // _generation_get_bin_from_range() method when calculating $bin.
    $now = new DateTime();
    // 86400 seconds in a day. 129600 = 1.5 days (being the "fudge factor")
    if($end > $now && ($now->format('U') - $start->format('U') < 129600)) {
      $bin = 'min15';
    }

    // Map Generation module's bins to Tigo bins.
    $bin_map = array(
      'min15' => array('min', 15),
      // As of 2018-05-15, sending 'min', 60 will cause API call to fail with 'Request timed out'.
      // This affects the 'Week' tab. Assuming too much data is being requested. This workaround will
      // display only one data point per day for seven days instead.
      'hour' => array('day', 1),
      'day' => array('day', 1),
      'week' => array('day', 7),
      // Tigo data for 30-day intervals appears faulty. May need to request 1-day intervals and combine them.
      'month' => array('day', 1),
    );
    $level = $bin_map[$bin][0];
    $interval = $bin_map[$bin][1];

    $data = $this->getData($sysid, $start, array('end' => $end, 'level' => $level, 'interval' => $interval));

    // remove header rows - these can appear more than once in the data (they seem to occur at the top, plus again every 90 rows or so).
    $data = array_filter($data, function($row) {
      if ($row[0] == 'DATETIME') {
        return false;
      } else {
        return true;
      }
    });
    $data = array_values($data);  // re-index the array. some code later needs the first element index to be zero.

    $energy_aggregates = array_map(function ($row) use ($tz, $level, $interval, $aggregate, $bin) {
      $timestamp = strtotime(array_shift($row) . ' ' . $tz);

      // Sum up the data points into a single value. Data is in watts, so divide by 1000 to convert to kW
      $energy = array_sum($row) / 1000;

      // Depending on the statistic we're showing, we need to do some math to calculate the correct values.
      if($aggregate === 'Photovoltaic Energy [Interval]') {
        if ($level == 'min') {
          // For "minute" intervals, convert average watts to watt-hours based on the interval length.
          $energy = $energy * $interval / 60;
        }
      } else if($aggregate === 'Photovoltaic Power [Avg]') {
        // Photovoltaic Energy [Interval] (kilowatt-hours)
        if ($level == 'day' && $bin != 'month') {  // for graphs using the "month" bin, calculations are handled below.
          $energy = $energy / 24;
        }
      }
      return array($timestamp, $energy);
    }, $data);

    // When showing a graph with 1-month intervals, we query in 1-day intervals, then add up all the days in each month.
    // FYI: '$bin == month' is used by the "year" and "lifetime" tabs.
    if ($bin == 'month') {
      $energy_aggregates = array_reduce($energy_aggregates, function ($months, $day) use ($tz) {
        // Round the date to the first of the month.
        // FIXME: the dates here will be displayed in the wrong time zone on the tooltips on the charts.
        // But fixing the time zone makes the graph display the bars incorrectly. Argh.
        $date = new DateTime("@$day[0]");
        $date = new DateTime($date->format("Y-m-1 00:00") . " $tz");
        $date = $date->format("Y-m-d 00:00");

        if (!isset($months[$date])) {
          $months[$date] = 0;
        }
        // build the aggregate of each monthly total.
        $months[$date] += $day[1];
        return $months;
      }, array());
      // Map the associative array of date/energy back to the 2D array needed for plotting.
      $energy_aggregates = array_map(function ($date, $energy) use ($aggregate) {
        $date = new DateTime($date);
        $date = $date->getTimeStamp();

        // Previously we added up the total generation for the month in kWh.
        // To get the average power in kW we need to divide by the number of days in the month * 24 hours.
        if ($aggregate === 'Photovoltaic Power [Avg]') {
          $days_in_month = date('t', $date);
          $energy = $energy / 24 / $days_in_month;
        }
        return array($date, $energy);
      }, array_keys($energy_aggregates), $energy_aggregates);
    }

    // The API excluded rows if the levels are zero. Quick hack to fill in these rows.
    if($level === 'day') {
      return $energy_aggregates;
    }

    $range_start = $energy_aggregates[0][0];
    $range_end = $energy_aggregates[count($energy_aggregates) - 1][0];
    $range_step = ($interval * 60);
    $ret = array();

    foreach(range($range_start, $range_end, $range_step) as $ts_step) {
      if($energy_aggregates[0][0] === $ts_step) {
        $ret[] = array_shift($energy_aggregates);
      } else {
        $ret[] = array($ts_step, 0);
      }
    }
    // end excluded rows hack

    return $ret;
  }

  /**
   * @inheritDoc
   */
  public function queryBinDevice($device_id, array $variables, DateTime $date_start, DateTime $date_end, $options = array()) {
    throw new Exception('unimplemented');
  }

  /**
   * @inheritDoc
   */
  public function getBinData(stdClass $response) {
    throw new Exception('unimplemented');
  }

  /**
   * @inheritDoc
   */
  public function getDeviceName(EntityMetadataWrapper $device) {
    throw new Exception('unimplemented');
  }

  /**
   * @inheritDoc
   */
  public function queryInstantSummary($site = NULL) {
    $systems = $this->getSystemList();
    $summaries = array();

    if (!is_null($site)) {
      $sites = array($site);
      $query_all_sites =  FALSE;
    }
    else {
      $query_all_sites = TRUE;
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'generation_site')
        ->entityCondition('bundle', 'tigo_energy');
      $result = $query->execute();
      $sites = entity_load('generation_site', array_keys($result));
    }

    foreach ($sites as $site) {
      $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'tigo_energy'));
      $sysid = $site->field_tigo_sysid->value();
      $system = $systems->xpath('//System[@SysID="' . $sysid . '"]');
      $system_arr = $this->xml2array($system[0]);

      $lifetimeEnergy = $lastData = 0;
      foreach($system_arr['DataSource'] as $dataSource) {
        $lifetimeEnergy += (float)$dataSource['LifetimeEnergy'];
        $lastData += (float)$dataSource['LastData'];
      }

      $summaries[$site->id->value()] = array(
        'generation' => (float)$lifetimeEnergy / 1000, // Data is in watt-hours, divide by 1000 to convert to kWh
        'power' => (float)$lastData,
      );
    }

    if ($query_all_sites) {
      // Tigo doesn't support querying for all sites.
      // Doing this in a loop would be too slow, so we return nothing.
      return FALSE;
    }
    return empty($summaries) ? FALSE : $summaries[$site->id->value()];
  }

  /**
   * @inheritDoc
   */
  public function queryWindowSummary(Entity $site, DateTime $start, DateTime $end) {

    $total_energy = 0;
    $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'tigo_energy'));
    $sysid = $site->field_tigo_sysid->value();

    // prepare the params for the API call
    $params = [
      'end' => $end,
      'agg' => 'avg'
    ];

    //if we are querying for a day total have to total the minute readings
    if (($end->getTimeStamp() - $start->getTimeStamp()) < 86400 * 2) {
      // day graph uses 15-minute intervals
      $params['level'] = 'min';
      $params['interval'] = 15;
    } else {
      // NOTE: when level is 'day' the API won't return any data for the current day.
      $params['level'] = 'day';
      $params['interval'] = 1;
    }

    $data = $this->getData($sysid, $start, $params);

    // now total up all the data points to get the summary for the given time period.
    array_shift($data); // remove header row
    foreach ($data as $row) {
      array_shift($row); // remove timestamp in first column
      $subtotal = 0;
      foreach ($row as $data_point) {
        $subtotal += (float) $data_point; // this multiplier converts the average kW output into kWh
      }
      // when using an interval of minutes, we need to use a multiplier to convert to kWh
      if ($params['level'] == 'min') {
        $subtotal = $subtotal / 60 * $params['interval'];
      }
      $total_energy += $subtotal;
    }
    $total_energy = $total_energy / 1000; // Data is in watt-hours, divide by 1000 to convert to kWh

    return array(
      'generation' => $total_energy
    );
  }

  /**
   * @inheritDoc
   */
  public function updateSites() {
    $systems = $this->getSystemList()->xpath('//System');

    foreach ($systems as $system) {
      $sysid = (int)$system['SysID'];
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'generation_site')
        ->entityCondition('bundle', 'tigo_energy')
        ->fieldCondition('field_tigo_sysid', 'value', $sysid, '=');
      $result = $query->execute();

      if (isset($result['generation_site'])) {
        $site = current(entity_load('generation_site', array_keys($result['generation_site'])));
        $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'tigo_energy'));
      }
      else {
        $site = entity_create('generation_site', array('type' => 'tigo_energy'));
        $site = entity_metadata_wrapper('generation_site', $site, array('bundle' => 'tigo_energy'));
        $site->field_tigo_sysid = $sysid;
        $site->status = 1;
      }
      $site->title = (string)$system['Name'];
      $site->field_timezone = (string)$system->DateTime[0]['TZ'];
      $site->field_tigo_commission_date = strtotime((string)$system->Commission);

      $site->field_geolocation = array(
        'lat' => (string)$system->Location->Latitude,
        'lon' => (string)$system->Location->Longitude);
      $site->save();
    }

  }

  /**
   * @inheritDoc
   */
  public function updateSite(stdClass $location) {
    throw new Exception('unimplemented');
  }

  /**
   * @inheritDoc
   */
  public function getInstallDate(Entity $site) {
    $wrapper = entity_metadata_wrapper('generation_site', $site);
    $date = new DateTime();
    $date->setTimestamp($wrapper->field_tigo_commission_date->value());
    return $date;
  }

  /**
   * @inheritDoc
   */
  public function getVariableFunctions($variable = NULL) {
    return array(
      'Avg'  => t('Avg'),
      'Diff' => t('Diff'),
    );
  }

  /**
   * @inheritDoc
   */
  public function getVariableUnits() {
    return array(
      'kilowatts' => array('label' => 'kW'),
      'kilowatt-hours' => array('label' => 'kWh'),
    );
  }

  /**
   * @inheritDoc
   */
  public function getVariables() {
    return array(
      'generation' => 'Energy',
    );
  }

  /**
   * @inheritDoc
   */
  public function getSiteVariables(Entity $site) {
    // @TODO
    return array(
      'generation' => array(
        'variable' => 'generation',
        'unit' => 'kWh',
      ),
    );
  }

  /**
   * @inheritDoc
   */
  public function getSiteDevices(Entity $site) {
    // @TODO
    return array();
  }

  /**
   * Queries the list of all installed solar systems
   * @return SimpleXMLElement The XML tree with the Tigo systems.
   */
  private function getSystemList() {
    $url = 'https://' . variable_get('tigo_energy_api_username') . ':' .
      variable_get('tigo_energy_api_password') . '@' . TIGO_API_HOST . '/api/data?cmd=list';
    $response = drupal_http_request($url);
    return simplexml_load_string($response->data);
  }

  /**
   * Gets a list of all the "objects" at each site, where an object == 1 solar panel
   * @param $sysid The ID of the system (see getSystemList())
   * @return SimpleXMLElement The XML tree with Tigo objects
   */
  private function getObjectList($sysid) {
    $url = 'https://' . variable_get('tigo_energy_api_username') . ':' .
      variable_get('tigo_energy_api_password') . '@' . TIGO_API_HOST . '/api/data?cmd=objects' .
      "&sysid=$sysid";
    $response = drupal_http_request($url);
    return simplexml_load_string($response->data);
  }

  /**
   * @param $sysid
   * @param DateTime $start
   * @param array $params
   *   Refer to https://support.tigoenergy.com/hc/en-us/article_attachments/200201256/Tigo_Energy_API_v1.pdf
   *   for complete parameter list.
   * @return array
   *
   */
  private function getData($sysid, DateTime $start, $params = array()) {
    $params['sysid'] = $sysid;

    $params['start'] = $this->dateQueryFormat($start);
    if (isset($params['end'])) {
      $params['end'] = $this->dateQueryFormat($params['end']);
    }
    // this query always requests the "average" aggregate data point
    $params['agg'] = 'avg';

    // Only get data from Panel objects
    $objects = $this->getObjectList($sysid);
    $panels = $objects->xpath('//Object[@Type="Panel"]');
    $oids = array();
    foreach ($panels as $panel) {
      $oid = (string) $panel->attributes()->ID;
      if (isset($oid) && $oid) {
        $oids[] = $oid;
      }
    }
    $params['oids'] = implode(',', $oids);
    $options = array();
    // Try to avoid Apache 414 errors
    if (strlen($params['oids']) > 7000) {
      $options['data'] = drupal_http_build_query(array(
        'oids' => $params['oids'],
      ));
      $options['method'] = 'POST';
      unset($params['oids']);
    }

    // call the API
    // NOTE: omitting the 'oids' argument makes it return the data points for all objects at the site.
    $url = 'https://' . variable_get('tigo_energy_api_username') . ':' .
      variable_get('tigo_energy_api_password') . '@' . TIGO_API_HOST . '/api/data?cmd=data&' .
      drupal_http_build_query($params);
    $response = drupal_http_request($url, $options);

    // turn api data into an array
    $data = array_map('str_getcsv', explode("\n", $response->data));
    // remove empty rows from the end of the data
    if (!$data[count($data) - 1][0]) {
      unset($data[count($data) - 1]);
    }
    return $data;
  }

  /**
   * @param DateTime $date
   * @return string Date formatted as a Tigo query parameter.
   */
  private function dateQueryFormat(DateTime $date) {
    return $date->format('Y-m-d_H-i-s');
  }

  /**
   * Method to turn a SimpleXML Object into an associative array.
   *
   * http://www.binarytides.com/convert-simplexml-object-to-array-in-php/
   *
   * @param string $fname The XML string.
   *
   * @return array The associative array.
   */
  protected function xml2array($xml) {
    $arr = array();
    foreach ($xml->children() as $r) {
      $t = array();
      if(count($r->children()) == 0) {
        $arr[$r->getName()] = strval($r);
      } else {
        $arr[$r->getName()][] = $this->xml2array($r);
      }
    }
    return $arr;
  }
}
