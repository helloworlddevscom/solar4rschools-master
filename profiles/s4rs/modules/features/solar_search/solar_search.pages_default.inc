<?php
/**
 * @file
 * solar_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_content';
  $page->task = 'page';
  $page->admin_title = 'Search content';
  $page->admin_description = 'Search results for node indexes';
  $page->path = 'search/projects';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Contents',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Search',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_content_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_content';
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
  $display->title = 'Search results';
  $display->uuid = '5be99528-7072-4558-a68b-21df5a00b105';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search_content_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f8853e9d-0716-4206-bdd1-10967f4e217a';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'node_search-panel_pane_6';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f8853e9d-0716-4206-bdd1-10967f4e217a';
  $display->content['new-f8853e9d-0716-4206-bdd1-10967f4e217a'] = $pane;
  $display->panels['content_main_column'][0] = 'new-f8853e9d-0716-4206-bdd1-10967f4e217a';
  $pane = new stdClass();
  $pane->pid = 'new-e1547476-c5ea-4de9-a09e-43cba9ff2fd4';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'user_recent_search';
  $pane->subtype = 'user_recent_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '3600',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e1547476-c5ea-4de9-a09e-43cba9ff2fd4';
  $display->content['new-e1547476-c5ea-4de9-a09e-43cba9ff2fd4'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-e1547476-c5ea-4de9-a09e-43cba9ff2fd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_content'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_funders';
  $page->task = 'page';
  $page->admin_title = 'Search Funders';
  $page->admin_description = 'Search results for node indexes';
  $page->path = 'search/funders';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Funders',
    'name' => 'navigation',
    'weight' => '1',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Search',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_funders_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_funders';
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
  $display->title = 'Search results';
  $display->uuid = '5be99528-7072-4558-a68b-21df5a00b105';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search_funders_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f6f86e86-9abb-4b77-92c0-d77907577103';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'funder_index-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f6f86e86-9abb-4b77-92c0-d77907577103';
  $display->content['new-f6f86e86-9abb-4b77-92c0-d77907577103'] = $pane;
  $display->panels['content_main_column'][0] = 'new-f6f86e86-9abb-4b77-92c0-d77907577103';
  $pane = new stdClass();
  $pane->pid = 'new-e1547476-c5ea-4de9-a09e-43cba9ff2fd4';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'user_recent_search';
  $pane->subtype = 'user_recent_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '3600',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e1547476-c5ea-4de9-a09e-43cba9ff2fd4';
  $display->content['new-e1547476-c5ea-4de9-a09e-43cba9ff2fd4'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-e1547476-c5ea-4de9-a09e-43cba9ff2fd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_funders'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solar_learning_center';
  $page->task = 'page';
  $page->admin_title = 'Solar Learning Center';
  $page->admin_description = 'A page to display and allow for the saving of various articles on solar-related topics.';
  $page->path = 'learn/!search';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Learn',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'search' => array(
      'id' => 1,
      'identifier' => 'Article search string',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solar_learning_center_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'solar_learning_center';
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
  $display->title = 'Teacher Learning Center';
  $display->uuid = '6360e0fc-7042-4bdc-b21f-57b55ccbe84d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solar_learning_center_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9fcd855e-bad1-4e22-bc09-1e04e0f2d9ff';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'node_search-panel_pane_7';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9fcd855e-bad1-4e22-bc09-1e04e0f2d9ff';
  $display->content['new-9fcd855e-bad1-4e22-bc09-1e04e0f2d9ff'] = $pane;
  $display->panels['content_main_column'][0] = 'new-9fcd855e-bad1-4e22-bc09-1e04e0f2d9ff';
  $pane = new stdClass();
  $pane->pid = 'new-220bb462-33ed-4930-a540-7e47e0f13df7';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_flags-panel_pane_2';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'uid' => '%user:uid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 0,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '220bb462-33ed-4930-a540-7e47e0f13df7';
  $display->content['new-220bb462-33ed-4930-a540-7e47e0f13df7'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-220bb462-33ed-4930-a540-7e47e0f13df7';
  $pane = new stdClass();
  $pane->pid = 'new-757f2e0d-0898-44d1-8043-cb1d61a2d647';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-field-articles-category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Teacher Learning Center Content',
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
  $pane->uuid = '757f2e0d-0898-44d1-8043-cb1d61a2d647';
  $display->content['new-757f2e0d-0898-44d1-8043-cb1d61a2d647'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-757f2e0d-0898-44d1-8043-cb1d61a2d647';
  $pane = new stdClass();
  $pane->pid = 'new-5ff93626-4852-4175-98fc-1962830903f7';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'user_recent_search';
  $pane->subtype = 'user_recent_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '15',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5ff93626-4852-4175-98fc-1962830903f7';
  $display->content['new-5ff93626-4852-4175-98fc-1962830903f7'] = $pane;
  $display->panels['content_secondary_column'][2] = 'new-5ff93626-4852-4175-98fc-1962830903f7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solar_learning_center'] = $page;

  return $pages;

}
