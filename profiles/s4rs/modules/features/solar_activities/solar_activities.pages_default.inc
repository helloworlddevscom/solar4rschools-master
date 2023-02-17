<?php
/**
 * @file
 * solar_activities.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function solar_activities_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__article-page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Article page',
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
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'articles' => 'articles',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
    'name' => 'article-page',
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
  $display->uuid = 'cdfd867a-852d-4ca1-b0c0-56e94abd1806';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__article-page';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
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
  $pane->uuid = '8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $display->content['new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd'] = $pane;
  $display->panels['content_main_column'][0] = 'new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $pane = new stdClass();
  $pane->pid = 'new-e9dca13e-7357-47e1-8f8c-d5822f33f113';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e9dca13e-7357-47e1-8f8c-d5822f33f113';
  $display->content['new-e9dca13e-7357-47e1-8f8c-d5822f33f113'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-e9dca13e-7357-47e1-8f8c-d5822f33f113';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-8eae5e6d-b244-4fe2-b060-4dd9c7911abd';
  $handler->conf['display'] = $display;
  $export['node_view__article-page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
  $handler->conf = array(
    'title' => 'Activity page',
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
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'Author',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'activity' => 'activity',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Teach
Teacher Activity Center',
    'panels_breadcrumbs_paths' => 'teach
teach/teacher-activity-center',
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
  $display->title = '%node:title';
  $display->uuid = '62675bc8-628a-4560-b594-5b6e3fe8e840';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-228a87fb-2b36-4761-b0d4-5ea8a2c20339';
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
  $pane->uuid = '228a87fb-2b36-4761-b0d4-5ea8a2c20339';
  $display->content['new-228a87fb-2b36-4761-b0d4-5ea8a2c20339'] = $pane;
  $display->panels['content_main_column'][0] = 'new-228a87fb-2b36-4761-b0d4-5ea8a2c20339';
  $pane = new stdClass();
  $pane->pid = 'new-f18420d2-2a7c-4130-86d4-2e2acda11e0c';
  $pane->panel = 'content_main_column';
  $pane->type = 'link_pane';
  $pane->subtype = 'link_pane';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'delete own activity content',
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_schema:uid-node-user_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'links_pane' => array(
      'request_removal_of_activity' => 'request_removal_of_activity',
      'sample_link_to_front' => 0,
      'activity_add' => 0,
      'funder_edit_profile' => 0,
      'get_widgets' => 0,
    ),
    'links_pane_render' => 'unformatted',
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'context_user_1',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f18420d2-2a7c-4130-86d4-2e2acda11e0c';
  $display->content['new-f18420d2-2a7c-4130-86d4-2e2acda11e0c'] = $pane;
  $display->panels['content_main_column'][1] = 'new-f18420d2-2a7c-4130-86d4-2e2acda11e0c';
  $pane = new stdClass();
  $pane->pid = 'new-2f1a9158-7b58-4d53-bcdb-22cda8890a08';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2f1a9158-7b58-4d53-bcdb-22cda8890a08';
  $display->content['new-2f1a9158-7b58-4d53-bcdb-22cda8890a08'] = $pane;
  $display->panels['content_main_column'][2] = 'new-2f1a9158-7b58-4d53-bcdb-22cda8890a08';
  $pane = new stdClass();
  $pane->pid = 'new-a9303b93-6fd3-4273-8acb-7110d883521e';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_flags-panel_pane_1';
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
  $pane->uuid = 'a9303b93-6fd3-4273-8acb-7110d883521e';
  $display->content['new-a9303b93-6fd3-4273-8acb-7110d883521e'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-a9303b93-6fd3-4273-8acb-7110d883521e';
  $pane = new stdClass();
  $pane->pid = 'new-df875a54-3883-4bd8-be96-059d67e5efdf';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'block';
  $pane->subtype = 'block-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Want to upload a new activity?',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'df875a54-3883-4bd8-be96-059d67e5efdf';
  $display->content['new-df875a54-3883-4bd8-be96-059d67e5efdf'] = $pane;
  $display->panels['content_secondary_column'][1] = 'new-df875a54-3883-4bd8-be96-059d67e5efdf';
  $pane = new stdClass();
  $pane->pid = 'new-7f867c15-4312-476c-bd16-69f163dabf48';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'activities-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7f867c15-4312-476c-bd16-69f163dabf48';
  $display->content['new-7f867c15-4312-476c-bd16-69f163dabf48'] = $pane;
  $display->panels['content_secondary_column'][2] = 'new-7f867c15-4312-476c-bd16-69f163dabf48';
  $pane = new stdClass();
  $pane->pid = 'new-6235b4dd-7b99-432a-aaf1-f0781a8ffe3a';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'activities-panel_pane_5';
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
  $pane->uuid = '6235b4dd-7b99-432a-aaf1-f0781a8ffe3a';
  $display->content['new-6235b4dd-7b99-432a-aaf1-f0781a8ffe3a'] = $pane;
  $display->panels['content_secondary_column'][3] = 'new-6235b4dd-7b99-432a-aaf1-f0781a8ffe3a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'title' => 'Science Kit page',
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
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'Author',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'science_kit' => 'science_kit',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Teach
Science Kit Materials',
    'panels_breadcrumbs_paths' => 'teach
teach/science-kits',
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
  $display->title = '%node:title';
  $display->uuid = '62675bc8-628a-4560-b594-5b6e3fe8e840';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-68631c14-040b-4a93-b723-c17a143de7af';
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
  $pane->uuid = '68631c14-040b-4a93-b723-c17a143de7af';
  $display->content['new-68631c14-040b-4a93-b723-c17a143de7af'] = $pane;
  $display->panels['content_main_column'][0] = 'new-68631c14-040b-4a93-b723-c17a143de7af';
  $pane = new stdClass();
  $pane->pid = 'new-2f1a9158-7b58-4d53-bcdb-22cda8890a08';
  $pane->panel = 'content_main_column';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'teaser',
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
  $pane->uuid = '2f1a9158-7b58-4d53-bcdb-22cda8890a08';
  $display->content['new-2f1a9158-7b58-4d53-bcdb-22cda8890a08'] = $pane;
  $display->panels['content_main_column'][1] = 'new-2f1a9158-7b58-4d53-bcdb-22cda8890a08';
  $pane = new stdClass();
  $pane->pid = 'new-a9303b93-6fd3-4273-8acb-7110d883521e';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_flags-panel_pane_1';
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
  $pane->uuid = 'a9303b93-6fd3-4273-8acb-7110d883521e';
  $display->content['new-a9303b93-6fd3-4273-8acb-7110d883521e'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-a9303b93-6fd3-4273-8acb-7110d883521e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_78f71cea-40b0-4f21-bdb0-78db312a407c';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Articles Categories',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'article_categories' => 'article_categories',
            ),
          ),
          'context' => 'argument_term_1',
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
  $display->uuid = '3fa7933f-c37a-455a-8034-7619e01a8bc2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__panel_context_78f71cea-40b0-4f21-bdb0-78db312a407c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e9491ddc-071f-40cc-977a-75dd3bd4dab4';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'article_categories-pane_article_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'tid' => '%term:tid',
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
  $pane->uuid = 'e9491ddc-071f-40cc-977a-75dd3bd4dab4';
  $display->content['new-e9491ddc-071f-40cc-977a-75dd3bd4dab4'] = $pane;
  $display->panels['content_main_column'][0] = 'new-e9491ddc-071f-40cc-977a-75dd3bd4dab4';
  $pane = new stdClass();
  $pane->pid = 'new-4c6cd434-6bcd-4d8a-bc01-cc760ae00733';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4c6cd434-6bcd-4d8a-bc01-cc760ae00733';
  $display->content['new-4c6cd434-6bcd-4d8a-bc01-cc760ae00733'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-4c6cd434-6bcd-4d8a-bc01-cc760ae00733';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4c6cd434-6bcd-4d8a-bc01-cc760ae00733';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_78f71cea-40b0-4f21-bdb0-78db312a407c'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function solar_activities_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'my_activities';
  $page->task = 'page';
  $page->admin_title = 'My activities';
  $page->admin_description = 'A user\'s activities';
  $page->path = 'user/%user/my-activities';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'ruleset:can_see_project_tabs',
        'settings' => NULL,
        'context' => array(
          0 => 'logged-in-user',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 7,
            2 => 4,
            3 => 3,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'My Activities',
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
  $handler->name = 'page_my_activities_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'my_activities';
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
  $display->title = 'My activities';
  $display->uuid = '2add95f5-3a18-4799-9bfc-259bc0e36d07';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_my_activities_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-86adcb51-6579-4d4d-a859-38b8cab793e7';
  $pane->panel = 'first';
  $pane->type = 'views_panes';
  $pane->subtype = 'activities-panel_pane_6';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
    ),
  );
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
  $pane->uuid = '86adcb51-6579-4d4d-a859-38b8cab793e7';
  $display->content['new-86adcb51-6579-4d4d-a859-38b8cab793e7'] = $pane;
  $display->panels['first'][0] = 'new-86adcb51-6579-4d4d-a859-38b8cab793e7';
  $pane = new stdClass();
  $pane->pid = 'new-445d0d2e-5ab1-4d19-a9bd-223155ddd022';
  $pane->panel = 'first';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_flags-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'uid' => '%user:uid',
    ),
  );
  $pane->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '445d0d2e-5ab1-4d19-a9bd-223155ddd022';
  $display->content['new-445d0d2e-5ab1-4d19-a9bd-223155ddd022'] = $pane;
  $display->panels['first'][1] = 'new-445d0d2e-5ab1-4d19-a9bd-223155ddd022';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['my_activities'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'science_kits';
  $page->task = 'page';
  $page->admin_title = 'Science Kits';
  $page->admin_description = 'Listing of science kits';
  $page->path = 'teach/science-kits';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Browse Science Kit Catalog',
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
  $handler->name = 'page_science_kits_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'science_kits';
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
  $display->title = 'Science Kit Catalog';
  $display->uuid = 'f71afd61-2785-4ecc-92c1-efd88aa9ce22';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_science_kits_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-adbad2d4-27dd-48f1-8582-b39df5c14a24';
  $pane->panel = 'content_main_column';
  $pane->type = 'views_panes';
  $pane->subtype = 'node_search-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'type' => 'science_kit',
    ),
    'arguments' => array(
      'type' => 'science_kit',
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
  $pane->uuid = 'adbad2d4-27dd-48f1-8582-b39df5c14a24';
  $display->content['new-adbad2d4-27dd-48f1-8582-b39df5c14a24'] = $pane;
  $display->panels['content_main_column'][0] = 'new-adbad2d4-27dd-48f1-8582-b39df5c14a24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['science_kits'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'teacher_activity_center';
  $page->task = 'page';
  $page->admin_title = 'Teacher Activity Center';
  $page->admin_description = '';
  $page->path = 'teach/teacher-activity-center';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Search Teacher Activity Center',
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
  $handler->name = 'page_teacher_activity_center_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'teacher_activity_center';
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
  $display->layout = 'comendite-left';
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
  $display->title = 'Teacher Activity Center';
  $display->uuid = '3ddc5fe2-15fd-46de-87d8-3d371dea71a3';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_teacher_activity_center_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0f60e13b-aad9-4d41-819f-e150e14c9dc1';
  $pane->panel = 'content_header';
  $pane->type = 'block';
  $pane->subtype = 'block-3';
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
  $pane->uuid = '0f60e13b-aad9-4d41-819f-e150e14c9dc1';
  $display->content['new-0f60e13b-aad9-4d41-819f-e150e14c9dc1'] = $pane;
  $display->panels['content_header'][0] = 'new-0f60e13b-aad9-4d41-819f-e150e14c9dc1';
  $pane = new stdClass();
  $pane->pid = 'new-b328c808-b618-4c65-9c6c-eddecebd564b';
  $pane->panel = 'content_main_column';
  $pane->type = 'views';
  $pane->subtype = 'teacher_activity_center';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->uuid = 'b328c808-b618-4c65-9c6c-eddecebd564b';
  $display->content['new-b328c808-b618-4c65-9c6c-eddecebd564b'] = $pane;
  $display->panels['content_main_column'][0] = 'new-b328c808-b618-4c65-9c6c-eddecebd564b';
  $pane = new stdClass();
  $pane->pid = 'new-50111b1e-25d2-4a92-a76a-058d98cbc6e5';
  $pane->panel = 'content_secondary_column';
  $pane->type = 'panels_mini';
  $pane->subtype = 'teacher_activity_center_sidebar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '50111b1e-25d2-4a92-a76a-058d98cbc6e5';
  $display->content['new-50111b1e-25d2-4a92-a76a-058d98cbc6e5'] = $pane;
  $display->panels['content_secondary_column'][0] = 'new-50111b1e-25d2-4a92-a76a-058d98cbc6e5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['teacher_activity_center'] = $page;

  return $pages;

}
