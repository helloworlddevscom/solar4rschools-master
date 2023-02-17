<?php
/**
 * @file
 * Includes for solar Weather module.
 */

/**
 * solar Weather API endpoint (uses NOAA now).
 */
define('SOLAR_WEATHER_API_ENDPOINT', 'http://forecast.weather.gov/MapClick.php?&unit=0&lg=english&FcstType=dwml');

/**
 * Units to use in query. Options are "e" (English) or "m" (Metric).
 */
define('SOLAR_WEATHER_API_UNIT_FLAG', 'Unit=e');

/**
 * Get weather based on lat/long.
 *
 * @param $latitude
 * @param $longitude
 */
function solar_weather_get_weather($latitude, $longitude) {
  static $weather;
  if (empty($weather)) {
    $weather = _solar_weather_request($latitude, $longitude);
  }
  return $weather;
}

/**
 * Make and parse request to NOAA.
 *
 * @param $latitude
 *   Latitude.
 * @param $longitude
 *   Longitude.
 *
 * @return array
 *   A keyed array containing:
 *     - icon
 *     - condition
 *     - temperature
 *     - wind_direction
 *     - wind_speed
 */
function _solar_weather_request($latitude, $longitude) {
  if ((integer) $latitude == 0 || (integer) $longitude == 0) {
    return FALSE;
  }
  $latlong = 'lat=' . $latitude . '&lon=' . $longitude;
  $source = SOLAR_WEATHER_API_ENDPOINT . '&' . $latlong . '&' . SOLAR_WEATHER_API_UNIT_FLAG;
  $data = drupal_http_request($source);
  if ($data->code == 200) {
    try {
      $xml = new SimpleXMLElement($data->data);
      $weather = array(
        'source' => $source,
      );
      foreach ($xml->data as $element) {
        // Only interested in the 'current observations' element.
        if ((string) $element->attributes()->type === 'current observations') {
          $parameters = $element->parameters;

          // Temperature.
          $weather['temperature'] = (string) $parameters->temperature->value;

          // Icon.
          $weather['icon'] = (string) $parameters->{'conditions-icon'}->{'icon-link'};

          // Current condition.
          $weather['condition'] = (string) $parameters->weather->{'weather-conditions'}->attributes()->{'weather-summary'};

          // Wind direction.
          foreach ($parameters->direction as $direction) {
            if ($direction->attributes()->type == 'wind') {
              $weather['wind_direction'] = (string) $direction->value;
            }
          }

          // Wind speed.
          foreach ($parameters->{'wind-speed'} as $speed) {
            if ($speed->attributes()->type == 'sustained') {
              $weather['wind_speed'] = (string) $speed->value;
              $weather['wind_units'] = (string) $speed->attributes()->units;
            }
          }

          // Time.
          $weather['time'] = (string) $element->{'time-layout'}->{'start-valid-time'};
        }
      }
    }
    catch (Exception $e) {
      // @todo error logging.
      return FALSE;
    }
  }
  return $weather;
}

/**
 * Convert absolute compass direction to generalized direction.
 *
 * @param numeric $direction
 *   Compass direction in Degrees N.
 * @param string
 */
function solar_weather_compass_to_fuzzy($direction) {
  if (($direction > 337.5) || ($direction <= 22.5)) {
    $fuzzy = 'N';
  }
  elseif (($direction > 22.5) && ($direction <= 67.5)) {
    $fuzzy = 'NE';
  }
  elseif (($direction > 67.5) && ($direction <= 112.5)) {
    $fuzzy = 'E';
  }
  elseif (($direction > 112.5) && ($direction <= 157.5)) {
    $fuzzy = 'SE';
  }
  elseif (($direction > 157.5) && ($direction <= 202.5)) {
    $fuzzy = 'S';
  }
  elseif (($direction > 202.5) && ($direction <= 247.5)) {
    $fuzzy = 'SW';
  }
  elseif (($direction > 247.5) && ($direction <= 292.5)) {
    $fuzzy = 'W';
  }
  elseif (($direction > 292.5) && ($direction <= 337.5)) {
    $fuzzy = 'NW';
  }
  else {
    // Error handling.
  }

  return $fuzzy;
}

/**
 * Convert Fahrenheit To Centigrade.
 *
 * @param float $fahrenheit
 *   Temperature in Fahrenheit.
 * @return float
 *   Temperature in Centigrade.
 */
function solar_weather_temp_to_centigrade($fahrenheit) {
  return 5 / 9 * ($fahrenheit - 32);
}

/**
 * Convert Centigrade to Fahrenheit.
 *
 * @param float $centigrade
 *   Temperature in Centigrade.
 * @return float
 *   Temperature in Fahrenheit.
 */
function solar_weather_temp_to_fahrenheit($centigrade) {
  return (9 / 5 * $centigrade) + 32;
}

/**
 * Convert Knots to Miles/Hour.
 */
function solar_weather_speed_to_mph($knots) {
  return $knots * 1.151;
}

/**
 * Convert Miles/Hour to Knots.
 */
function solar_weather_speed_to_knots($mph) {
  return $mph / 1.151;
}

/**
 * Given a postal code, attempt to retrieve coordinates that can be passed to NOAA.
 */
function solar_weather_get_coords($postal_code) {
  static $coordinates;
  if (empty($coordinates)) {
    $cache = cache_get('solar_weather_coordinates');
    $coordinates = !empty($cache->data) ? $cache->data : array();
  }

  if (!isset($coordinates[$postal_code])) {
    $coordinates[$postal_code] = _solar_weather_get_coords($postal_code);
    cache_set('solar_weather_coordinates', $coordinates, 'cache', CACHE_PERMANENT);
  }

  return $coordinates[$postal_code];
}

/**
 * Make a direct call to determine coordinates for a given postal code.
 *
 * @return array
 *   An array containing latitude and longitude.
 */
function _solar_weather_get_coords($postal_code) {
  $data = drupal_http_request('http://graphical.weather.gov/xml/sample_products/browser_interface/ndfdXMLclient.php?listZipCodeList=' . $postal_code);
  if ($data->code == 200) {
    try {
      $xml = new SimpleXMLElement($data->data);
      $coords = (string) $xml->latLonList;
      return explode(',', $coords);
    }
    catch (Exception $e) {
      // @todo error handling.
      return FALSE;
    }
  }
  return FALSE;
}

/**
 * Given a kiosk id, return the weather at its related data collection location.
 *
 * @param stdClass $project
 * @return string
 */
function solar_weather_collect_data($generation_site) {
  module_load_include('inc', 'solar_weather');
  $site = entity_metadata_wrapper('generation_site', $generation_site);
  $site_location = $site->field_geolocation->value();
  $latitude = $site_location['lat'];
  $longitude = $site_location['lon'];
  if (((integer) $latitude == 0 || (integer) $longitude == 0)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'project')
      ->fieldCondition('field_data_collection_site', 'target_id', $site->getIdentifier())
      ->fieldCondition('field_geolocation', 'lat', 'NULL', '!=')
      ->fieldCondition('field_geolocation', 'lon', 'NULL', '!=');

    $result = $query->execute();
    $project = isset($result['node']) ? node_load(current($result['node'])->nid) : FALSE;
    if ($project) {
      $location = field_get_items('node', $project, 'field_geolocation');
      $site->field_geolocation->set($location[0]);
      $site->save();
    }
  }

  // If this is a bad location, attempt zipcode.
  if (((integer) $latitude == 0 || (integer) $longitude == 0) && isset($project->field_project_location[LANGUAGE_NONE][0]['postal_code'])) {
    list($latitude, $longitude) = solar_weather_get_coords($project->field_project_location[LANGUAGE_NONE][0]['postal_code']);
  }

  $data = solar_weather_get_weather($latitude, $longitude);
  if (!$data) {
    return;
  }

  return theme('solar_weather_block', array('data' => $data));
}
