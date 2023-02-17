<?php
/**
 * @file
 * Administrative interface code.
 */

/**
 * Page callback: Form constructor for the Variable preset selection form page.
 *
 * Path: generation_site/' . $bundle->name . '/%generation_site/charts/explore-data
 */
function explore_data_variable_presets_form($form, &$form_state, $site) {
  $form = array();

  module_load_include('inc', 'generation', 'generation');
  $form['site_id'] = array(
    '#type' => 'hidden',
    '#value' => $site->id,
  );

  // Certain providers have different available variables per
  // location. Update these here.
  $variables = _generation_update_variable_presets_location($site);
  $presets = _generation_get_variable_presets_options($site, $variables);
  $form['presets'] = array(
    '#type' => 'select',
    '#title' => t('Allowed variable presets on Data Exploration Center'),
    '#multiple' => TRUE,
    '#options' => $presets,
    '#default_value' => array_keys($site->explore_data_presets),
    '#attributes' => array(
      'data-placeholder' => t('Click to select variable presets'),
    ),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Form submission handler for explore_data_variable_presets_form().
 */
function explore_data_variable_presets_form_submit($form, &$form_state) {
  $site_id = $form_state['values']['site_id'];
  $preset_ids = $form_state['values']['presets'];

  // Delete existing rows for this node, first.
  db_delete('explore_data_site_presets')
  ->condition('site_id', $site_id)
  ->execute();

  foreach ($preset_ids as $preset_id) {
    $dec_preset = array(
      'site_id' => $site_id,
      'preset_id' => $preset_id,
    );
    drupal_write_record('explore_data_site_presets', $dec_preset);
  }

  $site = generation_site_load($site_id);
  $site->save();
  drupal_set_message(t('The Data Exploration Center presets have been saved.'));
}
