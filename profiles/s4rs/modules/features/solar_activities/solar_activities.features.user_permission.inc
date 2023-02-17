<?php
/**
 * @file
 * solar_activities.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_activities_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create activities without bio'.
  $permissions['create activities without bio'] = array(
    'name' => 'create activities without bio',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'solar_activities',
  );

  // Exported permission: 'create activity content'.
  $permissions['create activity content'] = array(
    'name' => 'create activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create order content'.
  $permissions['create order content'] = array(
    'name' => 'create order content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create science_kit content'.
  $permissions['create science_kit content'] = array(
    'name' => 'create science_kit content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any activity content'.
  $permissions['delete any activity content'] = array(
    'name' => 'delete any activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any order content'.
  $permissions['delete any order content'] = array(
    'name' => 'delete any order content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any science_kit content'.
  $permissions['delete any science_kit content'] = array(
    'name' => 'delete any science_kit content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own activity content'.
  $permissions['delete own activity content'] = array(
    'name' => 'delete own activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own order content'.
  $permissions['delete own order content'] = array(
    'name' => 'delete own order content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own science_kit content'.
  $permissions['delete own science_kit content'] = array(
    'name' => 'delete own science_kit content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any activity content'.
  $permissions['edit any activity content'] = array(
    'name' => 'edit any activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any order content'.
  $permissions['edit any order content'] = array(
    'name' => 'edit any order content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any science_kit content'.
  $permissions['edit any science_kit content'] = array(
    'name' => 'edit any science_kit content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own activity content'.
  $permissions['edit own activity content'] = array(
    'name' => 'edit own activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own order content'.
  $permissions['edit own order content'] = array(
    'name' => 'edit own order content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own science_kit content'.
  $permissions['edit own science_kit content'] = array(
    'name' => 'edit own science_kit content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag my_saved_activities'.
  $permissions['flag my_saved_activities'] = array(
    'name' => 'flag my_saved_activities',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'unflag my_saved_activities'.
  $permissions['unflag my_saved_activities'] = array(
    'name' => 'unflag my_saved_activities',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
