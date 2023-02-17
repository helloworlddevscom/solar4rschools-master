<?php

/**
 * @file
 * Bedrock Flint panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Flint'),
  'icon' => 'flint.png',
  'category' => t('Bedrock'),
  'theme' => 'flint',
  'admin css' => 'admin.flint.css',
  'regions' => array(
    'sidebar' => t('Sidebar'),
    'content_main' => t('Content Main'),
  ),
);
