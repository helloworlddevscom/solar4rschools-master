<?php
/**
 * @file
 * solar_activities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solar_activities_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'activities';
  $view->description = 'All views that show Activities content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Activities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'activity' => 'activity',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Related Activities */
  $handler = $view->new_display('panel_pane', 'Related Activities', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Activities';
  $handler->display->display_options['display_description'] = 'Activities related to a given science kit';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Science Kit Material(s) Used (field_science_kit_materials_used) */
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['id'] = 'field_science_kit_materials_used_target_id';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['table'] = 'field_data_field_science_kit_materials_used';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['field'] = 'field_science_kit_materials_used_target_id';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_science_kit_materials_used_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Recently Added Activities */
  $handler = $view->new_display('panel_pane', 'Recently Added Activities', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Newest Activities';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Top Rated Activities */
  $handler = $view->new_display('panel_pane', 'Top Rated Activities', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Top Rated Activities';
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
  /* Sort criterion: Content: Average Rating (field_activity_rating:rating) */
  $handler->display->display_options['sorts']['field_activity_rating_rating']['id'] = 'field_activity_rating_rating';
  $handler->display->display_options['sorts']['field_activity_rating_rating']['table'] = 'field_data_field_activity_rating';
  $handler->display->display_options['sorts']['field_activity_rating_rating']['field'] = 'field_activity_rating_rating';
  $handler->display->display_options['sorts']['field_activity_rating_rating']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';

  /* Display: My authored activities */
  $handler = $view->new_display('entityreference', 'My authored activities', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'This entity reference view will be used when authors wish to request an activity be removed.';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'activity' => 'activity',
  );

  /* Display: My uploaded activities - teasers */
  $handler = $view->new_display('panel_pane', 'My uploaded activities - teasers', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My uploaded activities';
  $handler->display->display_options['display_description'] = 'Teasers of activities a given user has authored. Made for My Activities page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="blue-button"><a href="/node/add/activity">Add activity</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '- none -';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content author',
    ),
  );
  $export['activities'] = $view;

  $view = new view();
  $view->name = 'activity_node_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Activity Node Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Activity Node Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_unit_title']['id'] = 'field_unit_title';
  $handler->display->display_options['fields']['field_unit_title']['table'] = 'field_data_field_unit_title';
  $handler->display->display_options['fields']['field_unit_title']['field'] = 'field_unit_title';
  $handler->display->display_options['fields']['field_unit_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_unit_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_unit_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_unit_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_unit_title']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_unit_title']['settings'] = array(
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
  $handler->display->display_options['fields']['field_unit_title']['field_api_classes'] = TRUE;
  /* Field: Content: Lesson Number */
  $handler->display->display_options['fields']['field_lesson_number']['id'] = 'field_lesson_number';
  $handler->display->display_options['fields']['field_lesson_number']['table'] = 'field_data_field_lesson_number';
  $handler->display->display_options['fields']['field_lesson_number']['field'] = 'field_lesson_number';
  $handler->display->display_options['fields']['field_lesson_number']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lesson_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lesson_number']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_lesson_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lesson_number']['settings'] = array(
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
  $handler->display->display_options['fields']['field_lesson_number']['field_api_classes'] = TRUE;
  /* Field: Content: Intended Grade Level(s) */
  $handler->display->display_options['fields']['field_grade_levels']['id'] = 'field_grade_levels';
  $handler->display->display_options['fields']['field_grade_levels']['table'] = 'field_data_field_grade_levels';
  $handler->display->display_options['fields']['field_grade_levels']['field'] = 'field_grade_levels';
  $handler->display->display_options['fields']['field_grade_levels']['element_type'] = '0';
  $handler->display->display_options['fields']['field_grade_levels']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_grade_levels']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_grade_levels']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_grade_levels']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_grade_levels']['settings'] = array(
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
  $handler->display->display_options['fields']['field_grade_levels']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_grade_levels']['field_api_classes'] = TRUE;
  /* Field: Content: Relevant Common Core Standard(s) */
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['id'] = 'field_common_core_standard_s_met';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['table'] = 'field_data_field_common_core_standard_s_met';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['field'] = 'field_common_core_standard_s_met';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['element_type'] = '0';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['settings'] = array(
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
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_common_core_standard_s_met']['field_api_classes'] = TRUE;
  /* Field: Content: Relevant NGSS PE */
  $handler->display->display_options['fields']['field_next_generation_science_st']['id'] = 'field_next_generation_science_st';
  $handler->display->display_options['fields']['field_next_generation_science_st']['table'] = 'field_data_field_next_generation_science_st';
  $handler->display->display_options['fields']['field_next_generation_science_st']['field'] = 'field_next_generation_science_st';
  $handler->display->display_options['fields']['field_next_generation_science_st']['element_type'] = '0';
  $handler->display->display_options['fields']['field_next_generation_science_st']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_next_generation_science_st']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_next_generation_science_st']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_next_generation_science_st']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_next_generation_science_st']['settings'] = array(
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
  $handler->display->display_options['fields']['field_next_generation_science_st']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_next_generation_science_st']['field_api_classes'] = TRUE;
  /* Field: Content: Subject Area(s) Covered */
  $handler->display->display_options['fields']['field_subject_area_s_']['id'] = 'field_subject_area_s_';
  $handler->display->display_options['fields']['field_subject_area_s_']['table'] = 'field_data_field_subject_area_s_';
  $handler->display->display_options['fields']['field_subject_area_s_']['field'] = 'field_subject_area_s_';
  $handler->display->display_options['fields']['field_subject_area_s_']['label'] = 'Subject Area(s) Covered (deprecated)';
  $handler->display->display_options['fields']['field_subject_area_s_']['element_type'] = '0';
  $handler->display->display_options['fields']['field_subject_area_s_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subject_area_s_']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_subject_area_s_']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_subject_area_s_']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject_area_s_']['settings'] = array(
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
  $handler->display->display_options['fields']['field_subject_area_s_']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_subject_area_s_']['field_api_classes'] = TRUE;
  /* Field: Content: Other Subjects Covered */
  $handler->display->display_options['fields']['field_activity_other_subjects']['id'] = 'field_activity_other_subjects';
  $handler->display->display_options['fields']['field_activity_other_subjects']['table'] = 'field_data_field_activity_other_subjects';
  $handler->display->display_options['fields']['field_activity_other_subjects']['field'] = 'field_activity_other_subjects';
  $handler->display->display_options['fields']['field_activity_other_subjects']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_other_subjects']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_other_subjects']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_other_subjects']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_other_subjects']['settings'] = array(
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
  $handler->display->display_options['fields']['field_activity_other_subjects']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_other_subjects']['field_api_classes'] = TRUE;
  /* Field: Content: NGSS Science and Engineering Practices */
  $handler->display->display_options['fields']['field_activity_ngss_science']['id'] = 'field_activity_ngss_science';
  $handler->display->display_options['fields']['field_activity_ngss_science']['table'] = 'field_data_field_activity_ngss_science';
  $handler->display->display_options['fields']['field_activity_ngss_science']['field'] = 'field_activity_ngss_science';
  $handler->display->display_options['fields']['field_activity_ngss_science']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_ngss_science']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_ngss_science']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_ngss_science']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_ngss_science']['settings'] = array(
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
  $handler->display->display_options['fields']['field_activity_ngss_science']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_ngss_science']['field_api_classes'] = TRUE;
  /* Field: Content: NGSS Disciplinary Core Idea */
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['id'] = 'field_activity_ngss_disciplinary';
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['table'] = 'field_data_field_activity_ngss_disciplinary';
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['field'] = 'field_activity_ngss_disciplinary';
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['settings'] = array(
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
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_ngss_disciplinary']['field_api_classes'] = TRUE;
  /* Field: Content: Energy Content */
  $handler->display->display_options['fields']['field_activity_energy_content']['id'] = 'field_activity_energy_content';
  $handler->display->display_options['fields']['field_activity_energy_content']['table'] = 'field_data_field_activity_energy_content';
  $handler->display->display_options['fields']['field_activity_energy_content']['field'] = 'field_activity_energy_content';
  $handler->display->display_options['fields']['field_activity_energy_content']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_energy_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_energy_content']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_energy_content']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_energy_content']['settings'] = array(
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
  $handler->display->display_options['fields']['field_activity_energy_content']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_energy_content']['field_api_classes'] = TRUE;
  /* Field: Content: Pedagogy & Practice */
  $handler->display->display_options['fields']['field_activity_education_science']['id'] = 'field_activity_education_science';
  $handler->display->display_options['fields']['field_activity_education_science']['table'] = 'field_data_field_activity_education_science';
  $handler->display->display_options['fields']['field_activity_education_science']['field'] = 'field_activity_education_science';
  $handler->display->display_options['fields']['field_activity_education_science']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_education_science']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_education_science']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_education_science']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_education_science']['settings'] = array(
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
  $handler->display->display_options['fields']['field_activity_education_science']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_education_science']['field_api_classes'] = TRUE;
  /* Field: Content: Learning Goal(s) */
  $handler->display->display_options['fields']['field_learning_goals_met']['id'] = 'field_learning_goals_met';
  $handler->display->display_options['fields']['field_learning_goals_met']['table'] = 'field_data_field_learning_goals_met';
  $handler->display->display_options['fields']['field_learning_goals_met']['field'] = 'field_learning_goals_met';
  $handler->display->display_options['fields']['field_learning_goals_met']['element_type'] = '0';
  $handler->display->display_options['fields']['field_learning_goals_met']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_learning_goals_met']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_learning_goals_met']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_learning_goals_met']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_learning_goals_met']['settings'] = array(
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
  $handler->display->display_options['fields']['field_learning_goals_met']['field_api_classes'] = TRUE;
  /* Field: Content: Estimated Activity Length */
  $handler->display->display_options['fields']['field_activity_length2']['id'] = 'field_activity_length2';
  $handler->display->display_options['fields']['field_activity_length2']['table'] = 'field_data_field_activity_length2';
  $handler->display->display_options['fields']['field_activity_length2']['field'] = 'field_activity_length2';
  $handler->display->display_options['fields']['field_activity_length2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_length2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_length2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_length2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_length2']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  $handler->display->display_options['fields']['field_activity_length2']['field_api_classes'] = TRUE;
  /* Field: Content: Science Kit Material(s) Used */
  $handler->display->display_options['fields']['field_science_kit_materials_used']['id'] = 'field_science_kit_materials_used';
  $handler->display->display_options['fields']['field_science_kit_materials_used']['table'] = 'field_data_field_science_kit_materials_used';
  $handler->display->display_options['fields']['field_science_kit_materials_used']['field'] = 'field_science_kit_materials_used';
  $handler->display->display_options['fields']['field_science_kit_materials_used']['element_type'] = '0';
  $handler->display->display_options['fields']['field_science_kit_materials_used']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_science_kit_materials_used']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_science_kit_materials_used']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_science_kit_materials_used']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
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
  $handler->display->display_options['fields']['field_science_kit_materials_used']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_science_kit_materials_used']['field_api_classes'] = TRUE;
  /* Field: Content: Other Material(s) Used */
  $handler->display->display_options['fields']['field_other_materials_used']['id'] = 'field_other_materials_used';
  $handler->display->display_options['fields']['field_other_materials_used']['table'] = 'field_data_field_other_materials_used';
  $handler->display->display_options['fields']['field_other_materials_used']['field'] = 'field_other_materials_used';
  $handler->display->display_options['fields']['field_other_materials_used']['element_type'] = '0';
  $handler->display->display_options['fields']['field_other_materials_used']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_other_materials_used']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_other_materials_used']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_other_materials_used']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_other_materials_used']['settings'] = array(
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
  $handler->display->display_options['fields']['field_other_materials_used']['field_api_classes'] = TRUE;
  /* Field: Content: Lesson Plan Extensions for this Activity */
  $handler->display->display_options['fields']['field_activity_extensions']['id'] = 'field_activity_extensions';
  $handler->display->display_options['fields']['field_activity_extensions']['table'] = 'field_data_field_activity_extensions';
  $handler->display->display_options['fields']['field_activity_extensions']['field'] = 'field_activity_extensions';
  $handler->display->display_options['fields']['field_activity_extensions']['element_type'] = '0';
  $handler->display->display_options['fields']['field_activity_extensions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_extensions']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_activity_extensions']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_extensions']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_activity_extensions']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_activity_extensions']['settings'] = array(
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
  $handler->display->display_options['fields']['field_activity_extensions']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_extensions']['field_api_classes'] = TRUE;
  /* Field: Content: Files Associated with this Activity */
  $handler->display->display_options['fields']['field_file_downloads']['id'] = 'field_file_downloads';
  $handler->display->display_options['fields']['field_file_downloads']['table'] = 'field_data_field_file_downloads';
  $handler->display->display_options['fields']['field_file_downloads']['field'] = 'field_file_downloads';
  $handler->display->display_options['fields']['field_file_downloads']['element_type'] = '0';
  $handler->display->display_options['fields']['field_file_downloads']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_downloads']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_file_downloads']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_file_downloads']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_downloads']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_downloads']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_downloads']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_file_downloads']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'activity' => 'activity',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_unit_title' => 'field_unit_title',
    'field_lesson_number' => 'field_lesson_number',
    'field_subject_area_s_' => 'field_subject_area_s_',
    'field_activity_other_subjects' => 'field_activity_other_subjects',
    'field_common_core_standard_s_met' => 'field_common_core_standard_s_met',
    'field_next_generation_science_st' => 'field_next_generation_science_st',
    'field_activity_ngss_science' => 'field_activity_ngss_science',
    'field_activity_ngss_disciplinary' => 'field_activity_ngss_disciplinary',
    'field_activity_energy_content' => 'field_activity_energy_content',
    'field_activity_education_science' => 'field_activity_education_science',
    'field_learning_goals_met' => 'field_learning_goals_met',
    'field_grade_levels' => 'field_grade_levels',
    'field_activity_length2' => 'field_activity_length2',
    'field_activity_extensions' => 'field_activity_extensions',
    'field_science_kit_materials_used' => 'field_science_kit_materials_used',
    'field_other_materials_used' => 'field_other_materials_used',
    'field_file_downloads' => 'field_file_downloads',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_unit_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lesson_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subject_area_s_' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_other_subjects' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_common_core_standard_s_met' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_next_generation_science_st' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_ngss_science' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_ngss_disciplinary' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_energy_content' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_education_science' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_learning_goals_met' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grade_levels' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_length2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_extensions' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_science_kit_materials_used' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_other_materials_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_downloads' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'api/activity-node-export';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'api/activity-node-export/activity-node-export.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['activity_node_export'] = $view;

  $view = new view();
  $view->name = 'article_categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Article Categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'article_categories' => 'article_categories',
  );
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
    'articles' => 'articles',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'pane_article_categories');
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'user',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID',
    ),
  );
  $export['article_categories'] = $view;

  $view = new view();
  $view->name = 'science_kits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Science Kits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Newest Science Kit materials';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'science_kit' => 'science_kit',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Newest science kits */
  $handler = $view->new_display('panel_pane', 'Newest science kits', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'The latest created science kits';
  $export['science_kits'] = $view;

  $view = new view();
  $view->name = 'teacher_activity_center';
  $view->description = 'Search view to power the Teacher Activity Center based on Activities Solr index.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_activities';
  $view->human_name = 'Teacher Activity Center';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teacher Activity Center';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['preserve_facet_query_args'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Apply Keyword';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset All Filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_unit_title' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'activity_center';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results were found. <a href="/teach/teacher-activity-center">Click here</a> to restart search.';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_activities';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Unit: Name (indexed) */
  $handler->display->display_options['sorts']['field_unit_title_name']['id'] = 'field_unit_title_name';
  $handler->display->display_options['sorts']['field_unit_title_name']['table'] = 'search_api_index_activities';
  $handler->display->display_options['sorts']['field_unit_title_name']['field'] = 'field_unit_title_name';
  /* Sort criterion: Indexed Node: Sort by Lesson Number */
  $handler->display->display_options['sorts']['sort_field_lesson_number']['id'] = 'sort_field_lesson_number';
  $handler->display->display_options['sorts']['sort_field_lesson_number']['table'] = 'search_api_index_activities';
  $handler->display->display_options['sorts']['sort_field_lesson_number']['field'] = 'sort_field_lesson_number';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_activities';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_activities';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'activity' => 'activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_activities';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_activities';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword(s) or Phrase';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
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
  /* Filter criterion: Hidden via CSS. Triggers Chosen JS. */
  $handler->display->display_options['filters']['field_unit_title']['id'] = 'field_unit_title';
  $handler->display->display_options['filters']['field_unit_title']['table'] = 'search_api_index_activities';
  $handler->display->display_options['filters']['field_unit_title']['field'] = 'field_unit_title';
  $handler->display->display_options['filters']['field_unit_title']['ui_name'] = 'Hidden via CSS. Triggers Chosen JS.';
  $handler->display->display_options['filters']['field_unit_title']['value'] = array();
  $handler->display->display_options['filters']['field_unit_title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_unit_title']['expose']['operator_id'] = 'field_unit_title_op';
  $handler->display->display_options['filters']['field_unit_title']['expose']['label'] = 'Unit';
  $handler->display->display_options['filters']['field_unit_title']['expose']['operator'] = 'field_unit_title_op';
  $handler->display->display_options['filters']['field_unit_title']['expose']['identifier'] = 'field_unit_title';
  $handler->display->display_options['filters']['field_unit_title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_unit_title']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_unit_title']['type'] = 'select';

  /* Display: Search pane */
  $handler = $view->new_display('panel_pane', 'Search pane', 'panel_pane_search');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['teacher_activity_center'] = $view;

  return $export;
}
