<?php
/**
 * @file
 * solar_funders.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function solar_funders_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -6;
  $handler->conf = array(
    'title' => 'Funder Details',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'funder' => 'funder',
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
  $display->title = '<none>';
  $display->uuid = 'c241189d-bb03-47b5-932b-96ccefca7c4f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-316a63aa-1d75-4008-8cf2-79ff19922933';
  $pane->panel = 'content_main_column';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_funder_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
      'image_style' => 'funder_small',
      'image_link' => '',
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
  $pane->uuid = '316a63aa-1d75-4008-8cf2-79ff19922933';
  $display->content['new-316a63aa-1d75-4008-8cf2-79ff19922933'] = $pane;
  $display->panels['content_main_column'][0] = 'new-316a63aa-1d75-4008-8cf2-79ff19922933';
  $pane = new stdClass();
  $pane->pid = 'new-653b3a9f-e17e-4920-967a-91cf895b2487';
  $pane->panel = 'content_main_column';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_funder_body';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'border-bottom-dotted',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '653b3a9f-e17e-4920-967a-91cf895b2487';
  $display->content['new-653b3a9f-e17e-4920-967a-91cf895b2487'] = $pane;
  $display->panels['content_main_column'][1] = 'new-653b3a9f-e17e-4920-967a-91cf895b2487';
  $pane = new stdClass();
  $pane->pid = 'new-e968a200-71f6-4465-b46c-4ef0c7feefd0';
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
          'leaflet_1' => 'solar_map_funder_projects_map_feed_funder_projects',
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
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e968a200-71f6-4465-b46c-4ef0c7feefd0';
  $display->content['new-e968a200-71f6-4465-b46c-4ef0c7feefd0'] = $pane;
  $display->panels['content_main_column'][2] = 'new-e968a200-71f6-4465-b46c-4ef0c7feefd0';
  $pane = new stdClass();
  $pane->pid = 'new-5b398bf2-3eaf-485d-9b87-cd8182f685ca';
  $pane->panel = 'content_main_column';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_funder_schools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Sponsored Projects:',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'view-solar-maps-projects',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5b398bf2-3eaf-485d-9b87-cd8182f685ca';
  $display->content['new-5b398bf2-3eaf-485d-9b87-cd8182f685ca'] = $pane;
  $display->panels['content_main_column'][3] = 'new-5b398bf2-3eaf-485d-9b87-cd8182f685ca';
  $pane = new stdClass();
  $pane->pid = 'new-48cf47c8-8139-4652-9577-c0facd8476c5';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-funder_widgets';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'This funder\'s reach',
      'nid' => '%node:nid',
    ),
    'override_title' => 1,
    'override_title_text' => 'This funder\'s reach',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '900',
      'granularity' => 'context',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '48cf47c8-8139-4652-9577-c0facd8476c5';
  $display->content['new-48cf47c8-8139-4652-9577-c0facd8476c5'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-48cf47c8-8139-4652-9577-c0facd8476c5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_9'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Funder profile',
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
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
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'content_header' => NULL,
      'content_main_column' => NULL,
      'content_secondary_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = 'eb2904d0-3f52-432c-b8a3-80dc54b57127';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-82b38dfb-200c-401f-939a-486ddd78fa2d';
  $pane->panel = 'content_main_column';
  $pane->type = 'leaflet_geojson.map_pane';
  $pane->subtype = 'leaflet_geojson.map_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'map_settings' => array(
      'base' => 'geocommons',
      'info' => array(
        'data' => array(
          'leaflet_1' => 'solar_maps_funder_projects_map_feed_funder_projects',
        ),
        'add_layer' => 'Add another layer',
      ),
      'height' => '400',
      'override_zoom_center' => 1,
      'custom_zoom_center' => array(
        'zoom' => '4',
        'center' => array(
          'lon' => '-98',
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
  $pane->uuid = '82b38dfb-200c-401f-939a-486ddd78fa2d';
  $display->content['new-82b38dfb-200c-401f-939a-486ddd78fa2d'] = $pane;
  $display->panels['content_main_column'][0] = 'new-82b38dfb-200c-401f-939a-486ddd78fa2d';
  $pane = new stdClass();
  $pane->pid = 'new-a99f90af-f113-40ab-8136-a0cde2efae66';
  $pane->panel = 'content_main_column';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:user_1',
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
  $pane->uuid = 'a99f90af-f113-40ab-8136-a0cde2efae66';
  $display->content['new-a99f90af-f113-40ab-8136-a0cde2efae66'] = $pane;
  $display->panels['content_main_column'][1] = 'new-a99f90af-f113-40ab-8136-a0cde2efae66';
  $pane = new stdClass();
  $pane->pid = 'new-11511b85-4a45-4644-9f69-094f6bf509c9';
  $pane->panel = 'content_main_column';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_bio_100';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:user_1',
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
  $pane->uuid = '11511b85-4a45-4644-9f69-094f6bf509c9';
  $display->content['new-11511b85-4a45-4644-9f69-094f6bf509c9'] = $pane;
  $display->panels['content_main_column'][2] = 'new-11511b85-4a45-4644-9f69-094f6bf509c9';
  $pane = new stdClass();
  $pane->pid = 'new-a8c66adf-7c96-42b0-a4fe-87a744a59110';
  $pane->panel = 'content_main_column';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'user:profile_funder';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:user_1',
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
  $pane->uuid = 'a8c66adf-7c96-42b0-a4fe-87a744a59110';
  $display->content['new-a8c66adf-7c96-42b0-a4fe-87a744a59110'] = $pane;
  $display->panels['content_main_column'][3] = 'new-a8c66adf-7c96-42b0-a4fe-87a744a59110';
  $pane = new stdClass();
  $pane->pid = 'new-41a15d2b-e9bb-48ff-9130-99b5d1eb0811';
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
    'override_title_text' => 'Projects',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '41a15d2b-e9bb-48ff-9130-99b5d1eb0811';
  $display->content['new-41a15d2b-e9bb-48ff-9130-99b5d1eb0811'] = $pane;
  $display->panels['content_main_column'][4] = 'new-41a15d2b-e9bb-48ff-9130-99b5d1eb0811';
  $pane = new stdClass();
  $pane->pid = 'new-25fd501e-98cd-426e-ba8b-2dbe16b335f7';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'widgets_selects-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'name' => 'This funder\'s reach',
      'uid' => '%user:uid',
    ),
    'context' => array(
      1 => 'relationship_profile2_1',
    ),
    'override_title' => 1,
    'override_title_text' => 'This funder\'s reach',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '900',
      'granularity' => 'context',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '25fd501e-98cd-426e-ba8b-2dbe16b335f7';
  $display->content['new-25fd501e-98cd-426e-ba8b-2dbe16b335f7'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-25fd501e-98cd-426e-ba8b-2dbe16b335f7';
  $pane = new stdClass();
  $pane->pid = 'new-ebaff608-6a21-4cab-9e26-452cd1e173ba';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'link_pane';
  $pane->subtype = 'link_pane';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'argument_entity_id:user_1',
          1 => 'logged-in-user',
        ),
        'not' => FALSE,
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
      0 => 'empty',
      1 => 'argument_entity_id:user_1',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ebaff608-6a21-4cab-9e26-452cd1e173ba';
  $display->content['new-ebaff608-6a21-4cab-9e26-452cd1e173ba'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-ebaff608-6a21-4cab-9e26-452cd1e173ba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_funders_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'browse_funders';
  $page->task = 'page';
  $page->admin_title = 'Browse Funders';
  $page->admin_description = 'The page that displays results for funders';
  $page->path = 'browse-funders';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Browse funders',
    'name' => 'main-menu',
    'weight' => '4',
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
  $handler->name = 'page_browse_funders_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'browse_funders';
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
  $display->title = 'Browse Funders';
  $display->uuid = 'fd125a46-8c03-465d-86d4-c1dbe21d6241';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_browse_funders_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1b2bea4f-81c2-4864-9b41-d89f470f845f';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'founding_partners-panel_pane_1';
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
  $pane->uuid = '1b2bea4f-81c2-4864-9b41-d89f470f845f';
  $display->content['new-1b2bea4f-81c2-4864-9b41-d89f470f845f'] = $pane;
  $display->panels['content_main_column'][0] = 'new-1b2bea4f-81c2-4864-9b41-d89f470f845f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['browse_funders'] = $page;

  return $pages;

}
