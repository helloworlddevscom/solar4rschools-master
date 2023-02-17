<?php

/**
 * @file
 * Bedrock Granite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Jerusalem Marble'),
  'icon' => 'jerusalem_marble.png',
  'category' => t('Bedrock'),
  'theme' => 'jerusalem_marble',
  'admin css' => 'admin.jerusalem_marble.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'column_left' => t('Column Left'),
    'column_inner_left' => t('Column Inner Left'),
    'column_inner_right' => t('Column Inner Right'),
    'column_right' => t('Column Right'),
    'content_full' => t('Column Full-Width'),
  ),
);
