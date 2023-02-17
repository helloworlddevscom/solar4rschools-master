<?php
/**
 * @file
 * solar_kiosk.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_kiosk_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
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
function solar_kiosk_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function solar_kiosk_image_default_styles() {
  $styles = array();

  // Exported image style: kiosk_about_project_image.
  $styles['kiosk_about_project_image'] = array(
    'label' => 'Kiosk About Project Image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 492,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function solar_kiosk_node_info() {
  $items = array(
    'kiosk' => array(
      'name' => t('Kiosk'),
      'base' => 'node_content',
      'description' => t('Kiosks display project information with a special theme for use in kiosks at a specific site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
