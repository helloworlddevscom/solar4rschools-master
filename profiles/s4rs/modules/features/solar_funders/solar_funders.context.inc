<?php
/**
 * @file
 * solar_funders.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_funders_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'browse_funders';
  $context->description = 'Block placements specific to the Funders pages';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'browse-funders' => 'browse-funders',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-092f0b2a8ab9c7c34d5f07ecdfeb7271' => array(
          'module' => 'views',
          'delta' => '092f0b2a8ab9c7c34d5f07ecdfeb7271',
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
  t('Block placements specific to the Funders pages');
  t('Solar 4R Schools');
  $export['browse_funders'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'funder_node';
  $context->description = 'Funder/User page-specific context';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'users/*' => 'users/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'solar_projects-project_map_expand' => array(
          'module' => 'solar_projects',
          'delta' => 'project_map_expand',
          'region' => 'main_prefix',
          'weight' => '-10',
          'title' => '',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Funder/User page-specific context');
  t('Solar 4R Schools');
  $export['funder_node'] = $context;

  return $export;
}
