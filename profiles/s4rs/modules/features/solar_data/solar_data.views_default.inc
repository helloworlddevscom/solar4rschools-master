<?php
/**
 * @file
 * solar_data.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solar_data_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'manage_equivalencies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_equivalencies_statistics';
  $view->human_name = 'Manage Equivalencies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage equivalencies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Equivalencies/Statistics */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Edit';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_add_widget_to_all_projects' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Equivalencies/Statistics: Rendered Equivalencies/Statistics */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_equivalencies_statistics';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Data';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Equivalencies/Statistics: Widget categories */
  $handler->display->display_options['fields']['field_widget_categories']['id'] = 'field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['field'] = 'field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['label'] = 'Category';
  $handler->display->display_options['fields']['field_widget_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_widget_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_widget_categories']['settings'] = array(
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
  $handler->display->display_options['fields']['field_widget_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['field_api_classes'] = TRUE;
  /* Field: Equivalencies/Statistics: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Field: Equivalencies/Statistics: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  /* Filter criterion: Equivalencies/Statistics: Widget categories (field_widget_categories) */
  $handler->display->display_options['filters']['field_widget_categories_tid']['id'] = 'field_widget_categories_tid';
  $handler->display->display_options['filters']['field_widget_categories_tid']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['filters']['field_widget_categories_tid']['field'] = 'field_widget_categories_tid';
  $handler->display->display_options['filters']['field_widget_categories_tid']['value'] = array(
    14 => '14',
    3 => '3',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['filters']['field_widget_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_widget_categories_tid']['vocabulary'] = 'widget_types';

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'page_1');
  $handler->display->display_options['path'] = 'admin/structure/entity-type/equivalencies_statistics/equivalencies_statistics/bulk-add/projects';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['description'] = 'Add Equivelencies to all projects at once';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Bulk add';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Funders */
  $handler = $view->new_display('page', 'Funders', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Equivalencies/Statistics */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Edit';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::solar_data_add_widget_to_all_funders' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Equivalencies/Statistics: Rendered Equivalencies/Statistics */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_equivalencies_statistics';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Data';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Equivalencies/Statistics: Widget categories */
  $handler->display->display_options['fields']['field_widget_categories']['id'] = 'field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['field'] = 'field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['label'] = 'Category';
  $handler->display->display_options['fields']['field_widget_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_widget_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_widget_categories']['settings'] = array(
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
  $handler->display->display_options['fields']['field_widget_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['field_api_classes'] = TRUE;
  /* Field: Equivalencies/Statistics: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Field: Equivalencies/Statistics: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Equivalencies/Statistics: Widget categories (field_widget_categories) */
  $handler->display->display_options['filters']['field_widget_categories_tid']['id'] = 'field_widget_categories_tid';
  $handler->display->display_options['filters']['field_widget_categories_tid']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['filters']['field_widget_categories_tid']['field'] = 'field_widget_categories_tid';
  $handler->display->display_options['filters']['field_widget_categories_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_widget_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_widget_categories_tid']['vocabulary'] = 'widget_types';
  $handler->display->display_options['path'] = 'admin/structure/entity-type/equivalencies_statistics/equivalencies_statistics/bulk-add/funders';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Funders';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['manage_equivalencies'] = $view;

  $view = new view();
  $view->name = 'widgets_selects';
  $view->description = 'Shown as fields so empty calculations can hide icons and titles.';
  $view->tag = 'default';
  $view->base_table = 'eck_equivalencies_statistics';
  $view->human_name = 'Widgets selects';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Equivalencies/Statistics: Widget categories (field_widget_categories) */
  $handler->display->display_options['relationships']['field_widget_categories_tid']['id'] = 'field_widget_categories_tid';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['field'] = 'field_widget_categories_tid';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['label'] = 'Term';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['required'] = TRUE;
  /* Field: Equivalencies/Statistics: Widget categories */
  $handler->display->display_options['fields']['field_widget_categories']['id'] = 'field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['field'] = 'field_widget_categories';
  $handler->display->display_options['fields']['field_widget_categories']['label'] = '';
  $handler->display->display_options['fields']['field_widget_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_widget_categories']['settings'] = array(
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
  $handler->display->display_options['fields']['field_widget_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_widget_categories']['field_api_classes'] = TRUE;
  /* Field: Equivalencies/Statistics: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_widget_categories_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Filter criterion: Equivalencies/Statistics: equivalencies_statistics type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'equivalencies_statistics' => 'equivalencies_statistics',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_widget_categories',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_widget_categories' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_widget_categories' => 'field_widget_categories',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: A project's widgets */
  $handler = $view->new_display('panel_pane', 'A project\'s widgets', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'This view is intended to be displayed in a pane on a project node.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Equivalencies/Statistics: Widget categories (field_widget_categories) */
  $handler->display->display_options['relationships']['field_widget_categories_tid']['id'] = 'field_widget_categories_tid';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['field'] = 'field_widget_categories_tid';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['label'] = 'Term';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_show_realtime_node']['id'] = 'reverse_field_show_realtime_node';
  $handler->display->display_options['relationships']['reverse_field_show_realtime_node']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['relationships']['reverse_field_show_realtime_node']['field'] = 'reverse_field_show_realtime_node';
  $handler->display->display_options['relationships']['reverse_field_show_realtime_node']['label'] = 'Project node';
  $handler->display->display_options['relationships']['reverse_field_show_realtime_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Equivalencies/Statistics: Equivalency icon */
  $handler->display->display_options['fields']['field_equivalency_icon']['id'] = 'field_equivalency_icon';
  $handler->display->display_options['fields']['field_equivalency_icon']['table'] = 'field_data_field_equivalency_icon';
  $handler->display->display_options['fields']['field_equivalency_icon']['field'] = 'field_equivalency_icon';
  $handler->display->display_options['fields']['field_equivalency_icon']['label'] = '';
  $handler->display->display_options['fields']['field_equivalency_icon']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_equivalency_icon']['element_type'] = '0';
  $handler->display->display_options['fields']['field_equivalency_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_equivalency_icon']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_equivalency_icon']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_equivalency_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_equivalency_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
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
  $handler->display->display_options['fields']['field_equivalency_icon']['field_api_classes'] = TRUE;
  /* Field: Equivalencies/Statistics: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Equivalencies/Statistics: Calculation source */
  $handler->display->display_options['fields']['field_calculation_source2']['id'] = 'field_calculation_source2';
  $handler->display->display_options['fields']['field_calculation_source2']['table'] = 'field_data_field_calculation_source2';
  $handler->display->display_options['fields']['field_calculation_source2']['field'] = 'field_calculation_source2';
  $handler->display->display_options['fields']['field_calculation_source2']['label'] = '';
  $handler->display->display_options['fields']['field_calculation_source2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_calculation_source2']['alter']['text'] = '[field_equivalency_icon] [title] [field_calculation_source2]';
  $handler->display->display_options['fields']['field_calculation_source2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_calculation_source2']['element_class'] = 'widget-item';
  $handler->display->display_options['fields']['field_calculation_source2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calculation_source2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_calculation_source2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_calculation_source2']['click_sort_column'] = 'source';
  $handler->display->display_options['fields']['field_calculation_source2']['settings'] = array(
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
  $handler->display->display_options['fields']['field_calculation_source2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_calculation_source2']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_widget_categories_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_show_realtime_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Equivalencies/Statistics: equivalencies_statistics type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'equivalencies_statistics' => 'equivalencies_statistics',
  );
  /* Filter criterion: Content: Data collection site (field_data_collection_site) */
  $handler->display->display_options['filters']['field_data_collection_site_target_id']['id'] = 'field_data_collection_site_target_id';
  $handler->display->display_options['filters']['field_data_collection_site_target_id']['table'] = 'field_data_field_data_collection_site';
  $handler->display->display_options['filters']['field_data_collection_site_target_id']['field'] = 'field_data_collection_site_target_id';
  $handler->display->display_options['filters']['field_data_collection_site_target_id']['relationship'] = 'reverse_field_show_realtime_node';
  $handler->display->display_options['filters']['field_data_collection_site_target_id']['operator'] = 'not empty';
  $handler->display->display_options['argument_input'] = array(
    'name' => array(
      'type' => 'user',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Widget category',
    ),
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Funder Widgets */
  $handler = $view->new_display('panel_pane', 'Funder Widgets', 'funder_widgets');
  $handler->display->display_options['display_description'] = 'This view is intended to be displayed in a pane on a funder details page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_show_widgets_node']['id'] = 'reverse_field_show_widgets_node';
  $handler->display->display_options['relationships']['reverse_field_show_widgets_node']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['relationships']['reverse_field_show_widgets_node']['field'] = 'reverse_field_show_widgets_node';
  $handler->display->display_options['relationships']['reverse_field_show_widgets_node']['label'] = 'Funder profile';
  $handler->display->display_options['relationships']['reverse_field_show_widgets_node']['required'] = TRUE;
  /* Relationship: Equivalencies/Statistics: Widget categories (field_widget_categories) */
  $handler->display->display_options['relationships']['field_widget_categories_tid']['id'] = 'field_widget_categories_tid';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['table'] = 'field_data_field_widget_categories';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['field'] = 'field_widget_categories_tid';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['label'] = 'Term';
  $handler->display->display_options['relationships']['field_widget_categories_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Equivalencies/Statistics: Equivalency icon */
  $handler->display->display_options['fields']['field_equivalency_icon']['id'] = 'field_equivalency_icon';
  $handler->display->display_options['fields']['field_equivalency_icon']['table'] = 'field_data_field_equivalency_icon';
  $handler->display->display_options['fields']['field_equivalency_icon']['field'] = 'field_equivalency_icon';
  $handler->display->display_options['fields']['field_equivalency_icon']['label'] = '';
  $handler->display->display_options['fields']['field_equivalency_icon']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_equivalency_icon']['element_type'] = '0';
  $handler->display->display_options['fields']['field_equivalency_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_equivalency_icon']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_equivalency_icon']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_equivalency_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_equivalency_icon']['settings'] = array(
    'image_style' => 'icon',
    'image_link' => '',
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
  $handler->display->display_options['fields']['field_equivalency_icon']['field_api_classes'] = TRUE;
  /* Field: Equivalencies/Statistics: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_equivalencies_statistics';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Equivalencies/Statistics: Calculation source */
  $handler->display->display_options['fields']['field_calculation_source2']['id'] = 'field_calculation_source2';
  $handler->display->display_options['fields']['field_calculation_source2']['table'] = 'field_data_field_calculation_source2';
  $handler->display->display_options['fields']['field_calculation_source2']['field'] = 'field_calculation_source2';
  $handler->display->display_options['fields']['field_calculation_source2']['label'] = '';
  $handler->display->display_options['fields']['field_calculation_source2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_calculation_source2']['alter']['text'] = '[field_equivalency_icon] [title] [field_calculation_source2]';
  $handler->display->display_options['fields']['field_calculation_source2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_calculation_source2']['element_class'] = 'widget-item';
  $handler->display->display_options['fields']['field_calculation_source2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calculation_source2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_calculation_source2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_calculation_source2']['click_sort_column'] = 'source';
  $handler->display->display_options['fields']['field_calculation_source2']['settings'] = array(
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
  $handler->display->display_options['fields']['field_calculation_source2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_calculation_source2']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_widget_categories_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_show_widgets_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'name' => array(
      'type' => 'user',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Widget category',
    ),
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['widgets_selects'] = $view;

  return $export;
}
