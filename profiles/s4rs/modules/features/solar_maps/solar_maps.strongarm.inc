<?php
/**
 * @file
 * solar_maps.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function solar_maps_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_bing';
  $strongarm->value = '';
  $export['geocoder_apikey_bing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_google';
  $strongarm->value = 'AIzaSyAX4c0AtVTZ8eMmrIwXt_l790aH0MTZV0c';
  $export['geocoder_apikey_google'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_mapbox';
  $strongarm->value = '';
  $export['geocoder_apikey_mapbox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_mapquest';
  $strongarm->value = '';
  $export['geocoder_apikey_mapquest'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_mapzen';
  $strongarm->value = '';
  $export['geocoder_apikey_mapzen'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_yahoo';
  $strongarm->value = '';
  $export['geocoder_apikey_yahoo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_apikey_yandex';
  $strongarm->value = '';
  $export['geocoder_apikey_yandex'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_cache_empty_results';
  $strongarm->value = 1;
  $export['geocoder_cache_empty_results'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_google_auth_method';
  $strongarm->value = '2';
  $export['geocoder_google_auth_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_google_client_id';
  $strongarm->value = '';
  $export['geocoder_google_client_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_google_delay';
  $strongarm->value = '200';
  $export['geocoder_google_delay'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_google_private_key';
  $strongarm->value = '';
  $export['geocoder_google_private_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_log_empty_results';
  $strongarm->value = 1;
  $export['geocoder_log_empty_results'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_recode';
  $strongarm->value = 0;
  $export['geocoder_recode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'geocoder_settings';
  $strongarm->value = array(
    'geocoder_apikey_yahoo' => '',
    'geocoder_apikey_yandex' => '',
    'geocoder_apikey_bing' => '',
    'geocoder_apikey_mapzen' => '',
    'geocoder_apikey_mapbox' => '',
    'geocoder_apikey_google' => 'AIzaSyAX4c0AtVTZ8eMmrIwXt_l790aH0MTZV0c',
    'geocoder_apikey_mapquest' => '',
  );
  $export['geocoder_settings'] = $strongarm;

  return $export;
}
