<?php

/**
 * @file
 * Bedrock Basalt panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Basalt'),
  'icon' => 'basalt.png',
  'category' => t('Bedrock'),
  'theme' => 'basalt',
  'admin css' => 'admin.basalt.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'column_left' => t('Column Left'),
    'column_middle' => t('Column Middle'),
    'column_right' => t('Column Right'),
  ),
);
