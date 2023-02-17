<?php
/**
 * @file
 * solar_slideshow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_slideshow_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update homepage_slideshow entityqueue'.
  $permissions['update homepage_slideshow entityqueue'] = array(
    'name' => 'update homepage_slideshow entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'entityqueue',
  );

  return $permissions;
}
