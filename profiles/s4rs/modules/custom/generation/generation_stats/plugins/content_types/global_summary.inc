<?php
/**
 * @file
 * Global summary panel pane plugin.
 */

/**
 * Global summary plugin definition.
 */
$plugin = array(
  'title' => t('Global summary'),
  'category' => t('Solar4Rschools elements'),
  'description' => t('Summary for all projects')
);

/**
 * CTools content type output function.
 */
function generation_stats_global_summary_content_type_render($subtype, $conf, $panels_args, $context) {
  // Build the custom content pane.

  $pane = new stdClass();
  $pane->module  = 'generation_stats';
  $pane->title   = '';
  $pane->content = _generation_stats_block_view('global_summary');

  return $pane;
}

/**
 * Pane admin form.
 */
function generation_stats_global_summary_content_type_edit_form($form, &$form_state) {
  // No additional config.
  return $form;
}
