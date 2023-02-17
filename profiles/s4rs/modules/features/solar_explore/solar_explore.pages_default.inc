<?php
/**
 * @file
 * solar_explore.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_explore_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'explore_data';
  $page->task = 'page';
  $page->admin_title = 'Explore data';
  $page->admin_description = 'The Explore Data part of the site.';
  $page->path = 'explore-data/!generation_site/!start/!end/!presets/!saved_graph';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Explore Data',
    'name' => 'main-menu',
    'weight' => '2',
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
    'start' => array(
      'id' => 1,
      'identifier' => 'Start Date',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'end' => array(
      'id' => 2,
      'identifier' => 'End date',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'presets' => array(
      'id' => 3,
      'identifier' => 'Preset Ids',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'saved_graph' => array(
      'id' => 1,
      'identifier' => 'Saved Graph: ID',
      'name' => 'entity_id:saved_graph',
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
  $handler->name = 'page_test_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'explore_data';
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
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'hawaiite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_header' => NULL,
      'column_left' => NULL,
      'column_middle' => NULL,
      'column_right' => NULL,
      'content_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Energy Exploration Center';
  $display->uuid = '3813b8a6-9805-4a7e-b25e-a58f5febc171';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_test_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-13afe894-183e-4e77-ad53-c9f20f31eedf';
  $pane->panel = 'column_left';
  $pane->type = 'graph_form';
  $pane->subtype = 'graph_form';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:generation_site_1',
      1 => 'argument_entity_id:saved_graph_1',
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
  $pane->uuid = '13afe894-183e-4e77-ad53-c9f20f31eedf';
  $display->content['new-13afe894-183e-4e77-ad53-c9f20f31eedf'] = $pane;
  $display->panels['column_left'][0] = 'new-13afe894-183e-4e77-ad53-c9f20f31eedf';
  $pane = new stdClass();
  $pane->pid = 'new-f6adca94-f02d-45e0-bb89-2eefca64eebb';
  $pane->panel = 'column_middle';
  $pane->type = 'block';
  $pane->subtype = 'explore_data-explore_data_chart_tools';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_bundle:generation_site',
        'settings' => array(
          'type' => array(
            'deck' => 'deck',
            'power_one' => 'power_one',
            'tigo_energy' => 'tigo_energy',
            'locus_energy' => 'locus_energy',
          ),
        ),
        'context' => 'argument_entity_id:generation_site_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-1][0-9]-[0-3][0-9]-[0-9]{4}/',
          'case' => 0,
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-9]+/',
          'case' => 0,
        ),
        'context' => 'argument_string_3',
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-1][0-9]-[0-3][0-9]-[0-9]{4}/',
          'case' => 0,
        ),
        'context' => 'argument_string_2',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
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
  $pane->uuid = 'f6adca94-f02d-45e0-bb89-2eefca64eebb';
  $display->content['new-f6adca94-f02d-45e0-bb89-2eefca64eebb'] = $pane;
  $display->panels['column_middle'][0] = 'new-f6adca94-f02d-45e0-bb89-2eefca64eebb';
  $pane = new stdClass();
  $pane->pid = 'new-1efb5559-f366-4f45-b6a2-9ab057cbc312';
  $pane->panel = 'column_middle';
  $pane->type = 'sharethis';
  $pane->subtype = 'sharethis';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_bundle:generation_site',
        'settings' => array(
          'type' => array(
            'deck' => 'deck',
            'power_one' => 'power_one',
            'tigo_energy' => 'tigo_energy',
          ),
        ),
        'context' => 'argument_entity_id:generation_site_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-1][0-9]-[0-3][0-9]-[0-9]{4}/',
          'case' => 0,
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-9]+/',
          'case' => 0,
        ),
        'context' => 'argument_string_3',
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-1][0-9]-[0-3][0-9]-[0-9]{4}/',
          'case' => 0,
        ),
        'context' => 'argument_string_2',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $pane->configuration = array(
    'path' => 'current',
    'path-external' => '',
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
  $pane->uuid = '1efb5559-f366-4f45-b6a2-9ab057cbc312';
  $display->content['new-1efb5559-f366-4f45-b6a2-9ab057cbc312'] = $pane;
  $display->panels['column_middle'][1] = 'new-1efb5559-f366-4f45-b6a2-9ab057cbc312';
  $pane = new stdClass();
  $pane->pid = 'new-18e5bcd8-a22c-4cf3-941c-173cd9509eb9';
  $pane->panel = 'column_right';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_flags-panel_pane_3';
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
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '18e5bcd8-a22c-4cf3-941c-173cd9509eb9';
  $display->content['new-18e5bcd8-a22c-4cf3-941c-173cd9509eb9'] = $pane;
  $display->panels['column_right'][0] = 'new-18e5bcd8-a22c-4cf3-941c-173cd9509eb9';
  $pane = new stdClass();
  $pane->pid = 'new-6a439301-f737-4489-afa1-f25be4a7ba45';
  $pane->panel = 'content_footer';
  $pane->type = 'block';
  $pane->subtype = 'explore_data-explore_data_results';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_bundle:generation_site',
        'settings' => array(
          'type' => array(
            'deck' => 'deck',
            'power_one' => 'power_one',
            'tigo_energy' => 'tigo_energy',
            'locus_energy' => 'locus_energy',
          ),
        ),
        'context' => 'argument_entity_id:generation_site_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-1][0-9]-[0-3][0-9]-[0-9]{4}/',
          'case' => 0,
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-9]+/',
          'case' => 0,
        ),
        'context' => 'argument_string_3',
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => 'regex',
          'value' => '/[0-1][0-9]-[0-3][0-9]-[0-9]{4}/',
          'case' => 0,
        ),
        'context' => 'argument_string_2',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
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
  $pane->uuid = '6a439301-f737-4489-afa1-f25be4a7ba45';
  $display->content['new-6a439301-f737-4489-afa1-f25be4a7ba45'] = $pane;
  $display->panels['content_footer'][0] = 'new-6a439301-f737-4489-afa1-f25be4a7ba45';
  $pane = new stdClass();
  $pane->pid = 'new-6c752335-229a-4b97-862f-76247e19921e';
  $pane->panel = 'content_footer';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:9d65a0dd-4fec-4d72-a96d-ab7fe0d891fe';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'and',
    'plugins' => array(),
  );
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '86400',
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
  $pane->uuid = '6c752335-229a-4b97-862f-76247e19921e';
  $display->content['new-6c752335-229a-4b97-862f-76247e19921e'] = $pane;
  $display->panels['content_footer'][1] = 'new-6c752335-229a-4b97-862f-76247e19921e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['explore_data'] = $page;

  return $pages;

}
