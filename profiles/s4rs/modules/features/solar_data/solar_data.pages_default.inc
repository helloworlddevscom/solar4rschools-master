<?php
/**
 * @file
 * solar_data.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_data_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'funder_widget';
  $page->task = 'page';
  $page->admin_title = 'Funder widget';
  $page->admin_description = 'List of widgets for a given project';
  $page->path = 'user/%user/widget';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Widgets',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
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
  $handler->name = 'page_funder_widget_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'funder_widget';
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
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'funder',
        'context' => 'argument_entity_id:user_1',
        'id' => 1,
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'slate';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '90c7dd2c-f714-400b-b967-641504f45f00';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_funder_widget_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cbdce59b-fac6-41cb-945b-afd051765000';
  $pane->panel = 'main_content';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'This funder\'s reach',
    ),
    'context' => array(
      1 => 'relationship_profile2_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cbdce59b-fac6-41cb-945b-afd051765000';
  $display->content['new-cbdce59b-fac6-41cb-945b-afd051765000'] = $pane;
  $display->panels['main_content'][0] = 'new-cbdce59b-fac6-41cb-945b-afd051765000';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['funder_widget'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'node_widget';
  $page->task = 'page';
  $page->admin_title = 'Node widget';
  $page->admin_description = 'List of widgets for a given project';
  $page->path = 'node/%node/widget';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'project' => 'project',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Widgets',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_node_widget_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'node_widget';
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
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'slate';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '90c7dd2c-f714-400b-b967-641504f45f00';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_node_widget_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f8839c3b-f69e-405e-be86-dffbf5d6266d';
  $pane->panel = 'main_content';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'Real-time data',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'widget',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f8839c3b-f69e-405e-be86-dffbf5d6266d';
  $display->content['new-f8839c3b-f69e-405e-be86-dffbf5d6266d'] = $pane;
  $display->panels['main_content'][0] = 'new-f8839c3b-f69e-405e-be86-dffbf5d6266d';
  $pane = new stdClass();
  $pane->pid = 'new-69fbee6f-230b-49a0-8d7c-bda5d31b6b02';
  $pane->panel = 'main_content';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'System lifetime data',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'widget',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '69fbee6f-230b-49a0-8d7c-bda5d31b6b02';
  $display->content['new-69fbee6f-230b-49a0-8d7c-bda5d31b6b02'] = $pane;
  $display->panels['main_content'][1] = 'new-69fbee6f-230b-49a0-8d7c-bda5d31b6b02';
  $pane = new stdClass();
  $pane->pid = 'new-0befb603-43d4-4755-83e0-04e64e1cc0b1';
  $pane->panel = 'main_content';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'System specs',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'widget',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0befb603-43d4-4755-83e0-04e64e1cc0b1';
  $display->content['new-0befb603-43d4-4755-83e0-04e64e1cc0b1'] = $pane;
  $display->panels['main_content'][2] = 'new-0befb603-43d4-4755-83e0-04e64e1cc0b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['node_widget'] = $page;

  return $pages;

}
