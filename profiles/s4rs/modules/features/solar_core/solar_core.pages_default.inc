<?php
/**
 * @file
 * solar_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function solar_core_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Basic page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'slate';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cdfd867a-852d-4ca1-b0c0-56e94abd1806';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $pane->panel = 'main_content';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $display->content['new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd'] = $pane;
  $display->panels['main_content'][0] = 'new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'About section',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'about
about/*
program-overview',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'comendite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e0f86d53-3dd4-4b2e-b52e-62a3b24205f4';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-76be6fa3-a772-43ce-9fbb-5eee69456c4a';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '76be6fa3-a772-43ce-9fbb-5eee69456c4a';
  $display->content['new-76be6fa3-a772-43ce-9fbb-5eee69456c4a'] = $pane;
  $display->panels['content_main_column'][0] = 'new-76be6fa3-a772-43ce-9fbb-5eee69456c4a';
  $pane = new stdClass();
  $pane->pid = 'new-bfd677f6-c71d-42ad-8cd7-393af05f57dc';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:a9006dff-b08b-4b94-a954-5adb5047406b';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'about-tout',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bfd677f6-c71d-42ad-8cd7-393af05f57dc';
  $display->content['new-bfd677f6-c71d-42ad-8cd7-393af05f57dc'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-bfd677f6-c71d-42ad-8cd7-393af05f57dc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'error_404';
  $page->task = 'page';
  $page->admin_title = 'error 404';
  $page->admin_description = '404 page';
  $page->path = 'error404';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_error_404_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'error_404';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sample_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'This page was not Found';
  $display->uuid = 'f714d73d-fbb3-4df0-a02d-8b08ae6e87e2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_error_404_panel_context';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['error_404'] = $page;

  return $pages;

}
