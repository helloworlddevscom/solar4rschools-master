<?php
/**
 * @file
 * cebf_resources.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function cebf_resources_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_dec9f52b-c4b2-4a6f-9c2e-0fcd88db7b04';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Resource page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'resource' => 'resource',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
  $display->uuid = '2a9b6a2c-12bb-4e63-b7a2-d89d8fcc3522';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_dec9f52b-c4b2-4a6f-9c2e-0fcd88db7b04';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3975229b-5acf-40ca-b661-2d5821bd1c43';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '<none>',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3975229b-5acf-40ca-b661-2d5821bd1c43';
  $display->content['new-3975229b-5acf-40ca-b661-2d5821bd1c43'] = $pane;
  $display->panels['content_main_column'][0] = 'new-3975229b-5acf-40ca-b661-2d5821bd1c43';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3975229b-5acf-40ca-b661-2d5821bd1c43';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_dec9f52b-c4b2-4a6f-9c2e-0fcd88db7b04'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function cebf_resources_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'resource_library';
  $page->task = 'page';
  $page->admin_title = 'Resource Library';
  $page->admin_description = '';
  $page->path = 'learn/resource-library';
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
  $handler->name = 'page_resource_library__panel_context_ab765f61-195c-47e3-bdb2-0fa600d396a5';
  $handler->task = 'page';
  $handler->subtask = 'resource_library';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'comendite-left';
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
  $display->title = 'Resource Library';
  $display->uuid = '47f820c4-c6d3-411f-994a-cb1157892608';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_resource_library__panel_context_ab765f61-195c-47e3-bdb2-0fa600d396a5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-eb9cdf6b-913f-407a-ad99-1b737ad4a4c1';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'resource_library-panel_pane_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'eb9cdf6b-913f-407a-ad99-1b737ad4a4c1';
  $display->content['new-eb9cdf6b-913f-407a-ad99-1b737ad4a4c1'] = $pane;
  $display->panels['content_main_column'][0] = 'new-eb9cdf6b-913f-407a-ad99-1b737ad4a4c1';
  $pane = new stdClass();
  $pane->pid = 'new-6fad1324-e2bb-4d65-995a-5dd566ac7681';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'panels_mini';
  $pane->subtype = 'resource_library_sidebar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6fad1324-e2bb-4d65-995a-5dd566ac7681';
  $display->content['new-6fad1324-e2bb-4d65-995a-5dd566ac7681'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-6fad1324-e2bb-4d65-995a-5dd566ac7681';
  $pane = new stdClass();
  $pane->pid = 'new-f908df20-36d6-4fd9-8683-2018e1a3f44b';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'block';
  $pane->subtype = 'block-5';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f908df20-36d6-4fd9-8683-2018e1a3f44b';
  $display->content['new-f908df20-36d6-4fd9-8683-2018e1a3f44b'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-f908df20-36d6-4fd9-8683-2018e1a3f44b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['resource_library'] = $page;

  return $pages;

}
