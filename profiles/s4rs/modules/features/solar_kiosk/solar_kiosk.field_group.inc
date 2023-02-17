<?php
/**
 * @file
 * solar_kiosk.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function solar_kiosk_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kiosk_about_partners|node|kiosk|form';
  $field_group->group_name = 'group_kiosk_about_partners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kiosk';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_kiosk_tabs';
  $field_group->data = array(
    'label' => 'About Partners',
    'weight' => '7',
    'children' => array(
      0 => 'field_kiosk_about_partners_body',
      1 => 'field_kiosk_about_partners_thx',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-kiosk-about-partners field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kiosk_about_project|node|kiosk|form';
  $field_group->group_name = 'group_kiosk_about_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kiosk';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_kiosk_tabs';
  $field_group->data = array(
    'label' => 'About Project',
    'weight' => '6',
    'children' => array(
      0 => 'field_kiosk_about_project_body',
      1 => 'field_kiosk_about_project_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-kiosk-about-project field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kiosk_call_to_action|node|kiosk|form';
  $field_group->group_name = 'group_kiosk_call_to_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kiosk';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_kiosk_tabs';
  $field_group->data = array(
    'label' => 'Call to Action',
    'weight' => '9',
    'children' => array(
      0 => 'field_kiosk_call_to_action_body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-kiosk-call-to-action field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kiosk_green_tech|node|kiosk|form';
  $field_group->group_name = 'group_kiosk_green_tech';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kiosk';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_kiosk_tabs';
  $field_group->data = array(
    'label' => 'Green Technology',
    'weight' => '8',
    'children' => array(
      0 => 'field_kiosk_green_tech_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-kiosk-green-tech field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kiosk_how_it_works|node|kiosk|form';
  $field_group->group_name = 'group_kiosk_how_it_works';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kiosk';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_kiosk_tabs';
  $field_group->data = array(
    'label' => 'How It Works',
    'weight' => '5',
    'children' => array(
      0 => 'field_kiosk_how_it_works_body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-kiosk-how-it-works field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kiosk_tabs|node|kiosk|form';
  $field_group->group_name = 'group_kiosk_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kiosk';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kiosk Tabs',
    'weight' => '6',
    'children' => array(
      0 => 'group_kiosk_about_partners',
      1 => 'group_kiosk_about_project',
      2 => 'group_kiosk_call_to_action',
      3 => 'group_kiosk_green_tech',
      4 => 'group_kiosk_how_it_works',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-kiosk-tabs field-group-tabs',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About Partners');
  t('About Project');
  t('Call to Action');
  t('Green Technology');
  t('How It Works');
  t('Kiosk Tabs');

  return $field_groups;
}
