<?php
/**
 * @file
 * solar_core.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function solar_core_features_override_default_overrides() {
  // This code is only used for UI in features.
  // Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: file_type.
  $overrides["file_type.document.disabled"] = FALSE;
  $overrides["file_type.document.mimetypes|11"] = 'application/zip';

  // Exported overrides for: views_view.
  $overrides["views_view.media_default.display|default|display_options|access|perm"] = 'administer files';

  return $overrides;
}
