<?php
/**
 * @file
 * Theme functions for Explore Data module.
 */

/**
 * Theme implementation for explore_data_chart_tools().
 */
function theme_explore_data_chart_tools() {
  $tools = '';

  // Build path to CSV download.
  $args = arg();
  $args[0] = 'explore-data-csv';

  $tools .= l(t('Download CSV'), implode($args, '/'), array('attributes' => array('class' => 'button')));
  $tools .= '<a class="button" href="javascript:print();">' . t('Print') . '</a>';

  return '<div id="explore-data-chart-tools" class="clear-block">' . $tools . '</div>';
}
