<?php

/**
 * @file
 * Bedrock Adakite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Adakite'),
  'icon' => 'adakite.png',
  'category' => t('Bedrock'),
  'theme' => 'adakite',
  'admin css' => 'admin.adakite.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'column_left' => t('Column Left'),
    'column_middle' => t('Column Middle'),
    'column_right' => t('Column Right'),
    'content_footer_left' => t('Content Footer Left'),
    'content_footer_right' => t('Content Footer Right'),
  ),
);
