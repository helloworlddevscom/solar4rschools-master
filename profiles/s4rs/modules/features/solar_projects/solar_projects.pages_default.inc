<?php
/**
 * @file
 * solar_projects.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function solar_projects_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Project page',
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
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Browse Projects',
    'panels_breadcrumbs_paths' => 'browse-projects',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'rhyolite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
      'content_tertiary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f84e40a6-085b-40fe-8dc6-03ced4e39504';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2f77272d-46e2-4673-bb72-62d008cdaeb7';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'picture',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'project_large_image',
      'image_link' => '',
      'picture_group' => 'project_large',
      'fallback_image_style' => '',
      'colorbox' => 'project_large',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f77272d-46e2-4673-bb72-62d008cdaeb7';
  $display->content['new-2f77272d-46e2-4673-bb72-62d008cdaeb7'] = $pane;
  $display->panels['content_header'][0] = 'new-2f77272d-46e2-4673-bb72-62d008cdaeb7';
  $pane = new stdClass();
  $pane->pid = 'new-7600c061-b396-4a98-90df-c4405012f682';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_this_project_funded_by';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
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
  $pane->uuid = '7600c061-b396-4a98-90df-c4405012f682';
  $display->content['new-7600c061-b396-4a98-90df-c4405012f682'] = $pane;
  $display->panels['content_header'][1] = 'new-7600c061-b396-4a98-90df-c4405012f682';
  $pane = new stdClass();
  $pane->pid = 'new-62c45dae-2e2b-4c55-8f1c-6b4290311466';
  $pane->panel = 'content_main_column';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
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
  $pane->uuid = '62c45dae-2e2b-4c55-8f1c-6b4290311466';
  $display->content['new-62c45dae-2e2b-4c55-8f1c-6b4290311466'] = $pane;
  $display->panels['content_main_column'][0] = 'new-62c45dae-2e2b-4c55-8f1c-6b4290311466';
  $pane = new stdClass();
  $pane->pid = 'new-b35de0a1-101c-4300-8ca7-a7d9c77473a2';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 1,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b35de0a1-101c-4300-8ca7-a7d9c77473a2';
  $display->content['new-b35de0a1-101c-4300-8ca7-a7d9c77473a2'] = $pane;
  $display->panels['content_main_column'][1] = 'new-b35de0a1-101c-4300-8ca7-a7d9c77473a2';
  $pane = new stdClass();
  $pane->pid = 'new-4a35c70b-3956-4207-8cad-20a7572b3d77';
  $pane->panel = 'content_main_column';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 7,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Link to add classroom updates',
    'title' => '',
    'body' => '<p><a href="/node/add/classroom-updates?og_group_ref=%node:nid">Add new classroom update</a></p>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4a35c70b-3956-4207-8cad-20a7572b3d77';
  $display->content['new-4a35c70b-3956-4207-8cad-20a7572b3d77'] = $pane;
  $display->panels['content_main_column'][2] = 'new-4a35c70b-3956-4207-8cad-20a7572b3d77';
  $pane = new stdClass();
  $pane->pid = 'new-887a0e89-9676-4f1f-a09d-9dc223f0748c';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'this_group_s_files-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '887a0e89-9676-4f1f-a09d-9dc223f0748c';
  $display->content['new-887a0e89-9676-4f1f-a09d-9dc223f0748c'] = $pane;
  $display->panels['content_main_column'][3] = 'new-887a0e89-9676-4f1f-a09d-9dc223f0748c';
  $pane = new stdClass();
  $pane->pid = 'new-13e3f58d-6fd1-490e-a04e-4813867a11fa';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'Educational impact data',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 0,
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
  $pane->uuid = '13e3f58d-6fd1-490e-a04e-4813867a11fa';
  $display->content['new-13e3f58d-6fd1-490e-a04e-4813867a11fa'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-13e3f58d-6fd1-490e-a04e-4813867a11fa';
  $pane = new stdClass();
  $pane->pid = 'new-27db4394-7d0b-42f7-9022-371c6ffd6e48';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'Real-time data',
    ),
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '1800',
      'granularity' => 'args',
    ),
  );
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 0,
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
  $pane->uuid = '27db4394-7d0b-42f7-9022-371c6ffd6e48';
  $display->content['new-27db4394-7d0b-42f7-9022-371c6ffd6e48'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-27db4394-7d0b-42f7-9022-371c6ffd6e48';
  $pane = new stdClass();
  $pane->pid = 'new-328f9001-c80b-4091-9daa-39304902f910';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'System lifetime data',
    ),
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '1800',
      'granularity' => 'args',
    ),
  );
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
  $pane->uuid = '328f9001-c80b-4091-9daa-39304902f910';
  $display->content['new-328f9001-c80b-4091-9daa-39304902f910'] = $pane;
  $display->panels['content_secondary_column'][2] = 'new-328f9001-c80b-4091-9daa-39304902f910';
  $pane = new stdClass();
  $pane->pid = 'new-786732d2-2183-4550-b09d-cd266b832d85';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'System specs',
    ),
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '1800',
      'granularity' => 'args',
    ),
  );
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '786732d2-2183-4550-b09d-cd266b832d85';
  $display->content['new-786732d2-2183-4550-b09d-cd266b832d85'] = $pane;
  $display->panels['content_secondary_column'][3] = 'new-786732d2-2183-4550-b09d-cd266b832d85';
  $pane = new stdClass();
  $pane->pid = 'new-7b305c23-fe04-4cd5-a68c-51cc07e855ce';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'link_pane';
  $pane->subtype = 'link_pane';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'links_pane' => array(
      'get_widgets' => 'get_widgets',
      'sample_link_to_front' => 0,
      'activity_add' => 0,
      'funder_edit_profile' => 0,
      'request_removal_of_activity' => 0,
    ),
    'links_pane_render' => 'unformatted',
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'context_user_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'blue-button',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7b305c23-fe04-4cd5-a68c-51cc07e855ce';
  $display->content['new-7b305c23-fe04-4cd5-a68c-51cc07e855ce'] = $pane;
  $display->panels['content_secondary_column'][4] = 'new-7b305c23-fe04-4cd5-a68c-51cc07e855ce';
  $pane = new stdClass();
  $pane->pid = 'new-90d84cfb-61a4-45fc-9b2c-a610064118d8';
  $pane->panel = 'content_tertiary_column';
  $pane->type = 'link_pane';
  $pane->subtype = 'link_pane';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'links_pane' => array(
      'funder_edit_profile' => 'funder_edit_profile',
      'activity_add' => 0,
      'sample_link_to_front' => 0,
    ),
    'links_pane_render' => 'unformatted',
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'context_user_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'blue-button',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '90d84cfb-61a4-45fc-9b2c-a610064118d8';
  $display->content['new-90d84cfb-61a4-45fc-9b2c-a610064118d8'] = $pane;
  $display->panels['content_tertiary_column'][0] = 'new-90d84cfb-61a4-45fc-9b2c-a610064118d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -5;
  $handler->conf = array(
    'title' => 'Project Page 2 Columns',
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
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Browse Projects',
    'panels_breadcrumbs_paths' => 'browse-projects',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'comendite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
      'content_tertiary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f84e40a6-085b-40fe-8dc6-03ced4e39504';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2f77272d-46e2-4673-bb72-62d008cdaeb7';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'picture',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'project_large_image',
      'image_link' => '',
      'picture_group' => 'project_large',
      'fallback_image_style' => '',
      'colorbox' => 'project_large',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f77272d-46e2-4673-bb72-62d008cdaeb7';
  $display->content['new-2f77272d-46e2-4673-bb72-62d008cdaeb7'] = $pane;
  $display->panels['content_header'][0] = 'new-2f77272d-46e2-4673-bb72-62d008cdaeb7';
  $pane = new stdClass();
  $pane->pid = 'new-7600c061-b396-4a98-90df-c4405012f682';
  $pane->panel = 'content_header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_this_project_funded_by';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
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
  $pane->uuid = '7600c061-b396-4a98-90df-c4405012f682';
  $display->content['new-7600c061-b396-4a98-90df-c4405012f682'] = $pane;
  $display->panels['content_header'][1] = 'new-7600c061-b396-4a98-90df-c4405012f682';
  $pane = new stdClass();
  $pane->pid = 'new-90d84cfb-61a4-45fc-9b2c-a610064118d8';
  $pane->panel = 'content_header';
  $pane->type = 'link_pane';
  $pane->subtype = 'link_pane';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'links_pane' => array(
      'funder_edit_profile' => 'funder_edit_profile',
      'activity_add' => 0,
      'sample_link_to_front' => 0,
    ),
    'links_pane_render' => 'unformatted',
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'context_user_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'blue-button',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '90d84cfb-61a4-45fc-9b2c-a610064118d8';
  $display->content['new-90d84cfb-61a4-45fc-9b2c-a610064118d8'] = $pane;
  $display->panels['content_header'][2] = 'new-90d84cfb-61a4-45fc-9b2c-a610064118d8';
  $pane = new stdClass();
  $pane->pid = 'new-62c45dae-2e2b-4c55-8f1c-6b4290311466';
  $pane->panel = 'content_main_column';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
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
  $pane->uuid = '62c45dae-2e2b-4c55-8f1c-6b4290311466';
  $display->content['new-62c45dae-2e2b-4c55-8f1c-6b4290311466'] = $pane;
  $display->panels['content_main_column'][0] = 'new-62c45dae-2e2b-4c55-8f1c-6b4290311466';
  $pane = new stdClass();
  $pane->pid = 'new-b35de0a1-101c-4300-8ca7-a7d9c77473a2';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 1,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b35de0a1-101c-4300-8ca7-a7d9c77473a2';
  $display->content['new-b35de0a1-101c-4300-8ca7-a7d9c77473a2'] = $pane;
  $display->panels['content_main_column'][1] = 'new-b35de0a1-101c-4300-8ca7-a7d9c77473a2';
  $pane = new stdClass();
  $pane->pid = 'new-4a35c70b-3956-4207-8cad-20a7572b3d77';
  $pane->panel = 'content_main_column';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 7,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Link to add classroom updates',
    'title' => '',
    'body' => '<p><a href="/node/add/classroom-updates?og_group_ref=%node:nid">Add new classroom update</a></p>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4a35c70b-3956-4207-8cad-20a7572b3d77';
  $display->content['new-4a35c70b-3956-4207-8cad-20a7572b3d77'] = $pane;
  $display->panels['content_main_column'][2] = 'new-4a35c70b-3956-4207-8cad-20a7572b3d77';
  $pane = new stdClass();
  $pane->pid = 'new-887a0e89-9676-4f1f-a09d-9dc223f0748c';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'this_group_s_files-panel_pane_2';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '887a0e89-9676-4f1f-a09d-9dc223f0748c';
  $display->content['new-887a0e89-9676-4f1f-a09d-9dc223f0748c'] = $pane;
  $display->panels['content_main_column'][3] = 'new-887a0e89-9676-4f1f-a09d-9dc223f0748c';
  $pane = new stdClass();
  $pane->pid = 'new-554ec814-b2da-4111-a62b-fbb1ba4d93b8';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'kiosks-project';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'nid' => '%node:nid',
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
  $pane->uuid = '554ec814-b2da-4111-a62b-fbb1ba4d93b8';
  $display->content['new-554ec814-b2da-4111-a62b-fbb1ba4d93b8'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-554ec814-b2da-4111-a62b-fbb1ba4d93b8';
  $pane = new stdClass();
  $pane->pid = 'new-13e3f58d-6fd1-490e-a04e-4813867a11fa';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'Educational impact data',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 0,
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
  $pane->uuid = '13e3f58d-6fd1-490e-a04e-4813867a11fa';
  $display->content['new-13e3f58d-6fd1-490e-a04e-4813867a11fa'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-13e3f58d-6fd1-490e-a04e-4813867a11fa';
  $pane = new stdClass();
  $pane->pid = 'new-27db4394-7d0b-42f7-9022-371c6ffd6e48';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'Real-time data',
    ),
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '1800',
      'granularity' => 'args',
    ),
  );
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 0,
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
  $pane->uuid = '27db4394-7d0b-42f7-9022-371c6ffd6e48';
  $display->content['new-27db4394-7d0b-42f7-9022-371c6ffd6e48'] = $pane;
  $display->panels['content_secondary_column'][2] = 'new-27db4394-7d0b-42f7-9022-371c6ffd6e48';
  $pane = new stdClass();
  $pane->pid = 'new-328f9001-c80b-4091-9daa-39304902f910';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'System lifetime data',
    ),
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '1800',
      'granularity' => 'args',
    ),
  );
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '328f9001-c80b-4091-9daa-39304902f910';
  $display->content['new-328f9001-c80b-4091-9daa-39304902f910'] = $pane;
  $display->panels['content_secondary_column'][3] = 'new-328f9001-c80b-4091-9daa-39304902f910';
  $pane = new stdClass();
  $pane->pid = 'new-786732d2-2183-4550-b09d-cd266b832d85';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'System specs',
    ),
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '1800',
      'granularity' => 'args',
    ),
  );
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '786732d2-2183-4550-b09d-cd266b832d85';
  $display->content['new-786732d2-2183-4550-b09d-cd266b832d85'] = $pane;
  $display->panels['content_secondary_column'][4] = 'new-786732d2-2183-4550-b09d-cd266b832d85';
  $pane = new stdClass();
  $pane->pid = 'new-7b305c23-fe04-4cd5-a68c-51cc07e855ce';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'link_pane';
  $pane->subtype = 'link_pane';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'links_pane' => array(
      'get_widgets' => 'get_widgets',
      'sample_link_to_front' => 0,
      'activity_add' => 0,
      'funder_edit_profile' => 0,
      'request_removal_of_activity' => 0,
    ),
    'links_pane_render' => 'unformatted',
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'context_user_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'blue-button',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '7b305c23-fe04-4cd5-a68c-51cc07e855ce';
  $display->content['new-7b305c23-fe04-4cd5-a68c-51cc07e855ce'] = $pane;
  $display->panels['content_secondary_column'][5] = 'new-7b305c23-fe04-4cd5-a68c-51cc07e855ce';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_projects_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'browse_projects';
  $page->task = 'page';
  $page->admin_title = 'Browse Projects';
  $page->admin_description = 'The projects brows page';
  $page->path = 'browse-projects';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Browse projects',
    'name' => 'main-menu',
    'weight' => '3',
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
  $handler->name = 'page_browse_projects_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'browse_projects';
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
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Browse Projects',
    'panels_breadcrumbs_paths' => 'browse-projects',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'comendite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Project Profiles';
  $display->uuid = '50c6e441-4443-44ca-afe9-78fdc9e73eef';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_browse_projects_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ca0fb1e9-15f4-480e-8ebc-92629e7c8168';
  $pane->panel = 'content_header';
  $pane->type = 'block';
  $pane->subtype = 'solar_projects-project_map_expand_placeholder';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'ca0fb1e9-15f4-480e-8ebc-92629e7c8168';
  $display->content['new-ca0fb1e9-15f4-480e-8ebc-92629e7c8168'] = $pane;
  $display->panels['content_header'][0] = 'new-ca0fb1e9-15f4-480e-8ebc-92629e7c8168';
  $pane = new stdClass();
  $pane->pid = 'new-0862b432-112c-4155-9beb-8eef04274192';
  $pane->panel = 'content_main_column';
  $pane->type = 'leaflet_geojson.map_pane';
  $pane->subtype = 'leaflet_geojson.map_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'map_settings' => array(
      'base' => 'google-roadmap',
      'info' => array(
        'data' => array(
          'leaflet_1' => 'solar_maps_projects_map_feed_funded',
        ),
        'add_layer' => 'Add another layer',
      ),
      'height' => '400',
      'override_zoom_center' => 1,
      'custom_zoom_center' => array(
        'zoom' => '4',
        'center' => array(
          'lon' => '-96',
          'lat' => '39',
        ),
      ),
    ),
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
  $pane->uuid = '0862b432-112c-4155-9beb-8eef04274192';
  $display->content['new-0862b432-112c-4155-9beb-8eef04274192'] = $pane;
  $display->panels['content_main_column'][0] = 'new-0862b432-112c-4155-9beb-8eef04274192';
  $pane = new stdClass();
  $pane->pid = 'new-e13163da-960a-4a49-ba63-a42e0049f94a';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'solar_maps_projects-projects_pane_map_companion_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
    'offset' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'path' => 'browse-projects',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'ajax-response-map-companion-list',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e13163da-960a-4a49-ba63-a42e0049f94a';
  $display->content['new-e13163da-960a-4a49-ba63-a42e0049f94a'] = $pane;
  $display->panels['content_main_column'][1] = 'new-e13163da-960a-4a49-ba63-a42e0049f94a';
  $pane = new stdClass();
  $pane->pid = 'new-60ad969f-71cd-462a-9123-cd711ebfbf6f';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'projects-panel_pane_1';
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
  $pane->uuid = '60ad969f-71cd-462a-9123-cd711ebfbf6f';
  $display->content['new-60ad969f-71cd-462a-9123-cd711ebfbf6f'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-60ad969f-71cd-462a-9123-cd711ebfbf6f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0862b432-112c-4155-9beb-8eef04274192';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['browse_projects'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'school_pages_redirect';
  $page->task = 'page';
  $page->admin_title = 'School pages redirect';
  $page->admin_description = 'Ensures pages that had a path like schools/*something*/*something* redirect to browse-projects/*something*/*something*';
  $page->path = 'schools/%redirect';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'redirect' => array(
      'id' => 1,
      'identifier' => 'redirect',
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
  $handler->name = 'page_school_pages_redirect_http_response';
  $handler->task = 'page';
  $handler->subtask = 'school_pages_redirect';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'HTTP response code',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'browse-projects/%redirect',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['school_pages_redirect'] = $page;

  return $pages;

}
