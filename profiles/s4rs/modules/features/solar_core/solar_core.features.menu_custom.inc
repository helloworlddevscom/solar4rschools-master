<?php
/**
 * @file
 * solar_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function solar_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-bef-websites.
  $menus['menu-bef-websites'] = array(
    'menu_name' => 'menu-bef-websites',
    'title' => 'BEF Websites',
    'description' => 'A list of related BEF Websites that will appear near the bottom of the page.',
  );
  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => 'Links at the bottom of the page meant as a quick reference for visitors. Contains items like the sitemap, terms and conditions, and repeats of the items at the root of the main menu.',
  );
  // Exported menu: menu-quick-links.
  $menus['menu-quick-links'] = array(
    'menu_name' => 'menu-quick-links',
    'title' => 'Quick links',
    'description' => 'Links at the top of the page intended to help with sharing the site. Items might include sharethis, pressrooms, RFP details, etc.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A list of related BEF Websites that will appear near the bottom of the page.');
  t('BEF Websites');
  t('Footer menu');
  t('Links at the bottom of the page meant as a quick reference for visitors. Contains items like the sitemap, terms and conditions, and repeats of the items at the root of the main menu.');
  t('Links at the top of the page intended to help with sharing the site. Items might include sharethis, pressrooms, RFP details, etc.');
  t('Quick links');

  return $menus;
}
