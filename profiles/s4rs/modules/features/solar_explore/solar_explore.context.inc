<?php
/**
 * @file
 * solar_explore.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_explore_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solar_explore';
  $context->description = 'Solar Data Exploration center';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'explore-data*' => 'explore-data*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'explore_data-explore_data_form' => array(
          'module' => 'explore_data',
          'delta' => 'explore_data_form',
          'region' => 'main_prefix',
          'weight' => '-10',
          'title' => 'Graph Window',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Solar 4R Schools');
  t('Solar Data Exploration center');
  $export['solar_explore'] = $context;

  return $export;
}
