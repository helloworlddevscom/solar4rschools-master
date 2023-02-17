<?php

/**
 * Admin settings form.
 */
function tigo_energy_admin_settings_form($form, &$form_state) {
  $form = array();
  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication'),
    '#description' => t('Settings for authenticating with the Tigo Energy service.'),
  );
  $form['authentication']['tigo_energy_api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('tigo_energy_api_username', ''),
    '#required' => TRUE,
  );
  $form['authentication']['tigo_energy_api_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('tigo_energy_api_password', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Test the connection to the Tigo web service.
 */
function tigo_energy_test_page() {
// Test authentication.
  $url = 'https://' . variable_get('tigo_energy_api_username') . ':' .
    variable_get('tigo_energy_api_password') . '@' . TIGO_API_HOST . '/api/data?cmd=list';
  $response = drupal_http_request($url);

  if ($response->status_message == "OK") {
    drupal_set_message(t('Successfully authenticated to Tigo Energy.'));
  }
  else {
    drupal_set_message(t('Failed to authenticate to Tigo Energy.'), 'error');
  }

  return '';
}