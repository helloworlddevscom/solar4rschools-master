<?php
/**
 * @file
 * solar_maps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solar_maps_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solar_map_funder_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solar Maps: Funder Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Funder Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_geolocation';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'title';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Relationship: Funder */
  $handler->display->display_options['relationships']['reverse_field_funder_schools_node']['id'] = 'reverse_field_funder_schools_node';
  $handler->display->display_options['relationships']['reverse_field_funder_schools_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_funder_schools_node']['field'] = 'reverse_field_funder_schools_node';
  $handler->display->display_options['relationships']['reverse_field_funder_schools_node']['ui_name'] = 'Funder';
  $handler->display->display_options['relationships']['reverse_field_funder_schools_node']['label'] = 'Funder';
  $handler->display->display_options['relationships']['reverse_field_funder_schools_node']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Geolocation */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation']['element_type'] = '0';
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_geolocation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geolocation']['settings'] = array(
    'data' => 'full',
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
  $handler->display->display_options['fields']['field_geolocation']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_funder_schools_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'funder' => 'funder',
  );
  /* Contextual filter: Custom: Bounding box */
  $handler->display->display_options['arguments']['bbox_argument']['id'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['table'] = 'views';
  $handler->display->display_options['arguments']['bbox_argument']['field'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['bbox_argument']['default_argument_type'] = 'querystring';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bbox_argument']['summary_options']['items_per_page'] = '25';
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
    'project' => 'project',
  );

  /* Display: Map Feed: Funder Projects */
  $handler = $view->new_display('page', 'Map Feed: Funder Projects', 'map_feed_funder_projects');
  $handler->display->display_options['path'] = 'solar-map-funder-projects/%';
  $export['solar_map_funder_projects'] = $view;

  $view = new view();
  $view->name = 'solar_maps_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solar Maps: Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solar Map Feeds';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = 'custom';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '86400';
  $handler->display->display_options['cache']['output_lifespan'] = 'custom';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '86400';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'views_exposed_groups';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['views_exposed_groups'] = array(
    'format_groups' => 'div',
    'groups' => 'Column 1
Column 2
Column 3',
    'group-nid_entityreference_filter' => array(
      'group' => '0',
      'filter_name' => 'nid_entityreference_filter',
      'weight' => '-10',
    ),
    'group-uid_entityreference_filter' => array(
      'group' => '0',
      'filter_name' => 'uid_entityreference_filter',
      'weight' => '-8',
    ),
    'group-field_project_location_administrative_area' => array(
      'group' => '0',
      'filter_name' => 'field_project_location_administrative_area',
      'weight' => '-9',
    ),
    'group-field_grade_levels_tid' => array(
      'group' => '1',
      'filter_name' => 'field_grade_levels_tid',
      'weight' => '-6',
    ),
    'group-field_project_type_value' => array(
      'group' => '1',
      'filter_name' => 'field_project_type_value',
      'weight' => '-7',
    ),
    'group-field_technology_type_tid' => array(
      'group' => '1',
      'filter_name' => 'field_technology_type_tid',
      'weight' => '-8',
    ),
    'group-field_system_size_value' => array(
      'group' => '2',
      'filter_name' => 'field_system_size_value',
      'weight' => '-9',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'wkt';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_geolocation';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_geolocation';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['data_source']['view_mode'] = 'teaser';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_related_user']['label'] = 'Funder';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Field: Geolocation */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Funding level (field_funding_level) */
  $handler->display->display_options['filters']['field_funding_level_value']['id'] = 'field_funding_level_value';
  $handler->display->display_options['filters']['field_funding_level_value']['table'] = 'field_data_field_funding_level';
  $handler->display->display_options['filters']['field_funding_level_value']['field'] = 'field_funding_level_value';
  $handler->display->display_options['filters']['field_funding_level_value']['value'] = array(
    'funded' => 'funded',
  );
  $handler->display->display_options['filters']['field_funding_level_value']['group'] = 1;
  /* Filter criterion: Content: Nid (reference filter) */
  $handler->display->display_options['filters']['nid_entityreference_filter']['id'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['table'] = 'node';
  $handler->display->display_options['filters']['nid_entityreference_filter']['field'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['nid_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['operator_id'] = 'nid_entityreference_filter_op';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['label'] = 'Project name(s)';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['operator'] = 'nid_entityreference_filter_op';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['identifier'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['nid_entityreference_filter']['reference_display'] = 'projects:entityreference_1';
  /* Filter criterion: Field: Physical Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['filters']['field_project_location_administrative_area']['id'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['field'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['operator'] = 'word';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['operator_id'] = 'field_project_location_administrative_area_op';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['label'] = 'State(s)';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['operator'] = 'field_project_location_administrative_area_op';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['identifier'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_project_location_administrative_area']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group_info']['label'] = 'State(s)';
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
  /* Filter criterion: Content: Intended Grade Level(s) (field_grade_levels) */
  $handler->display->display_options['filters']['field_grade_levels_tid']['id'] = 'field_grade_levels_tid';
  $handler->display->display_options['filters']['field_grade_levels_tid']['table'] = 'field_data_field_grade_levels';
  $handler->display->display_options['filters']['field_grade_levels_tid']['field'] = 'field_grade_levels_tid';
  $handler->display->display_options['filters']['field_grade_levels_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_grade_levels_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade_levels_tid']['expose']['operator_id'] = 'field_grade_levels_tid_op';
  $handler->display->display_options['filters']['field_grade_levels_tid']['expose']['label'] = 'Grade level(s)';
  $handler->display->display_options['filters']['field_grade_levels_tid']['expose']['operator'] = 'field_grade_levels_tid_op';
  $handler->display->display_options['filters']['field_grade_levels_tid']['expose']['identifier'] = 'field_grade_levels_tid';
  $handler->display->display_options['filters']['field_grade_levels_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_grade_levels_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_grade_levels_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_grade_levels_tid']['vocabulary'] = 'grade_levels';
  /* Filter criterion: Content: Technology Type (field_technology_type) */
  $handler->display->display_options['filters']['field_technology_type_tid']['id'] = 'field_technology_type_tid';
  $handler->display->display_options['filters']['field_technology_type_tid']['table'] = 'field_data_field_technology_type';
  $handler->display->display_options['filters']['field_technology_type_tid']['field'] = 'field_technology_type_tid';
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
  /* Filter criterion: Content: PV System Size (field_system_size) */
  $handler->display->display_options['filters']['field_system_size_value']['id'] = 'field_system_size_value';
  $handler->display->display_options['filters']['field_system_size_value']['table'] = 'field_data_field_system_size';
  $handler->display->display_options['filters']['field_system_size_value']['field'] = 'field_system_size_value';
  $handler->display->display_options['filters']['field_system_size_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_system_size_value']['group'] = 1;
  $handler->display->display_options['filters']['field_system_size_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_system_size_value']['expose']['operator_id'] = 'field_system_size_value_op';
  $handler->display->display_options['filters']['field_system_size_value']['expose']['label'] = 'System Size in Kilowatts';
  $handler->display->display_options['filters']['field_system_size_value']['expose']['operator'] = 'field_system_size_value_op';
  $handler->display->display_options['filters']['field_system_size_value']['expose']['identifier'] = 'field_system_size_value';
  $handler->display->display_options['filters']['field_system_size_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Map Feed: Funded Projects */
  $handler = $view->new_display('page', 'Map Feed: Funded Projects', 'map_feed_funded');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-pane-map-feed';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_geolocation';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_geolocation';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['data_source']['view_mode'] = 'map_bubble_teaser';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Field: Geolocation */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation']['element_type'] = '0';
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_geolocation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geolocation']['settings'] = array(
    'data' => 'full',
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
  $handler->display->display_options['fields']['field_geolocation']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Custom: Bounding box */
  $handler->display->display_options['arguments']['bbox_argument']['id'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['table'] = 'views';
  $handler->display->display_options['arguments']['bbox_argument']['field'] = 'bbox_argument';
  $handler->display->display_options['arguments']['bbox_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['bbox_argument']['default_argument_type'] = 'querystring';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bbox_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bbox_argument']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'solar-map-feed-projects';

  /* Display: Pane: Map Companion List */
  $handler = $view->new_display('panel_pane', 'Pane: Map Companion List', 'projects_pane_map_companion_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="loadspinner companion-list"></div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 'offset';
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'bbox_argument' => array(
      'type' => 'none',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Custom: Bounding box',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['solar_maps_projects'] = $view;

  return $export;
}
