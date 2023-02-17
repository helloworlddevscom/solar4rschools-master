<?php
/**
 * @file
 * bef_recaptcha_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bef_recaptcha_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_captcha:admin/config/people/captcha.
  $menu_links['management_captcha:admin/config/people/captcha'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/captcha',
    'router_path' => 'admin/config/people/captcha',
    'link_title' => 'CAPTCHA',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer how and where CAPTCHAs are used.',
      ),
      'identifier' => 'management_captcha:admin/config/people/captcha',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_people:admin/config/people',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CAPTCHA');

  return $menu_links;
}
