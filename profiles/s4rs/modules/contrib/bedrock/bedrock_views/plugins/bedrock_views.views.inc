<?php
/**
 * @file
 * Contains Views module hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function bedrock_views_views_plugins() {
  $path = drupal_get_path('module', 'bedrock_views');
  return array(
    'module' => 'bedrock_views',
    'row' => array(
      'dropdown' => array(
        'title' => t('Hover dropdown'),
        'help' => t('Displays items in a dropdown on mouseover'),
        'handler' => 'bedrock_views_plugin_row_hover',
        'path' => $path . '/plugins',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'theme' => 'bedrock_views_view_fields',
        'theme file' => 'bedrock_views.theme.inc',
        'theme path' => $path . '/theme',
        'type' => 'normal',
      ),
    ),
  );
}
