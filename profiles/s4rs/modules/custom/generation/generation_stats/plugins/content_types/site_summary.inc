<?php
/**
 * @file
 * Kiosk Charts panel pane plugin.
 */

/**
 * Kiosk Charts plugin definition.
 */
$plugin = array(
  'title' => t('Site summary'),
  'category' => t('Solar4Rschools elements'),
  'description' => t('Summary for a given kiosk'),
  'required context' => new ctools_context_required(t('Generation Site'), 'generation_site'),
);

/**
 * CTools content type output function.
 */
function generation_stats_site_summary_content_type_render($subtype, $conf, $panels_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Build the custom content pane.

  $pane = new stdClass();
  $pane->module  = 'generation_stats';
  $pane->title   = '';
  $pane->content = generation_stats_get_stats_content($context->data);

  return $pane;
}

/**
 * Pane admin form.
 */
function generation_stats_site_summary_content_type_edit_form($form, &$form_state) {
  // No additional config.
  return $form;
}

/**
 * Get the site summary for a given site.
 *
 * @param Entity $site
 *   The generation site.
 *
 * @return string
 *   The content for the kiosk charts.
 */
function generation_stats_get_stats_content(Entity $site) {
  $period = 'week';
  $delta = 'site_summary';
  drupal_alter('generation_stats_default_period', $period, $delta);
  return _generation_stats_block_view($delta, $site, $period);
}
