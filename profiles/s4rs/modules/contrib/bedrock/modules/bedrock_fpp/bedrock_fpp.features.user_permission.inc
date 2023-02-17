<?php
/**
 * @file
 * bedrock_fpp.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bedrock_fpp_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable slide'.
  $permissions['create fieldable slide'] = array(
    'name' => 'create fieldable slide',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable slideshow'.
  $permissions['create fieldable slideshow'] = array(
    'name' => 'create fieldable slideshow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable slide'.
  $permissions['delete fieldable slide'] = array(
    'name' => 'delete fieldable slide',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable slideshow'.
  $permissions['delete fieldable slideshow'] = array(
    'name' => 'delete fieldable slideshow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable slide'.
  $permissions['edit fieldable slide'] = array(
    'name' => 'edit fieldable slide',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable slideshow'.
  $permissions['edit fieldable slideshow'] = array(
    'name' => 'edit fieldable slideshow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
