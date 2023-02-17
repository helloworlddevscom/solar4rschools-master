<?php
/**
 * @file
 * solar_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'browse_projects';
  $context->description = 'Block placements specific to the Browse Projects page';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'browse-projects' => 'browse-projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-920a216bab2878c242538bc079fc8f1c' => array(
          'module' => 'views',
          'delta' => '920a216bab2878c242538bc079fc8f1c',
          'region' => 'main_prefix',
          'weight' => '35',
          'title' => 'Search window',
        ),
        'solar_projects-project_map_expand' => array(
          'module' => 'solar_projects',
          'delta' => 'project_map_expand',
          'region' => 'main_prefix',
          'weight' => '-34',
          'title' => '',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block placements specific to the Browse Projects page');
  t('Solar 4R Schools');
  $export['browse_projects'] = $context;

  return $export;
}
