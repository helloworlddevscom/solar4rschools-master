<?php

/**
 * @file
 * Bedrock Andesite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Andesite'),
  'icon' => 'andesite.png',
  'category' => t('Bedrock'),
  'theme' => 'andesite',
  'admin css' => 'admin.andesite.css',
  'regions' => array(
    'content_header_left' => t('Content Header Left'),
    'content_header_right' => t('Content Header Right'),
    'column_left' => t('Column Left'),
    'column_middle' => t('Column Middle'),
    'column_right' => t('Column Right'),
  ),
);
