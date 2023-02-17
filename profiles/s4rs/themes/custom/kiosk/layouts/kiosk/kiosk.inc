<?php

/**
 * @file
 * Bedrock Hawaiite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Kiosk Basic'),
  'icon' => 'kiosk.png',
  'category' => t('S4RS Kiosk'),
  'theme' => 'kiosk',
  'admin css' => 'admin.kiosk.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'content_prefix' => t('Content Prefix'),
    'main_content' => t('Main Content'),
    'content_suffix' => t('Content Suffix'),
    'content_footer' => t('Content Footer'),
  ),
);
