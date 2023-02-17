<?php

/**
 * @file
 * Holds the class defining the Views plugin loading the groups a given user
 * is member of.
 */

/**
 * The class defining the Views plugin loading the groups of the acting user.
 */
class solar_projects_argument_given_user_groups extends og_plugin_argument_default_user_groups {

  /**
   * Get the default argument.
   */
  function get_argument() {
    // We want to get the user id from the url, so we're borrowing a function.
    $uid = @views_plugin_argument_default_user::get_argument();

    if($uid) {
      $account = user_load($uid);
      if ($gids = og_get_groups_by_user($account, $this->options['group_type'])) {
        return implode($this->options['glue'], $gids);
      }
    }
    return FALSE;
  }
}
