<?php
/**
 * @file
 * solar_data.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function solar_data_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subpathauto_depth';
  $strongarm->value = '3';
  $export['subpathauto_depth'] = $strongarm;

  return $export;
}
