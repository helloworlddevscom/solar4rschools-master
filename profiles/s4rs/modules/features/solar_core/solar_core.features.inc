<?php
/**
 * @file
 * solar_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "link_pane" && $api == "default_link_pane_presets") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function solar_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_file_default_types_alter().
 */
function solar_core_file_default_types_alter(&$data) {
  if (isset($data['document'])) {
    $data['document']->disabled = FALSE; /* WAS: '' */
    $data['document']->mimetypes['11'] = 'application/zip'; /* WAS: 'application/vnd.openxmlformats-officedocument.presentationml.presentation' */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function solar_core_views_default_views_alter(&$data) {
  if (isset($data['media_default'])) {
    $data['media_default']->display['default']->display_options['access']['perm'] = 'administer files'; /* WAS: 'view files' */
  }
}

/**
 * Implements hook_image_default_styles().
 */
function solar_core_image_default_styles() {
  $styles = array();

  // Exported image style: funder_icon.
  $styles['funder_icon'] = array(
    'label' => 'Funder icon',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 50,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: funder_small.
  $styles['funder_small'] = array(
    'label' => 'Funder small',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => 75,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: icon.
  $styles['icon'] = array(
    'label' => 'Icon',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 55,
          'height' => 50,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
