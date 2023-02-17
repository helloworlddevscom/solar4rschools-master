<?php
/**
 * @file
 * solar_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home page';
  $page->admin_description = 'The site\'s home page';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'menu-footer-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
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
  $handler->name = 'page_home_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Solar 4R Schools',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Token',
        'keyword' => 'token',
        'name' => 'token',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'jadeite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'column_left_top' => NULL,
      'column_middle_top' => NULL,
      'column_right_top' => NULL,
      'column_left_bottom' => NULL,
      'column_middle_bottom' => NULL,
      'column_right_bottom' => NULL,
      'content_header' => NULL,
    ),
    'style' => 'naked',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '10883df9-89db-47dc-aafe-cb005179feed';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2b0a7fef-20be-4ab0-b444-bc01af06bf05';
  $pane->panel = 'column_left_bottom';
  $pane->type = 'views';
  $pane->subtype = 'events_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_event_teaser',
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = '2b0a7fef-20be-4ab0-b444-bc01af06bf05';
  $display->content['new-2b0a7fef-20be-4ab0-b444-bc01af06bf05'] = $pane;
  $display->panels['column_left_bottom'][0] = 'new-2b0a7fef-20be-4ab0-b444-bc01af06bf05';
  $pane = new stdClass();
  $pane->pid = 'new-eaf69741-4c35-4cec-a755-032f961deeca';
  $pane->panel = 'column_left_bottom';
  $pane->type = 'views';
  $pane->subtype = 'events_list';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '8',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_events_list',
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = 'eaf69741-4c35-4cec-a755-032f961deeca';
  $display->content['new-eaf69741-4c35-4cec-a755-032f961deeca'] = $pane;
  $display->panels['column_left_bottom'][1] = 'new-eaf69741-4c35-4cec-a755-032f961deeca';
  $pane = new stdClass();
  $pane->pid = 'new-38cfb190-f849-4311-a68d-9b824486a15a';
  $pane->panel = 'column_left_bottom';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:4';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '38cfb190-f849-4311-a68d-9b824486a15a';
  $display->content['new-38cfb190-f849-4311-a68d-9b824486a15a'] = $pane;
  $display->panels['column_left_bottom'][2] = 'new-38cfb190-f849-4311-a68d-9b824486a15a';
  $pane = new stdClass();
  $pane->pid = 'new-2cced986-2981-4fcc-990b-685744094957';
  $pane->panel = 'column_left_top';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '60',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2cced986-2981-4fcc-990b-685744094957';
  $display->content['new-2cced986-2981-4fcc-990b-685744094957'] = $pane;
  $display->panels['column_left_top'][0] = 'new-2cced986-2981-4fcc-990b-685744094957';
  $pane = new stdClass();
  $pane->pid = 'new-2842a676-631f-44c6-9a35-5ae5c8d38e8e';
  $pane->panel = 'column_middle_bottom';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:c396ee56-e189-497c-a451-161867626a34';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2842a676-631f-44c6-9a35-5ae5c8d38e8e';
  $display->content['new-2842a676-631f-44c6-9a35-5ae5c8d38e8e'] = $pane;
  $display->panels['column_middle_bottom'][0] = 'new-2842a676-631f-44c6-9a35-5ae5c8d38e8e';
  $pane = new stdClass();
  $pane->pid = 'new-dac31612-c057-40ab-9f83-f778f5f13de0';
  $pane->panel = 'column_middle_top';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '60',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'dac31612-c057-40ab-9f83-f778f5f13de0';
  $display->content['new-dac31612-c057-40ab-9f83-f778f5f13de0'] = $pane;
  $display->panels['column_middle_top'][0] = 'new-dac31612-c057-40ab-9f83-f778f5f13de0';
  $pane = new stdClass();
  $pane->pid = 'new-c12e1071-d07c-4dc0-a5fb-1fe8ac09011c';
  $pane->panel = 'column_right_bottom';
  $pane->type = 'block';
  $pane->subtype = 'solar_core-twitter';
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
  $pane->uuid = 'c12e1071-d07c-4dc0-a5fb-1fe8ac09011c';
  $display->content['new-c12e1071-d07c-4dc0-a5fb-1fe8ac09011c'] = $pane;
  $display->panels['column_right_bottom'][0] = 'new-c12e1071-d07c-4dc0-a5fb-1fe8ac09011c';
  $pane = new stdClass();
  $pane->pid = 'new-3f87d327-acb2-4fc4-92e2-0665085e00f0';
  $pane->panel = 'column_right_bottom';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:6';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3f87d327-acb2-4fc4-92e2-0665085e00f0';
  $display->content['new-3f87d327-acb2-4fc4-92e2-0665085e00f0'] = $pane;
  $display->panels['column_right_bottom'][1] = 'new-3f87d327-acb2-4fc4-92e2-0665085e00f0';
  $pane = new stdClass();
  $pane->pid = 'new-7ee26bf3-0767-46dc-a69b-2532bdefde9c';
  $pane->panel = 'column_right_top';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '60',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7ee26bf3-0767-46dc-a69b-2532bdefde9c';
  $display->content['new-7ee26bf3-0767-46dc-a69b-2532bdefde9c'] = $pane;
  $display->panels['column_right_top'][0] = 'new-7ee26bf3-0767-46dc-a69b-2532bdefde9c';
  $pane = new stdClass();
  $pane->pid = 'new-69b8a223-b459-40ac-9407-1eb46bf6260e';
  $pane->panel = 'content_header';
  $pane->type = 'views';
  $pane->subtype = 'homepage_slideshow';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '69b8a223-b459-40ac-9407-1eb46bf6260e';
  $display->content['new-69b8a223-b459-40ac-9407-1eb46bf6260e'] = $pane;
  $display->panels['content_header'][0] = 'new-69b8a223-b459-40ac-9407-1eb46bf6260e';
  $pane = new stdClass();
  $pane->pid = 'new-52b66f2d-5d4c-4dfe-a2bc-c916195d240d';
  $pane->panel = 'content_header';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:23';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'slide',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '60',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '52b66f2d-5d4c-4dfe-a2bc-c916195d240d';
  $display->content['new-52b66f2d-5d4c-4dfe-a2bc-c916195d240d'] = $pane;
  $display->panels['content_header'][1] = 'new-52b66f2d-5d4c-4dfe-a2bc-c916195d240d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  return $pages;

}
