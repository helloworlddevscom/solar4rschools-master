<?php
/**
 * @file
 * deck_monitoring.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function deck_monitoring_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'deck_lid'.
  $field_bases['deck_lid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'deck_lid',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
