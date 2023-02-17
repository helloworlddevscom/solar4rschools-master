<?php
/**
 * @file
 * solar_data.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_data_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'widgets';
  $context->description = 'Blank theme for widget iframes';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/widget' => 'node/*/widget',
        'user/*/widget' => 'user/*/widget',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'flare' => array(
        'disable' => array(
          'header' => 'header',
          'main_prefix' => 'main_prefix',
          'main_suffix' => 'main_suffix',
          'footer' => 'footer',
          'dashboard_main' => 'dashboard_main',
          'dashboard_sidebar' => 'dashboard_sidebar',
          'dashboard_inactive' => 'dashboard_inactive',
          'content' => 0,
        ),
      ),
      'kiosk' => array(
        'disable' => array(
          'header' => 0,
          'main_prefix' => 0,
          'content' => 0,
          'main_suffix' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'help' => 'help',
          'page_top' => 'page_top',
          'page_bottom' => 'page_bottom',
          'sidebar_first' => 'sidebar_first',
          'dashboard_main' => 'dashboard_main',
          'dashboard_sidebar' => 'dashboard_sidebar',
          'dashboard_inactive' => 'dashboard_inactive',
          'content' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blank theme for widget iframes');
  t('Solar 4R Schools');
  $export['widgets'] = $context;

  return $export;
}
