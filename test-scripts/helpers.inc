<?php

/**
 * Return a mock instance of the LocusEnergyGenerationProvider.
 *
 * @return LocusEnergyGenerationProvider
 */
function getMockInstance() {
  $api = new LocusEnergyGenerationProvider();
  $api->api_url = 'https://private-anon-d049c2dab-locusenergy.apiary-mock.com/';
  $api->client_id = 'test';
  $api->client_secret = 'test';

  return $api;
}

/**
 * Assert that two things are equal.
 *
 * @param mixed $a
 *   Expected value
 * @param mixed $b
 *   Actual value
 * @param string $comment
 *   Assertion
 */
function assertEquals($a, $b, $comment = '') {
  if ($a !== $b) {
    echo "\033[0;31m"; // red
    drush_print('Failure ' . $comment);
    echo 'expected (' . gettype($a) . '): '; drush_print_r($a);
    echo 'actual (' . gettype($b) .'): '; drush_print_r($b);
    echo "\033[0m"; // no color
    return FALSE;
  }
  else {
    echo "\033[0;32m"; // green
    drush_print('Success ' . $comment);
    echo "\033[0m"; // no color
    return TRUE;
  }
}
