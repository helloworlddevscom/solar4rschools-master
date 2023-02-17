<?php
/**
 * @file
 * solar_applications.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function solar_applications_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'title' => 'Apply section',
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
            'paths' => 'apply
apply/*',
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
  $display->storage_id = 'node_view_panel_context_4';
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
  $pane->pid = 'new-7b6aa1ab-7a2d-453d-b69e-a14f84094f93';
  $pane->panel = 'content_main_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:fec1131f-986a-4e4f-b185-05c0362da5c4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7b6aa1ab-7a2d-453d-b69e-a14f84094f93';
  $display->content['new-7b6aa1ab-7a2d-453d-b69e-a14f84094f93'] = $pane;
  $display->panels['content_main_column'][1] = 'new-7b6aa1ab-7a2d-453d-b69e-a14f84094f93';
  $pane = new stdClass();
  $pane->pid = 'new-bbefb457-41cf-469d-863d-b4be1503a416';
  $pane->panel = 'content_main_column';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:448e7b49-5d82-421e-859e-8ea31063fd2f';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'bbefb457-41cf-469d-863d-b4be1503a416';
  $display->content['new-bbefb457-41cf-469d-863d-b4be1503a416'] = $pane;
  $display->panels['content_main_column'][2] = 'new-bbefb457-41cf-469d-863d-b4be1503a416';
  $pane = new stdClass();
  $pane->pid = 'new-fb02d500-b5d9-4492-b247-e83110c17248';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_applications-panel_pane_1';
  $pane->shown = TRUE;
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
  $pane->uuid = 'fb02d500-b5d9-4492-b247-e83110c17248';
  $display->content['new-fb02d500-b5d9-4492-b247-e83110c17248'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-fb02d500-b5d9-4492-b247-e83110c17248';
  $pane = new stdClass();
  $pane->pid = 'new-2a764048-17f9-4253-a82d-ece7a47233e4';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Apply buttons',
    'title' => '',
    'body' => '<p><a href="/apply/start-new-application"><img alt="Start a new renewable school application" src="/profiles/s4rs/modules/features/solar_applications/application-button-images/rs-application-button.jpg" title="Start a new renewable school application"></a></p>',
    'format' => 'full_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2a764048-17f9-4253-a82d-ece7a47233e4';
  $display->content['new-2a764048-17f9-4253-a82d-ece7a47233e4'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-2a764048-17f9-4253-a82d-ece7a47233e4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_applications_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'my_applications_page';
  $page->task = 'page';
  $page->admin_title = 'My Applications page';
  $page->admin_description = '';
  $page->path = 'user/%user/my-applications';
  $page->access = array(
    'plugins' => array(
      2 => array(
        'name' => 'ruleset:can_see_project_tabs',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 7,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'My Applications',
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
      'keyword' => 'user',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_my_applications_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'my_applications_page';
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
  $display->title = '';
  $display->uuid = '648b663f-a6a3-4b7c-96a7-311ae4fb7da6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_my_applications_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a743a76b-cc99-41e5-a287-ace8153e0483';
  $pane->panel = 'first';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_applications-panel_pane_2';
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
  $pane->uuid = 'a743a76b-cc99-41e5-a287-ace8153e0483';
  $display->content['new-a743a76b-cc99-41e5-a287-ace8153e0483'] = $pane;
  $display->panels['first'][0] = 'new-a743a76b-cc99-41e5-a287-ace8153e0483';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['my_applications_page'] = $page;

  return $pages;

}
