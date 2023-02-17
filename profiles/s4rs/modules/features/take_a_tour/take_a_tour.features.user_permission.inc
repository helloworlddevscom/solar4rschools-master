<?php
/**
 * @file
 * take_a_tour.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function take_a_tour_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add tour_video bundles'.
  $permissions['eck add tour_video bundles'] = array(
    'name' => 'eck add tour_video bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add tour_video tour_video entities'.
  $permissions['eck add tour_video tour_video entities'] = array(
    'name' => 'eck add tour_video tour_video entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer tour_video bundles'.
  $permissions['eck administer tour_video bundles'] = array(
    'name' => 'eck administer tour_video bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer tour_video tour_video entities'.
  $permissions['eck administer tour_video tour_video entities'] = array(
    'name' => 'eck administer tour_video tour_video entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete tour_video bundles'.
  $permissions['eck delete tour_video bundles'] = array(
    'name' => 'eck delete tour_video bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete tour_video tour_video entities'.
  $permissions['eck delete tour_video tour_video entities'] = array(
    'name' => 'eck delete tour_video tour_video entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit tour_video bundles'.
  $permissions['eck edit tour_video bundles'] = array(
    'name' => 'eck edit tour_video bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit tour_video tour_video entities'.
  $permissions['eck edit tour_video tour_video entities'] = array(
    'name' => 'eck edit tour_video tour_video entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list tour_video bundles'.
  $permissions['eck list tour_video bundles'] = array(
    'name' => 'eck list tour_video bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list tour_video tour_video entities'.
  $permissions['eck list tour_video tour_video entities'] = array(
    'name' => 'eck list tour_video tour_video entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view tour_video bundles'.
  $permissions['eck view tour_video bundles'] = array(
    'name' => 'eck view tour_video bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view tour_video tour_video entities'.
  $permissions['eck view tour_video tour_video entities'] = array(
    'name' => 'eck view tour_video tour_video entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage tour_video properties'.
  $permissions['manage tour_video properties'] = array(
    'name' => 'manage tour_video properties',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  return $permissions;
}
