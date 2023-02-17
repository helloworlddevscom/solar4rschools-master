<?php
/**
 * @file
 * solar_slideshow.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function solar_slideshow_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_slideshow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function solar_slideshow_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function solar_slideshow_image_default_styles() {
  $styles = array();

  // Exported image style: slideshow.
  $styles['slideshow'] = array(
    'label' => 'Slideshow',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 450,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function solar_slideshow_node_info() {
  $items = array(
    'front_slide' => array(
      'name' => t('Front Slide'),
      'base' => 'node_content',
      'description' => t('To create a slider for the homepage slide show, create <em>Front Slide</em> content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
