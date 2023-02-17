<?php

/**
 * @file
 * Bedrock comendite-left panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Comendite Left'),
  'icon' => 'comendite-left.png',
  'category' => t('Bedrock'),
  'theme' => 'comendite-left',
  'admin css' => 'admin.comendite-left.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'content_main_column' => t('Content Main Column'),
    'content_secondary_column' => t('Content Secondary Column'),
  ),
);
