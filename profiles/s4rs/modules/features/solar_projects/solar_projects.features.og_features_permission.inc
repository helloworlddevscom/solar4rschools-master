<?php
/**
 * @file
 * solar_projects.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function solar_projects_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:project:administer group'
  $permissions['node:project:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:create classroom_updates content'
  $permissions['node:project:create classroom_updates content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:create project content'
  $permissions['node:project:create project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create project_files content'
  $permissions['node:project:create project_files content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:delete any classroom_updates content'
  $permissions['node:project:delete any classroom_updates content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any project content'
  $permissions['node:project:delete any project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any project_files content'
  $permissions['node:project:delete any project_files content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own classroom_updates content'
  $permissions['node:project:delete own classroom_updates content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own project content'
  $permissions['node:project:delete own project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own project_files content'
  $permissions['node:project:delete own project_files content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any classroom_updates content'
  $permissions['node:project:update any classroom_updates content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any project content'
  $permissions['node:project:update any project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any project_files content'
  $permissions['node:project:update any project_files content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update group'
  $permissions['node:project:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update own classroom_updates content'
  $permissions['node:project:update own classroom_updates content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:update own project content'
  $permissions['node:project:update own project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update own project_files content'
  $permissions['node:project:update own project_files content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
