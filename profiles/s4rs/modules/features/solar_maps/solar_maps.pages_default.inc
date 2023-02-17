<?php
/**
 * @file
 * solar_maps.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_maps_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clean_energy_fellowship';
  $page->task = 'page';
  $page->admin_title = 'Clean Energy Fellowship';
  $page->admin_description = '';
  $page->path = 'clean-energy-fellowship';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clean_energy_fellowship__panel_context_a04150d2-6ba4-4e10-94ef-307aec74ba00';
  $handler->task = 'page';
  $handler->subtask = 'clean_energy_fellowship';
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
  $display->layout = 'comendite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Clean Energy Fellowship';
  $display->uuid = 'f1b6c5b5-bde5-4178-b4c8-4f669ad262e0';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_clean_energy_fellowship__panel_context_a04150d2-6ba4-4e10-94ef-307aec74ba00';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-166a11d2-8339-4f5d-be43-b4c81a87938c';
  $pane->panel = 'content_header';
  $pane->type = 'block';
  $pane->subtype = 'block-4';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane--clean-energy-fellowship-iframe',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '166a11d2-8339-4f5d-be43-b4c81a87938c';
  $display->content['new-166a11d2-8339-4f5d-be43-b4c81a87938c'] = $pane;
  $display->panels['content_header'][0] = 'new-166a11d2-8339-4f5d-be43-b4c81a87938c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clean_energy_fellowship'] = $page;

  return $pages;

}
