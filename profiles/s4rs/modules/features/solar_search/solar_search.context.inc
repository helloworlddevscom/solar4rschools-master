<?php
/**
 * @file
 * solar_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'learning_center';
  $context->description = 'Context for the Solar Learning center or "Learn" tab.';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '/learn' => '/learn',
        '/learn/article-categories/*' => '/learn/article-categories/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-node_search-panel_pane_7' => array(
          'module' => 'views',
          'delta' => '-exp-node_search-panel_pane_7',
          'region' => 'main_prefix',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the Solar Learning center or "Learn" tab.');
  t('Solar 4R Schools');
  $export['learning_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_page';
  $context->description = 'Default search page specific context.';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-node_search-panel_pane_6' => array(
          'module' => 'views',
          'delta' => '-exp-node_search-panel_pane_6',
          'region' => 'main_prefix',
          'weight' => '-10',
          'title' => 'Search Options',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default search page specific context.');
  t('Solar 4R Schools');
  $export['search_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_result_item';
  $context->description = 'Nodes or users usually reached from a search page.';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'activity' => 'activity',
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'solar_search-back_button' => array(
          'module' => 'solar_search',
          'delta' => 'back_button',
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
  t('Nodes or users usually reached from a search page.');
  t('Solar 4R Schools');
  $export['search_result_item'] = $context;

  return $export;
}
