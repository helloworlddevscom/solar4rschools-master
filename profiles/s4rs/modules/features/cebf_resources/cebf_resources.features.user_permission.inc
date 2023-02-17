<?php
/**
 * @file
 * cebf_resources.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cebf_resources_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear resources_csv feeds'.
  $permissions['clear resources_csv feeds'] = array(
    'name' => 'clear resources_csv feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'create new resource'.
  $permissions['create new resource'] = array(
    'name' => 'create new resource',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cebf_resources',
  );

  // Exported permission: 'import resources_csv feeds'.
  $permissions['import resources_csv feeds'] = array(
    'name' => 'import resources_csv feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock resources_csv feeds'.
  $permissions['unlock resources_csv feeds'] = array(
    'name' => 'unlock resources_csv feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'feeds',
  );

  return $permissions;
}
