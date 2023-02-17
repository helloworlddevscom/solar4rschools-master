<?php

/**
 * @file
 * Bedrock Jadeite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Jadeite'),
  'icon' => 'jadeite.png',
  'category' => t('Bedrock'),
  'theme' => 'jadeite',
  'admin css' => 'admin.jadeite.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'column_left_top' => t('Column Left Top'),
    'column_middle_top' => t('Column Middle Top'),
    'column_right_top' => t('Column Right Top'),
    'column_left_bottom' => t('Column Left Bottom'),
    'column_middle_bottom' => t('Column Middle Bottom'),
    'column_right_bottom' => t('Column Right Bottom'),
  ),
);
