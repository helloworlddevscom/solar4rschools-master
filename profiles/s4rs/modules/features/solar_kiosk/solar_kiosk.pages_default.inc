<?php
/**
 * @file
 * solar_kiosk.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function solar_kiosk_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -4;
  $handler->conf = array(
    'title' => 'Kiosk Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Generation Site from Node (on Node: Data collection site [field_data_collection_site])',
        'keyword' => 'generation_site',
        'name' => 'entity_from_field:field_data_collection_site-node-generation_site',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cb67bd6b-ad80-4fb1-8422-fe7af76821ab';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fbc736af-7ecf-4230-9da1-cca0e0e73989';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = 'fbc736af-7ecf-4230-9da1-cca0e0e73989';
  $display->content['new-fbc736af-7ecf-4230-9da1-cca0e0e73989'] = $pane;
  $display->panels['content_footer'][0] = 'new-fbc736af-7ecf-4230-9da1-cca0e0e73989';
  $pane = new stdClass();
  $pane->pid = 'new-a1a4f7f5-02fb-459c-b3f6-a19f8156fe2c';
  $pane->panel = 'content_footer';
  $pane->type = 'views_panes';
  $pane->subtype = 'this_generation_site_s_projects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'relationship_entity_from_field:field_data_collection_site-node-generation_site_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a1a4f7f5-02fb-459c-b3f6-a19f8156fe2c';
  $display->content['new-a1a4f7f5-02fb-459c-b3f6-a19f8156fe2c'] = $pane;
  $display->panels['content_footer'][1] = 'new-a1a4f7f5-02fb-459c-b3f6-a19f8156fe2c';
  $pane = new stdClass();
  $pane->pid = 'new-9c32c84b-0661-45f0-9249-05a2368fa44c';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '9c32c84b-0661-45f0-9249-05a2368fa44c';
  $display->content['new-9c32c84b-0661-45f0-9249-05a2368fa44c'] = $pane;
  $display->panels['content_header'][0] = 'new-9c32c84b-0661-45f0-9249-05a2368fa44c';
  $pane = new stdClass();
  $pane->pid = 'new-860903f6-6d38-419c-a0b1-3f89d181300f';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '860903f6-6d38-419c-a0b1-3f89d181300f';
  $display->content['new-860903f6-6d38-419c-a0b1-3f89d181300f'] = $pane;
  $display->panels['content_header'][1] = 'new-860903f6-6d38-419c-a0b1-3f89d181300f';
  $pane = new stdClass();
  $pane->pid = 'new-32cd9069-b8a1-4fd4-a22f-560cddc78b64';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '32cd9069-b8a1-4fd4-a22f-560cddc78b64';
  $display->content['new-32cd9069-b8a1-4fd4-a22f-560cddc78b64'] = $pane;
  $display->panels['content_header'][2] = 'new-32cd9069-b8a1-4fd4-a22f-560cddc78b64';
  $pane = new stdClass();
  $pane->pid = 'new-3f756097-8145-4f66-985a-08dc516a9caf';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3f756097-8145-4f66-985a-08dc516a9caf';
  $display->content['new-3f756097-8145-4f66-985a-08dc516a9caf'] = $pane;
  $display->panels['content_header'][3] = 'new-3f756097-8145-4f66-985a-08dc516a9caf';
  $pane = new stdClass();
  $pane->pid = 'new-99a9dbb1-bc67-45c9-89fa-d076611dc58c';
  $pane->panel = 'content_suffix';
  $pane->type = 'site_summary';
  $pane->subtype = 'site_summary';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_data_collection_site-node-generation_site_1',
    'override_title' => 0,
    'override_title_text' => 'Environmental Benefits: Since Installation',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '99a9dbb1-bc67-45c9-89fa-d076611dc58c';
  $display->content['new-99a9dbb1-bc67-45c9-89fa-d076611dc58c'] = $pane;
  $display->panels['content_suffix'][0] = 'new-99a9dbb1-bc67-45c9-89fa-d076611dc58c';
  $pane = new stdClass();
  $pane->pid = 'new-b16ea414-0298-49cb-bae0-1cbaf163ab70';
  $pane->panel = 'main_content';
  $pane->type = 'site_equivalents';
  $pane->subtype = 'site_equivalents';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_data_collection_site-node-generation_site_1',
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
  $pane->uuid = 'b16ea414-0298-49cb-bae0-1cbaf163ab70';
  $display->content['new-b16ea414-0298-49cb-bae0-1cbaf163ab70'] = $pane;
  $display->panels['main_content'][0] = 'new-b16ea414-0298-49cb-bae0-1cbaf163ab70';
  $pane = new stdClass();
  $pane->pid = 'new-4a99e489-f5bc-44e2-b8ea-676516bdd062';
  $pane->panel = 'main_content';
  $pane->type = 'kiosk_charts';
  $pane->subtype = 'kiosk_charts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_data_collection_site-node-generation_site_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '86400',
      'granularity' => 'args',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4a99e489-f5bc-44e2-b8ea-676516bdd062';
  $display->content['new-4a99e489-f5bc-44e2-b8ea-676516bdd062'] = $pane;
  $display->panels['main_content'][1] = 'new-4a99e489-f5bc-44e2-b8ea-676516bdd062';
  $pane = new stdClass();
  $pane->pid = 'new-87585a42-d0a0-45c6-b3df-12c978fcc1d2';
  $pane->panel = 'main_content';
  $pane->type = 'weather';
  $pane->subtype = 'weather';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_data_collection_site-node-generation_site_1',
    'override_title' => 1,
    'override_title_text' => 'Weather',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '87585a42-d0a0-45c6-b3df-12c978fcc1d2';
  $display->content['new-87585a42-d0a0-45c6-b3df-12c978fcc1d2'] = $pane;
  $display->panels['main_content'][2] = 'new-87585a42-d0a0-45c6-b3df-12c978fcc1d2';
  $pane = new stdClass();
  $pane->pid = 'new-d41d47b8-419d-4615-b944-d2438c48f23a';
  $pane->panel = 'main_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_system_specs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:kiosk:field_system_specs',
        'settings' => array(
          'field_system_specs' => array(
            'und' => array(),
          ),
          'field_system_specs_value' => array(),
          'field_system_specs_format' => array(),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'System Specifications',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd41d47b8-419d-4615-b944-d2438c48f23a';
  $display->content['new-d41d47b8-419d-4615-b944-d2438c48f23a'] = $pane;
  $display->panels['main_content'][3] = 'new-d41d47b8-419d-4615-b944-d2438c48f23a';
  $pane = new stdClass();
  $pane->pid = 'new-a12250c6-8617-4a20-8358-afaf2ef83af1';
  $pane->panel = 'main_content';
  $pane->type = 'entity_view';
  $pane->subtype = 'generation_site';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:kiosk:field_system_specs',
        'settings' => array(
          'field_system_specs' => array(
            'und' => array(),
          ),
          'field_system_specs_value' => array(),
          'field_system_specs_format' => array(),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'view_mode' => 'teaser',
    'context' => 'relationship_entity_from_field:field_data_collection_site-node-generation_site_1',
    'override_title' => 1,
    'override_title_text' => 'System Specifications',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a12250c6-8617-4a20-8358-afaf2ef83af1';
  $display->content['new-a12250c6-8617-4a20-8358-afaf2ef83af1'] = $pane;
  $display->panels['main_content'][4] = 'new-a12250c6-8617-4a20-8358-afaf2ef83af1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_kiosk_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kiosk_about_partners';
  $page->task = 'page';
  $page->admin_title = 'Kiosk - About Partners';
  $page->admin_description = 'The "About Partners" page for kiosk displays.';
  $page->path = 'node/%node/about-partners';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'kiosk' => 'kiosk',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'About Partners',
    'name' => 'navigation',
    'weight' => '-17',
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
  $handler->name = 'page_kiosk_about_partners_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kiosk_about_partners';
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
        'identifier' => 'Kiosk Project (on Node: Project [field_kiosk_project])',
        'keyword' => 'Project',
        'name' => 'entity_from_field:field_kiosk_project-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content_header_left' => NULL,
      'content_header_right' => NULL,
      'content_main' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fad167f9-0fb7-4b9b-bcda-bfbeccec4c56';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kiosk_about_partners_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-941d24b6-94aa-478c-9525-12b3a433cba0';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '941d24b6-94aa-478c-9525-12b3a433cba0';
  $display->content['new-941d24b6-94aa-478c-9525-12b3a433cba0'] = $pane;
  $display->panels['content_footer'][0] = 'new-941d24b6-94aa-478c-9525-12b3a433cba0';
  $pane = new stdClass();
  $pane->pid = 'new-66e91511-ef53-4b97-af6c-1f58cbf20444';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '66e91511-ef53-4b97-af6c-1f58cbf20444';
  $display->content['new-66e91511-ef53-4b97-af6c-1f58cbf20444'] = $pane;
  $display->panels['content_footer'][1] = 'new-66e91511-ef53-4b97-af6c-1f58cbf20444';
  $pane = new stdClass();
  $pane->pid = 'new-10ce3239-7732-4a3f-aec6-ab6c46704f12';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '10ce3239-7732-4a3f-aec6-ab6c46704f12';
  $display->content['new-10ce3239-7732-4a3f-aec6-ab6c46704f12'] = $pane;
  $display->panels['content_header'][0] = 'new-10ce3239-7732-4a3f-aec6-ab6c46704f12';
  $pane = new stdClass();
  $pane->pid = 'new-cfed1c94-d5cc-4db7-9e24-3ccae3f7a45f';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'cfed1c94-d5cc-4db7-9e24-3ccae3f7a45f';
  $display->content['new-cfed1c94-d5cc-4db7-9e24-3ccae3f7a45f'] = $pane;
  $display->panels['content_header'][1] = 'new-cfed1c94-d5cc-4db7-9e24-3ccae3f7a45f';
  $pane = new stdClass();
  $pane->pid = 'new-ffbd841f-3f29-41f6-89b5-e5c654a75f45';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ffbd841f-3f29-41f6-89b5-e5c654a75f45';
  $display->content['new-ffbd841f-3f29-41f6-89b5-e5c654a75f45'] = $pane;
  $display->panels['content_header'][2] = 'new-ffbd841f-3f29-41f6-89b5-e5c654a75f45';
  $pane = new stdClass();
  $pane->pid = 'new-e0a2055b-dc5e-4a2f-a841-7193517d7047';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e0a2055b-dc5e-4a2f-a841-7193517d7047';
  $display->content['new-e0a2055b-dc5e-4a2f-a841-7193517d7047'] = $pane;
  $display->panels['content_header'][3] = 'new-e0a2055b-dc5e-4a2f-a841-7193517d7047';
  $pane = new stdClass();
  $pane->pid = 'new-884bc2dd-c575-457b-a05a-f16bea4ae19d';
  $pane->panel = 'content_prefix';
  $pane->type = 'block';
  $pane->subtype = 'blockify-blockify-messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '884bc2dd-c575-457b-a05a-f16bea4ae19d';
  $display->content['new-884bc2dd-c575-457b-a05a-f16bea4ae19d'] = $pane;
  $display->panels['content_prefix'][0] = 'new-884bc2dd-c575-457b-a05a-f16bea4ae19d';
  $pane = new stdClass();
  $pane->pid = 'new-8993456d-f1e1-4dc7-8f6b-d560c6341bdc';
  $pane->panel = 'content_suffix';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_about_partners_thx';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '8993456d-f1e1-4dc7-8f6b-d560c6341bdc';
  $display->content['new-8993456d-f1e1-4dc7-8f6b-d560c6341bdc'] = $pane;
  $display->panels['content_suffix'][0] = 'new-8993456d-f1e1-4dc7-8f6b-d560c6341bdc';
  $pane = new stdClass();
  $pane->pid = 'new-b2db2903-0813-464c-9b56-dda2941debde';
  $pane->panel = 'main_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_about_partners_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'b2db2903-0813-464c-9b56-dda2941debde';
  $display->content['new-b2db2903-0813-464c-9b56-dda2941debde'] = $pane;
  $display->panels['main_content'][0] = 'new-b2db2903-0813-464c-9b56-dda2941debde';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kiosk_about_partners'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kiosk_about_project';
  $page->task = 'page';
  $page->admin_title = 'Kiosk - About Project';
  $page->admin_description = 'The "About Project" page for kiosk displays.';
  $page->path = 'node/%node/about-project';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'kiosk' => 'kiosk',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'About Project',
    'name' => 'navigation',
    'weight' => '-18',
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
  $handler->name = 'page_kiosk_about_project_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kiosk_about_project';
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
        'identifier' => 'Kiosk Project (on Node: Project [field_kiosk_project])',
        'keyword' => 'Project',
        'name' => 'entity_from_field:field_kiosk_project-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content_header_left' => NULL,
      'content_header_right' => NULL,
      'content_main' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1e12ea08-96b7-4bb5-8ad2-bf8e21ee824c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kiosk_about_project_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d2a38260-0667-4bc2-9790-6d9a824609f8';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = 'd2a38260-0667-4bc2-9790-6d9a824609f8';
  $display->content['new-d2a38260-0667-4bc2-9790-6d9a824609f8'] = $pane;
  $display->panels['content_footer'][0] = 'new-d2a38260-0667-4bc2-9790-6d9a824609f8';
  $pane = new stdClass();
  $pane->pid = 'new-d19845eb-b173-4e19-a170-c78f0cbb916e';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd19845eb-b173-4e19-a170-c78f0cbb916e';
  $display->content['new-d19845eb-b173-4e19-a170-c78f0cbb916e'] = $pane;
  $display->panels['content_footer'][1] = 'new-d19845eb-b173-4e19-a170-c78f0cbb916e';
  $pane = new stdClass();
  $pane->pid = 'new-1dc4261f-4a80-4a73-a1fc-281509745d14';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '1dc4261f-4a80-4a73-a1fc-281509745d14';
  $display->content['new-1dc4261f-4a80-4a73-a1fc-281509745d14'] = $pane;
  $display->panels['content_header'][0] = 'new-1dc4261f-4a80-4a73-a1fc-281509745d14';
  $pane = new stdClass();
  $pane->pid = 'new-89dcd865-eab7-441e-9d28-6d829709df85';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '89dcd865-eab7-441e-9d28-6d829709df85';
  $display->content['new-89dcd865-eab7-441e-9d28-6d829709df85'] = $pane;
  $display->panels['content_header'][1] = 'new-89dcd865-eab7-441e-9d28-6d829709df85';
  $pane = new stdClass();
  $pane->pid = 'new-165424b1-f3eb-4941-8c28-fdf059d86a77';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '165424b1-f3eb-4941-8c28-fdf059d86a77';
  $display->content['new-165424b1-f3eb-4941-8c28-fdf059d86a77'] = $pane;
  $display->panels['content_header'][2] = 'new-165424b1-f3eb-4941-8c28-fdf059d86a77';
  $pane = new stdClass();
  $pane->pid = 'new-8203b8b8-849b-48bf-bd46-2af8140e7856';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '8203b8b8-849b-48bf-bd46-2af8140e7856';
  $display->content['new-8203b8b8-849b-48bf-bd46-2af8140e7856'] = $pane;
  $display->panels['content_header'][3] = 'new-8203b8b8-849b-48bf-bd46-2af8140e7856';
  $pane = new stdClass();
  $pane->pid = 'new-751dc382-9bf9-4028-ac8d-5e6a44f7c8ca';
  $pane->panel = 'content_prefix';
  $pane->type = 'block';
  $pane->subtype = 'blockify-blockify-messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '751dc382-9bf9-4028-ac8d-5e6a44f7c8ca';
  $display->content['new-751dc382-9bf9-4028-ac8d-5e6a44f7c8ca'] = $pane;
  $display->panels['content_prefix'][0] = 'new-751dc382-9bf9-4028-ac8d-5e6a44f7c8ca';
  $pane = new stdClass();
  $pane->pid = 'new-64852964-1e58-40d8-9894-a4e49ca65cbd';
  $pane->panel = 'main_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_about_project_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '64852964-1e58-40d8-9894-a4e49ca65cbd';
  $display->content['new-64852964-1e58-40d8-9894-a4e49ca65cbd'] = $pane;
  $display->panels['main_content'][0] = 'new-64852964-1e58-40d8-9894-a4e49ca65cbd';
  $pane = new stdClass();
  $pane->pid = 'new-55545314-cd3a-452f-a0bc-a7b8e7b3ed6f';
  $pane->panel = 'main_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_about_project_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'kiosk_about_project_image',
      'image_link' => '',
      'picture_group' => 'project_large',
      'fallback_image_style' => '',
      'colorbox' => 'homepage_callout',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '55545314-cd3a-452f-a0bc-a7b8e7b3ed6f';
  $display->content['new-55545314-cd3a-452f-a0bc-a7b8e7b3ed6f'] = $pane;
  $display->panels['main_content'][1] = 'new-55545314-cd3a-452f-a0bc-a7b8e7b3ed6f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kiosk_about_project'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kiosk_call_to_action';
  $page->task = 'page';
  $page->admin_title = 'Kiosk - Call to Action';
  $page->admin_description = 'The "Call to Action" page for kiosk displays.';
  $page->path = 'node/%node/call-to-action';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'kiosk' => 'kiosk',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Call to Action',
    'name' => 'navigation',
    'weight' => '-14',
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
  $handler->name = 'page_kiosk_call_to_action_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kiosk_call_to_action';
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
        'identifier' => 'Kiosk Project (on Node: Project [field_kiosk_project])',
        'keyword' => 'Project',
        'name' => 'entity_from_field:field_kiosk_project-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'column_left' => NULL,
      'column_right' => NULL,
      'content_header' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
      'content_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '07473846-5f07-44d1-b91c-14f8dd935417';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kiosk_call_to_action_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-039087e5-6237-40c7-acfe-fe92d18bc245';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '039087e5-6237-40c7-acfe-fe92d18bc245';
  $display->content['new-039087e5-6237-40c7-acfe-fe92d18bc245'] = $pane;
  $display->panels['content_footer'][0] = 'new-039087e5-6237-40c7-acfe-fe92d18bc245';
  $pane = new stdClass();
  $pane->pid = 'new-5ccc3853-7b07-4073-9602-ff4f38a4cdba';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5ccc3853-7b07-4073-9602-ff4f38a4cdba';
  $display->content['new-5ccc3853-7b07-4073-9602-ff4f38a4cdba'] = $pane;
  $display->panels['content_footer'][1] = 'new-5ccc3853-7b07-4073-9602-ff4f38a4cdba';
  $pane = new stdClass();
  $pane->pid = 'new-6a1ee75a-a9fd-4c17-8653-1eb097ac7c15';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '6a1ee75a-a9fd-4c17-8653-1eb097ac7c15';
  $display->content['new-6a1ee75a-a9fd-4c17-8653-1eb097ac7c15'] = $pane;
  $display->panels['content_header'][0] = 'new-6a1ee75a-a9fd-4c17-8653-1eb097ac7c15';
  $pane = new stdClass();
  $pane->pid = 'new-e9441fe1-6844-46b6-94ee-01ab04caed7e';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e9441fe1-6844-46b6-94ee-01ab04caed7e';
  $display->content['new-e9441fe1-6844-46b6-94ee-01ab04caed7e'] = $pane;
  $display->panels['content_header'][1] = 'new-e9441fe1-6844-46b6-94ee-01ab04caed7e';
  $pane = new stdClass();
  $pane->pid = 'new-e38d2ca7-91bb-4dc7-ae92-0a1b66645845';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e38d2ca7-91bb-4dc7-ae92-0a1b66645845';
  $display->content['new-e38d2ca7-91bb-4dc7-ae92-0a1b66645845'] = $pane;
  $display->panels['content_header'][2] = 'new-e38d2ca7-91bb-4dc7-ae92-0a1b66645845';
  $pane = new stdClass();
  $pane->pid = 'new-b48c9a2d-5052-43fa-afbc-8aa9b6442211';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b48c9a2d-5052-43fa-afbc-8aa9b6442211';
  $display->content['new-b48c9a2d-5052-43fa-afbc-8aa9b6442211'] = $pane;
  $display->panels['content_header'][3] = 'new-b48c9a2d-5052-43fa-afbc-8aa9b6442211';
  $pane = new stdClass();
  $pane->pid = 'new-3c9a66ac-8ea2-435e-81ce-29c7f6e6bdbe';
  $pane->panel = 'content_prefix';
  $pane->type = 'block';
  $pane->subtype = 'blockify-blockify-messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '3c9a66ac-8ea2-435e-81ce-29c7f6e6bdbe';
  $display->content['new-3c9a66ac-8ea2-435e-81ce-29c7f6e6bdbe'] = $pane;
  $display->panels['content_prefix'][0] = 'new-3c9a66ac-8ea2-435e-81ce-29c7f6e6bdbe';
  $pane = new stdClass();
  $pane->pid = 'new-3680bfff-647d-4662-b36c-ee0d62478b8b';
  $pane->panel = 'main_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_call_to_action_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '3680bfff-647d-4662-b36c-ee0d62478b8b';
  $display->content['new-3680bfff-647d-4662-b36c-ee0d62478b8b'] = $pane;
  $display->panels['main_content'][0] = 'new-3680bfff-647d-4662-b36c-ee0d62478b8b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kiosk_call_to_action'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kiosk_green_technology';
  $page->task = 'page';
  $page->admin_title = 'Kiosk - Green Technology';
  $page->admin_description = 'The "Green Technology" page for kiosk displays.';
  $page->path = 'node/%node/green-technology';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'kiosk' => 'kiosk',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Green Technology',
    'name' => 'navigation',
    'weight' => '-16',
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
  $handler->name = 'page_kiosk_green_technology_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kiosk_green_technology';
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
        'identifier' => 'Kiosk Project (on Node: Project [field_kiosk_project])',
        'keyword' => 'Project',
        'name' => 'entity_from_field:field_kiosk_project-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0d1bdf25-779b-4cff-a4c2-5ca238663056';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kiosk_green_technology_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a65012bb-52f3-4bb9-8f99-96a7c7183ea8';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = 'a65012bb-52f3-4bb9-8f99-96a7c7183ea8';
  $display->content['new-a65012bb-52f3-4bb9-8f99-96a7c7183ea8'] = $pane;
  $display->panels['content_footer'][0] = 'new-a65012bb-52f3-4bb9-8f99-96a7c7183ea8';
  $pane = new stdClass();
  $pane->pid = 'new-820162e6-ba45-4e22-bea3-0becc509dac8';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '820162e6-ba45-4e22-bea3-0becc509dac8';
  $display->content['new-820162e6-ba45-4e22-bea3-0becc509dac8'] = $pane;
  $display->panels['content_footer'][1] = 'new-820162e6-ba45-4e22-bea3-0becc509dac8';
  $pane = new stdClass();
  $pane->pid = 'new-39d45f69-beaf-4f12-8816-0b88f9c63427';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '39d45f69-beaf-4f12-8816-0b88f9c63427';
  $display->content['new-39d45f69-beaf-4f12-8816-0b88f9c63427'] = $pane;
  $display->panels['content_header'][0] = 'new-39d45f69-beaf-4f12-8816-0b88f9c63427';
  $pane = new stdClass();
  $pane->pid = 'new-b909aefd-41b3-4d7d-8806-b46319025442';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b909aefd-41b3-4d7d-8806-b46319025442';
  $display->content['new-b909aefd-41b3-4d7d-8806-b46319025442'] = $pane;
  $display->panels['content_header'][1] = 'new-b909aefd-41b3-4d7d-8806-b46319025442';
  $pane = new stdClass();
  $pane->pid = 'new-22ae376b-a398-42be-8d83-c9ef3519a089';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '22ae376b-a398-42be-8d83-c9ef3519a089';
  $display->content['new-22ae376b-a398-42be-8d83-c9ef3519a089'] = $pane;
  $display->panels['content_header'][2] = 'new-22ae376b-a398-42be-8d83-c9ef3519a089';
  $pane = new stdClass();
  $pane->pid = 'new-2f957e38-43c9-4fe2-942a-ceec0f3ae6f9';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2f957e38-43c9-4fe2-942a-ceec0f3ae6f9';
  $display->content['new-2f957e38-43c9-4fe2-942a-ceec0f3ae6f9'] = $pane;
  $display->panels['content_header'][3] = 'new-2f957e38-43c9-4fe2-942a-ceec0f3ae6f9';
  $pane = new stdClass();
  $pane->pid = 'new-1a863a0c-f7c4-4a45-af91-8b79db41a28e';
  $pane->panel = 'content_prefix';
  $pane->type = 'block';
  $pane->subtype = 'blockify-blockify-messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '1a863a0c-f7c4-4a45-af91-8b79db41a28e';
  $display->content['new-1a863a0c-f7c4-4a45-af91-8b79db41a28e'] = $pane;
  $display->panels['content_prefix'][0] = 'new-1a863a0c-f7c4-4a45-af91-8b79db41a28e';
  $pane = new stdClass();
  $pane->pid = 'new-c7f02e41-5e9e-4314-8119-d0d8b75a5bcd';
  $pane->panel = 'main_content';
  $pane->type = 'green_tech_list';
  $pane->subtype = 'green_tech_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = 'c7f02e41-5e9e-4314-8119-d0d8b75a5bcd';
  $display->content['new-c7f02e41-5e9e-4314-8119-d0d8b75a5bcd'] = $pane;
  $display->panels['main_content'][0] = 'new-c7f02e41-5e9e-4314-8119-d0d8b75a5bcd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kiosk_green_technology'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kiosk_how_it_works';
  $page->task = 'page';
  $page->admin_title = 'Kiosk - How It Works';
  $page->admin_description = 'The "How It Works" tab on kiosk displays.';
  $page->path = 'node/%node/how-it-works';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'kiosk' => 'kiosk',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'How It Works',
    'name' => 'navigation',
    'weight' => '-19',
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
  $handler->name = 'page_kiosk_how_it_works_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kiosk_how_it_works';
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
        'identifier' => 'Kiosk Project (on Node: Project [field_kiosk_project])',
        'keyword' => 'Project',
        'name' => 'entity_from_field:field_kiosk_project-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content_header_left' => NULL,
      'content_header_right' => NULL,
      'content_main' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'How It Works';
  $display->uuid = '92533556-d531-44bf-8f75-60d6ce6824d2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kiosk_how_it_works_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-24bc86e3-3a10-4c4a-b315-ebde6dc677ef';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '24bc86e3-3a10-4c4a-b315-ebde6dc677ef';
  $display->content['new-24bc86e3-3a10-4c4a-b315-ebde6dc677ef'] = $pane;
  $display->panels['content_footer'][0] = 'new-24bc86e3-3a10-4c4a-b315-ebde6dc677ef';
  $pane = new stdClass();
  $pane->pid = 'new-a297569c-4867-4f26-8ea9-121bb13f7000';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a297569c-4867-4f26-8ea9-121bb13f7000';
  $display->content['new-a297569c-4867-4f26-8ea9-121bb13f7000'] = $pane;
  $display->panels['content_footer'][1] = 'new-a297569c-4867-4f26-8ea9-121bb13f7000';
  $pane = new stdClass();
  $pane->pid = 'new-757ed592-5a9a-43fe-8e2d-c724b1f49eaf';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '757ed592-5a9a-43fe-8e2d-c724b1f49eaf';
  $display->content['new-757ed592-5a9a-43fe-8e2d-c724b1f49eaf'] = $pane;
  $display->panels['content_header'][0] = 'new-757ed592-5a9a-43fe-8e2d-c724b1f49eaf';
  $pane = new stdClass();
  $pane->pid = 'new-644d9dc3-6ca5-45c2-bdb8-1661d1a2cb90';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '644d9dc3-6ca5-45c2-bdb8-1661d1a2cb90';
  $display->content['new-644d9dc3-6ca5-45c2-bdb8-1661d1a2cb90'] = $pane;
  $display->panels['content_header'][1] = 'new-644d9dc3-6ca5-45c2-bdb8-1661d1a2cb90';
  $pane = new stdClass();
  $pane->pid = 'new-13b2fb80-45fe-4884-b092-7f66d5727c43';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '13b2fb80-45fe-4884-b092-7f66d5727c43';
  $display->content['new-13b2fb80-45fe-4884-b092-7f66d5727c43'] = $pane;
  $display->panels['content_header'][2] = 'new-13b2fb80-45fe-4884-b092-7f66d5727c43';
  $pane = new stdClass();
  $pane->pid = 'new-30d11fe4-37a4-4813-8176-bdb0a3410a82';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '30d11fe4-37a4-4813-8176-bdb0a3410a82';
  $display->content['new-30d11fe4-37a4-4813-8176-bdb0a3410a82'] = $pane;
  $display->panels['content_header'][3] = 'new-30d11fe4-37a4-4813-8176-bdb0a3410a82';
  $pane = new stdClass();
  $pane->pid = 'new-7167b945-9bf2-44b8-bf48-97d7106f06ec';
  $pane->panel = 'content_prefix';
  $pane->type = 'block';
  $pane->subtype = 'blockify-blockify-messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '7167b945-9bf2-44b8-bf48-97d7106f06ec';
  $display->content['new-7167b945-9bf2-44b8-bf48-97d7106f06ec'] = $pane;
  $display->panels['content_prefix'][0] = 'new-7167b945-9bf2-44b8-bf48-97d7106f06ec';
  $pane = new stdClass();
  $pane->pid = 'new-48941a77-2aa0-4859-bfc1-d8e4c406e845';
  $pane->panel = 'main_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_how_it_works_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '48941a77-2aa0-4859-bfc1-d8e4c406e845';
  $display->content['new-48941a77-2aa0-4859-bfc1-d8e4c406e845'] = $pane;
  $display->panels['main_content'][0] = 'new-48941a77-2aa0-4859-bfc1-d8e4c406e845';
  $pane = new stdClass();
  $pane->pid = 'new-b53d483a-34e5-40c6-94a5-9d3b5c2ac164';
  $pane->panel = 'main_content';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'How It Works animation',
    'title' => '',
    'body' => '<object type="application/x-shockwave-flash" width="891" height="563" data="/profiles/s4rs/modules/features/solar_kiosk/flash/HIW_v1.3_commercial2.swf"><param name="movie" value="/profiles/s4rs/modules/features/solar_kiosk/flash/HIW_v1.3_commercial2.swf"><param name="quality" value="high"></object>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-node-how-it-works-default-body',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b53d483a-34e5-40c6-94a5-9d3b5c2ac164';
  $display->content['new-b53d483a-34e5-40c6-94a5-9d3b5c2ac164'] = $pane;
  $display->panels['main_content'][1] = 'new-b53d483a-34e5-40c6-94a5-9d3b5c2ac164';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kiosk_how_it_works'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kiosk_renewable_benefts';
  $page->task = 'page';
  $page->admin_title = 'Kiosk - Renewable Benefts';
  $page->admin_description = 'The "Renewable Benefits" page for kiosk displays.';
  $page->path = 'node/%node/renewable-benefits';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'kiosk' => 'kiosk',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Renewable Benefits',
    'name' => 'navigation',
    'weight' => '-15',
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
  $handler->name = 'page_kiosk_renewable_benefts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kiosk_renewable_benefts';
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
        'identifier' => 'Kiosk Project (on Node: Project [field_kiosk_project])',
        'keyword' => 'Project',
        'name' => 'entity_from_field:field_kiosk_project-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
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
  $display->layout = 'kiosk';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
      'content_prefix' => NULL,
      'main_content' => NULL,
      'content_suffix' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2a9c1602-3a6a-4112-a688-789e7afbaa68';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kiosk_renewable_benefts_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0efba04e-f633-4239-89ff-c40ea8b97906';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '0efba04e-f633-4239-89ff-c40ea8b97906';
  $display->content['new-0efba04e-f633-4239-89ff-c40ea8b97906'] = $pane;
  $display->panels['content_footer'][0] = 'new-0efba04e-f633-4239-89ff-c40ea8b97906';
  $pane = new stdClass();
  $pane->pid = 'new-2db3cbdc-d59e-4eeb-b106-4e38a2266eb8';
  $pane->panel = 'content_footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2db3cbdc-d59e-4eeb-b106-4e38a2266eb8';
  $display->content['new-2db3cbdc-d59e-4eeb-b106-4e38a2266eb8'] = $pane;
  $display->panels['content_footer'][1] = 'new-2db3cbdc-d59e-4eeb-b106-4e38a2266eb8';
  $pane = new stdClass();
  $pane->pid = 'new-8c93aceb-3b67-4ac1-9d98-f007af673c04';
  $pane->panel = 'content_header';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = '8c93aceb-3b67-4ac1-9d98-f007af673c04';
  $display->content['new-8c93aceb-3b67-4ac1-9d98-f007af673c04'] = $pane;
  $display->panels['content_header'][0] = 'new-8c93aceb-3b67-4ac1-9d98-f007af673c04';
  $pane = new stdClass();
  $pane->pid = 'new-08efcfaa-4c8e-4ada-85ac-892868c2ced3';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '08efcfaa-4c8e-4ada-85ac-892868c2ced3';
  $display->content['new-08efcfaa-4c8e-4ada-85ac-892868c2ced3'] = $pane;
  $display->panels['content_header'][1] = 'new-08efcfaa-4c8e-4ada-85ac-892868c2ced3';
  $pane = new stdClass();
  $pane->pid = 'new-fe50d3d3-626a-4042-8ef2-e8c72d69f570';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_kiosk_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fe50d3d3-626a-4042-8ef2-e8c72d69f570';
  $display->content['new-fe50d3d3-626a-4042-8ef2-e8c72d69f570'] = $pane;
  $display->panels['content_header'][2] = 'new-fe50d3d3-626a-4042-8ef2-e8c72d69f570';
  $pane = new stdClass();
  $pane->pid = 'new-fc8b3a25-cd99-493c-a65c-8f536e139c68';
  $pane->panel = 'content_header';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'fc8b3a25-cd99-493c-a65c-8f536e139c68';
  $display->content['new-fc8b3a25-cd99-493c-a65c-8f536e139c68'] = $pane;
  $display->panels['content_header'][3] = 'new-fc8b3a25-cd99-493c-a65c-8f536e139c68';
  $pane = new stdClass();
  $pane->pid = 'new-7c0a87b8-12df-4699-9acc-24712c2f22c8';
  $pane->panel = 'content_prefix';
  $pane->type = 'block';
  $pane->subtype = 'blockify-blockify-messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '7c0a87b8-12df-4699-9acc-24712c2f22c8';
  $display->content['new-7c0a87b8-12df-4699-9acc-24712c2f22c8'] = $pane;
  $display->panels['content_prefix'][0] = 'new-7c0a87b8-12df-4699-9acc-24712c2f22c8';
  $pane = new stdClass();
  $pane->pid = 'new-e4db2785-f080-417f-93a5-9590c08032c9';
  $pane->panel = 'main_content';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:10';
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
    'css_class' => 'kiosk-renewable-energy',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e4db2785-f080-417f-93a5-9590c08032c9';
  $display->content['new-e4db2785-f080-417f-93a5-9590c08032c9'] = $pane;
  $display->panels['main_content'][0] = 'new-e4db2785-f080-417f-93a5-9590c08032c9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kiosk_renewable_benefts'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'old_kiosk_url';
  $page->task = 'page';
  $page->admin_title = 'Old kiosk url';
  $page->admin_description = 'Ensures urls like: /kiosk-hosford-middle-school/node/1260/home will end up on /kiosk-hosford-middle-school';
  $page->path = 'node/%node/node/!string';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'string' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 1,
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
  $handler->name = 'page_old_kiosk_url_http_response';
  $handler->task = 'page';
  $handler->subtask = 'old_kiosk_url';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'HTTP response code',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => '%node:url',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'kiosk' => 'kiosk',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['old_kiosk_url'] = $page;

  return $pages;

}
