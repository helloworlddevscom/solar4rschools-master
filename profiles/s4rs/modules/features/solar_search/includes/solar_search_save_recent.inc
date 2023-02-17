<?php

/**
 * @file
 * Contains SolarSearchSaveRecent.
 */

/**
 * Post-process for saving queries that achieved results.
 */
class SolarSearchSaveRecent extends SearchApiAbstractProcessor {

  /**
   * Adds an entry to the database if the search keywords found anything.
   *
   * @param array $response
   * @param SearchApiQuery $query
   * @return \SolarSearchSaveRecent
   */
  public function postprocessSearchResults(array &$response, SearchApiQuery $query) {
    $original_keys = trim($query->getOriginalKeys());
    if (isset($response['result count']) && $response['result count'] > 0 && !empty($original_keys)) {
      $recent_searches = isset($_COOKIE['Drupal_visitor_recent_searches']) ? drupal_json_decode($_COOKIE['Drupal_visitor_recent_searches']) : array();
      $this_search = drupal_get_destination();

      $saved_searches = array(array(
        'path' => $this_search['destination'],
        'title' => $query->getOriginalKeys(),
      ));

      foreach ($recent_searches as $key => $search) {
        if($search['path'] != $this_search['destination']) {
          $saved_searches[] = $search;
        }
        if (count($saved_searches) > 3) {
          break;
        }
      }

      user_cookie_save(array('recent_searches' => drupal_json_encode($saved_searches)));
    }

    return $this;
  }

}
