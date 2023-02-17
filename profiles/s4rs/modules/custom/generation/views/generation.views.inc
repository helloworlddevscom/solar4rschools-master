<?php
/**
 * @file
 * Views integration for Generation API.
 */

/**
 * Implements hook_views_data_alter().
 */
function generation_views_data_alter(&$data) {
  $data['node']['generation_lifetime_energy'] = array(
    'title' => t('Generation lifetime energy'),
    'help' => t('Total amount of energy a generation site has generated to date.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'generation_handler_field_generation',
    ),
  );
  $data['node']['generation_current_power'] = array(
    'title' => t('Generation current power'),
    'help' => t('Current amount of power a generation site is producing.'),
    'field' => array(
      'handler' => 'generation_handler_field_generation',
    ),
  );
  $data['node']['generation_node_type'] = array(
    'title' => t('Generation site node types'),
    'help' => t('Filters to generation sites only.'),
    'field' => array(
      'handler' => 'views_handler_field_node_type',
    ),
    'filter' => array(
      'handler' => 'generation_handler_filter_node_type',
    ),
  );
}

/**
 * Implements hook_views_handlers().
 */
function generation_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'generation') . '/views',
    ),
    'handlers' => array(
      'generation_handler_field_generation' => array(
        'parent' => 'views_handler_field',
        'file' => 'generation_handler_field_generation.inc',
      ),
      'generation_handler_filter_node_type' => array(
        'parent' => 'views_handler_filter_in_operator',
        'file' => 'generation_handler_filter_node_type.inc',
      ),
    ),
  );
}
