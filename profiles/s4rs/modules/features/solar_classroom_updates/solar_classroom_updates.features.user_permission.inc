<?php
/**
 * @file
 * solar_classroom_updates.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_classroom_updates_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create classroom_updates content'.
  $permissions['create classroom_updates content'] = array(
    'name' => 'create classroom_updates content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any classroom_updates content'.
  $permissions['delete any classroom_updates content'] = array(
    'name' => 'delete any classroom_updates content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own classroom_updates content'.
  $permissions['delete own classroom_updates content'] = array(
    'name' => 'delete own classroom_updates content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any classroom_updates content'.
  $permissions['edit any classroom_updates content'] = array(
    'name' => 'edit any classroom_updates content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own classroom_updates content'.
  $permissions['edit own classroom_updates content'] = array(
    'name' => 'edit own classroom_updates content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'node',
  );

  return $permissions;
}
