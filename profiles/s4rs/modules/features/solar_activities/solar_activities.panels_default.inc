<?php
/**
 * @file
 * solar_activities.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function solar_activities_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'teacher_activity_center_sidebar';
  $mini->category = '';
  $mini->admin_title = 'Teacher Activity Center Sidebar';
  $mini->admin_description = 'Sidebar for Teacher Activity Center containing search fields and facets.';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c0671102-2d05-40c5-8b12-5a9a22d67ba3';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'teacher_activity_center_sidebar';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8673b4b3-85be-4fad-90c0-4bb46f993731';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-4af75d3ccd89188685c8af91be157aee';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
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
  $pane->uuid = '8673b4b3-85be-4fad-90c0-4bb46f993731';
  $display->content['new-8673b4b3-85be-4fad-90c0-4bb46f993731'] = $pane;
  $display->panels['middle'][0] = 'new-8673b4b3-85be-4fad-90c0-4bb46f993731';
  $pane = new stdClass();
  $pane->pid = 'new-7cfd2ec7-3e78-46bc-b4b0-d6d8c246cad7';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-YAPZZ4EtmKpz6SluMLvEq7eDPdNt8KaT';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7cfd2ec7-3e78-46bc-b4b0-d6d8c246cad7';
  $display->content['new-7cfd2ec7-3e78-46bc-b4b0-d6d8c246cad7'] = $pane;
  $display->panels['middle'][1] = 'new-7cfd2ec7-3e78-46bc-b4b0-d6d8c246cad7';
  $pane = new stdClass();
  $pane->pid = 'new-39db3da9-1974-43b4-b228-0e20ee8203f3';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Teacher Activity Center Sidebar - Help Text',
    'title' => '<none>',
    'title_heading' => 'h2',
    'body' => '<p><span style="color: rgb(23, 43, 77); font-family: -apple-system, system-ui, &quot;Segoe UI&quot;, Roboto, Oxygen, Ubuntu, &quot;Fira Sans&quot;, &quot;Droid Sans&quot;, &quot;Helvetica Neue&quot;, sans-serif; font-size: 14px; letter-spacing: -0.07px; white-space: pre-wrap;">Select all that apply. </span></p><p><span style="color: rgb(23, 43, 77); font-family: -apple-system, system-ui, &quot;Segoe UI&quot;, Roboto, Oxygen, Ubuntu, &quot;Fira Sans&quot;, &quot;Droid Sans&quot;, &quot;Helvetica Neue&quot;, sans-serif; font-size: 14px; letter-spacing: -0.07px; white-space: pre-wrap;">You can select more than one option from each field.</span></p>',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'teacher-activity-center-sidebar__help-text',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '39db3da9-1974-43b4-b228-0e20ee8203f3';
  $display->content['new-39db3da9-1974-43b4-b228-0e20ee8203f3'] = $pane;
  $display->panels['middle'][2] = 'new-39db3da9-1974-43b4-b228-0e20ee8203f3';
  $pane = new stdClass();
  $pane->pid = 'new-642d2f31-f4a3-4f7e-afa1-21f0097d2d29';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-Sy9jaCMTC8HFGllveFCtnpAQhPPtja0D';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '642d2f31-f4a3-4f7e-afa1-21f0097d2d29';
  $display->content['new-642d2f31-f4a3-4f7e-afa1-21f0097d2d29'] = $pane;
  $display->panels['middle'][3] = 'new-642d2f31-f4a3-4f7e-afa1-21f0097d2d29';
  $pane = new stdClass();
  $pane->pid = 'new-2abcf985-e0ae-41b9-b65e-b2544a2bc143';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-yK0WlT3a0n4wFmv5LHThUnFPCvyJZWy8';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2abcf985-e0ae-41b9-b65e-b2544a2bc143';
  $display->content['new-2abcf985-e0ae-41b9-b65e-b2544a2bc143'] = $pane;
  $display->panels['middle'][4] = 'new-2abcf985-e0ae-41b9-b65e-b2544a2bc143';
  $pane = new stdClass();
  $pane->pid = 'new-f9fd34b2-d815-40ad-8f67-96ecf7720123';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-QX0wNxgaFAuXRaStHqP7RDFWZ96tjZbI';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f9fd34b2-d815-40ad-8f67-96ecf7720123';
  $display->content['new-f9fd34b2-d815-40ad-8f67-96ecf7720123'] = $pane;
  $display->panels['middle'][5] = 'new-f9fd34b2-d815-40ad-8f67-96ecf7720123';
  $pane = new stdClass();
  $pane->pid = 'new-66c3b5d8-18a9-4797-b538-42fd5d9590df';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-M2vM9LgyKi5cKmXOp1x93wHqDOGFVfXF';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '66c3b5d8-18a9-4797-b538-42fd5d9590df';
  $display->content['new-66c3b5d8-18a9-4797-b538-42fd5d9590df'] = $pane;
  $display->panels['middle'][6] = 'new-66c3b5d8-18a9-4797-b538-42fd5d9590df';
  $pane = new stdClass();
  $pane->pid = 'new-95fba7b6-cf1e-4c2a-ae34-8fdf855941fc';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-nJIaAlI0wnx403mttB1N9KoY9XFTy9Qj';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '95fba7b6-cf1e-4c2a-ae34-8fdf855941fc';
  $display->content['new-95fba7b6-cf1e-4c2a-ae34-8fdf855941fc'] = $pane;
  $display->panels['middle'][7] = 'new-95fba7b6-cf1e-4c2a-ae34-8fdf855941fc';
  $pane = new stdClass();
  $pane->pid = 'new-8f4f2e86-b0a9-442e-8b7d-aa8dd5d3e865';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-HDbRSwWvJN4Bx202RSgJnMk5a1THlm86';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '8f4f2e86-b0a9-442e-8b7d-aa8dd5d3e865';
  $display->content['new-8f4f2e86-b0a9-442e-8b7d-aa8dd5d3e865'] = $pane;
  $display->panels['middle'][8] = 'new-8f4f2e86-b0a9-442e-8b7d-aa8dd5d3e865';
  $pane = new stdClass();
  $pane->pid = 'new-d0a8032c-57bb-4e02-8b59-381d5365ee35';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zhswH6MGO5d301aJczIXvKBzZXmSE9uQ';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'd0a8032c-57bb-4e02-8b59-381d5365ee35';
  $display->content['new-d0a8032c-57bb-4e02-8b59-381d5365ee35'] = $pane;
  $display->panels['middle'][9] = 'new-d0a8032c-57bb-4e02-8b59-381d5365ee35';
  $pane = new stdClass();
  $pane->pid = 'new-ddc1cc0b-c753-44d4-ad66-3a4814e55a78';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-YXn7d3LSpmu1RkcQfGIazwLrAip1U1Ed';
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
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'ddc1cc0b-c753-44d4-ad66-3a4814e55a78';
  $display->content['new-ddc1cc0b-c753-44d4-ad66-3a4814e55a78'] = $pane;
  $display->panels['middle'][10] = 'new-ddc1cc0b-c753-44d4-ad66-3a4814e55a78';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['teacher_activity_center_sidebar'] = $mini;

  return $export;
}
