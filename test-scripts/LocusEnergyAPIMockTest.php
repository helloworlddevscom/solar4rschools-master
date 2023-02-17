<?php
/**
 * @file
 * A drush script to try to run a test.
 *
 * To run the tests, simply run the script from drush:
 *   drush php-script --script-path=../test-scripts/ LocusEnergyAPIMockTest.php
 *
 * NOTE: The test will make database changes, so only run this on a dev environment.
 */
require_once 'helpers.inc';

// --- Test Locations ---

// Story 1:
// Given valid Locus Energy API credentials
// And the system does not have a valid access token
variable_del('locus_energy_access_token_expires');
$api = getMockInstance();
// When querying the Locus Energy API
// Then the system should authenticate with Locus Energy API
$authenticated = $api->authenticate();
assertEquals(TRUE, $authenticated, 'authenticating!');
// And store the access token from the successful authentication response
$access_token = $api->access_token;
assertEquals('vOJEF6WKkEsA4t7a0rgERaoEwGgQ', $access_token, 'matching access token!');

// Destroy our mock instance and get a new one
$api = getMockInstance();

// Story 2:
// Given valid Locus Energy API credentials
$authenticated = $api->authenticate();
assertEquals(TRUE, $authenticated, 'authenticating again!');
// And the system already has a valid access token
// When querying the Locus Energy API
// Then the system should query the Locus Energy API using the access token
assertEquals($access_token, $api->access_token, 'using same access token!');

// Destory our mock instance and get a new one
$api = getMockInstance();

// Set our expiration to a few seconds ago
variable_set('locus_energy_access_token_expires', time() - 10);

$authenticated = $api->authenticate();
assertEquals(TRUE, $authenticated, 're-authenticating!');

$access_token = $api->access_token;
assertEquals('vOJEF6WKkEsA4t7a0rgERaoEwGgQ', $access_token, 'matching access token!');

// Create New Locus Energy Locations
// Story 1:
// Given that a new location exists in the Locus Energy API response
db_query('DELETE FROM {locus_energy_locations} where site_id in (123, 789)');
$api->updateSites();
// When cron runs
// Then a new Locus Location node should be created
$result = db_query('SELECT * FROM {locus_energy_locations} where site_id in (123,789)');
$sites = array();
while ($site = db_fetch_object($result)) {
  $sites[$site->site_id] = $site;
}

assertEquals(TRUE, in_array(123, array_keys($sites)), '123 created');
assertEquals(TRUE, in_array(789, array_keys($sites)), '789 created');

// Story 2:
// Given that no new locations exist in the Locus Energy API response
// When cron runs
// Then no new Locus Location nodes should be created

// Test for duplicates
db_query('DELETE FROM {locus_energy_locations} where site_id in (789)');
$api->updateSites();
// When cron runs
// Then a new Locus Location node should be created
$result = db_query('SELECT * FROM {locus_energy_locations} where site_id in (123,789)');
$sites = array();
while ($site = db_fetch_object($result)) {
  $sites[$site->site_id] = $site;
}

assertEquals(TRUE, in_array(123, array_keys($sites)), 'creating site 123');
assertEquals(TRUE, in_array(789, array_keys($sites)), 'checking site 789 exists');

if (isset($sites[123])) {
  $node123 = node_load($sites[123]->nid);
  assertEquals($sites[123]->nid, $node123->nid, 'loading node for site 123');
  // Test that address is set on node
  assertEquals('Test Site', $node123->title, 'setting site title');
  assertEquals('657 Mission St', $node123->location['street'], 'setting location street');
  assertEquals('San Francisco', $node123->location['city'], 'setting location city');
  assertEquals('CA', $node123->location['province'], 'setting location state');
  assertEquals('94105', $node123->location['postal_code'], 'setting location zip code');
  // Test that install date is set on node
  assertEquals('2014-05-08T00:00:00', $node123->field_school_install_date[0]['value'], 'setting install date field');
  // Test that installer is set on node
  assertEquals('ABC Solar', $node123->field_site_installer[0]['value'], 'setting installer field');
  // Test that getInstallDate returns the install date and that it is correct
  $apiInstallDate = $api->getInstallDate($node123);
  assertEquals(true, $apiInstallDate ==  new DateTime('2014-05-08T00:00:00'), 'getting install date');
}

if (isset($sites[789])) {
  $node789 = node_load($sites[789]->nid);
  assertEquals($sites[789]->nid, $node789->nid, 'loading node for site 789');
  // Test that address is set on node
  assertEquals('Test Site 2', $node789->title, 'setting site title');
  assertEquals('2 Hudson Place', $node789->location['street'], 'setting location street');
  assertEquals('Hoboken', $node789->location['city'], 'setting location city');
  assertEquals('NJ', $node789->location['province'], 'setting location state');
  assertEquals('07030', $node789->location['postal_code'], 'setting location zip code');
  // Test that install date is set on node
  assertEquals('2014-05-08T00:00:00', $node789->field_school_install_date[0]['value'], 'setting install date field');
  // Test that installer is set on node
  assertEquals('ABC Solar', $node789->field_site_installer[0]['value'], 'setting installer field');
  // Test that getInstallDate returns the install date and that it is correct
  $apiInstallDate = $api->getInstallDate($node789);
  assertEquals(true, $apiInstallDate == new DateTime('2014-05-08T00:00:00'), 'getting install date');
}

// --- Test Variables ---

// Given there exists a Locus Energy Location
// And that location is the most outdated
// When cron runs
// And a new variable exists in the Variables API response for that location
// Then a new record will be created for that variable in the database

// Delete the mock variables
db_query('DELETE FROM {locus_energy_location_variables} WHERE site_id IN (123,789)');
// Deletes unused variables
db_query('DELETE FROM {locus_energy_variables} WHERE variable_id NOT IN (SELECT variable_id FROM {locus_energy_location_variables})');
// Deletes variable functions for missing variables
db_query('DELETE FROM {locus_energy_variable_functions} WHERE variable_id NOT IN (SELECT variable_id FROM {locus_energy_variables})');
// Mark site 123 as the most outdated
db_query('UPDATE {locus_energy_locations} SET last_variable_update=10, last_data_update=0 WHERE site_id=789');
db_query('UPDATE {locus_energy_locations} SET last_variable_update=0, last_data_update=0 WHERE site_id=123');
// Call our getSiteNeedingVariablesUpdate() method
$site123 = $api->getSiteNeedingVariablesUpdate();
$site_id = (int) $site123->site_id;
// Assert that it returns site 123
assertEquals(123, $site_id, 'getting site to update');
// Run our updateVariablesForSite() method
$api->updateVariablesForSite($site123->site_id);
// Test that site 123 is no longer the most outdated
$site789 = $api->getSiteNeedingVariablesUpdate();
$site_id = (int) $site789->site_id;
assertEquals(FALSE, $site_id === 123, 'marking site as updated');
// Add this sites variables, helps test we don't create duplicates
$api->updateVariablesForSite($site789->site_id);

// Test that getSiteVariables() returns the mock variables
$mock_site_vars = array(
  'W' => array(
    'variable' => 'W',
    'unit' => 'W',
  ),
  'W_c' => array(
    'variable' => 'W_c',
    'unit' => 'W',
  ),
  'W_n' => array(
    'variable' => 'W_n',
    'unit' => 'W',
  ),
  'Wh' => array(
    'variable' => 'Wh',
    'unit' => 'Wh',
  ),
  'Wh_c' => array(
    'variable' => 'Wh_c',
    'unit' => 'Wh',
  ),
  'Wh_n' => array(
    'variable' => 'Wh_n',
    'unit' => 'Wh',
  ),
);
$node123 = node_load($site123->nid);
assertEquals($site123->nid, $node123->nid, 'loading node');
assertEquals(123, (int) $node123->locus_energy->site_id, 'checking nodes site id');
$site_vars = $api->getSiteVariables($node123);
assertEquals($mock_site_vars, $site_vars, 'getting site variables');
// Test that getVariables() returns the mock variables
$mock_all_vars = array(
  'W' => 'AC Power',
  'W_c' => 'AC Power Consumed',
  'W_n' => 'AC Power Net',
  'Wh' => 'AC Energy',
  'Wh_c' => 'AC Energy Consumed',
  'Wh_n' => 'AC Energy Net',
);
$all_vars = $api->getVariables();
// Our test loops on the mock variables array because we can't compare the
// arrays directly since other variables may exist from getVariables()
foreach ($mock_all_vars as $key => $val) {
  assertEquals(TRUE, array_key_exists($key, $all_vars), 'getting ' . $key . ' in all variables');
  assertEquals($val, $all_vars[$key], 'getting ' . $key . ' in all variables');
}

// Test that getVariableUnits() returns the right units
$mock_all_units = array(
  'W' => array('label' => 'W'),
  'Wh' => array('label' => 'Wh'),
);
// Test that each of the mock units is in the all units
$all_units = $api->getVariableUnits();
foreach ($mock_all_units as $unit => $info) {
  assertEquals(TRUE, array_key_exists($unit, $all_units), 'getting ' . $unit . ' unit');
  assertEquals($info, $all_units[$unit], 'getting ' . $unit . ' unit info');
}
// Our test loops on the mock site variables array because we can't compare
// the arrays directly since other variables may exist from getVariableUnits()
foreach ($mock_site_vars as $var => $info) {
  $mock_var_units = array($info['unit'] => $mock_all_units[$info['unit']]);
  $units = $api->getVariableUnits($var);
  assertEquals($mock_var_units, $units, 'getting ' . $var . ' units');
}

// Test that getVariableFunctions() returns the right functions
$mock_all_aggregations = array(
  'avg' => t('Avg'),
  'max' => t('Max'),
  'sum' => t('Sum'),
);
$mock_var_aggregations = array(
  'W' => array(
    'avg' => t('Avg'),
    'max' => t('Max'),
  ),
  'W_c' => array(
    'avg' => t('Avg'),
    'max' => t('Max'),
  ),
  'W_n' => array(
    'avg' => t('Avg'),
    'max' => t('Max'),
  ),
  'Wh' => array(
    'sum' => t('Sum'),
  ),
  'Wh_c' => array(
    'sum' => t('Sum'),
  ),
  'Wh_n' => array(
    'sum' => t('Sum'),
  ),
);
$all_funcs = $api->getVariableFunctions();
assertEquals($mock_all_aggregations, $all_funcs, 'getting all functions');
foreach (array_keys($site_vars) as $var) {
  // getVariableFunctions takes an object
  $variable = (object) array(
    'name' => $var,
  );
  $mock_var_funcs = $mock_var_aggregations[$var];
  $funcs = $api->getVariableFunctions($variable);
  assertEquals($mock_var_funcs, $funcs, 'getting ' . $var . ' functions');
}

// Given there exists a Locus Energy Location
// And that location is the most outdated
// When cron runs
// And no new variable exists in the Variables API response for that location
// Then no new variable records will be created in the database

// Mark site 123 as the most outdated
db_query('UPDATE {locus_energy_locations} SET last_variable_update=0, last_data_update=0 WHERE site_id=123');
// Call our getSiteNeedingVariablesUpdate() method
$site = $api->getSiteNeedingVariablesUpdate();
// Assert that it returns site 123
$site_id = (int) $site->site_id;
assertEquals(123, $site_id, 'getting site to update');
// Run our updateVariablesForSite() method
$api->updateVariablesForSite($site->site_id);
// Test that there are not duplicate variables
$result = db_query('SELECT COUNT(*) AS var_count FROM {locus_energy_variables} GROUP BY baseField ORDER BY var_count DESC LIMIT 1');
$count = db_fetch_object($result);
assertEquals(1, (int) $count->var_count, 'ensuring no duplicate variables');

// Given there exists a Locus Energy Location
// And that location is the most outdated
// When cron runs
// And a variable no longer exists in the Variables API response for that location
// Then the variable record should be marked as inactive in the database

// Add a fake variable to the database
db_query("INSERT INTO {locus_energy_variables} (baseField, longName, source, unit)
  VALUES ('FAKE', 'Fake Variable', 'Imagined', 'fakeVar')");
$var_id = db_last_insert_id('locus_energy_variables', 'variable_id');
db_query("INSERT INTO {locus_energy_location_variables} (variable_id, site_id, minimum_granularity, removed)
  VALUES (%d, 123, '5min', 0)", $var_id);
db_query("INSERT INTO {locus_energy_variable_functions} (variable_id, aggregation, shortName)
  VALUES (%d, 'fakeFunction', 'Fake function')", $var_id);
// Mark site 123 as the most outdated
db_query('UPDATE {locus_energy_locations} SET last_variable_update=0, last_data_update=0 WHERE site_id=123');
// Call our getSiteNeedingVariablesUpdate() method
$site = $api->getSiteNeedingVariablesUpdate();
// Assert that it returns site 123
$site_id = (int) $site->site_id;
assertEquals(123, $site_id, 'getting site to update');
// Run our updateVariablesForSite() method
$api->updateVariablesForSite($site->site_id);
// Test that the variable in the database is now inactive
$result = db_query("SELECT * FROM {locus_energy_location_variables} WHERE variable_id=%d AND site_id=123", $var_id);
$row = db_fetch_object($result);
assertEquals(1, (int) $row->removed, 'marking variable as removed from api');
// Test that getSiteVariables() doesn't return the inactive variable
$site_vars = $api->getSiteVariables($node123);
assertEquals(FALSE, in_array('FAKE', array_keys($site_vars)), 'not showing removed variables in site variables');
assertEquals($mock_site_vars, $site_vars, 'getting site variables');
// Test that getVariables() doesn't return the inactive variable
$all_vars = $api->getVariables();
assertEquals(FALSE, in_array('FAKE', array_keys($all_vars)), 'not showing removed variables in all variables');
// Test that getVariableUnits() doesn't return the inactive variable
$units = $api->getVariableUnits();
assertEquals(FALSE, in_array('fakeVar', array_keys($units)), 'not showing removed units in all units');
// Test that getVariableFunctions() doesn't return the inactive variable
$funcs = $api->getVariableFunctions();
assertEquals(FALSE, in_array('fakeFunction', array_keys($funcs)), 'not showing removed functions in all functions');

// Mark all sites as up to date
db_query('UPDATE {locus_energy_locations} SET last_variable_update=%d, last_data_update=%d', time(), time());
// Test that getSiteNeedingVariablesUpdate() returns false when they are all up to date.
$site = $api->getSiteNeedingVariablesUpdate();
assertEquals(FALSE, $site, 'all sites variables up to date');
// Test that getSiteNeedingDataUpdate() returns false when they are all up to date.
$site = $api->getSiteNeedingDataUpdate();
assertEquals(FALSE, $site, 'all sites data up to date');


// Test that a variable that was re-added to the API is no longer marked as removed
$var_result = db_query("SELECT variable_id FROM {locus_energy_variables} WHERE baseField='W'");
$var_row = db_fetch_object($var_result);
db_query("UPDATE {locus_energy_location_variables} SET removed=1 WHERE site_id=123 AND variable_id=%d", $var_row->variable_id);
// Mark site 123 as the most outdated
db_query('UPDATE {locus_energy_locations} SET last_variable_update=0, last_data_update=0 WHERE site_id=123');
// Call our getSiteNeedingVariablesUpdate() method
$site = $api->getSiteNeedingVariablesUpdate();
// Assert that it returns site 123
$site_id = (int) $site->site_id;
assertEquals(123, $site_id, 'getting site to update');
// Run our updateVariablesForSite() method
$api->updateVariablesForSite($site->site_id);
// Test that the variable in the database is now active
$result = db_query('SELECT removed FROM {locus_energy_location_variables} WHERE site_id=123 AND variable_id=%d', $var_row->variable_id);
$row = db_fetch_object($result);
assertEquals(0, (int) $row->removed, 'marking variable as no longer removed');
