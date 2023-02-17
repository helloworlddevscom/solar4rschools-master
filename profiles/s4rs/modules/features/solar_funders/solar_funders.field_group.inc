<?php
/**
 * @file
 * solar_funders.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function solar_funders_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funder_widgets|node|funder|form';
  $field_group->group_name = 'group_funder_widgets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funder';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Widgets',
    'weight' => '9',
    'children' => array(
      0 => 'field_show_widgets',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-funder-widgets field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_widgets|profile2|funder|form';
  $field_group->group_name = 'group_widgets';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'funder';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Widgets',
    'weight' => '10',
    'children' => array(
      0 => 'field_show_funder_widgets',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-widgets field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Widgets');

  return $field_groups;
}
