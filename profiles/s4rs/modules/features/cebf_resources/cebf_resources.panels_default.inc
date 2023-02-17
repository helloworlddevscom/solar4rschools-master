<?php
/**
 * @file
 * cebf_resources.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function cebf_resources_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'resource_library_sidebar';
  $mini->category = '';
  $mini->admin_title = 'Resource Library Sidebar';
  $mini->admin_description = 'Sidebar for Resource Library containing search fields and facets.';
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
  $display->storage_id = 'resource_library_sidebar';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bdba8010-5dcb-47ec-80ff-aa4230da37ed';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-83962dd7ecba3db8c81bf0f049ca5663';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
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
  $pane->uuid = 'bdba8010-5dcb-47ec-80ff-aa4230da37ed';
  $display->content['new-bdba8010-5dcb-47ec-80ff-aa4230da37ed'] = $pane;
  $display->panels['middle'][0] = 'new-bdba8010-5dcb-47ec-80ff-aa4230da37ed';
  $pane = new stdClass();
  $pane->pid = 'new-baa646b4-6801-4dc6-ae9b-dda110ce6fc0';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Resource Library Sidebar - Help Text',
    'title' => '<none>',
    'title_heading' => 'h2',
    'body' => '<p style="font-size: 13.008px;"><span style="color: rgb(23, 43, 77); font-family: -apple-system, system-ui, &quot;Segoe UI&quot;, Roboto, Oxygen, Ubuntu, &quot;Fira Sans&quot;, &quot;Droid Sans&quot;, &quot;Helvetica Neue&quot;, sans-serif; font-size: 14px; letter-spacing: -0.07px; white-space: pre-wrap;">Select all that apply. </span></p><p style="font-size: 13.008px;"><span style="color: rgb(23, 43, 77); font-family: -apple-system, system-ui, &quot;Segoe UI&quot;, Roboto, Oxygen, Ubuntu, &quot;Fira Sans&quot;, &quot;Droid Sans&quot;, &quot;Helvetica Neue&quot;, sans-serif; font-size: 14px; letter-spacing: -0.07px; white-space: pre-wrap;">You can select more than one option from each field.</span></p>',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'resource-library-sidebar__help-text',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'baa646b4-6801-4dc6-ae9b-dda110ce6fc0';
  $display->content['new-baa646b4-6801-4dc6-ae9b-dda110ce6fc0'] = $pane;
  $display->panels['middle'][1] = 'new-baa646b4-6801-4dc6-ae9b-dda110ce6fc0';
  $pane = new stdClass();
  $pane->pid = 'new-dc31d050-4c07-485b-826a-7ca833c33fa2';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-BTwaoQK0shIAZIMKWaX4hoNlqsrvnJmf';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dc31d050-4c07-485b-826a-7ca833c33fa2';
  $display->content['new-dc31d050-4c07-485b-826a-7ca833c33fa2'] = $pane;
  $display->panels['middle'][2] = 'new-dc31d050-4c07-485b-826a-7ca833c33fa2';
  $pane = new stdClass();
  $pane->pid = 'new-d74b7265-a455-482a-825b-e8a2d1dd1cd4';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-ZkNIc1aqWaAqX1DxOK10bQwtPb7G08jY';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd74b7265-a455-482a-825b-e8a2d1dd1cd4';
  $display->content['new-d74b7265-a455-482a-825b-e8a2d1dd1cd4'] = $pane;
  $display->panels['middle'][3] = 'new-d74b7265-a455-482a-825b-e8a2d1dd1cd4';
  $pane = new stdClass();
  $pane->pid = 'new-5a4da3c0-ba02-42f0-91d2-8eae5f8d76a3';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-pnsC86BpIdrsHvByyY2NBj07YQCTSct1';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5a4da3c0-ba02-42f0-91d2-8eae5f8d76a3';
  $display->content['new-5a4da3c0-ba02-42f0-91d2-8eae5f8d76a3'] = $pane;
  $display->panels['middle'][4] = 'new-5a4da3c0-ba02-42f0-91d2-8eae5f8d76a3';
  $pane = new stdClass();
  $pane->pid = 'new-9e6b6ff3-ba4b-484c-8d38-2ce92c5ecb6a';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-bklDVeycudj44v0wX301ATBYodcaYHev';
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
  $pane->uuid = '9e6b6ff3-ba4b-484c-8d38-2ce92c5ecb6a';
  $display->content['new-9e6b6ff3-ba4b-484c-8d38-2ce92c5ecb6a'] = $pane;
  $display->panels['middle'][5] = 'new-9e6b6ff3-ba4b-484c-8d38-2ce92c5ecb6a';
  $pane = new stdClass();
  $pane->pid = 'new-545ec679-ae89-4d37-bb74-2764852be2df';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-sCUZ3xWUHSFErHqsQdwe87cIBw0QfJZO';
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
  $pane->uuid = '545ec679-ae89-4d37-bb74-2764852be2df';
  $display->content['new-545ec679-ae89-4d37-bb74-2764852be2df'] = $pane;
  $display->panels['middle'][6] = 'new-545ec679-ae89-4d37-bb74-2764852be2df';
  $pane = new stdClass();
  $pane->pid = 'new-c6b484a0-4904-42fa-b8f4-d48f62c91d19';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-HBSWwgK0vcVrxAl47x3fAU4N0AP4kjnL';
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
  $pane->uuid = 'c6b484a0-4904-42fa-b8f4-d48f62c91d19';
  $display->content['new-c6b484a0-4904-42fa-b8f4-d48f62c91d19'] = $pane;
  $display->panels['middle'][7] = 'new-c6b484a0-4904-42fa-b8f4-d48f62c91d19';
  $pane = new stdClass();
  $pane->pid = 'new-d0aca5ac-3154-4621-a854-e7a60854c379';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zN6XWL40YIZ7SycwrgGw01ogdEKNYMEk';
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
  $pane->uuid = 'd0aca5ac-3154-4621-a854-e7a60854c379';
  $display->content['new-d0aca5ac-3154-4621-a854-e7a60854c379'] = $pane;
  $display->panels['middle'][8] = 'new-d0aca5ac-3154-4621-a854-e7a60854c379';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['resource_library_sidebar'] = $mini;

  return $export;
}
