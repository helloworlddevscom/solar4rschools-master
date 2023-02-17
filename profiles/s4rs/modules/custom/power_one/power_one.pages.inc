<?php
/**
 * @file
 * Power-One Node pages.
 */

/**
 * Refresh data form.
 */
function power_one_refresh_form($form, &$form_state, $site) {
  $form['site_id'] = array(
    '#type' => 'hidden',
    '#value' => $site->id,
  );
  $form['child_data'] = array(
    '#type' => 'radios',
    '#title' => t('Refresh descendant data?'),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => 0,
    '#required' => TRUE,
    '#description' => t('<strong>Warning</strong>: This option can take quite a while to complete, depending on the amount of descendant data in need of refreshing.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh'),
  );
  return $form;
}

/**
 * Data refresh submit handler.
 */
function power_one_refresh_form_submit($form, &$form_state) {
  $site = generation_site_load($form_state['values']['site_id']);
  $descendant_data = $form_state['values']['child_data'];
  power_one_refresh($site, $descendant_data);
}
