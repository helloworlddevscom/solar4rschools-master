<?php
/**
 * @file
 * Administration page callbacks for Generation Charts.
 */

/**
 * Page callback: Form constructor for chart block configuration form.
 *
 * Path: generation_site/%bundle/%generation_site/charts/chart-block
 */
function generation_charts_site_chart_block_form($form, &$form_state, $site) {
  $form = array();

  $form['site_id'] = array(
    '#type' => 'hidden',
    '#value' => $site->id,
  );

  $form['presets'] = array(
    '#type' => 'fieldset',
    '#title' => t('Variable presets to graph on project page'),
    '#tree' => TRUE,
  );

  module_load_include('inc', 'generation', 'generation');
  // Certain providers have different available variables per
  // location. Update these here.
  $variables = _generation_update_variable_presets_location($site);
  $options = _generation_get_variable_presets_options($site, $variables);
  foreach (_generation_charts_get_periods() as $period => $label) {
    $form['presets'][$period] = array(
      '#type' => 'select',
      '#title' => t('%period tab', array('%period' => $label)),
      '#multiple' => TRUE,
      '#options' => $options,
      '#default_value' => array_keys($site->site_chart_presets[$period]),
      '#attributes' => array(
        'data-placeholder' => t('Click to select variable presets'),
      ),
    );
  }

  // Allow customization of presets on a per-school basis.
  $form['overrides'] = array(
    '#type' => 'fieldset',
    '#title' => t('Preset overrides'),
    '#description' => t('Values set here will be in effect for this site <strong>only</strong>. They will override those set at <a href="!url">the preset configuration section</a>. These only become available once values have been set above.',
      array('!url' => 'admin/config/generation/variable-presets')),
    '#tree' => TRUE,
  );
  foreach ($options as $preset_id => $label) {
    _generation_charts_per_site_preset_override_form($form, $preset_id, $site);
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['cache_clear'] = array(
    '#type' => 'fieldset',
    '#description' => t('All cached data for this site will be cleared.'),
    '#weight' => -50,
  );
  $form['cache_clear']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear cached data'),
    '#submit' => array('generation_charts_cache_clear_submit'),
  );

  return $form;
}

/**
 * Form validation callback for generation_site_chart_block_form().
 */
function generation_charts_site_chart_block_form_validate($form, &$form_state) {
  // Sanity check the variable preset ids.
  foreach ($form_state['values']['presets'] as $period => $presets) {
    foreach ($presets as $preset_id) {
      if (!generation_variable_preset_load($preset_id)) {
        form_set_error('presets][' . $period, t('Invalid preset selected.'));
      }
    }
  }
}

/**
 * Form submission callback for generation_site_chart_block_form().
 */
function generation_charts_site_chart_block_form_submit($form, &$form_state) {
  $site_id = $form_state['values']['site_id'];

  // First, clean the slate.
  db_delete('generation_charts_site_presets')
    ->condition('site_id', $site_id)
    ->execute();

  // Insert all selections.
  foreach ($form_state['values']['presets'] as $period => $presets) {
    foreach ($presets as $preset_id) {
      $record = array(
        'site_id' => $site_id,
        'period' => $period,
        'preset_id' => $preset_id,
      );
      if (!drupal_write_record('generation_charts_site_presets', $record)) {
        drupal_set_message(t('Internal error saving site presets'), 'error');
      }
    }
  }

  // Manage overrides.
  $overrides = $form_state['values']['overrides'];

  db_delete('generation_preset_override')
    ->condition('site_id', $site_id)
    ->execute();
  foreach ($overrides as $preset_id => $override) {
    $override = (object) $override;
    if (_generation_is_preset_overridden($override)) {
      $record = array(
        'site_id' => $site_id,
        'preset_id' => $preset_id,
        'alias' => $override->alias,
        'description' => $override->description,
        'units' => $override->units,
      );
      drupal_write_record('generation_preset_override', $record);
    }
  }
  $site = generation_site_load($site_id);
  $site->save();
  drupal_set_message(t('The site chart presets have been saved.'));
}

/**
 * Submit handler: clear cached data for given site.
 */
function generation_charts_cache_clear_submit($form, &$form_state) {
  module_load_include('inc', 'generation');
  $site = entity_load_single('generation_site', $form_state['values']['site_id']);
  generation_cache_clear($site->id);
  drupal_set_message(t('Clear cached data for %title.', array('%title' => $site->title)));
}

/**
 * Add to form necessary values for overriding a preset on a per-site basis.
 *
 * @param array &$form
 *   Drupal form array.
 * @param string $preset_id
 *   The preset ID that may be overridden.
 * @param object $node
 *   The fully-loaded site node object.
 */
function _generation_charts_per_site_preset_override_form(&$form, $preset_id, $node) {
  // First, load any existing overrides.
  $override = generation_get_site_preset_override($node, $preset_id);
  $preset = generation_variable_preset_load($preset_id);
  $is_overridden = _generation_is_preset_overridden($override);

  $form['overrides'][$preset_id] = array(
    '#type' => 'fieldset',
    '#title' => check_plain($preset->alias),
    '#collapsible' => TRUE,
    '#collapsed' => !$is_overridden,
    '#tree' => TRUE,
  );

  // Specific fields.
  $form['overrides'][$preset_id]['alias'] = array(
    '#type' => 'textfield',
    '#default_value' => $override ? $override->alias : FALSE,
    '#title' => t('Alias'),
  );
  $form['overrides'][$preset_id]['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $override ? $override->description : FALSE,
    '#title' => t('Description'),
  );

  $variable = generation_variable_load($preset->variable_id);
  $units = _generation_get_possible_units($variable);
  $unit_options = array('' => t('--Select--'));
  foreach ($units as $key => $raw_unit) {
    $unit_options[$key] = t('!unit (!label)', array('!unit' => $key, '!label' => $raw_unit['label']));
  }
  $form['overrides'][$preset_id]['units'] = array(
    '#type' => 'select',
    '#default_value' => $override ? $override->units : FALSE,
    '#options' => $unit_options,
    '#title' => t('Units'),
  );
}


/**
 * Manage per-device preset combinations.
 */
function generation_charts_admin_device_presets_form($form, $form_state, $site) {
  module_load_include('inc', 'generation');
  $provider = generation_get_provider($site);
  $devices = $provider->getSiteDevices($site);
  if (empty($devices)) {
    $form['description'] = array(
      '#type' => 'markup',
      '#value' => t('No devices found for %title', array('%title' => $site->title)),
    );
    return $form;
  }

  $units = _generation_get_possible_units();
  $variable_options = array(t('--Select--')) + _generation_get_variable_options($site, array_keys($provider->getSiteVariables($site)));
  $device_options = $function_options = $unit_options = array(t('--Select--'));
  foreach ($devices as $id => $device) {
    $device_options[$id] = $provider->getDeviceName($device);
  }

  foreach ($units as $id => $unit) {
    $unit_options[$id] = $id;
  }

  // Find existing device presets for this location.
  $result = db_select('generation_variable_presets', 'gvp')
    ->fields('gvp')
    ->condition('device_id', array_keys($devices))
    ->execute();

  $existing = array();
  foreach ($result as $preset) {
    if (!empty($preset->device_id)) {
      // If `device_id` is set, this is a device-level preset.
      $existing[$preset->preset_id] = $preset;
    }
  }

  // Add an empty preset for creating new presets.
  $existing['new_preset'] = (object) array(
    'preset_id' => 'new_preset',
    'variable_id' => NULL,
    'alias' => '',
    'function' => '',
    'chart_type' => '',
    'units' => '',
    'description' => '',
    'device_id' => 0,
  );

  // Initialize form elements.
  $form['site_id'] = array(
    '#type' => 'value',
    '#value' => $site->id,
  );
  $form_items = array(
    'delete',
    'device_id',
    'variable_id',
    'alias',
    'function',
    'chart_type',
    'units',
    'description',
  );
  foreach ($form_items as $element) {
    $form[$element]['#tree'] = TRUE;
  }

  foreach ($existing as $id => $preset) {
    $form['device_id'][$preset->preset_id] = array(
      '#type' => 'select',
      '#options' => $device_options,
      '#default_value' => $preset->device_id,
    );
    $form['variable_id'][$preset->preset_id] = array(
      '#type' => 'select',
      '#options' => $variable_options,
      '#default_value' => $preset->variable_id,
    );
    $form['alias'][$preset->preset_id] = array(
      '#type' => 'textfield',
      '#default_value' => $preset->alias,
      '#size' => 10,
    );
    $form['function'][$preset->preset_id] = array(
      '#type' => 'select',
      '#default_value' => $preset->function,
      '#options' => array(t('--Select--')) + _generation_get_possible_functions(),
    );
    $form['chart_type'][$preset->preset_id] = array(
      '#type' => 'select',
      '#default_value' => $preset->chart_type,
      '#options' => array(t('--Select--')) + generation_charts_chart_types(),
    );
    $form['units'][$preset->preset_id] = array(
      '#type' => 'select',
      '#default_value' => $preset->units,
      '#options' => $unit_options,
    );
    $form['description'][$preset->preset_id] = array(
      '#type' => 'textfield',
      '#default_value' => $preset->description,
      '#size' => 10,
    );
    // Add a delete checkbox.
    $form['delete'][$preset->preset_id] = array(
      '#type' => $preset->preset_id != 'new_preset' ? 'checkbox' : 'markup',
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save device presets'),
  );

  $form['#theme'] = 'generation_device_presets';

  return $form;
}


/**
 * Validate the per-device preset form.
 */
function generation_charts_admin_device_presets_form_validate($form, &$form_state) {
  // Required fields.
  $required_fields = array(
    'variable_id' => t('Variable'),
    'alias' => t('Alias'),
    'chart_type' => t('Chart type'),
    'function' => t('Function'),
  );

  // Load node.
  $site = generation_site_load($form_state['values']['site_id']);

  foreach ($form_state['values']['device_id'] as $preset_id => $device_id) {
    $errors = FALSE;
    $preset = array(
      'device_id' => $device_id,
    );
    if (!empty($device_id)) {
      foreach ($required_fields as $field => $label) {
        if (empty($form_state['values'][$field][$preset_id])) {
          form_set_error($field . '][' . $preset_id, t('@label is required', array('@label' => $label)));
          $errors = TRUE;
        }
        else {
          $preset[$field] = $form_state['values'][$field][$preset_id];
        }
      }
    }

    // Units are not required, add them here.
    $preset['units'] = $form_state['values']['units'][$preset_id];

    if (!$errors && $device_id) {
      // Valid preset, test it out.
      $provider = generation_get_provider($site);
      // Test 1 month in the past.
      $date_start = new DateTime('-1 month');
      $date_end = new DateTime();

      // Construct a preset.
      $preset = (object) $preset;

      $result = $provider->queryBinDevice($device_id, array($preset), $date_start, $date_end);
      if (!$result->success) {
        // Load krumo for nicer display.
        include_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'devel') . '/devel.module';
        has_krumo();
        $error = krumo_ob($result);
        form_set_error('variable][' . $preset_id, t('Invalid variable/device combination. Raw response: !error', array('!error' => $error)));
      }

      // Empty response may indicate invalid preset combination, throw warning.
      // Load krumo for nicer display.
      $data = $provider->getBinData($result);
      if (empty($data)) {
        include_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'devel') . '/devel.module';
        has_krumo();
        $warning = krumo_ob($result);
        drupal_set_message(t('Empty data response, might indicate invalid combination. Raw response: !warning', array('!warning' => $warning)), 'warning');
      }
    }
  }

}

/**
 * Submit handler for per-device preset form.
 */
function generation_charts_admin_device_presets_form_submit($form, &$form_state) {
  $site = generation_site_load($form_state['values']['site_id']);
  $provider_info = generation_get_provider_info($site);
  $values = $form_state['values'];

  foreach ($values['device_id'] as $preset_id => $device_id) {
    if (empty($device_id)) {
      continue;
    }

    $preset = new stdClass();
    $preset->device_id = $device_id;
    $preset->module = $provider_info['module'];
    if ($preset_id === 'new_preset') {
      $update = array();
    }
    else {
      $update = array('preset_id');
      $preset->preset_id = $preset_id;
    }

    $preset_vars = array(
      'variable_id',
      'alias',
      'function',
      'chart_type',
      'units',
      'description',
    );
    foreach ($preset_vars as $var) {
      $preset->{$var} = $values[$var][$preset_id];
    }

    if ($values['delete'][$preset_id]) {
      // Delete preset and continue on.
      generation_variable_preset_delete($preset);
    }
    else {
      $result = drupal_write_record('generation_variable_presets', $preset, $update);
      if ($result === FALSE) {
        $device = $form['device_id'][$preset_id]['#options'][$device_id];
        form_set_error('device_id][' . $preset_id, t('Failed to save device preset combination (@preset).', array('@preset' => $device)));
      }
    }
  }
}
