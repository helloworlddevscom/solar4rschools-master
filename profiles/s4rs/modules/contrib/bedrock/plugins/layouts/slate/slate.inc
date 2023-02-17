<?php

/**
 * @file
 * Bedrock Slate panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Slate'),
  'icon' => 'slate.png',
  'category' => t('Bedrock'),
  'theme' => 'slate',
  'admin css' => 'admin.slate.css',
  'regions' => array(
    'main_content' => t('Main Content'),
  ),
);
