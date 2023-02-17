<?php

/**
 * @file
 * Bedrock Granite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Granite'),
  'icon' => 'granite.png',
  'category' => t('Bedrock'),
  'theme' => 'granite',
  'admin css' => 'admin.granite.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'column_left' => t('Column Left'),
    'column_right' => t('Column Right'),
  ),
);
