<?php
/**
 * @file
 * solar_projects.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function solar_projects_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funder_info|node|project|form';
  $field_group->group_name = 'group_funder_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Funding information',
    'weight' => '17',
    'children' => array(
      0 => 'field_funding_level',
      1 => 'field_funding_needed',
      2 => 'field_this_project_funded_by',
      3 => 'field_total_project_cost',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Funding information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|project|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Media',
    'weight' => '16',
    'children' => array(
      0 => 'field_photo_gallery',
      1 => 'field_video_gallery',
      2 => 'field_thumbnail_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_1|node|project|teaser';
  $field_group->group_name = 'group_row_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 1',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_type',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Row 1',
      'instance_settings' => array(
        'classes' => 'group-row-1 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_2|node|project|teaser';
  $field_group->group_name = 'group_row_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 2',
    'weight' => '1',
    'children' => array(
      0 => 'field_project_location',
      1 => 'field_grade_levels',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 2',
      'instance_settings' => array(
        'classes' => 'group-row-2 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_project_teaser_group_row_2',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_3|node|project|teaser';
  $field_group->group_name = 'group_row_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 3',
    'weight' => '2',
    'children' => array(
      0 => 'field_system_size',
      1 => 'field_technology_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 3',
      'instance_settings' => array(
        'classes' => 'group-row-3 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_project_teaser_group_row_3',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_4|node|project|default';
  $field_group->group_name = 'group_row_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 4',
    'weight' => '3',
    'children' => array(
      0 => 'field_project_location',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 4',
      'instance_settings' => array(
        'classes' => 'group-row-4 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_project_full_group_row_4',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_5|node|project|default';
  $field_group->group_name = 'group_row_5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 5',
    'weight' => '6',
    'children' => array(
      0 => 'field_photo_gallery',
      1 => 'field_video_gallery',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 5',
      'instance_settings' => array(
        'classes' => 'group-row-5 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_project_full_group_row_5',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_widgets|node|project|form';
  $field_group->group_name = 'group_widgets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Widgets',
    'weight' => '20',
    'children' => array(
      0 => 'field_show_realtime',
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
  t('Funding information');
  t('Project Media');
  t('Row 1');
  t('Row 2');
  t('Row 3');
  t('Row 4');
  t('Row 5');
  t('Widgets');

  return $field_groups;
}
