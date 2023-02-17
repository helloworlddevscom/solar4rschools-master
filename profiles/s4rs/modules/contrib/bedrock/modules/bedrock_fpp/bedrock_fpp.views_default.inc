<?php
/**
 * @file
 * bedrock_fpp.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bedrock_fpp_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bedrock_fpp_slide_search';
  $view->description = 'Search view for slides';
  $view->tag = 'default';
  $view->base_table = 'fieldable_panels_panes';
  $view->human_name = 'Search for slides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit fieldable fieldable_panels_pane';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'footable';
  /* Field: Fieldable pane: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Fieldable panel pane: Slide image */
  $handler->display->display_options['fields']['field_slideshow_slide_image']['id'] = 'field_slideshow_slide_image';
  $handler->display->display_options['fields']['field_slideshow_slide_image']['table'] = 'field_data_field_slideshow_slide_image';
  $handler->display->display_options['fields']['field_slideshow_slide_image']['field'] = 'field_slideshow_slide_image';
  $handler->display->display_options['fields']['field_slideshow_slide_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_slideshow_slide_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_slide_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_slide_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slideshow_slide_image']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
  );
  /* Field: Fieldable pane: Fieldable pane ID */
  $handler->display->display_options['fields']['fpid']['id'] = 'fpid';
  $handler->display->display_options['fields']['fpid']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['fpid']['field'] = 'fpid';
  $handler->display->display_options['fields']['fpid']['exclude'] = TRUE;
  /* Field: Fieldable panel pane: Link */
  $handler->display->display_options['fields']['field_slideshow_slide_link']['id'] = 'field_slideshow_slide_link';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['table'] = 'field_data_field_slideshow_slide_link';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['field'] = 'field_slideshow_slide_link';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_slide_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_slideshow_slide_link']['field_api_classes'] = TRUE;
  /* Filter criterion: Fieldable pane: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'slide' => 'slide',
  );

  /* Display: Reference dialog Search */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['attach'] = array(
    0 => 'fieldable_panels_pane:field_slideshow_slide:slideshow',
  );
  $export['bedrock_fpp_slide_search'] = $view;

  return $export;
}
