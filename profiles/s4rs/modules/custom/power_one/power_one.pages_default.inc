<?php
/**
 * @file
 * power_one.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function power_one_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'node_descendents_refresh';
  $page->task = 'page';
  $page->admin_title = 'Node descendents refresh';
  $page->admin_description = '';
  $page->path = 'generation_site/power_one/%generation_site/refresh';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_bundle:generation_site',
        'settings' => array(
          'type' => array(
            'power_one' => 'power_one',
          ),
        ),
        'context' => 'argument_entity_id:generation_site_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Refresh data',
    'name' => 'navigation',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'generation_site' => array(
      'id' => 1,
      'identifier' => 'Generation Site: ID',
      'name' => 'entity_id:generation_site',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_node_descendents_refresh_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'node_descendents_refresh';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'eck edit generation_site power_one entities',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Refresh "%generation_site:title" descendent data?';
  $display->uuid = 'd6987f3d-4a3d-4382-92aa-81173227ec3a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_node_descendents_refresh_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-92072f9b-5dd4-4e9b-876d-570a7bc7d245';
  $pane->panel = 'first';
  $pane->type = 'pow_refresh';
  $pane->subtype = 'pow_refresh';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:generation_site_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '92072f9b-5dd4-4e9b-876d-570a7bc7d245';
  $display->content['new-92072f9b-5dd4-4e9b-876d-570a7bc7d245'] = $pane;
  $display->panels['first'][0] = 'new-92072f9b-5dd4-4e9b-876d-570a7bc7d245';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['node_descendents_refresh'] = $page;

  return $pages;

}
