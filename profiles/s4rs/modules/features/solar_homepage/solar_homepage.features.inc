<?php
/**
 * @file
 * solar_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function solar_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: homepage_callout.
  $styles['homepage_callout'] = array(
    'label' => 'Homepage callout',
    'effects' => array(),
  );

  // Exported image style: homepage_callout_breakpoints_theme_flare_default_1x.
  $styles['homepage_callout_breakpoints_theme_flare_default_1x'] = array(
    'label' => 'homepage_callout_breakpoints_theme_flare_default_1x',
    'effects' => array(),
  );

  // Exported image style: homepage_callout_breakpoints_theme_flare_large_1x.
  $styles['homepage_callout_breakpoints_theme_flare_large_1x'] = array(
    'label' => 'homepage_callout_breakpoints_theme_flare_large_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_callout_breakpoints_theme_flare_medium_1x.
  $styles['homepage_callout_breakpoints_theme_flare_medium_1x'] = array(
    'label' => 'homepage_callout_breakpoints_theme_flare_medium_1x',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_callout_breakpoints_theme_flare_small_1x.
  $styles['homepage_callout_breakpoints_theme_flare_small_1x'] = array(
    'label' => 'homepage_callout_breakpoints_theme_flare_small_1x',
    'effects' => array(),
  );

  // Exported image style: homepage_callout_breakpoints_theme_flare_xlarge_1x.
  $styles['homepage_callout_breakpoints_theme_flare_xlarge_1x'] = array(
    'label' => 'homepage_callout_breakpoints_theme_flare_xlarge_1x',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 375,
          'height' => 225,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
