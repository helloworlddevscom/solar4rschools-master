<?php

class LocusEnergyService
{


  protected static $_instance;


  protected $data_fields = array(
    'W_avg',
    'Wh_sum',
    'W_max',
  );


  public static function get() {
    if (isset(self::$_instance)) {
      return self::$_instance;
    }

    self::$_instance = new LocusEnergyService();
    return self::$_instance;
  }


  /**
   * Returns array of fields used by Locus API for site data and used
   * by locus_api_data table.
   *
   * @return array Fields used by Locus API.
   */
  public function getDataFields()
  {
    return $this->data_fields;
  }


  public function getAllSites()
  {
    if ($partnerId = variable_get('locus_energy_partner_id')) {
      $response =  LocusEnergyApi::getSitesForPartner( $partnerId);
      if ($response->statusCode == "200") {
        $sites = array();
        foreach ($response->sites as $site) {
          $sites[] = $site;
        }
        return $sites;
      }

    }

    return array();
  }


  public function getSiteDetails(stdClass $site)
  {
    $installInfo = LocusEnergyApi::getSiteInstallInfo( $site->id );
    if ($installInfo->statusCode == "200") {
      $site->installInfo = $installInfo;
    }

//    $modelSettings = LocusEnergyApi::getSiteModelSettings( $site->id );
//    if ($modelSettings->statusCode == "200") {
//      $site->modelSettings = $modelSettings;
//    }
    return $site;
  }


  /**
   * Get new data for all sites from Locus API and save in locus_api_data table.
   * Called by locus_energy_cron_hourly() cron job.
   */
  public function getNewDataForAllSites($granularity)
  {

    // Get all site ids.
    $site_ids = $this->getAllActiveSiteIds();

    foreach ($site_ids as $site_id) {
      $this->getDataForSite($site_id, $granularity);
    }
  }


  /**
   * Get data for one site from Locus API and save in locus_api_data table.
   */
  public function getDataForSite($site_id, $granularity, DateTime $start_datetime = null, Datetime $end_datetime = null)
  {

    // Fields to get from API.
    $fields = $this->getDataFields();

    $granularity_key = $this->getGranularityKey($granularity);

    // Get site timezone.
    $site_time_zone = $this->getSiteTimeZone($site_id);
    if (!$site_time_zone) {
      $site_time_zone = 'US/Pacific';
    }

    // If no start and end dates are given, we figure them out automatically
    // based on the current date and the most recent date in database (if there is one).
    if (is_null($start_datetime) && is_null($end_datetime)) {
      $end_datetime = new DateTime();
      $end_datetime->setTimezone(new DateTimeZone($site_time_zone));

      // Query database for previous data to get start timestamp.
      $most_recent_data_query = db_select('locus_api_data', 'l');
      $most_recent_data_stmt = $most_recent_data_query
        ->fields('l', array('data_timestamp'))
        ->condition('site_id', $site_id, '=')
        ->condition('granularity', $granularity_key, '=')
        ->orderBy('data_timestamp', 'DESC')
        ->execute();
      $most_recent_timestamp = $most_recent_data_stmt->fetchColumn();

      // Check that there is already data for this site and granularity.
      // If there is not we need to pull data starting from install date.
      if (!empty($most_recent_timestamp)) {
        $start_timestamp = $most_recent_timestamp;
        $end_timestamp = $end_datetime->getTimestamp();

        // Check that the diff between $most_recent_timestamp and $end_timestamp
        // is at least as large as the granularity. For example, if the diff for a year
        // is less than a year, the API will return nothing.
        switch ($granularity) {
          case 'hourly':
            if ($end_timestamp - $most_recent_timestamp <= 3600) {
              $start_timestamp = strtotime('-1 hour', $end_timestamp);
            }
            break;

          case 'daily':
            if ($end_timestamp - $most_recent_timestamp <= 86400) {
              $start_timestamp = strtotime('-1 day', $end_timestamp);
            }
            break;

          case 'monthly':
            if ($end_timestamp - $most_recent_timestamp <= 2629743) {
              $start_timestamp = strtotime('-1 month', $end_timestamp);
            }
            break;

          case 'yearly':
            if ($end_timestamp - $most_recent_timestamp <= 31556926) {
              $start_timestamp = strtotime('-1 year', $end_timestamp);
            }
            break;
        }

        $start_datetime = new DateTime();
        $start_datetime->setTimezone(new DateTimeZone($site_time_zone));
        $start_datetime->setTimestamp($start_timestamp);

        // Call API for site data.
        $response = LocusEnergyApi::getDataForSite($site_id, $fields, $this->formatDate($start_datetime), $this->formatDate($end_datetime), $granularity, $site_time_zone);
      }
      else {
        // If this is the first ever call for this site and granularity, we need to limit time periods within API specs.
        $response = $this->getFirstDataForSite($site_id, $fields, $end_datetime, $granularity, $site_time_zone);
      }
    }
    else {
      // If there is a start and end date given, call API using those dates.
      $start_datetime->setTimezone(new DateTimeZone($site_time_zone));
      $end_datetime->setTimezone(new DateTimeZone($site_time_zone));
      $response = LocusEnergyApi::getDataForSite($site_id, $fields, $this->formatDate($start_datetime), $this->formatDate($end_datetime), $granularity, $site_time_zone);
    }

    if (!empty($response)) {
      if ($response->statusCode == '200' && isset($response->data)) {
        foreach ($response->data as $data) {

          // If field data is not empty.
          if (!empty($data->Wh_sum) || !empty($data->W_avg)) {

            $data_datetime = new DateTime($data->ts);
            $data_timestamp = $data_datetime->getTimestamp();

            // Use db_merge() instead of db_insert().
            // This is because I'm assuming that the data with the most recent date in our database
            // might be "incomplete". If we pulled hourly data from the API,
            // the next time we pull we should pull the most recent hourly data in our database
            // from the API again and update the data because that hour
            // might not have been finished when we last pulled and so the API would have returned
            // data for only part of the hour. This is just an assumption, but doing this
            // does not increase the number of calls and ensures data is complete and final.
            $insert_query = db_merge('locus_api_data')
              ->key(array('site_id' => $data->id, 'granularity' => $granularity_key, 'data_timestamp' => $data_timestamp))
              ->fields(array(
                'site_id' => $data->id,
                'Wh_sum' => $data->Wh_sum,
                'W_avg' => $data->W_avg,
                'W_max' => $data->W_max,
                'granularity' => $granularity_key,
                'data_timestamp' => $data_timestamp,
              ));
            $insert_query->execute();
          }
        }
      }
    }
  }


  /**
   * Calls Locus API to get site data from site install date to now.
   * Only called when there is no previous data for site and granularity in locus_api_data table.
   * Limits time periods in API call to specs:
   * Limit hourly to < 31 days
   * Limit daily to < 1 year
   * https://developer.locusenergy.com/#overview41
   *
   * @param $site_id
   * @param $fields
   * @param $curr_datetime
   * @param $granularity
   * @param $site_time_zone
   * @return Response data from Locus API, or aggregated response data from multiple requests formatted as one request.
   */
  private function getFirstDataForSite($site_id, $fields, $curr_datetime, $granularity, $site_time_zone)
  {
    // Get install date of site to determine start date of API call.
    $install_date = $this->getSiteInstallDate($site_id);

    // Not all sites have values for install date field.
    // If no value, set to 1/1/2010 just because what else can we do?
    if (!$install_date) {
      $start_datetime = new Datetime();
      $start_datetime->setTimezone(new DateTimeZone($site_time_zone));
      $start_datetime->setTimestamp(1262307600);
      $start_timestamp = $start_datetime->getTimestamp();
    }
    else {
      $start_datetime = new DateTime($install_date);
      $start_timestamp = $start_datetime->getTimestamp();
    }

    $curr_timestamp = $curr_datetime->getTimestamp();

    if ($granularity == 'hourly' || $granularity == 'daily') {
      // Assuming that we don't actually need the hourly and daily data
      // from the install date of the project. We probably only need
      // it 31 days prior to now for daily granularity because that seems to be as
      // far back as data is ever graphed, and 7 days prior for hourly.
      // This will reduce rows in database significantly.
      // @TODO We could create a cron to remove old hourly and daily data.
      // @TODO If this assumption is incorrect you should be able to delete this
      // if/else statement and data should be called from site install date.
      if ($granularity == 'hourly') {
        $week_prior_timestamp = strtotime('-7 days', $curr_timestamp);
        $start_datetime->setTimestamp($week_prior_timestamp);
        $start_timestamp = $week_prior_timestamp;
      }
      else {
        $month_prior_timestamp = strtotime('-31 days', $curr_timestamp);
        $start_datetime->setTimestamp($month_prior_timestamp);
        $start_timestamp = $month_prior_timestamp;
      }

      $most_recent_timestamp = 0;
      $responses_data = new stdClass();
      $responses_data->data = array();
      $bad_status_codes = array();
      while ($most_recent_timestamp < $curr_timestamp) {
        if (!$most_recent_timestamp == 0) {
          $start_datetime = new Datetime();
          $start_datetime->setTimezone(new DateTimeZone($site_time_zone));
          $start_datetime->setTimestamp($most_recent_timestamp);
          $start_timestamp = $most_recent_timestamp;
        }

        $end_datetime = new DateTime();
        $end_datetime->setTimezone(new DateTimeZone($site_time_zone));
        switch ($granularity) {
          case 'hourly':
            $add_time = '+30 days';
            break;
          case 'daily':
            $add_time = '+1 year';
        }
        $end_datetime->setTimestamp(strtotime($add_time, $start_timestamp));

        $response = LocusEnergyApi::getDataForSite($site_id, $fields, $this->formatDate($start_datetime), $this->formatDate($end_datetime), $granularity, $site_time_zone);
        if (!empty($response)) {
          if ($response->statusCode == '200' && isset($response->data)) {
            foreach ($response->data as $data) {
              $responses_data->data[] = $data;
            }
          }
          if ($response->statusCode != '200') {
            $bad_status_codes[] = $response->statusCode;
          }
        }

        $most_recent_timestamp = $end_datetime->getTimestamp();
      }

      // If there is data we'll say statusCode was 200 for all requests.
      if (!empty($responses_data->data)) {
        $responses_data->statusCode = '200';
      }
      elseif (!empty($bad_status_codes)) {
        // If there is no data and a non 200 status code for one of the requests,
        // just return the first bad status code.
        $responses_data->statusCode = $bad_status_codes[0];
      }
      else {
        // If there is somehow no data and no non 200 status code we'll just fake 403 I guess.
        $responses_data->statusCode = '403';
      }

      // Return aggregated data from all requests formatted as though it were one request.
      return $responses_data;
    }
    else {
      // Monthly and yearly do not have a limit so start date can be install date and end date can be now.
      return LocusEnergyApi::getDataForSite($site_id, $fields, $this->formatDate($start_datetime), $this->formatDate($curr_datetime), $granularity, $site_time_zone);
    }
  }


  public function getAllActiveSiteIds()
  {
    $site_query = db_select('eck_generation_site', 's')
      ->condition('s.type', 'locus_energy', '=')
      ->condition('s.status', 1, '=');

    $site_query->join('field_data_field_locus_energy_site_id', 'i', 's.id = i.entity_id');

    $site_query
      ->fields('i', array('field_locus_energy_site_id_value'));

    $result = $site_query->execute();
    return $result->fetchAll(PDO::FETCH_COLUMN);
  }


  public function getSiteEntityId($site_id)
  {
    $site_entity_id_query =  db_select('field_data_field_locus_energy_site_id', 's');
    $site_entity_id_stmt = $site_entity_id_query
      ->fields('s', array('entity_id'))
      ->condition('field_locus_energy_site_id_value', $site_id, '=')
      ->execute();
    return $site_entity_id_stmt->fetchColumn();
  }


  public function getSiteInstallDate($site_id)
  {
    $site_entity_id = $this->getSiteEntityId($site_id);

    $install_date_query = db_select('field_data_field_locus_install_date', 'i');
    $install_date_stmt = $install_date_query
      ->fields('i', array('field_locus_install_date_value'))
      ->condition('entity_id', $site_entity_id, '=')
      ->execute();
    return $install_date_stmt->fetchColumn();
  }


  public function getSiteTimeZone($site_id)
  {
    $site_entity_id = $this->getSiteEntityId($site_id);

    $time_zone_query = db_select('field_data_field_timezone', 't');
    $time_zone_stmt = $time_zone_query
      ->fields('t', array('field_timezone_value'))
      ->condition('entity_id', $site_entity_id, '=')
      ->execute();
    return $time_zone_stmt->fetchColumn();
  }
  

  public function preprocessInterval(DateTime $start, DateTime $end)
  {
    $start_timestamp = $start->getTimestamp();
    $end_timestamp = $end->getTimestamp();

    $diff = $end_timestamp - $start_timestamp;

    // If getting more then 2 days of data
    if ($diff > 86400 * 2) {
      $this->setToTime($start);
      $this->setToTime($end, '23:59:59');
    }
  }


  public function setToTime(DateTime $datetime, $time = '00:00:00')
  {
    $parts = explode(':', $time);
    switch (count($parts)) {
      case 1:
        $datetime->setTime(intval($parts[0]), 0);
        break;
      case 2:
        $datetime->setTime(intval($parts[0]), intval($parts[1]));
        break;
      case 3:
        $datetime->setTime(intval($parts[0]), intval($parts[1]), intval($parts[2]));
    }
  }


  public function formatDate(DateTime $dateTime)
  {
    if ($dateTime instanceof GenerationLifetimeStartDateTime) {
      $dateTime = new DateTime('@0');
    }
    return $dateTime->format('Y-m-d\TH:i:s');
  }


  public function roundDateTimeHour(DateTime $datetime, $time = '12:00:00')
  {
    $parts = explode(':', $time);
    switch (count($parts)) {
      case 1:
        $datetime->setTime(intval($parts[0]), 0);
        break;
      case 2:
        $datetime->setTime(intval($parts[0]), intval($parts[1]));
        break;
      case 3:
        $datetime->setTime(intval($parts[0]), intval($parts[1]), intval($parts[2]));
    }

    return $datetime;
  }


  /**
   * Returns corresponding integer value used by granularity column in locus_api_data table
   * when given granularity in string format.
   *
   * @param string $granularity Granularity in string format.
   * @return int Corresponding integer used by granularity column in locus_api_data table.
   */
  public function getGranularityKey($granularity)
  {
    switch ($granularity) {
      case 'hourly':
        return 0;
        break;

      case 'daily':
        return 1;
        break;

      case 'monthly':
        return 2;
        break;

      case 'yearly':
        return 3;
        break;
    }
  }


  /**
   * Checks whether cron for Locus Energy is enabled or disabled.
   * Cron will only be enabled if in production environment, or if
   * this is included in local_settings.php:
   * $conf['locus_energy_cron_force_run'] = TRUE;
   *
   * @return bool True if cron is enabled, false if disabled.
   */
  public function cronEnabled()
  {
    $force_run = variable_get('locus_energy_cron_force_run', FALSE);
    $is_prod = defined('PANTHEON_ENVIRONMENT') && PANTHEON_ENVIRONMENT === 'live';
    // Skip unless we are forcing a run or this is production.
    if (!($force_run || $is_prod)) {
      return false;
    }
    else {
      return true;
    }
  }
}
