<?php
/**
 * @file
 * solar_fund.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_fund_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'funding_partner_options';
  $page->task = 'page';
  $page->admin_title = 'Funding partner options';
  $page->admin_description = 'A page listing funding partner options.';
  $page->path = 'fund/funding-partner-options-and-benefits';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Funding Partner Options And Benefits',
    'name' => 'main-menu',
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
  $handler->name = 'page_funding_partner_options_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'funding_partner_options';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
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
  $display->title = 'Funding Partner Options';
  $display->uuid = '39303630-4616-458c-b656-b6182689ae14';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_funding_partner_options_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a628a525-714d-4138-ab8e-f6711bdcb921';
  $pane->panel = 'content_main_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:12';
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
  $pane->uuid = 'a628a525-714d-4138-ab8e-f6711bdcb921';
  $display->content['new-a628a525-714d-4138-ab8e-f6711bdcb921'] = $pane;
  $display->panels['content_main_column'][0] = 'new-a628a525-714d-4138-ab8e-f6711bdcb921';
  $pane = new stdClass();
  $pane->pid = 'new-6bd3b400-56bf-4a58-a76e-cc1d11621bd8';
  $pane->panel = 'content_main_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:13';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6bd3b400-56bf-4a58-a76e-cc1d11621bd8';
  $display->content['new-6bd3b400-56bf-4a58-a76e-cc1d11621bd8'] = $pane;
  $display->panels['content_main_column'][1] = 'new-6bd3b400-56bf-4a58-a76e-cc1d11621bd8';
  $pane = new stdClass();
  $pane->pid = 'new-e0ca6248-844d-4acf-8ac9-9774a9cbebf6';
  $pane->panel = 'content_main_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:14';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e0ca6248-844d-4acf-8ac9-9774a9cbebf6';
  $display->content['new-e0ca6248-844d-4acf-8ac9-9774a9cbebf6'] = $pane;
  $display->panels['content_main_column'][2] = 'new-e0ca6248-844d-4acf-8ac9-9774a9cbebf6';
  $pane = new stdClass();
  $pane->pid = 'new-971b829c-28e7-4fe8-b32a-e6bcbc6694c5';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:11';
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
  $pane->uuid = '971b829c-28e7-4fe8-b32a-e6bcbc6694c5';
  $display->content['new-971b829c-28e7-4fe8-b32a-e6bcbc6694c5'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-971b829c-28e7-4fe8-b32a-e6bcbc6694c5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['funding_partner_options'] = $page;

  return $pages;

}
