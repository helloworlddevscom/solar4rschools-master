<?php
/**
 * @file
 * solar_explore.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_explore_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function solar_explore_eck_bundle_info() {
  $items = array(
    'saved_graph_saved_graph' => array(
      'machine_name' => 'saved_graph_saved_graph',
      'entity_type' => 'saved_graph',
      'name' => 'saved_graph',
      'label' => 'Saved Graph',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function solar_explore_eck_entity_type_info() {
  $items = array(
    'saved_graph' => array(
      'name' => 'saved_graph',
      'label' => 'Saved Graph',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
      ),
    ),
  );
  return $items;
}
