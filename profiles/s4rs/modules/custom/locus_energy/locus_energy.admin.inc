<?php

/**
 * Admin settings form.
 */
function locus_energy_admin_settings_form($form, &$form_state) {
  $form = array();
  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('Locus Energy API Authentication'),
    '#description' => t('Settings for authenticating with the Locus Energy service.'),
  );
  $form['authentication']['locus_energy_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => variable_get('locus_energy_client_id', ''),
    '#required' => TRUE,
  );
  $form['authentication']['locus_energy_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#default_value' => variable_get('locus_energy_client_secret', ''),
    '#required' => TRUE,
  );


  $form['authentication']['locus_energy_username'] = array(
      '#type' => 'textfield',
      '#title' => t('SolarOS Username'),
      '#default_value' => variable_get('locus_energy_username', ''),
      '#required' => TRUE,
  );
  $form['authentication']['locus_energy_password'] = array(
      '#type' => 'textfield',
      '#title' => t('SolarOS Password'),
      '#default_value' => variable_get('locus_energy_password', ''),
      '#required' => TRUE,
  );

  $form['authentication']['locus_energy_partner_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Partner ID'),
      '#default_value' => variable_get('locus_energy_partner_id', ''),
      '#required' => TRUE,
  );

  $form['authentication']['locus_energy_auto_update_available_sites'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto-update available sites'),
    '#default_value' => variable_get('locus_energy_auto_update_available_sites'),
  );

  $form['background_cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Background cache Locus kiosks'),
    '#description' => t('Enable/disable background caching of kiosk data.'),
  );

  $form['background_cache']['locus_energy_background_cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable background caching'),
    '#default_value' => variable_get('locus_energy_background_cache', 0),
  );

  $form['cache_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cache Settings'),
    '#description' => t('Cache settings Locus Energy API.'),
  );
  
  $cache_intervals = array(
    900 => '15 min',
    3600 => '1 Hour',
    21600 => '6 Hours',
    43200 => '12 Hours',
    86400 => '1 Day',
  );


  $form['cache_settings']['locus_energy_api_response_cache_expire'] = array(
    '#type' => 'select',
    '#title' => t('API Response Cache Time'),
    '#default_value' => variable_get('locus_energy_api_response_cache_expire', 3600),
    '#options' => $cache_intervals
  );

  $form['cache_settings']['locus_energy_current_day_cache_expire'] = array(
    '#type' => 'select',
    '#title' => t('Instant Summary Cache Time'),
    '#default_value' => variable_get('locus_energy_instant_summary_cache_expire', 3600),
    '#options' => $cache_intervals
  );


  $form['cache_settings']['locus_energy_instant_summary_cache_expire'] = array(
    '#type' => 'select',
    '#title' => t('Instant Summary Cache Time'),
    '#default_value' => variable_get('locus_energy_instant_summary_cache_expire', 3600),
    '#options' => $cache_intervals
  );


  $form['cache_settings']['locus_energy_service_response_cache'] = array(
    '#type' => 'select',
    '#title' => t('Service Response Cache Time'),
    '#default_value' => variable_get('locus_energy_service_response_cache', 3600),
    '#options' => $cache_intervals
  );
  
  
  $form['cache_settings']['locus_energy_window_summary_cache_expire'] = array(
    '#type' => 'select',
    '#title' => t('Windowed Summary Cache Time'),
    '#default_value' => variable_get('locus_energy_window_summary_cache_expire', 3600),
    '#options' => $cache_intervals
  );

  $form['cache_settings']['clear_locus_api_cache'] = array(
    '#type' => 'submit',
    '#value' => t('Clear API Cache'),
    '#submit' => array('locus_energy_admin_clear_cache_handler'),
  );



  $header = array('Month', 'Number of API calls');

  $api_totals = variable_get('locus_energy_api_call_totals', array());

  $rows = array();
  foreach ($api_totals as $month => $calls) {
    $rows[] = array( $month, $calls);
    
  }

  $form['api_call_table'] = array(
    '#type' => 'markup',
    '#markup' => theme('table', array('header' => $header, 'rows' => $rows))
  );

  $form['build_caches'] = array(
    '#type' => 'submit',
    '#value' => 'Build cache for all sites',
    '#submit' => array('locus_energy_build_caches_callback')
  );
  
  return system_settings_form($form);
}

function locus_energy_get_all_kiosk_sites() {
  module_load_include('inc', 'generation');

  $query =  db_select('field_data_field_data_collection_site', 's');
  $query->join('eck_generation_site', 'g', 's.field_data_collection_site_target_id = g.id');
  $query->join('field_data_field_locus_energy_site_id', 'l', 'g.id = l.entity_id');
  $stmt = $query
    ->fields('g', array('id'))
    ->condition('s.bundle', 'kiosk')
    ->condition('g.type', 'locus_energy')
    ->execute();

  $ids = array_unique($stmt->fetchCol());
  return entity_load('generation_site', $ids);
}


function locus_energy_build_caches_callback($form, &$form_state) {
  $batch = locus_energy_build_kiosk_batch_cache_operations();
  batch_set($batch);

}

/**
 * Test the connection to the Locus web service.
 */
function locus_energy_test_page() {

  
  $api = LocusEnergyApi::instance();
  
  if( $api->authenticate() ) {
    drupal_set_message(t('Successfully authenticated to Locus Energy.'));
  } else {
    drupal_set_message(t('Failed to authenticate to Locus Energy.'), 'error');    
  }
  
  return '';
}

function locus_energy_build_kiosk_batch_cache_operations() {
  module_load_include('inc', 'generation');

  $sites = locus_energy_get_all_kiosk_sites();

  $operations = array();

  foreach ($sites as $site) {

    $operations[] = array('locus_energy_cache_instant_summary', array($site));

    foreach (array('day', 'week', 'month', 'year', 'lifetime') as $period) {
      $operations[] = array('locus_energy_cache_window_summary', array($site, $period));
    }
  }

  $batch = array(
    'operations' => $operations,
    'title' => 'Caching Locus Energy Kiosk data',
    'init_message' => t('Locus Energy kiosk cache is starting...'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Locus Energy kiosk cache has encountered an error.'),
    'finished' => 'locus_energy_kiosk_cache_finished',
    'file' => drupal_get_path('module', 'locus_energy') . '/locus_energy.admin.inc'
  );
  return $batch;
}


function locus_energy_kiosk_cache_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message('Locus Energy kiosk caching complete');
  }
}

function locus_energy_cache_instant_summary($site) {
  module_load_include('inc', 'generation');
  $provider = generation_get_provider($site);
  $provider->queryInstantSummary($site);
}

function locus_energy_cache_window_summary($site, $period) {
  module_load_include('inc', 'generation');
  $provider = generation_get_provider($site);

  list($date_start, $date_end) = _generation_charts_get_period_dates($site, $period);
  $provider->queryWindowSummary($site, $date_start, $date_end);

  $preset_ids = array_keys($site->site_chart_presets[$period]);
  if (count($preset_ids) > 0) {

    $presets = generation_variable_preset_load_multiple($preset_ids);
    foreach ($presets as $preset_id => $preset) {
      if ($override = generation_get_site_preset_override($site, $preset_id)) {
        foreach (array('alias', 'description', 'units') as $parameter) {
          if (!empty($override->{$parameter})) {
            $presets[$preset_id]->{$parameter} = $override->{$parameter};
          }
        }
      }
    }

    $bin = _generation_get_bin_from_range($date_start, $date_end);

    $provider->queryBin($site, $presets, $date_start, $date_end, $bin);
  }
}





