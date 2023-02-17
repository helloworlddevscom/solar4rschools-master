<?php
/**
 * @file
 * solar_core.default_link_pane_presets.inc
 */

/**
 * Implements hook_default_link_pane_preset().
 */
function solar_core_default_link_pane_preset() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'activity_add';
  $preset->admin_title = 'Activity Add';
  $preset->description = 'A link to add an activity';
  $preset->text = 'Add new activity';
  $preset->path = 'node/add/activity';
  $preset->query = '';
  $preset->fragment = '';
  $preset->absolute = FALSE;
  $preset->alias = FALSE;
  $preset->external = FALSE;
  $preset->https = FALSE;
  $preset->id = '';
  $preset->class = 'flag';
  $preset->title = '';
  $preset->target = '';
  $preset->tabindex = '';
  $preset->accesskey = '';
  $export['activity_add'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'funder_edit_profile';
  $preset->admin_title = 'Funder edit profile';
  $preset->description = 'The funder will see this on any project they\'ve funded';
  $preset->text = 'Edit my profile';
  $preset->path = 'user/[current-user:uid]/edit';
  $preset->query = '';
  $preset->fragment = '';
  $preset->absolute = FALSE;
  $preset->alias = FALSE;
  $preset->external = FALSE;
  $preset->https = FALSE;
  $preset->id = '';
  $preset->class = 'flag';
  $preset->title = '';
  $preset->target = '';
  $preset->tabindex = '';
  $preset->accesskey = '';
  $export['funder_edit_profile'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'get_widgets';
  $preset->admin_title = 'Get widgets';
  $preset->description = 'Link to a project\'s widgets';
  $preset->text = 'Get my data widgets';
  $preset->path = 'user/[current-user:uid]/my-resources';
  $preset->query = '';
  $preset->fragment = '';
  $preset->absolute = FALSE;
  $preset->alias = FALSE;
  $preset->external = FALSE;
  $preset->https = FALSE;
  $preset->id = '';
  $preset->class = 'flag';
  $preset->title = '';
  $preset->target = '';
  $preset->tabindex = '';
  $preset->accesskey = '';
  $export['get_widgets'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'request_removal_of_activity';
  $preset->admin_title = 'Request removal of activity';
  $preset->description = 'If you\'ve created an activity you might not have the permissions to delete it.';
  $preset->text = 'Request this activity\'s removal';
  $preset->path = 'eform/submit/request-removal-of-an-activity';
  $preset->query = 'field_activities_to_remove=[node:nid]';
  $preset->fragment = '';
  $preset->absolute = FALSE;
  $preset->alias = FALSE;
  $preset->external = FALSE;
  $preset->https = FALSE;
  $preset->id = '';
  $preset->class = 'flag';
  $preset->title = '';
  $preset->target = '';
  $preset->tabindex = '';
  $preset->accesskey = '';
  $export['request_removal_of_activity'] = $preset;

  return $export;
}
