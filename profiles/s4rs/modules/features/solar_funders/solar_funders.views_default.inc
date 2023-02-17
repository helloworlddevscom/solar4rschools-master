<?php
/**
 * @file
 * solar_funders.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solar_funders_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'founding_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Founding Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'views_exposed_groups';
  $handler->display->display_options['exposed_form']['options']['views_exposed_groups'] = array(
    'format_groups' => 'div',
    'groups' => 'Column 1
Column 2
Column 3',
    'group-funder_id' => array(
      'group' => '0',
      'filter_name' => 'title_multiselect',
      'weight' => '-5',
    ),
    'group-field_project_location_administrative_area' => array(
      'group' => '1',
      'filter_name' => 'field_project_location_administrative_area',
      'weight' => '-4',
    ),
    'group-field_technology_type_tid' => array(
      'group' => '2',
      'filter_name' => 'field_technology_type_tid',
      'weight' => '-5',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Project */
  $handler->display->display_options['relationships']['field_funder_schools_target_id']['id'] = 'field_funder_schools_target_id';
  $handler->display->display_options['relationships']['field_funder_schools_target_id']['table'] = 'field_data_field_funder_schools';
  $handler->display->display_options['relationships']['field_funder_schools_target_id']['field'] = 'field_funder_schools_target_id';
  $handler->display->display_options['relationships']['field_funder_schools_target_id']['ui_name'] = 'Project';
  $handler->display->display_options['relationships']['field_funder_schools_target_id']['label'] = 'Project';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_funder_logo']['id'] = 'field_funder_logo';
  $handler->display->display_options['fields']['field_funder_logo']['table'] = 'field_data_field_funder_logo';
  $handler->display->display_options['fields']['field_funder_logo']['field'] = 'field_funder_logo';
  $handler->display->display_options['fields']['field_funder_logo']['label'] = '';
  $handler->display->display_options['fields']['field_funder_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_funder_logo']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_funder_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_funder_logo']['empty'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['field_funder_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_funder_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_funder_logo']['settings'] = array(
    'image_style' => 'funder_small',
    'image_link' => '',
    'empty_fields_handler' => 'EmptyFieldText',
    'empty_fields_emptyfieldtext_empty_text' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_funder_body']['id'] = 'field_funder_body';
  $handler->display->display_options['fields']['field_funder_body']['table'] = 'field_data_field_funder_body';
  $handler->display->display_options['fields']['field_funder_body']['field'] = 'field_funder_body';
  $handler->display->display_options['fields']['field_funder_body']['label'] = '';
  $handler->display->display_options['fields']['field_funder_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_funder_body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_funder_body']['settings'] = array(
    'trim_length' => '350',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '1',
    'more_text' => ' ​View full funder profile >>',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funder' => 'funder',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Funders List */
  $handler = $view->new_display('panel_pane', 'Funders List', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funder' => 'funder',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Funder Name(s) */
  $handler->display->display_options['filters']['title_multiselect']['id'] = 'title_multiselect';
  $handler->display->display_options['filters']['title_multiselect']['table'] = 'node';
  $handler->display->display_options['filters']['title_multiselect']['field'] = 'title_multiselect';
  $handler->display->display_options['filters']['title_multiselect']['ui_name'] = 'Funder Name(s)';
  $handler->display->display_options['filters']['title_multiselect']['group'] = 1;
  $handler->display->display_options['filters']['title_multiselect']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_multiselect']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['title_multiselect']['expose']['label'] = 'Funder Name(s)';
  $handler->display->display_options['filters']['title_multiselect']['expose']['operator'] = 'title_multiselect_op';
  $handler->display->display_options['filters']['title_multiselect']['expose']['identifier'] = 'funder_id';
  $handler->display->display_options['filters']['title_multiselect']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title_multiselect']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Project location(s) */
  $handler->display->display_options['filters']['field_project_location_administrative_area']['id'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['field'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['relationship'] = 'field_funder_schools_target_id';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['ui_name'] = 'Project location(s)';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['operator'] = 'word';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['operator_id'] = 'field_project_location_administrative_area_op';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['label'] = 'Physical Address - Administrative area (i.e. State / Province)';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['operator'] = 'field_project_location_administrative_area_op';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['identifier'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group_info']['label'] = 'Project location(s)';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group_info']['identifier'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Alabama',
      'operator' => '=',
      'value' => 'AL',
    ),
    2 => array(
      'title' => 'Alaska',
      'operator' => '=',
      'value' => 'AK',
    ),
    3 => array(
      'title' => 'Arizona',
      'operator' => '=',
      'value' => 'AZ',
    ),
    4 => array(
      'title' => 'Arkansas',
      'operator' => '=',
      'value' => 'AR',
    ),
    5 => array(
      'title' => 'California',
      'operator' => '=',
      'value' => 'CA',
    ),
    6 => array(
      'title' => 'Colorado',
      'operator' => '=',
      'value' => 'CO',
    ),
    7 => array(
      'title' => 'Connecticut',
      'operator' => '=',
      'value' => 'CT',
    ),
    8 => array(
      'title' => 'Delaware',
      'operator' => '=',
      'value' => 'DE',
    ),
    9 => array(
      'title' => 'District Of Columbia',
      'operator' => '=',
      'value' => 'DC',
    ),
    10 => array(
      'title' => 'Florida',
      'operator' => '=',
      'value' => 'FL',
    ),
    11 => array(
      'title' => 'Georgia',
      'operator' => '=',
      'value' => 'GA',
    ),
    12 => array(
      'title' => 'Hawaii',
      'operator' => '=',
      'value' => 'HI',
    ),
    13 => array(
      'title' => 'Idaho',
      'operator' => '=',
      'value' => 'ID',
    ),
    14 => array(
      'title' => 'Illinois',
      'operator' => '=',
      'value' => 'IL',
    ),
    15 => array(
      'title' => 'Indiana',
      'operator' => '=',
      'value' => 'IN',
    ),
    16 => array(
      'title' => 'Iowa',
      'operator' => '=',
      'value' => 'IA',
    ),
    17 => array(
      'title' => 'Kansas',
      'operator' => '=',
      'value' => 'KS',
    ),
    18 => array(
      'title' => 'Kentucky',
      'operator' => '=',
      'value' => 'KY',
    ),
    19 => array(
      'title' => 'Louisiana',
      'operator' => '=',
      'value' => 'LA',
    ),
    20 => array(
      'title' => 'Maine',
      'operator' => '=',
      'value' => 'ME',
    ),
    21 => array(
      'title' => 'Maryland',
      'operator' => '=',
      'value' => 'MD',
    ),
    22 => array(
      'title' => 'Massachusetts',
      'operator' => '=',
      'value' => 'MA',
    ),
    23 => array(
      'title' => 'Michigan',
      'operator' => '=',
      'value' => 'MI',
    ),
    24 => array(
      'title' => 'Minnesota',
      'operator' => '=',
      'value' => 'MN',
    ),
    25 => array(
      'title' => 'Mississippi',
      'operator' => '=',
      'value' => 'MS',
    ),
    26 => array(
      'title' => 'Missouri',
      'operator' => '=',
      'value' => 'MO',
    ),
    27 => array(
      'title' => 'Montana',
      'operator' => '=',
      'value' => 'MT',
    ),
    28 => array(
      'title' => 'Nebraska',
      'operator' => '=',
      'value' => 'NE',
    ),
    29 => array(
      'title' => 'Nevada',
      'operator' => '=',
      'value' => 'NV',
    ),
    30 => array(
      'title' => 'New Hampshire',
      'operator' => '=',
      'value' => 'NH',
    ),
    31 => array(
      'title' => 'New Jersey',
      'operator' => '=',
      'value' => 'NJ',
    ),
    32 => array(
      'title' => 'New Mexico',
      'operator' => '=',
      'value' => 'NM',
    ),
    33 => array(
      'title' => 'New York',
      'operator' => '=',
      'value' => 'NY',
    ),
    34 => array(
      'title' => 'North Carolina',
      'operator' => '=',
      'value' => 'NC',
    ),
    35 => array(
      'title' => 'North Dakota',
      'operator' => '=',
      'value' => 'ND',
    ),
    36 => array(
      'title' => 'Ohio',
      'operator' => '=',
      'value' => 'OH',
    ),
    37 => array(
      'title' => 'Oklahoma',
      'operator' => '=',
      'value' => 'OK',
    ),
    38 => array(
      'title' => 'Oregon',
      'operator' => '=',
      'value' => 'OR',
    ),
    39 => array(
      'title' => 'Pennsylvania',
      'operator' => '=',
      'value' => 'PA',
    ),
    40 => array(
      'title' => 'Rhode Island',
      'operator' => '=',
      'value' => 'RI',
    ),
    41 => array(
      'title' => 'South Carolina',
      'operator' => '=',
      'value' => 'SC',
    ),
    42 => array(
      'title' => 'South Dakota',
      'operator' => '=',
      'value' => 'SD',
    ),
    43 => array(
      'title' => 'Tennessee',
      'operator' => '=',
      'value' => 'TN',
    ),
    44 => array(
      'title' => 'Texas',
      'operator' => '=',
      'value' => 'TX',
    ),
    45 => array(
      'title' => 'Utah',
      'operator' => '=',
      'value' => 'UT',
    ),
    46 => array(
      'title' => 'Vermont',
      'operator' => '=',
      'value' => 'VT',
    ),
    47 => array(
      'title' => 'Virginia',
      'operator' => '=',
      'value' => 'VA',
    ),
    48 => array(
      'title' => 'Washington',
      'operator' => '=',
      'value' => 'WA',
    ),
    49 => array(
      'title' => 'West Virginia',
      'operator' => '=',
      'value' => 'WV',
    ),
    50 => array(
      'title' => 'Wisconsin',
      'operator' => '=',
      'value' => 'WI',
    ),
    51 => array(
      'title' => 'Wyoming',
      'operator' => '=',
      'value' => 'WY',
    ),
  );
  /* Filter criterion: Technology type(s) */
  $handler->display->display_options['filters']['field_technology_type_tid']['id'] = 'field_technology_type_tid';
  $handler->display->display_options['filters']['field_technology_type_tid']['table'] = 'field_data_field_technology_type';
  $handler->display->display_options['filters']['field_technology_type_tid']['field'] = 'field_technology_type_tid';
  $handler->display->display_options['filters']['field_technology_type_tid']['relationship'] = 'field_funder_schools_target_id';
  $handler->display->display_options['filters']['field_technology_type_tid']['ui_name'] = 'Technology type(s)';
  $handler->display->display_options['filters']['field_technology_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_technology_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_technology_type_tid']['expose']['operator_id'] = 'field_technology_type_tid_op';
  $handler->display->display_options['filters']['field_technology_type_tid']['expose']['label'] = 'Technology type(s)';
  $handler->display->display_options['filters']['field_technology_type_tid']['expose']['operator'] = 'field_technology_type_tid_op';
  $handler->display->display_options['filters']['field_technology_type_tid']['expose']['identifier'] = 'field_technology_type_tid';
  $handler->display->display_options['filters']['field_technology_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_technology_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_technology_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_technology_type_tid']['vocabulary'] = 'technology_type';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['founding_partners'] = $view;

  $view = new view();
  $view->name = 'funders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Funders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'user';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['label'] = 'Funder info';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'funder' => 'funder',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Profile: Show funder (field_show_funder) */
  $handler->display->display_options['filters']['field_show_funder_value']['id'] = 'field_show_funder_value';
  $handler->display->display_options['filters']['field_show_funder_value']['table'] = 'field_data_field_show_funder';
  $handler->display->display_options['filters']['field_show_funder_value']['field'] = 'field_show_funder_value';
  $handler->display->display_options['filters']['field_show_funder_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_show_funder_value']['value'] = array(
    1 => '1',
  );

  /* Display: Funders teaser */
  $handler = $view->new_display('panel_pane', 'Funders teaser', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'The teaser view of all funders';

  /* Display: Newest funders */
  $handler = $view->new_display('panel_pane', 'Newest funders', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Newest Funding Partners';
  $handler->display->display_options['display_description'] = 'The 4 latest funders';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;

  /* Display: Rules */
  $handler = $view->new_display('views_rules', 'Rules', 'views_rules_1');
  $handler->display->display_options['display_description'] = 'This view creates a loop traversed by the rule solar_data_add_widget_to_all_funders';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $handler->display->display_options['rules_variables'] = array(
    'uid' => array(
      'enabled' => 1,
      'rendered' => 0,
      'type' => 'user',
      'label' => 'User: Uid',
      'name' => 'uid',
    ),
  );
  $export['funders'] = $view;

  return $export;
}
