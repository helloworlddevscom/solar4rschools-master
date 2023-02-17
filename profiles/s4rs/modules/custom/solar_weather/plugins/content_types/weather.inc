<?php
/**
 * @file
 * Kiosk Charts panel pane plugin.
 */

/**
 * Kiosk Charts plugin definition.
 */
$plugin = array(
  'title' => t('Weather'),
  'category' => t('Solar4Rschools elements'),
  'description' => t('Local weather block for kiosks'),
  'required context' => new ctools_context_required(t('Generation Site'), 'generation_site'),
);

/**
 * CTools content type output function.
 */
function solar_weather_weather_content_type_render($subtype, $conf, $panels_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Build the custom content pane.
  module_load_include('inc', 'solar_weather');
  $pane = new stdClass();
  $pane->module  = 'solar_weather';
  $pane->title   = '';
  $pane->content = solar_weather_collect_data($context->data);

  return $pane;
}

/**
 * Pane admin form.
 */
function solar_weather_weather_content_type_edit_form($form, &$form_state) {
  // No additional config.
  return $form;
}
