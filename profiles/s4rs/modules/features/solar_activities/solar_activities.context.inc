<?php
/**
 * @file
 * solar_activities.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_activities_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'science_kit_catalog';
  $context->description = 'Block placements specific to the Science Kit Catalog';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'teach/science-kits' => 'teach/science-kits',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-node_search-panel_pane_1' => array(
          'module' => 'views',
          'delta' => '-exp-node_search-panel_pane_1',
          'region' => 'main_prefix',
          'weight' => '-10',
          'title' => 'Search Window',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block placements specific to the Science Kit Catalog');
  t('Solar 4R Schools');
  $export['science_kit_catalog'] = $context;

  return $export;
}
