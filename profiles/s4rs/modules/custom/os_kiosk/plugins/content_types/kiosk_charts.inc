<?php
/**
 * @file
 * Kiosk Charts panel pane plugin.
 */

/**
 * Kiosk Charts plugin definition.
 */
$plugin = array(
  'title' => t('Kiosk chart'),
  'category' => t('Solar4Rschools elements'),
  'description' => t('Charts for a given kiosk'),
  'required context' => new ctools_context_required(t('Generation Site'), 'generation_site'),
);

/**
 * CTools content type output function.
 */
function os_kiosk_kiosk_charts_content_type_render($subtype, $conf, $panels_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Build the custom content pane.

  $pane = new stdClass();
  $pane->module  = 'os_kiosk';
  $pane->title   = '';
  $pane->content = os_kiosk_get_chart_content($context->data);

  return $pane;
}

/**
 * Pane admin form.
 */
function os_kiosk_kiosk_charts_content_type_edit_form($form, &$form_state) {
  // No additional config.
  return $form;
}

/**
 * Get the chart for a given site.
 *
 * @param Entity $site
 *   The generation site.
 *
 * @return string
 *   The content for the kiosk charts.
 */
function os_kiosk_get_chart_content(Entity $site) {
  module_load_include('inc', 'os_kiosk', 'os_kiosk.pages');
  return _os_kiosk_chart_block($site, OS_KIOSK_DEFAULT_PERIOD);
}
