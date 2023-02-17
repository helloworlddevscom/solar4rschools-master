<?php
/**
 * @file
 * solar_classroom_updates.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_classroom_updates_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function solar_classroom_updates_node_info() {
  $items = array(
    'classroom_updates' => array(
      'name' => t('Classroom updates'),
      'base' => 'node_content',
      'description' => t('Updates on how a classroom is doing with their Solar project'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
