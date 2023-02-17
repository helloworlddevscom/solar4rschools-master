<?php
/**
 * @file
 * bef_recaptcha_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bef_recaptcha_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
