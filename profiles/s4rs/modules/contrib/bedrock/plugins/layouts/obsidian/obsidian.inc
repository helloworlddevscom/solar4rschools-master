<?php

/**
 * @file
 * Bedrock Obsidian panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Obsidian'),
  'icon' => 'obsidian.png',
  'category' => t('Bedrock'),
  'theme' => 'obsidian',
  'admin css' => 'admin.obsidian.css',
  'regions' => array(
    'column_left' => t('Column Left'),
    'column_middle' => t('Column Middle'),
    'column_right' => t('Column Right'),
  ),
);
