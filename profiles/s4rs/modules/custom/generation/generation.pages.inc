<?php
/**
 * @file
 * Generation API page callbacks.
 */

/**
 * Path: generation-instant-summary/%generation_site
 */
function generation_instant_summary_page($site) {
  // @todo: Should this be in this module? It's tied to generation's gmap/
  // views integration....
  module_load_include('inc', 'generation');
  $summary = _generation_get_instant_summary($site, 0);

  $summary['formatted'] = array();
  $to_format = array(
    'generation' => 'KWh',
    'power' => 'Watts',
  );
  foreach ($to_format as $key => $units) {
    if (isset($summary[$key])) {
      $values = array(
        '!value' => generation_number_format($summary[$key]),
        '!units' => $units,
      );
      $summary['formatted'][$key] = t('!value !units', $values);
    }
    else {
      $summary['formatted'][$key] = t('N/A');
    }
  }

  $summary['collected'] = (int) $summary['collected']->format('U');

  drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  echo json_encode($summary);
  exit();
}
