<?php
/**
 * @file
 * solar_applications.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function solar_applications_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_apply:<nolink>
  $menu_links['main-menu_apply:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Apply',
    'options' => array(
      'identifier' => 'main-menu_apply:<nolink>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
  );
  // Exported menu link: main-menu_before-you-applywhat-to-expect:node/3
  $menu_links['main-menu_before-you-applywhat-to-expect:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'before you apply—what to expect',
    'options' => array(
      'identifier' => 'main-menu_before-you-applywhat-to-expect:node/3',
      'attributes' => array(
        'title' => 'Educators—Discover what you can expect before applying for a Solar 4R Schools renewable energy education project grant, and read more about what you\'ll receive if awarded.',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_apply:<nolink>',
  );
  // Exported menu link: main-menu_start-an-application:eform/submit/renewable-school-application
  $menu_links['main-menu_start-an-application:eform/submit/renewable-school-application'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'eform/submit/renewable-school-application',
    'router_path' => 'eform/submit/%',
    'link_title' => 'start an application',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_start-an-application:eform/submit/renewable-school-application',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 1,
    'parent_identifier' => 'main-menu_apply:<nolink>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Apply');
  t('before you apply—what to expect');
  t('start an application');


  return $menu_links;
}
