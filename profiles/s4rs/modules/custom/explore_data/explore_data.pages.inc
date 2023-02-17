<?php

/**
 * @file
 * Page callbacks for Explore Data module.
 */

/**
 * Date format to use on the form and in URLs.
 */
define('EXPLORE_DATA_DATE_FORMAT', 'm-d-Y H:i');
define('EXPLORE_DATA_CSV_DATE_FORMAT', 'm-d-Y H:i');
define('EXPLORE_DATA_CSV_SEPARATOR', ',');
define('EXPLORE_DATA_DATE_YEAR_RANGE', '2004:+0');

/**
 * Converts dates formatted in EXPLORE_DATA_DATE_FORMAT into DateTime objects.
 *
 * @param object $site
 *   The site id
 * @param string $date_start
 *   In the format MM-DD-YYY or 0 if none
 * @param string $date_end
 *   In the format MM-DD-YYY
 */
function explore_data_convert_dates($site, &$date_start, &$date_end) {
  assert(is_string($date_start) && is_string($date_end));

  if (is_string($date_start) && is_string($date_end)) {
    $timezone = date_default_timezone_object(FALSE);
    if (!empty($site->field_timezone[LANGUAGE_NONE][0]['value'])) {
      $tz_name = $site->field_timezone[LANGUAGE_NONE][0]['value'];
      try {
        $timezone = new DateTimeZone($tz_name);
      } catch (Exception $e) {
        watchdog('explore_data', 'Invalid timezone @tz for @site (@id)', array(
          '@tz' => $tz_name,
          '@site' => $site->title,
          '@id' => $site->id,
        ), WATCHDOG_ERROR);
      }
    }
    $date_start = date_create_from_format(EXPLORE_DATA_DATE_FORMAT, $date_start, $timezone);
    $date_end = date_create_from_format(EXPLORE_DATA_DATE_FORMAT, $date_end, $timezone);
  }
}

/**
 * Page callback: Data Exploration Center page.
 *
 * Path: $arg[0][/%generation_site[/%[/%[/%]]]]
 */
function explore_data_page($site = NULL, $date_start = '', $date_end = '', $presets = array()) {
  return drupal_get_form('explore_data_form', $site, $date_start, $date_end, $presets);
}

/**
 * Page callback: Data Exploration Center CSV download.
 *
 * Path: explore-data-csv/%generation_site/%/%/%
 */
function explore_data_csv_page($site, $date_start, $date_end, $preset_ids_encoded) {
  module_load_include('inc', 'generation');

  $preset_ids = generation_urldecode_preset_ids($preset_ids_encoded);
  $presets = generation_variable_preset_load_multiple($preset_ids);

  // The dates are timestamps, so they're precise start and end times. No need
  // for using inclusive flag, which would add one day.
  explore_data_convert_dates($site, $date_start, $date_end, array('inclusive' => FALSE));

  $series_data = _generation_get_bin_data($site, $presets, $date_start, $date_end);

  $preset_aliases = array();
  foreach ($presets as $preset) {
    $alias = str_replace(' ', '-', drupal_strtolower($preset->alias));
    $preset_aliases[] = preg_replace('![^abcdefghijklmnopqrstuvwxyz0-9-_\.]+!s', '', $alias);
  }
  $preset_aliases = implode('.', $preset_aliases);

  // Build a descriptive filename for the CSV document based on the parameters.
  $filename = 's4rs-data.'
    . str_replace(' ', '-', $site->title) . '.'
    . $preset_aliases . '.'
    . $date_start->format(EXPLORE_DATA_DATE_FORMAT) . '.to.'
    . $date_end->format(EXPLORE_DATA_DATE_FORMAT) . '.csv';
  $filename = preg_replace('![^abcdefghijklmnopqrstuvwxyz0-9-_\.]+!s', '', drupal_strtolower($filename));

  if (count($series_data) == 0) {
    return t('Error: No data available for the requested CSV export.');
  }

  drupal_add_http_header('Content-Type', 'text/csv; charset=utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=' . $filename);

  // Print out the header line.
  $fields = array();
  $fields[] = _explore_data_quote_csv_field(t('Collected'));
  foreach ($series_data as $series) {
    $name = $series['name'];
    $units = $series['units'];
    $field = t('!series (!units)', array('!series' => $name, '!units' => $units));
    $fields[] = _explore_data_quote_csv_field($field);
  }
  print implode(EXPLORE_DATA_CSV_SEPARATOR, $fields) . "\n";

  $data_points_count = count($series_data[0]['data']);
  for ($row = 0; $row < $data_points_count; $row++) {
    $fields = array();

    // Format the time using the value from the first variable in the query.
    $datetime = generation_new_datetime_site($site, $series_data[0]['data'][$row][0]);
    $fields[] = _explore_data_quote_csv_field($datetime->format(EXPLORE_DATA_CSV_DATE_FORMAT));

    // Format the data with no thousands separator.
    for ($series = 0; $series < count($series_data); $series++) {
      $value = $series_data[$series]['data'][$row][1];
      $fields[] = number_format($value, 4, '.', '');
    }

    print implode(EXPLORE_DATA_CSV_SEPARATOR, $fields) . "\n";
  }

  drupal_exit();
}

/**
 * Returns the given string quoted, for use as a CSV field value.
 */
function _explore_data_quote_csv_field($value) {
  return '"' . trim(str_replace('"', '""', $value)) . '"';
}

/**
 * Form submit handler.
 */
function explore_data_form_submit($form, &$form_state) {
  $button = $form_state['clicked_button']['#value'];
  $args = arg(NULL, trim($form['#action'], '/'));

  if ($button == t('Reset')) {
    $form_state['redirect'] = $args[0];
    return;
  }
  $values = &$form_state['values']['explore_data'];

  $site_id = $values['site_id'];
  $site = generation_site_load($site_id);

  // Date API always gives values in YYYY-MM-DD format; no need to use
  // explore_data_convert_dates() here.
  $date_start = $values['date_start'];
  $date_end   = $values['date_end'];
  generation_charts_convert_dates($site, $date_start, $date_end, array('inclusive' => FALSE));

  $date_start = $date_start->format(EXPLORE_DATA_DATE_FORMAT);
  $date_end   = $date_end->format(EXPLORE_DATA_DATE_FORMAT);


  $redirect_to = "$args[0]/$site_id/$date_start/$date_end";

  $preset_ids_encoded = generation_urlencode_preset_ids($values['preset_ids']);
  // Presets may not be present, since the field input doesn't exist until a
  // school is selected.
  if (!empty($preset_ids_encoded)) {
    $redirect_to .= "/$preset_ids_encoded";
  }



  if ($site->type == 'locus_energy' && !empty($preset_ids_encoded)) {
    batch_load_site_data($site, $date_start, $date_end, $preset_ids_encoded, $redirect_to);
  } else {
    $form_state['redirect'] = $redirect_to;
  }

}

function batch_load_site_data($site, $date_start, $date_end, $preset_ids_encoded, $redirect_to_after) {

  $operations = array();


  $operations[] = array(
    'batch_load_data_op',
    array(
      'site' => $site,
      'date_start' => $date_start,
      'date_end' => $date_end,
      'preset_ids_encoded' => $preset_ids_encoded
    )
  );

  $batch = array(
    'operations' => $operations,
    'finished' => 'batch_load_site_data_callback'
  );

  batch_set($batch);
  batch_process($redirect_to_after);
}

