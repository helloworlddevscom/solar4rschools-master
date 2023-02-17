<?php
/**
 * @file
 * solar_activities.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function solar_activities_features_override_default_overrides() {
  // This code is only used for UI in features.
  // Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: user_permission.
  $overrides["user_permission.use basic cart.roles|anonymous user"]["DELETED"] = TRUE;
  $overrides["user_permission.use basic cart.roles|educator"] = 'educator';
  $overrides["user_permission.use basic cart.roles|teacher champion"] = 'teacher champion';

  return $overrides;
}
