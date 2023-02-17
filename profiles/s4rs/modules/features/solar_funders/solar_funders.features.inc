<?php
/**
 * @file
 * solar_funders.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_funders_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
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
function solar_funders_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function solar_funders_node_info() {
  $items = array(
    'funder' => array(
      'name' => t('Funder'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Funder name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function solar_funders_default_profile2_type() {
  $items = array();
  $items['funder'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "funder",
    "label" : "Funder",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
