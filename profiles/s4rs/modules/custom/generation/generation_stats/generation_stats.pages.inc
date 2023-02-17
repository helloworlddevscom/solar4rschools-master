<?php
/**
 * @file
 * Menu callbacks for Generation Stats module.
 */

/**
 * Path: generation-stats/%generation_site/%/%
 *
 * Menu callback to generate a fresh version of a generation_stats block.
 */
function generation_stats_block_ajax($site, $delta, $period) {
  $block = _generation_stats_block_view($delta, $site, $period, TRUE);

  drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  echo drupal_json_encode(array('content' => $block));
  exit();
}
