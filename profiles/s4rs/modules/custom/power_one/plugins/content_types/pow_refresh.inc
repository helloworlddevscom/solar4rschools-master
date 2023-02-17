<?php
/**
 * @file
 * Site Equivalents panel pane plugin.
 */

/**
 * Site Equivalents plugin definition.
 */
$plugin = array(
  'title' => t('Refresh Power One site'),
  'category' => t('Solar4Rschools elements'),
  'description' => t('Sync Power One site information.'),
  'required context' => array(
    new ctools_context_required(t('Generation site'), 'generation_site'),
  ),
);

/**
 * CTools content type output function.
 */
function power_one_pow_refresh_content_type_render($subtype, $conf, $panels_args, $context) {
  if (empty($context) || empty($context[0]->data)) {
    return;
  }

  module_load_include('inc', 'power_one', 'power_one.pages');

  // Build the custom content pane.
  $pane = new stdClass();
  $pane->module  = 'power_one';
  $pane->title   = '';
  $pane->content = drupal_get_form('power_one_refresh_form', $context[0]->data);

  return $pane;
}

/**
 * Pane admin form.
 */
function power_one_pow_refresh_content_type_edit_form($form, &$form_state) {
  // No additional config.
  return $form;
}
