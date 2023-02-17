<?php

/**
 * @file
 * Bedrock Pumice panels layout plugin.
 */

// Plugin definition
$plugin = array(
  'title' => t('Pumice'),
  'icon' => 'pumice.png',
  'category' => t('Bedrock'),
  'theme' => 'pumice',
  'admin css' => 'admin.pumice.css',
  'regions' => array(
    'column_left' => t('Column Left'),
    'column_right' => t('Column Right'),
  ),
);
