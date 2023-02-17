<?php
/**
 * @file default.settings.local.php
 */

// When using Lando, use Lando settings.
// Prepare a LANDO_INFO constant.
// See: https://jigarius.com/blog/drupal-with-lando
if (isset($_ENV['LANDO_INFO'])) {
  define('LANDO_INFO', json_decode($_ENV['LANDO_INFO'], TRUE));
}
if (defined('LANDO_INFO')) {
  // Databases.
  $databases['default']['default'] = [
    'driver' => 'mysql',
    'database' => LANDO_INFO['database']['creds']['database'],
    'username' => LANDO_INFO['database']['creds']['user'],
    'password' => LANDO_INFO['database']['creds']['password'],
    'host' => LANDO_INFO['database']['internal_connection']['host'],
    'port' => LANDO_INFO['database']['internal_connection']['port'],
    'prefix' => '',
  ];

  // Override search API server settings for Lando.
  // Run `lando info` and look for internal_connection info. We need to match that config here.
  $conf['search_api_override_mode'] = 'load';
  $conf['search_api_override_servers'] = array(
    'default' => array(
      'name' => 'CEBF Solr Server (overridden for Lando Solr)',
      'options' => array(
        'host' => LANDO_INFO['solr']['internal_connection']['host'],
        'port' => LANDO_INFO['solr']['internal_connection']['port'],
        'path' => '/solr/cebf_search_local',
        'http_user' => '',
        'http_pass' => '',
        'excerpt' => 0,
        'retrieve_data' => 0,
        'highlight_data' => 0,
        'http_method' => 'AUTO',
      ),
    ),
  );

  // Set base URL.
  $base_url = "https://cebf.lando";

  // Set tmp directory.
  $conf['file_temporary_path'] = '/tmp';
}
// If not Lando, use localhost config.
else {
  // Database config for localhost.
  $databases['default']['default'] = array(
    'driver' => 'mysql',
    'database' => 'cebf',
    'username' => 'cebf',
    'password' => 'cebf',
    'host' => 'localhost',
    'prefix' => '',
  );

  // Override search API server settings for local config.
  $conf['search_api_override_mode'] = 'load';
  $conf['search_api_override_servers'] = array(
    'default' => array(
      'name' => 'CEBF Solr Server (overridden)',
      'options' => array(
        'host' => 'localhost',
        'port' => '8983',
        'path' => '/solr',
        'http_user' => '',
        'http_pass' => '',
        'excerpt' => 0,
        'retrieve_data' => 0,
        'highlight_data' => 0,
        'http_method' => 'AUTO',
      ),
    ),
  );
}

// Page cache.
$conf['cache'] = FALSE;

// Block cache.
$conf['block_cache'] = FALSE;

$conf['cache_lifetime'] = FALSE;

$conf['page_cache_maximum_age'] = FALSE;

// Optimize CSS files.
$conf['preprocess_css'] = FALSE;

// Optimize JavaScript files.
$conf['preprocess_js'] = FALSE;

// Turn on HTML comment template suggestions.
$conf['theme_debug'] = TRUE;


// @TODO: Document this.
//$conf['bef_misc_legacy_domain'] = 'cebf.local';
//$conf['bef_misc_primary_domain'] = 'cebf.local';


// See README for explanation of this setting.
// Please leave commented or set to FALSE.
//$conf['locus_energy_cron_force_run'] = TRUE;
