<?php
/**
 * @file
 * solar_funders.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_funders_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any funder profile'.
  $permissions['edit any funder profile'] = array(
    'name' => 'edit any funder profile',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own funder profile'.
  $permissions['edit own funder profile'] = array(
    'name' => 'edit own funder profile',
    'roles' => array(
      'Funder' => 'Funder',
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any funder profile'.
  $permissions['view any funder profile'] = array(
    'name' => 'view any funder profile',
    'roles' => array(
      'Funder' => 'Funder',
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own funder profile'.
  $permissions['view own funder profile'] = array(
    'name' => 'view own funder profile',
    'roles' => array(
      'Funder' => 'Funder',
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
