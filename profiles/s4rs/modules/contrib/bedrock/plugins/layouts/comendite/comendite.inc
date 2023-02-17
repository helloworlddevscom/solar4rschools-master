<?php

/**
 * @file
 * Bedrock Comendite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Comendite'),
  'icon' => 'comendite.png',
  'category' => t('Bedrock'),
  'theme' => 'comendite',
  'admin css' => 'admin.comendite.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'content_main_column' => t('Content Main Column'),
    'content_secondary_column' => t('Content Secondary Column'),
  ),
);
