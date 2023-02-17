<?php
/**
 * @file
 * solar_fund.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function solar_fund_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_fund:<nolink>
  $menu_links['main-menu_fund:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Fund',
    'options' => array(
      'attributes' => array(
        'title' => 'Funding landing page',
      ),
      'identifier' => 'main-menu_fund:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Fund');


  return $menu_links;
}
