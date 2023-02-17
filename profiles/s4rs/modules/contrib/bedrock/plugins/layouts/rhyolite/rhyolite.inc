<?php

/**
 * @file
 * Bedrock Rhyolite panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Rhyolite'),
  'icon' => 'rhyolite.png',
  'category' => t('Bedrock'),
  'theme' => 'rhyolite',
  'admin css' => 'admin.rhyolite.css',
  'regions' => array(
    'content_header' => t('Content Header'),
    'content_main_column' => t('Content Main Column'),
    'content_secondary_column' => t('Content Secondary Column'),
    'content_tertiary_column' => t('Content Tertiary Column'),
  ),
);
