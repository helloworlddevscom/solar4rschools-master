<?php
/**
 * @file
 * solar_homepage.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function solar_homepage_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'homepage_callout';
  $picture_mapping->machine_name = 'homepage_callout';
  $picture_mapping->breakpoint_group = 'homepage_callout';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flare.xlarge' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_callout_breakpoints_theme_flare_xlarge_1x',
      ),
    ),
    'breakpoints.theme.flare.large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_callout_breakpoints_theme_flare_large_1x',
      ),
    ),
    'breakpoints.theme.flare.medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_callout_breakpoints_theme_flare_medium_1x',
      ),
    ),
    'breakpoints.theme.flare.small' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_callout_breakpoints_theme_flare_small_1x',
      ),
    ),
    'breakpoints.theme.flare.default' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_callout_breakpoints_theme_flare_default_1x',
      ),
    ),
  );
  $export['homepage_callout'] = $picture_mapping;

  return $export;
}
