<?php
/**
 * @file
 * power_one.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function power_one_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
