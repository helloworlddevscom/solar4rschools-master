<?php
/**
 * @file
 * Custom code for Kiosk charts.
 */

/**
 * Returns markup for kiosk chart block.
 */
function _os_kiosk_chart_block($site, $period) {
  assert(is_object($site));

  $options = array(
    'chart' => array(
      'chart' => array(
        // Make chart transparent to show the page's background.
        'backgroundColor' => 'rgba(255,255,255,0)',
      ),
    ),
    'css' => array(
      'width' => 669,
      'height' => 250,
    ),
    'period' => $period,
  );


  $options = generation_charts_configure_chart($site, array(), $options);

  return theme('generation_charts_placeholder', array('options' => $options)) .
      theme('generation_charts_period_selector', array('options' => $options));
}