<?php
/**
 * @file
 * solar_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ctools_access_ruleset" && $api == "ctools_rulesets") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
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
 * Implements hook_views_api().
 */
function solar_projects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function solar_projects_flag_default_flags() {
  $flags = array();
  // Exported flag: "My Projects to Explore".
  $flags['my_projects_to_explore'] = array(
    'entity_type' => 'node',
    'title' => 'My Projects to Explore',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Add to My Projects to Explore',
    'flag_long' => 'Add to My Projects to Explore',
    'flag_message' => 'Added',
    'unflag_short' => 'Remove from My Projects to Explore',
    'unflag_long' => 'Remove from My Projects to Explore',
    'unflag_message' => 'Removed',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'reference' => 0,
      'diff_standard' => 0,
      'map_bubble_teaser' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'solar_projects',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function solar_projects_image_default_styles() {
  $styles = array();

  // Exported image style: project_large.
  $styles['project_large'] = array(
    'label' => 'Project large',
    'effects' => array(),
  );

  // Exported image style: project_large_breakpoints_theme_flare_default_1x.
  $styles['project_large_breakpoints_theme_flare_default_1x'] = array(
    'label' => 'project_large_breakpoints_theme_flare_default_1x',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 310,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_large_breakpoints_theme_flare_large_1x.
  $styles['project_large_breakpoints_theme_flare_large_1x'] = array(
    'label' => 'project_large_breakpoints_theme_flare_large_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 940,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_large_breakpoints_theme_flare_medium_1x.
  $styles['project_large_breakpoints_theme_flare_medium_1x'] = array(
    'label' => 'project_large_breakpoints_theme_flare_medium_1x',
    'effects' => array(),
  );

  // Exported image style: project_large_breakpoints_theme_flare_small_1x.
  $styles['project_large_breakpoints_theme_flare_small_1x'] = array(
    'label' => 'project_large_breakpoints_theme_flare_small_1x',
    'effects' => array(),
  );

  // Exported image style: project_large_breakpoints_theme_flare_xlarge_1x.
  $styles['project_large_breakpoints_theme_flare_xlarge_1x'] = array(
    'label' => 'project_large_breakpoints_theme_flare_xlarge_1x',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 877,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_small.
  $styles['project_small'] = array(
    'label' => 'Project small',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 215,
          'height' => 145,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_small_breakpoints_theme_flare_default_1x.
  $styles['project_small_breakpoints_theme_flare_default_1x'] = array(
    'label' => 'project_small_breakpoints_theme_flare_default_1x',
    'effects' => array(),
  );

  // Exported image style: project_small_breakpoints_theme_flare_large_1x.
  $styles['project_small_breakpoints_theme_flare_large_1x'] = array(
    'label' => 'project_small_breakpoints_theme_flare_large_1x',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_small_breakpoints_theme_flare_medium_1x.
  $styles['project_small_breakpoints_theme_flare_medium_1x'] = array(
    'label' => 'project_small_breakpoints_theme_flare_medium_1x',
    'effects' => array(),
  );

  // Exported image style: project_small_breakpoints_theme_flare_small_1x.
  $styles['project_small_breakpoints_theme_flare_small_1x'] = array(
    'label' => 'project_small_breakpoints_theme_flare_small_1x',
    'effects' => array(),
  );

  // Exported image style: project_small_breakpoints_theme_flare_xlarge_1x.
  $styles['project_small_breakpoints_theme_flare_xlarge_1x'] = array(
    'label' => 'project_small_breakpoints_theme_flare_xlarge_1x',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 210,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_thumbnail.
  $styles['project_thumbnail'] = array(
    'label' => 'project_thumbnail_220x175',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 175,
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
function solar_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Projects have associated data collection.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project_files' => array(
      'name' => t('Project Files'),
      'base' => 'node_content',
      'description' => t('Files that belong to a given project, or to all projects.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
