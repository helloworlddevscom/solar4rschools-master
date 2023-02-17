<?php
/**
 * @file
 * solar_kiosk.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_kiosk_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'configure weather block debug'.
  $permissions['configure weather block debug'] = array(
    'name' => 'configure weather block debug',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'solar_weather',
  );

  // Exported permission: 'create fieldable green_tech_content'.
  $permissions['create fieldable green_tech_content'] = array(
    'name' => 'create fieldable green_tech_content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create kiosk content'.
  $permissions['create kiosk content'] = array(
    'name' => 'create kiosk content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any kiosk content'.
  $permissions['delete any kiosk content'] = array(
    'name' => 'delete any kiosk content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete fieldable green_tech_content'.
  $permissions['delete fieldable green_tech_content'] = array(
    'name' => 'delete fieldable green_tech_content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete own kiosk content'.
  $permissions['delete own kiosk content'] = array(
    'name' => 'delete own kiosk content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any kiosk content'.
  $permissions['edit any kiosk content'] = array(
    'name' => 'edit any kiosk content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit fieldable green_tech_content'.
  $permissions['edit fieldable green_tech_content'] = array(
    'name' => 'edit fieldable green_tech_content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit own kiosk content'.
  $permissions['edit own kiosk content'] = array(
    'name' => 'edit own kiosk content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view weather block debug'.
  $permissions['view weather block debug'] = array(
    'name' => 'view weather block debug',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'solar_weather',
  );

  return $permissions;
}
