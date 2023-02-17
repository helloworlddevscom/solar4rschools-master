<?php
/**
 * @file
 * solar_explore.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function solar_explore_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer explore data variables'.
  $permissions['administer explore data variables'] = array(
    'name' => 'administer explore data variables',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'explore_data',
  );

  // Exported permission: 'eck add deck_device bundles'.
  $permissions['eck add deck_device bundles'] = array(
    'name' => 'eck add deck_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add deck_device device entities'.
  $permissions['eck add deck_device device entities'] = array(
    'name' => 'eck add deck_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add equivalencies_statistics bundles'.
  $permissions['eck add equivalencies_statistics bundles'] = array(
    'name' => 'eck add equivalencies_statistics bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add equivalencies_statistics equivalencies_statistics entities'.
  $permissions['eck add equivalencies_statistics equivalencies_statistics entities'] = array(
    'name' => 'eck add equivalencies_statistics equivalencies_statistics entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add generation_site bundles'.
  $permissions['eck add generation_site bundles'] = array(
    'name' => 'eck add generation_site bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add generation_site deck entities'.
  $permissions['eck add generation_site deck entities'] = array(
    'name' => 'eck add generation_site deck entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add generation_site power_one entities'.
  $permissions['eck add generation_site power_one entities'] = array(
    'name' => 'eck add generation_site power_one entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add pow_device bundles'.
  $permissions['eck add pow_device bundles'] = array(
    'name' => 'eck add pow_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add pow_device device entities'.
  $permissions['eck add pow_device device entities'] = array(
    'name' => 'eck add pow_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add pow_logger bundles'.
  $permissions['eck add pow_logger bundles'] = array(
    'name' => 'eck add pow_logger bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add pow_logger logger entities'.
  $permissions['eck add pow_logger logger entities'] = array(
    'name' => 'eck add pow_logger logger entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add saved_graph bundles'.
  $permissions['eck add saved_graph bundles'] = array(
    'name' => 'eck add saved_graph bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add saved_graph saved_graph entities'.
  $permissions['eck add saved_graph saved_graph entities'] = array(
    'name' => 'eck add saved_graph saved_graph entities',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer deck_device bundles'.
  $permissions['eck administer deck_device bundles'] = array(
    'name' => 'eck administer deck_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer deck_device device entities'.
  $permissions['eck administer deck_device device entities'] = array(
    'name' => 'eck administer deck_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer equivalencies_statistics bundles'.
  $permissions['eck administer equivalencies_statistics bundles'] = array(
    'name' => 'eck administer equivalencies_statistics bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer equivalencies_statistics equivalencies_statistics entities'.
  $permissions['eck administer equivalencies_statistics equivalencies_statistics entities'] = array(
    'name' => 'eck administer equivalencies_statistics equivalencies_statistics entities',
    'roles' => array(
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer generation_site bundles'.
  $permissions['eck administer generation_site bundles'] = array(
    'name' => 'eck administer generation_site bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer generation_site deck entities'.
  $permissions['eck administer generation_site deck entities'] = array(
    'name' => 'eck administer generation_site deck entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer generation_site power_one entities'.
  $permissions['eck administer generation_site power_one entities'] = array(
    'name' => 'eck administer generation_site power_one entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer pow_device bundles'.
  $permissions['eck administer pow_device bundles'] = array(
    'name' => 'eck administer pow_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer pow_device device entities'.
  $permissions['eck administer pow_device device entities'] = array(
    'name' => 'eck administer pow_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer pow_logger bundles'.
  $permissions['eck administer pow_logger bundles'] = array(
    'name' => 'eck administer pow_logger bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer pow_logger logger entities'.
  $permissions['eck administer pow_logger logger entities'] = array(
    'name' => 'eck administer pow_logger logger entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer saved_graph bundles'.
  $permissions['eck administer saved_graph bundles'] = array(
    'name' => 'eck administer saved_graph bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer saved_graph saved_graph entities'.
  $permissions['eck administer saved_graph saved_graph entities'] = array(
    'name' => 'eck administer saved_graph saved_graph entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete deck_device bundles'.
  $permissions['eck delete deck_device bundles'] = array(
    'name' => 'eck delete deck_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete deck_device device entities'.
  $permissions['eck delete deck_device device entities'] = array(
    'name' => 'eck delete deck_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete equivalencies_statistics bundles'.
  $permissions['eck delete equivalencies_statistics bundles'] = array(
    'name' => 'eck delete equivalencies_statistics bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete equivalencies_statistics equivalencies_statistics entities'.
  $permissions['eck delete equivalencies_statistics equivalencies_statistics entities'] = array(
    'name' => 'eck delete equivalencies_statistics equivalencies_statistics entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete generation_site bundles'.
  $permissions['eck delete generation_site bundles'] = array(
    'name' => 'eck delete generation_site bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete generation_site deck entities'.
  $permissions['eck delete generation_site deck entities'] = array(
    'name' => 'eck delete generation_site deck entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete generation_site power_one entities'.
  $permissions['eck delete generation_site power_one entities'] = array(
    'name' => 'eck delete generation_site power_one entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete pow_device bundles'.
  $permissions['eck delete pow_device bundles'] = array(
    'name' => 'eck delete pow_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete pow_device device entities'.
  $permissions['eck delete pow_device device entities'] = array(
    'name' => 'eck delete pow_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete pow_logger bundles'.
  $permissions['eck delete pow_logger bundles'] = array(
    'name' => 'eck delete pow_logger bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete pow_logger logger entities'.
  $permissions['eck delete pow_logger logger entities'] = array(
    'name' => 'eck delete pow_logger logger entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete saved_graph bundles'.
  $permissions['eck delete saved_graph bundles'] = array(
    'name' => 'eck delete saved_graph bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete saved_graph saved_graph entities'.
  $permissions['eck delete saved_graph saved_graph entities'] = array(
    'name' => 'eck delete saved_graph saved_graph entities',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit deck_device bundles'.
  $permissions['eck edit deck_device bundles'] = array(
    'name' => 'eck edit deck_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit deck_device device entities'.
  $permissions['eck edit deck_device device entities'] = array(
    'name' => 'eck edit deck_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit equivalencies_statistics bundles'.
  $permissions['eck edit equivalencies_statistics bundles'] = array(
    'name' => 'eck edit equivalencies_statistics bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit equivalencies_statistics equivalencies_statistics entities'.
  $permissions['eck edit equivalencies_statistics equivalencies_statistics entities'] = array(
    'name' => 'eck edit equivalencies_statistics equivalencies_statistics entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit generation_site bundles'.
  $permissions['eck edit generation_site bundles'] = array(
    'name' => 'eck edit generation_site bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit generation_site deck entities'.
  $permissions['eck edit generation_site deck entities'] = array(
    'name' => 'eck edit generation_site deck entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit generation_site power_one entities'.
  $permissions['eck edit generation_site power_one entities'] = array(
    'name' => 'eck edit generation_site power_one entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit pow_device bundles'.
  $permissions['eck edit pow_device bundles'] = array(
    'name' => 'eck edit pow_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit pow_device device entities'.
  $permissions['eck edit pow_device device entities'] = array(
    'name' => 'eck edit pow_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit pow_logger bundles'.
  $permissions['eck edit pow_logger bundles'] = array(
    'name' => 'eck edit pow_logger bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit pow_logger logger entities'.
  $permissions['eck edit pow_logger logger entities'] = array(
    'name' => 'eck edit pow_logger logger entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit saved_graph bundles'.
  $permissions['eck edit saved_graph bundles'] = array(
    'name' => 'eck edit saved_graph bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit saved_graph saved_graph entities'.
  $permissions['eck edit saved_graph saved_graph entities'] = array(
    'name' => 'eck edit saved_graph saved_graph entities',
    'roles' => array(
      'administrator' => 'administrator',
      'educator' => 'educator',
      'site editor' => 'site editor',
      'teacher champion' => 'teacher champion',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list deck_device bundles'.
  $permissions['eck list deck_device bundles'] = array(
    'name' => 'eck list deck_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list deck_device device entities'.
  $permissions['eck list deck_device device entities'] = array(
    'name' => 'eck list deck_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entities'.
  $permissions['eck list entities'] = array(
    'name' => 'eck list entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list equivalencies_statistics bundles'.
  $permissions['eck list equivalencies_statistics bundles'] = array(
    'name' => 'eck list equivalencies_statistics bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list equivalencies_statistics equivalencies_statistics entities'.
  $permissions['eck list equivalencies_statistics equivalencies_statistics entities'] = array(
    'name' => 'eck list equivalencies_statistics equivalencies_statistics entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list generation_site bundles'.
  $permissions['eck list generation_site bundles'] = array(
    'name' => 'eck list generation_site bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list generation_site deck entities'.
  $permissions['eck list generation_site deck entities'] = array(
    'name' => 'eck list generation_site deck entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list generation_site power_one entities'.
  $permissions['eck list generation_site power_one entities'] = array(
    'name' => 'eck list generation_site power_one entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list pow_device bundles'.
  $permissions['eck list pow_device bundles'] = array(
    'name' => 'eck list pow_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list pow_device device entities'.
  $permissions['eck list pow_device device entities'] = array(
    'name' => 'eck list pow_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list pow_logger bundles'.
  $permissions['eck list pow_logger bundles'] = array(
    'name' => 'eck list pow_logger bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list pow_logger logger entities'.
  $permissions['eck list pow_logger logger entities'] = array(
    'name' => 'eck list pow_logger logger entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list saved_graph bundles'.
  $permissions['eck list saved_graph bundles'] = array(
    'name' => 'eck list saved_graph bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list saved_graph saved_graph entities'.
  $permissions['eck list saved_graph saved_graph entities'] = array(
    'name' => 'eck list saved_graph saved_graph entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view deck_device bundles'.
  $permissions['eck view deck_device bundles'] = array(
    'name' => 'eck view deck_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view deck_device device entities'.
  $permissions['eck view deck_device device entities'] = array(
    'name' => 'eck view deck_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view equivalencies_statistics bundles'.
  $permissions['eck view equivalencies_statistics bundles'] = array(
    'name' => 'eck view equivalencies_statistics bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view equivalencies_statistics equivalencies_statistics entities'.
  $permissions['eck view equivalencies_statistics equivalencies_statistics entities'] = array(
    'name' => 'eck view equivalencies_statistics equivalencies_statistics entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view generation_site bundles'.
  $permissions['eck view generation_site bundles'] = array(
    'name' => 'eck view generation_site bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view generation_site deck entities'.
  $permissions['eck view generation_site deck entities'] = array(
    'name' => 'eck view generation_site deck entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view generation_site power_one entities'.
  $permissions['eck view generation_site power_one entities'] = array(
    'name' => 'eck view generation_site power_one entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view pow_device bundles'.
  $permissions['eck view pow_device bundles'] = array(
    'name' => 'eck view pow_device bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view pow_device device entities'.
  $permissions['eck view pow_device device entities'] = array(
    'name' => 'eck view pow_device device entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view pow_logger bundles'.
  $permissions['eck view pow_logger bundles'] = array(
    'name' => 'eck view pow_logger bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view pow_logger logger entities'.
  $permissions['eck view pow_logger logger entities'] = array(
    'name' => 'eck view pow_logger logger entities',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view saved_graph bundles'.
  $permissions['eck view saved_graph bundles'] = array(
    'name' => 'eck view saved_graph bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view saved_graph saved_graph entities'.
  $permissions['eck view saved_graph saved_graph entities'] = array(
    'name' => 'eck view saved_graph saved_graph entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage deck_device properties'.
  $permissions['manage deck_device properties'] = array(
    'name' => 'manage deck_device properties',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage equivalencies_statistics properties'.
  $permissions['manage equivalencies_statistics properties'] = array(
    'name' => 'manage equivalencies_statistics properties',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage generation_site properties'.
  $permissions['manage generation_site properties'] = array(
    'name' => 'manage generation_site properties',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage pow_device properties'.
  $permissions['manage pow_device properties'] = array(
    'name' => 'manage pow_device properties',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage pow_logger properties'.
  $permissions['manage pow_logger properties'] = array(
    'name' => 'manage pow_logger properties',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage saved_graph properties'.
  $permissions['manage saved_graph properties'] = array(
    'name' => 'manage saved_graph properties',
    'roles' => array(),
    'module' => 'eck',
  );

  return $permissions;
}
