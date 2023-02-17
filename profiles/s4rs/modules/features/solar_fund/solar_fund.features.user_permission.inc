<?php
/**
 * @file
 * solar_fund.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_fund_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable funding_partner_option'.
  $permissions['create fieldable funding_partner_option'] = array(
    'name' => 'create fieldable funding_partner_option',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable funding_partner_option'.
  $permissions['delete fieldable funding_partner_option'] = array(
    'name' => 'delete fieldable funding_partner_option',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable funding_partner_option'.
  $permissions['edit fieldable funding_partner_option'] = array(
    'name' => 'edit fieldable funding_partner_option',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
