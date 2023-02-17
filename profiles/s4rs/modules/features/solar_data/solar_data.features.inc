<?php
/**
 * @file
 * solar_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function solar_data_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function solar_data_eck_bundle_info() {
  $items = array(
    'equivalencies_statistics_equivalencies_statistics' => array(
      'machine_name' => 'equivalencies_statistics_equivalencies_statistics',
      'entity_type' => 'equivalencies_statistics',
      'name' => 'equivalencies_statistics',
      'label' => 'Equivalencies/Statistics',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function solar_data_eck_entity_type_info() {
  $items = array(
    'equivalencies_statistics' => array(
      'name' => 'equivalencies_statistics',
      'label' => 'Equivalencies/Statistics',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}
