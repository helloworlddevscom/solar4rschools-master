<?php
/**
 * @file
 * solar_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solar_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'node_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default';
  $view->human_name = 'Node search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'None found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Node: String title */
  $handler->display->display_options['sorts']['search_api_aggregation_2']['id'] = 'search_api_aggregation_2';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['table'] = 'search_api_index_default';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['field'] = 'search_api_aggregation_2';
  /* Filter criterion: Indexed Node: Subject area(s) */
  $handler->display->display_options['filters']['field_subject_area_s_']['id'] = 'field_subject_area_s_';
  $handler->display->display_options['filters']['field_subject_area_s_']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_subject_area_s_']['field'] = 'field_subject_area_s_';
  $handler->display->display_options['filters']['field_subject_area_s_']['value'] = array();
  $handler->display->display_options['filters']['field_subject_area_s_']['group'] = 1;
  $handler->display->display_options['filters']['field_subject_area_s_']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subject_area_s_']['expose']['operator_id'] = 'field_subject_area_s__op';
  $handler->display->display_options['filters']['field_subject_area_s_']['expose']['label'] = 'Subject area(s)';
  $handler->display->display_options['filters']['field_subject_area_s_']['expose']['operator'] = 'field_subject_area_s__op';
  $handler->display->display_options['filters']['field_subject_area_s_']['expose']['identifier'] = 'field_subject_area_s_';
  $handler->display->display_options['filters']['field_subject_area_s_']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_subject_area_s_']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_subject_area_s_']['type'] = 'select';
  /* Filter criterion: Indexed Node: Equipment Type(s) */
  $handler->display->display_options['filters']['field_equipment_types']['id'] = 'field_equipment_types';
  $handler->display->display_options['filters']['field_equipment_types']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_equipment_types']['field'] = 'field_equipment_types';
  $handler->display->display_options['filters']['field_equipment_types']['value'] = array();
  $handler->display->display_options['filters']['field_equipment_types']['group'] = 1;
  $handler->display->display_options['filters']['field_equipment_types']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_equipment_types']['expose']['operator_id'] = 'field_equipment_types_op';
  $handler->display->display_options['filters']['field_equipment_types']['expose']['label'] = 'Equipment Type(s)';
  $handler->display->display_options['filters']['field_equipment_types']['expose']['operator'] = 'field_equipment_types_op';
  $handler->display->display_options['filters']['field_equipment_types']['expose']['identifier'] = 'field_equipment_types';
  $handler->display->display_options['filters']['field_equipment_types']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_equipment_types']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_equipment_types']['type'] = 'select';
  $handler->display->display_options['filters']['field_equipment_types']['error_message'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'science_kit' => 'science_kit',
  );

  /* Display: Science kits */
  $handler = $view->new_display('panel_pane', 'Science kits', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Science kits view.';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'views_exposed_groups';
  $handler->display->display_options['exposed_form']['options']['views_exposed_groups'] = array(
    'format_groups' => 'div',
    'groups' => 'Row 1
Row 2',
    'group-field_subject_area_s_' => array(
      'group' => '0',
      'filter_name' => 'field_subject_area_s_',
      'weight' => '-5',
    ),
    'group-field_equipment_types' => array(
      'group' => '0',
      'filter_name' => 'field_equipment_types',
      'weight' => '-4',
    ),
    'group-search_api_views_fulltext' => array(
      'group' => '1',
      'filter_name' => 'search_api_views_fulltext',
      'weight' => '-5',
    ),
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'type' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content type',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Projects funded */
  $handler = $view->new_display('panel_pane', 'Projects funded', 'panel_pane_2');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Active group members */
  $handler->display->display_options['filters']['members_1']['id'] = 'members_1';
  $handler->display->display_options['filters']['members_1']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['members_1']['field'] = 'members_1';
  $handler->display->display_options['filters']['members_1']['group'] = 1;
  $handler->display->display_options['filters']['members_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['members_1']['expose']['operator_id'] = 'members_1_op';
  $handler->display->display_options['filters']['members_1']['expose']['label'] = 'Active group members';
  $handler->display->display_options['filters']['members_1']['expose']['operator'] = 'members_1_op';
  $handler->display->display_options['filters']['members_1']['expose']['identifier'] = 'members_1';
  $handler->display->display_options['filters']['members_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['members_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Intended Grade Level(s) */
  $handler->display->display_options['filters']['field_grade_levels']['id'] = 'field_grade_levels';
  $handler->display->display_options['filters']['field_grade_levels']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_grade_levels']['field'] = 'field_grade_levels';
  $handler->display->display_options['filters']['field_grade_levels']['value'] = array();
  $handler->display->display_options['filters']['field_grade_levels']['group'] = 1;
  $handler->display->display_options['filters']['field_grade_levels']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade_levels']['expose']['operator_id'] = 'field_grade_levels_op';
  $handler->display->display_options['filters']['field_grade_levels']['expose']['label'] = 'Grade Level';
  $handler->display->display_options['filters']['field_grade_levels']['expose']['operator'] = 'field_grade_levels_op';
  $handler->display->display_options['filters']['field_grade_levels']['expose']['identifier'] = 'field_grade_levels';
  $handler->display->display_options['filters']['field_grade_levels']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_grade_levels']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_grade_levels']['expose']['reduce'] = 0;
  /* Filter criterion: Location: Administrative area (i.e. State / Province) (indexed) */
  $handler->display->display_options['filters']['field_project_location_administrative_area']['id'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['field'] = 'field_project_location_administrative_area';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['operator_id'] = 'field_project_location_administrative_area_op';
  $handler->display->display_options['filters']['field_project_location_administrative_area']['expose']['label'] = 'Location';
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
  /* Filter criterion: Indexed Node: Project Type */
  $handler->display->display_options['filters']['field_project_type']['id'] = 'field_project_type';
  $handler->display->display_options['filters']['field_project_type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_project_type']['field'] = 'field_project_type';
  $handler->display->display_options['filters']['field_project_type']['value'] = array();
  $handler->display->display_options['filters']['field_project_type']['group'] = 1;
  $handler->display->display_options['filters']['field_project_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_type']['expose']['operator_id'] = 'field_project_type_op';
  $handler->display->display_options['filters']['field_project_type']['expose']['label'] = 'Project type';
  $handler->display->display_options['filters']['field_project_type']['expose']['operator'] = 'field_project_type_op';
  $handler->display->display_options['filters']['field_project_type']['expose']['identifier'] = 'field_project_type';
  $handler->display->display_options['filters']['field_project_type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_project_type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Technology Type */
  $handler->display->display_options['filters']['field_technology_type']['id'] = 'field_technology_type';
  $handler->display->display_options['filters']['field_technology_type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_technology_type']['field'] = 'field_technology_type';
  $handler->display->display_options['filters']['field_technology_type']['value'] = array();
  $handler->display->display_options['filters']['field_technology_type']['group'] = 1;
  $handler->display->display_options['filters']['field_technology_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_technology_type']['expose']['operator_id'] = 'field_technology_type_op';
  $handler->display->display_options['filters']['field_technology_type']['expose']['label'] = 'Technology type';
  $handler->display->display_options['filters']['field_technology_type']['expose']['operator'] = 'field_technology_type_op';
  $handler->display->display_options['filters']['field_technology_type']['expose']['identifier'] = 'field_technology_type';
  $handler->display->display_options['filters']['field_technology_type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_technology_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_technology_type']['type'] = 'select';
  /* Filter criterion: Indexed Node: PV System Size */
  $handler->display->display_options['filters']['field_system_size_1']['id'] = 'field_system_size_1';
  $handler->display->display_options['filters']['field_system_size_1']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_system_size_1']['field'] = 'field_system_size';
  $handler->display->display_options['filters']['field_system_size_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_system_size_1']['group'] = 1;
  $handler->display->display_options['filters']['field_system_size_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_system_size_1']['expose']['operator_id'] = 'field_system_size_1_op';
  $handler->display->display_options['filters']['field_system_size_1']['expose']['label'] = 'System size greater than';
  $handler->display->display_options['filters']['field_system_size_1']['expose']['operator'] = 'field_system_size_1_op';
  $handler->display->display_options['filters']['field_system_size_1']['expose']['identifier'] = 'field_system_size_1';
  $handler->display->display_options['filters']['field_system_size_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: PV System Size */
  $handler->display->display_options['filters']['field_system_size']['id'] = 'field_system_size';
  $handler->display->display_options['filters']['field_system_size']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_system_size']['field'] = 'field_system_size';
  $handler->display->display_options['filters']['field_system_size']['operator'] = '<=';
  $handler->display->display_options['filters']['field_system_size']['group'] = 1;
  $handler->display->display_options['filters']['field_system_size']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_system_size']['expose']['operator_id'] = 'field_system_size_op';
  $handler->display->display_options['filters']['field_system_size']['expose']['label'] = 'but less than';
  $handler->display->display_options['filters']['field_system_size']['expose']['operator'] = 'field_system_size_op';
  $handler->display->display_options['filters']['field_system_size']['expose']['identifier'] = 'field_system_size';
  $handler->display->display_options['filters']['field_system_size']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Node: Funding level */
  $handler->display->display_options['filters']['field_funding_level']['id'] = 'field_funding_level';
  $handler->display->display_options['filters']['field_funding_level']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_funding_level']['field'] = 'field_funding_level';
  $handler->display->display_options['filters']['field_funding_level']['value'] = array(
    'funded' => 'funded',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['argument_input'] = array(
    'type' => array(
      'type' => 'user',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content type',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Projects seeking funding */
  $handler = $view->new_display('panel_pane', 'Projects seeking funding', 'panel_pane_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Node: Funding level */
  $handler->display->display_options['filters']['field_funding_level']['id'] = 'field_funding_level';
  $handler->display->display_options['filters']['field_funding_level']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['field_funding_level']['field'] = 'field_funding_level';
  $handler->display->display_options['filters']['field_funding_level']['value'] = array(
    'needs_funding' => 'needs_funding',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );

  /* Display: Projects by funder */
  $handler = $view->new_display('panel_pane', 'Projects by funder', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sponsored Projects';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Active group members */
  $handler->display->display_options['arguments']['members_1']['id'] = 'members_1';
  $handler->display->display_options['arguments']['members_1']['table'] = 'search_api_index_default';
  $handler->display->display_options['arguments']['members_1']['field'] = 'members_1';
  $handler->display->display_options['arguments']['members_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['members_1']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['members_1']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['members_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );

  /* Display: All nodes */
  $handler = $view->new_display('panel_pane', 'All nodes', 'panel_pane_6');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Sort by relevance';
  /* Sort criterion: Indexed Node: String title */
  $handler->display->display_options['sorts']['search_api_aggregation_2']['id'] = 'search_api_aggregation_2';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['table'] = 'search_api_index_default';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['field'] = 'search_api_aggregation_2';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_aggregation_2']['expose']['label'] = 'Sort by title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Articles */
  $handler = $view->new_display('panel_pane', 'Articles', 'panel_pane_7');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Enter Keyword(s) or Phrase';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'topic';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articles' => 'articles',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['node_search'] = $view;

  $view = new view();
  $view->name = 'taxonomy_term_override';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy Term Override';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Activity Center */
  $handler = $view->new_display('page', 'Activity Center', 'page_activity_center');
  $handler->display->display_options['display_description'] = 'Used for any Activity Center related vocabularies via TVI module. See vocabulary config.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'activity_center';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Lesson Number (field_lesson_number) */
  $handler->display->display_options['sorts']['field_lesson_number_value_1']['id'] = 'field_lesson_number_value_1';
  $handler->display->display_options['sorts']['field_lesson_number_value_1']['table'] = 'field_data_field_lesson_number';
  $handler->display->display_options['sorts']['field_lesson_number_value_1']['field'] = 'field_lesson_number_value';
  /* Sort criterion: Content: Lesson Number (field_lesson_number) */
  $handler->display->display_options['sorts']['field_lesson_number_value']['id'] = 'field_lesson_number_value';
  $handler->display->display_options['sorts']['field_lesson_number_value']['table'] = 'field_data_field_lesson_number';
  $handler->display->display_options['sorts']['field_lesson_number_value']['field'] = 'field_lesson_number_value';
  $handler->display->display_options['sorts']['field_lesson_number_value']['order'] = 'NASC';
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $export['taxonomy_term_override'] = $view;

  return $export;
}
