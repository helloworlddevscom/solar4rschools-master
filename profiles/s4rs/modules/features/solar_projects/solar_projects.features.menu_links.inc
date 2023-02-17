<?php
/**
 * @file
 * solar_projects.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function solar_projects_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_my-projects:user/1/my-projects
  $menu_links['user-menu_my-projects:user/1/my-projects'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/1/my-projects',
    'router_path' => 'user/%/my-projects',
    'link_title' => 'My Projects',
    'options' => array(
      'menu_token_link_path' => 'user/[current-user:uid]/my-projects',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'user-menu_my-projects:user/1/my-projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('My Projects');

  return $menu_links;
}
