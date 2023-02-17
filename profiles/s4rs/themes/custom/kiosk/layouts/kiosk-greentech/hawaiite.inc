<?php

/**
 * @file
 * Bedrock Hawaiite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Hawaiite'),
  'icon' => 'hawaiite.png',
  'category' => t('Bedrock'),
  'theme' => 'hawaiite',
  'admin css' => 'admin.hawaiite.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'column_left' => t('Column Left'),
    'column_middle' => t('Column Middle'),
    'column_right' => t('Column Right'),
    'content_footer' => t('Content Footer'),
  ),
);
