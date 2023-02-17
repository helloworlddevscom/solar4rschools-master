<?php
/**
 * @file
 * Theme functions for the Views hover display.
 */

/**
 * Prepare variables for hover template.
 */
function template_preprocess_bedrock_views_view_fields(&$vars) {
  // Use parent preprocessor.
  template_preprocess_views_view_fields($vars);

  // Setup the 2 groups of fields.
  $vars['exposed_fields'] = array();
  $vars['dropdown_fields'] = array();
  foreach ($vars['fields'] as $key => $field) {
    if (isset($vars['options']['in_dropdown'][$key]) && $vars['options']['in_dropdown'][$key]) {
      // Thise fields are in the dropdown.
      $vars['dropdown_fields'][$key] = $field;
    }
    else {
      // These fields are exposed.
      $vars['exposed_fields'][$key] = $field;
    }

    unset($vars['fields'][$key]);
  }

  // Need a unique ID.
  static $id = 1;
  $vars['dropdown_id'] = 'bedrock-dropdown-' . $id;
  $id ++;

  $vars['data_options'] = !empty($vars['options']['hover']) ? 'is_hover:true' : FALSE;
}
