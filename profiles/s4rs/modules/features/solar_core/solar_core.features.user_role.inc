<?php
/**
 * @file
 * solar_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function solar_core_user_default_roles() {
  $roles = array();

  // Exported role: Funder.
  $roles['Funder'] = array(
    'name' => 'Funder',
    'weight' => 2,
  );

  // Exported role: educator.
  $roles['educator'] = array(
    'name' => 'educator',
    'weight' => 4,
  );

  // Exported role: teacher champion.
  $roles['teacher champion'] = array(
    'name' => 'teacher champion',
    'weight' => 6,
  );

  // Exported role: wiki editor.
  $roles['wiki editor'] = array(
    'name' => 'wiki editor',
    'weight' => 3,
  );

  return $roles;
}
