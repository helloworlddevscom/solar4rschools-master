<?php
/**
 * @file
 * Power-One API admin pages.
 */

/**
 * Admin settings form.
 */
function power_one_admin_settings_form($form, &$form_state) {
  $form = array();
  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication'),
    '#description' => t('Settings for authenticating with the Power-One service.'),
  );
  $form['authentication']['power_one_api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('power_one_api_username', ''),
    '#required' => TRUE,
  );
  $form['authentication']['power_one_api_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('power_one_api_password', ''),
    '#required' => TRUE,
  );
  $form['authentication']['power_one_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Developer Application Key'),
    '#description' => t('This is the key provided by Power-One for authentication with the web service.'),
    '#default_value' => variable_get('power_one_api_key', ''),
  );
  $form['customer']['power_one_global_eid'] = array(
    '#type' => 'textfield',
    '#title' => t('Power-One Entity ID'),
    '#description' => t('Power One Global id for BEF.'),
    '#default_value' => variable_get('power_one_global_eid', ''),
  );

  module_load_include('inc', 'generation', 'generation.admin');
  _generation_set_admin_provider_breadcrumb();
  return system_settings_form($form);
}

/**
 * Test the connection to the Power-One web service.
 */
function power_one_test_page() {
  // Test that username, password and api key exist.
  $error = FALSE;
  foreach (array('username', 'password', 'key') as $var) {
    if (!variable_get('power_one_api_' . $var, '')) {
      drupal_set_message(t('No value found for %var', array('%var' => 'Power-One API ' . $var)), 'error');
      $error = TRUE;
    }
  }

  if ($error) {
    return t('There are problems with the <a href="!url">Power-One Configuration Settings</a>.', array('!url' => url('admin/config/generation/providers/power-one')));
  }

  $output = array();

  // Test authentication.
  $provider_info = generation_get_provider_info_all();
  $provider = generation_get_provider_from_info($provider_info['power_one']);

  if ($provider->authenticate()) {
    drupal_set_message(t('Successfully authenticated to Power-One.'));
  }
  else {
    drupal_set_message(t('Failed to authenticate to Power-One.'), 'error');
  }

//  dpm(power_one_get_devices_by_site_id(1866, 'All', 'All', TRUE));

  // Fields parameter processing.
  $test_fields = array(
    array(
      'field' => 'EarliestDate',
    ),
    array(
      'field' => 'LatestDate',
    ),
    array(
      'field' => 'GenerationPower',
    ),
    array(
      'field' => 'GenerationEnergy',
    ),
  );

  // @todo This arbitrary entityid doesn't exist. Pull it in some other way.
  return '';
  $defaults = array(
    'entityId' => 1912,
    'instant' => array(
      'atFixed' => REQUEST_TIME - 365 * 12 * 3600,
    ),
  );
  $node = (object) array(
    'entity_id' => 1912,
  );
  $summary = $provider->queryInstantSummary($node);
  dpm($summary, 'Instant summary for Power-One entity #1912');

  module_load_include('inc', 'generation', 'generation');
  $date_start = generation_new_datetime_local(REQUEST_TIME - 30 * 24 * 3600);
  $date_start = _generation_round_date($date_start, 30);

  $date_end = generation_new_datetime_local(REQUEST_TIME);
  $date_end = _generation_round_date($date_end, 30);

  $summary = $provider->queryWindowSummary($node, $date_start, $date_end);
  dpm($summary, 'Window (one month) summary for Power-One entity #1912');

  $defaults = array(
    'entityId' => 1866,
    'bins' => array(
      'binSize' => 'Day',
      'startFixed' => (REQUEST_TIME - (3600 * 30 * 24 * 1)),
      'function' => 'Avg',
      'relativeBase' => REQUEST_TIME,
    ),
  );
  $type = 'BinsRequest';
//  dpm(power_one_get_monitored_info($defaults, $fields, $type));

  module_load_include('inc', 'generation', 'generation.admin');
  $crumb = l(t('Power-One'), 'admin/config/generation/providers/power-one');
  _generation_set_admin_provider_breadcrumb(array($crumb));
  return '';
  return theme('item_list', array('items' => $output));
}
