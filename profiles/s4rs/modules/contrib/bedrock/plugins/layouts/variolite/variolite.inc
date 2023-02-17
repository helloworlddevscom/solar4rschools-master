<?php

/**
 * @file
 * Bedrock Variolite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Variolite'),
  'icon' => 'variolite.png',
  'category' => t('Bedrock'),
  'theme' => 'variolite',
  'admin css' => 'admin.variolite.css',
  'regions' => array(
    'sidebar' => t('Sidebar'),
    'content_header' => t('Content Header'),
    'content_main_column' => t('Content Main Column'),
    'content_secondary_column' => t('Content Secondary Column'),
  ),
);
