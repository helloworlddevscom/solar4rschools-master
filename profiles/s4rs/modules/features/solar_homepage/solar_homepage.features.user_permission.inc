<?php
/**
 * @file
 * solar_homepage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_homepage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable carousel_slide'.
  $permissions['create fieldable carousel_slide'] = array(
    'name' => 'create fieldable carousel_slide',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable carousel_slideshow'.
  $permissions['create fieldable carousel_slideshow'] = array(
    'name' => 'create fieldable carousel_slideshow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable homepage_callouts'.
  $permissions['create fieldable homepage_callouts'] = array(
    'name' => 'create fieldable homepage_callouts',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable carousel_slide'.
  $permissions['delete fieldable carousel_slide'] = array(
    'name' => 'delete fieldable carousel_slide',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable carousel_slideshow'.
  $permissions['delete fieldable carousel_slideshow'] = array(
    'name' => 'delete fieldable carousel_slideshow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable homepage_callouts'.
  $permissions['delete fieldable homepage_callouts'] = array(
    'name' => 'delete fieldable homepage_callouts',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable carousel_slide'.
  $permissions['edit fieldable carousel_slide'] = array(
    'name' => 'edit fieldable carousel_slide',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable carousel_slideshow'.
  $permissions['edit fieldable carousel_slideshow'] = array(
    'name' => 'edit fieldable carousel_slideshow',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable homepage_callouts'.
  $permissions['edit fieldable homepage_callouts'] = array(
    'name' => 'edit fieldable homepage_callouts',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
