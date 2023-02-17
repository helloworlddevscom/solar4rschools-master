<?php
/**
 * @file
 * solar_activities.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function solar_activities_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_deprecated|node|activity|form';
  $field_group->group_name = 'group_deprecated';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprecated',
    'weight' => '19',
    'children' => array(
      0 => 'field_subject_area_s_',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Deprecated',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-deprecated field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_0|node|activity|teaser';
  $field_group->group_name = 'group_row_0';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 0',
    'weight' => '1',
    'children' => array(
      0 => 'field_activity_rating',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 0',
      'instance_settings' => array(
        'classes' => 'group-row-0 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_activity_teaser_group_row_0',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_1|node|activity|default';
  $field_group->group_name = 'group_row_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_activity_rating',
      1 => 'field_activity_rating_rater',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 1',
      'instance_settings' => array(
        'classes' => 'group-row-1 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_activity_full_group_row_1',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_1|node|activity|teaser';
  $field_group->group_name = 'group_row_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 1',
    'weight' => '2',
    'children' => array(
      0 => 'field_grade_levels',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Row 1',
      'instance_settings' => array(
        'classes' => 'group-row-1 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_activity_teaser_group_row_1',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_2|node|activity|default';
  $field_group->group_name = 'group_row_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 2',
    'weight' => '2',
    'children' => array(
      0 => 'field_grade_levels',
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
        'id' => 'node_activity_full_group_row_2',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_2|node|activity|teaser';
  $field_group->group_name = 'group_row_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 2',
    'weight' => '3',
    'children' => array(
      0 => 'field_materials_used',
      1 => 'field_subject_area_s_',
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
        'id' => 'node_activity_teaser_group_row_2',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_3|node|activity|default';
  $field_group->group_name = 'group_row_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 3',
    'weight' => '3',
    'children' => array(
      0 => 'field_activity_length2',
      1 => 'field_subject_area_s_',
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
        'id' => 'node_activity_full_group_row_3',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_3|node|activity|teaser';
  $field_group->group_name = 'group_row_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 3',
    'weight' => '4',
    'children' => array(
      0 => 'field_activity_length2',
      1 => 'field_standards_met',
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
        'id' => 'node_activity_teaser_group_row_3',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_4|node|activity|default';
  $field_group->group_name = 'group_row_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 4',
    'weight' => '4',
    'children' => array(
      0 => 'field_common_core_standard_s_met',
      1 => 'field_next_generation_science_st',
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
        'id' => 'node_activity_full_group_row_4',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_4|node|activity|teaser';
  $field_group->group_name = 'group_row_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row 4',
    'weight' => '5',
    'children' => array(
      0 => 'field_learning_goals_met',
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
        'id' => 'node_activity_teaser_group_row_4',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_standards_met|node|activity|form';
  $field_group->group_name = 'group_standards_met';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Standards Met',
    'weight' => '13',
    'children' => array(
      0 => 'field_common_core_standard_s_met',
      1 => 'field_next_generation_science_st',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-standards-met field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subject_areas|node|activity|form';
  $field_group->group_name = 'group_subject_areas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Subject Areas',
    'weight' => '5',
    'children' => array(
      0 => 'field_activity_education_science',
      1 => 'field_activity_energy_content',
      2 => 'field_activity_ngss_disciplinary',
      3 => 'field_activity_other_subjects',
      4 => 'field_activity_ngss_science',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-subject-areas field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Deprecated');
  t('Row 0');
  t('Row 1');
  t('Row 2');
  t('Row 3');
  t('Row 4');
  t('Standards Met');
  t('Subject Areas');

  return $field_groups;
}
