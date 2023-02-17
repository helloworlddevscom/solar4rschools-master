<?php
/**
 * @file
 * bef_misc_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bef_misc_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
