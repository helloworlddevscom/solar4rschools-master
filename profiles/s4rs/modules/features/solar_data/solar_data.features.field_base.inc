<?php
/**
 * @file
 * solar_data.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function solar_data_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_calculation_source2'.
  $field_bases['field_calculation_source2'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_calculation_source2',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'generation_equation',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'generation_math_equation',
  );

  // Exported field_base: 'field_equivalency_icon'.
  $field_bases['field_equivalency_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_equivalency_icon',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_widget_categories'.
  $field_bases['field_widget_categories'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_widget_categories',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'widget_types',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
