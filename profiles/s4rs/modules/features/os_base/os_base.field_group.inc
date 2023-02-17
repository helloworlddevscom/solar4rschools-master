<?php
/**
 * @file
 * os_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os_base_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_full_width_iframe|node|page|form';
  $field_group->group_name = 'group_full_width_iframe';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Full Width Iframe',
    'weight' => '2',
    'children' => array(
      0 => 'field_full_width_iframe_width',
      1 => 'field_full_width_iframe_height',
      2 => 'field_full_width_iframe_url',
      3 => 'field_full_width_iframe_height_m',
      4 => 'field_full_width_iframe_width_m',
      5 => 'field_hide_title_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Full Width Iframe',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-full-width-iframe field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Full Width Iframe');

  return $field_groups;
}
