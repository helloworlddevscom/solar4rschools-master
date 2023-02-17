<?php

/**
 * Implements hook_ctools_plugin_api().
 */
function deck_monitoring_location_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implements hook_node_info().
 */
function deck_monitoring_location_node_info() {
  $items = array(
    'deck_monitoring_location' => array(
      'name' => t('Deck Monitoring Location'),
      'base' => 'deck_monitoring_location',
      'description' => t('A location monitored by DECK Monitoring.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
