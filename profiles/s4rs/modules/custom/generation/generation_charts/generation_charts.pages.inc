<?php

/**
 * @file
 * Menu path callbacks for Generation Charts.
 */

/**
 * Chart data menu AJAX callback.
 */
function generation_charts_chart_page($site, $preset_ids_encoded, $date_start, $date_end) {
  module_load_include('inc', 'generation');

  $preset_ids = generation_urldecode_preset_ids($preset_ids_encoded);
  $presets = generation_variable_preset_load_multiple($preset_ids);
  // Process any overrides.
  foreach ($presets as $preset_id => $preset) {
    if ($override = generation_get_site_preset_override($site, $preset_id)) {
      foreach (array('alias', 'description', 'units') as $parameter) {
        if (!empty($override->{$parameter})) {
          $presets[$preset_id]->{$parameter} = $override->{$parameter};
        }
      }
    }
  }
  generation_charts_convert_dates($site, $date_start, $date_end, array());

  $series_data = _generation_get_bin_data($site, $presets, $date_start, $date_end);

  if ($series_data) {
    $colors = generation_charts_default_colors();
    $dash_styles = generation_charts_default_dash_styles();

    $timezone = generation_get_site_timezone($site);

    $index = 0;
    $offset = FALSE;
    foreach (array_keys($series_data) as $j) {
      $series_data[$j]['color'] = $colors[$index];
      $series_data[$j]['dashStyle'] = $dash_styles[$index];
      $series_data[$j]['yAxis'] = $index++;

      $format = '<span style="color:{series.color}">{series.name}</span>:';
      $format .= ' <b>{point.y} ' . $series_data[$j]['units'] . '</b><br/>';
      $series_data[$j]['tooltip'] = array(
        'pointFormat' => $format,
        'valueDecimals' => 2,
      );

      $series_data[$j]['generationCharts'] = array(
        'description' => $series_data[$j]['description'],
      );
      unset($series_data[$j]['description']);

      foreach (array_keys($series_data[$j]['data']) as $i) {
        $time = $series_data[$j]['data'][$i][0];

        // Adjust to display times in timezone of school. This means building
        // a DateTime object for each point, because the offset can change, if,
        // for example, the charting period straddles a Daylight Savings switch.
        $offset = $timezone->getOffset(new DateTime('@' . $time));
        if ($offset) {
          $time += $offset;
        }

        // Convert timestamps to millisecond format, as needed by Highstock JS.
        // Timestamp is the first array entry of each data point.
        $series_data[$j]['data'][$i][0] = $time * 1000;
      }
    }

    $data_package = array(
      'series' => $series_data,
      'yAxis' => [],
    );

    $index = 0;
    foreach ($series_data as $series) {
      $style = array(
        'color' => $colors[$index],
        'fontSize' => '12px',
      );

      $data_package['yAxis'][] = array(
        'labels' => array(
          'style' => $style,
        ),
        'offset' => $index > 1 ? 90 : 30,
        'minPadding' => 0.0,
        'maxPadding' => 0.0,
        'opposite' => $index % 2,
        'ordinal' => FALSE,
        'title' => array(
          'text' => $series['name'],
          'style' => $style,
        ),
        'dataMin' => 0,
      );
      $index++;
    }
  }
  else {
    $data_package = array(
      'series' => array(),
    );
  }

  drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  echo drupal_json_encode($data_package);
  exit();
}

/**
 * Chart log AJAX callback.
 * Increments log for site for period in table generation_charts_log.
 * This data will be used to determine which kiosks are being used
 * in order to make decisions around sunsetting of kiosks.
 */
function generation_charts_log($site, $period) {
  module_load_include('inc', 'generation');

  switch ($period) {
    case 'day':
      $period_field = 'load_count_today';
      break;
    case 'week':
      $period_field = 'load_count_week';
      break;
    case 'month':
      $period_field = 'load_count_month';
      break;
    case 'year':
      $period_field = 'load_count_year';
      break;
    case 'lifetime':
      $period_field = 'load_count_lifetime';
      break;
  }

  $exists = db_select('generation_charts_log', 'g')
    ->fields('g', array(
      'site_id',
    ))
    ->condition('site_id', $site, '=')
    ->execute()
    ->fetchAll();


  if (empty(!$exists)) {
    db_update('generation_charts_log')
      ->expression($period_field, $period_field . ' + 1')
      ->condition('site_id', $site, '=')
      ->execute();
  }
  else {
    db_insert('generation_charts_log')
      ->fields(array(
        'site_id' => $site,
        $period_field => 1,
      ))
      ->execute();
  }
}
