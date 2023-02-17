<?php
/**
 * @file
 * solar_projects.ctools_rulesets.inc
 */

/**
 * Implements hook_default_ctools_access_ruleset().
 */
function solar_projects_default_ctools_access_ruleset() {
  $export = array();

  $ruleset = new stdClass();
  $ruleset->disabled = FALSE; /* Edit this to true to make a default ruleset disabled initially */
  $ruleset->api_version = 1;
  $ruleset->name = 'can_see_project_tabs';
  $ruleset->admin_title = 'Can see User tabs';
  $ruleset->admin_description = 'My Projects should only show up for certain users.';
  $ruleset->requiredcontexts = array(
    0 => array(
      'identifier' => 'User',
      'keyword' => 'user',
      'name' => 'user',
      'type' => 'select',
      'uid' => '',
      'id' => 1,
    ),
  );
  $ruleset->contexts = array();
  $ruleset->relationships = array();
  $ruleset->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer users',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'requiredcontext_user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $export['can_see_project_tabs'] = $ruleset;

  return $export;
}
