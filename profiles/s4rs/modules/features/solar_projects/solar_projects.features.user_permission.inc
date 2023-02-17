<?php
/**
 * @file
 * solar_projects.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_projects_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'og',
  );

  // Exported permission: 'create field_photo_gallery'.
  $permissions['create field_photo_gallery'] = array(
    'name' => 'create field_photo_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_video_gallery'.
  $permissions['create field_video_gallery'] = array(
    'name' => 'create field_video_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project_files content'.
  $permissions['create project_files content'] = array(
    'name' => 'create project_files content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project_files content'.
  $permissions['delete any project_files content'] = array(
    'name' => 'delete any project_files content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project_files content'.
  $permissions['delete own project_files content'] = array(
    'name' => 'delete own project_files content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project_files content'.
  $permissions['edit any project_files content'] = array(
    'name' => 'edit any project_files content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_photo_gallery'.
  $permissions['edit field_photo_gallery'] = array(
    'name' => 'edit field_photo_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_video_gallery'.
  $permissions['edit field_video_gallery'] = array(
    'name' => 'edit field_video_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_photo_gallery'.
  $permissions['edit own field_photo_gallery'] = array(
    'name' => 'edit own field_photo_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_video_gallery'.
  $permissions['edit own field_video_gallery'] = array(
    'name' => 'edit own field_video_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project_files content'.
  $permissions['edit own project_files content'] = array(
    'name' => 'edit own project_files content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag my_projects_to_explore'.
  $permissions['flag my_projects_to_explore'] = array(
    'name' => 'flag my_projects_to_explore',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag my_projects_to_explore'.
  $permissions['unflag my_projects_to_explore'] = array(
    'name' => 'unflag my_projects_to_explore',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'view field_photo_gallery'.
  $permissions['view field_photo_gallery'] = array(
    'name' => 'view field_photo_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_video_gallery'.
  $permissions['view field_video_gallery'] = array(
    'name' => 'view field_video_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_photo_gallery'.
  $permissions['view own field_photo_gallery'] = array(
    'name' => 'view own field_photo_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_video_gallery'.
  $permissions['view own field_video_gallery'] = array(
    'name' => 'view own field_video_gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
