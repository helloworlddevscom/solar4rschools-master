<?php

/**
 * @file
 * Bedrock Quartz panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Quartz'),
  'icon' => 'quartz.png',
  'category' => t('Bedrock'),
  'theme' => 'quartz',
  'admin css' => 'admin.quartz.css',
  'regions' => array(
    'content_header_left' => t('Content Header Left'),
    'content_header_right' => t('Content Header Right'),
    'content_main' => t('Content Main'),
  ),
);
