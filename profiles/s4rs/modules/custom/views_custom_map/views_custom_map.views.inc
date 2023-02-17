<?php

// $Id: views_custom_map.views.inc 88 2009-04-02 01:58:26Z jhedstrom $

/**
 * @file
 * Views hooks for Views Custom Map module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_custom_map_views_plugins() {

  $plugins = array();

  $plugins['style'] = array(
    'custom_map' => array(
      'title' => t('Custom map'),
      'help' => t('Displays rows on a custom map.'),
      'handler' => 'views_plugin_style_custom_map',
      'path' => drupal_get_path('module', 'views_custom_map'),
      'uses row plugin' => TRUE,
      'uses options' => TRUE,
      'uses fields' => TRUE,
      'type' => 'normal',
    ),
  );

  return $plugins;
}
