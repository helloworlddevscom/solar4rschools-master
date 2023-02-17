<?php
/**
 * @file
 * solar_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function solar_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Site-wide block placements';
  $context->tag = 'Solar 4R Schools';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'theme' => array(
      'values' => array(
        'flare' => 'flare',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'blockify-blockify-logo' => array(
          'module' => 'blockify',
          'delta' => 'blockify-logo',
          'region' => 'header',
          'weight' => '-10',
        ),
        'solar_search-global_search' => array(
          'module' => 'solar_search',
          'delta' => 'global_search',
          'region' => 'header',
          'weight' => '-9',
        ),
        'menu-menu-quick-links' => array(
          'module' => 'menu',
          'delta' => 'menu-quick-links',
          'region' => 'header',
          'weight' => '-8',
        ),
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'header',
          'weight' => '-7',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'main_prefix',
          'weight' => '-9',
        ),
        'take_a_tour-take_a_tour' => array(
          'module' => 'take_a_tour',
          'delta' => 'take_a_tour',
          'region' => 'main_prefix',
          'weight' => '-8',
        ),
        'blockify-blockify-page-title' => array(
          'module' => 'blockify',
          'delta' => 'blockify-page-title',
          'region' => 'main_prefix',
          'weight' => '-7',
        ),
        'blockify-blockify-messages' => array(
          'module' => 'blockify',
          'delta' => 'blockify-messages',
          'region' => 'main_prefix',
          'weight' => '-6',
        ),
        'blockify-blockify-tabs' => array(
          'module' => 'blockify',
          'delta' => 'blockify-tabs',
          'region' => 'main_prefix',
          'weight' => '-5',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'main_prefix',
          'weight' => '-4',
        ),
        'blockify-blockify-actions' => array(
          'module' => 'blockify',
          'delta' => 'blockify-actions',
          'region' => 'main_prefix',
          'weight' => '-3',
        ),
        'blockify-blockify-feed-icons' => array(
          'module' => 'blockify',
          'delta' => 'blockify-feed-icons',
          'region' => 'main_suffix',
          'weight' => '-33',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'main_suffix',
          'weight' => '-32',
        ),
        'menu-menu-bef-websites' => array(
          'module' => 'menu',
          'delta' => 'menu-bef-websites',
          'region' => 'main_suffix',
          'weight' => '-31',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'main_suffix',
          'weight' => '-30',
        ),
        'social_media_links-social-media-links' => array(
          'module' => 'social_media_links',
          'delta' => 'social-media-links',
          'region' => 'main_suffix',
          'weight' => '-29',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer',
          'weight' => '-33',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site-wide block placements');
  t('Solar 4R Schools');
  $export['sitewide'] = $context;

  return $export;
}
