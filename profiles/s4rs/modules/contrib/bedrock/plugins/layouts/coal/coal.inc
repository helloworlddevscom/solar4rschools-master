<?php

/**
 * @file
 * Bedrock Coal panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Coal'),
  'icon' => 'coal.png',
  'category' => t('Bedrock'),
  'theme' => 'coal',
  'admin css' => 'admin.coal.css',
  'regions' => array(
    'column_left' => t('Column Left'),
    'column_right' => t('Column Right'),
  ),
);
