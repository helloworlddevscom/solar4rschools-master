<?php

/**
 * @file
 * Theme functions for the kiosk theme.
 */


/**
 * Preprocess Functions
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function kiosk_preprocess_maintenance_page(&$vars) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  // kiosk_preprocess_html($variables, $hook);
  // kiosk_preprocess_page($variables, $hook);
  //
  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'kiosk';
  // Also, check $vars['db_is_active'] before doing any db queries.
}

/**
 * Implements hook_preprocess_html()
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function kiosk_preprocess_html(&$vars) {

}
*/

/**
 * Override or insert variables into the page template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function kiosk_preprocess_page(&$vars) {

}
*/

/**
 * Override or insert variables into the region templates.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function kiosk_preprocess_region(&$vars) {

}
*/

/**
 * Override or insert variables into the block templates.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function kiosk_preprocess_block(&$vars) {
  $vars['classes_array'][] = 'clearfix';
}


/**
 * Override or insert variables into the entity template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function kiosk_preprocess_entity(&$vars) {

}
*/

/**
 * Override or insert variables into the node template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function kiosk_preprocess_node(&$vars) {
  $node = $vars['node'];

  // Node listings should be heading 2.
  $vars['title_tag'] = $vars['view_mode'] == 'full' ? 'h1' : 'h2';

  // Break out type-specific preprocessors into their own functions.
  $function = '_' . __FUNCTION__ . '_' . $node->type;
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Override or insert variables into the field template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function kiosk_preprocess_field(&$vars) {
  // Code removed for the Foundation Orbit slider.
}

/**
 * Override or insert variables into the comment template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function kiosk_preprocess_comment(&$vars) {
  $comment = $vars['comment'];
}
*/

/**
 * Override or insert variables into the views template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function kiosk_preprocess_views_view(&$vars) {
  $view = $vars['view'];
}
*/

/**
 * Process Functions
 */


/**
 * Alter Hooks
 */


/**
 * Implements hook_modernizr_load_alter().
 *
 * @return (array)
 *   An array to be output as yepnope testObjects.
 */
/* -- Delete this line if you want to use this function
function kiosk_modernizr_load_alter(&$load) {

}
*/

/**
 * Override or insert css on the site.
 *
 * @param (array) $css
 *   An array of all CSS items being requested on the page.
 */
/* -- Delete this line if you want to use this function
function kiosk_css_alter(&$css) {

}
*/

/**
 * Override or insert javascript on the site.
 *
 * @param (array) $js
 *   An array of all JavaScript being presented on the page.
 */
/* -- Delete this line if you want to use this function
function kiosk_js_alter(&$js) {

}
*/

/**
 * Implements hook_form_alter().
 */
function kiosk_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'user_login_block':
      $form['name']['#weight'] = 0;
      $form['pass']['#weight'] = 0.001;
      $form['actions']['#weight'] = 0.002;
      break;
  }
}


/**
 * Theme Function Overrides.
 */


/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param (array) $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function kiosk_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode('', $breadcrumb) . '</div>';
    return $output;
  }
}

/**
 * Returns HTML to wrap child elements in a container.
 *
 * Used for grouped form items. Can also be used as a #theme_wrapper for any
 * renderable element, to surround it with a <div> and add attributes such as
 * classes or an HTML id.
 *
 * @param (array) $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #attributes, #children.
 *
 * @ingroup themeable
 */
function kiosk_container($variables) {
  $element = $variables['element'];

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    if (!isset($element['#attributes']['id'])) {
      $element['#attributes']['id'] = $element['#id'];
    }
    // Add the 'form-wrapper' class.
    $element['#attributes']['class'][] = 'form-wrapper';

    // Add the 'button-group' & 'radius' classes to form actions.
    if ($element['#id'] == 'edit-actions') {
      $element['#attributes']['class'][] = 'button-group';
      $element['#attributes']['class'][] = 'radius';
    }
  }

  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}

/**
 * Returns HTML for the main menu tabs.
 *
 * Adds tab-specific classes to the items.
 *
 * @param (array) $variables
 *   An associative array containing:
 *   - primary: (optional) An array of local tasks (tabs).
 *   - secondary: (optional) An array of local tasks (tabs).
 *
 * @ingroup themeable
 */
function kiosk_menu_local_tasks(&$variables) {
  foreach ($variables['primary'] as $key => $value) {
    switch ($value['#link']['path']) {
      case 'node/%/view':
        $class = 'kiosk-menu-tab-view';
        break;

      case 'node/%/edit':
        $class = 'kiosk-menu-tab-edit';
        break;

      case 'node/%/how-it-works':
        $class = 'kiosk-menu-tab-how-it-works';
        break;

      case 'node/%/about-project':
        $class = 'kiosk-menu-tab-about-project';
        break;

      case 'node/%/about-partners':
        $class = 'kiosk-menu-tab-about-partners';
        break;

      case 'node/%/green-technology':
        $class = 'kiosk-menu-tab-green-tech';
        break;

      case 'node/%/renewable-benefits':
        $class = 'kiosk-menu-tab-renewable-benefits';
        break;

      case 'node/%/call-to-action':
        $class = 'kiosk-menu-tab-call-to-action';
        break;

      default:
        $class = 'kiosk-menu-tab-default';
    }

    if (!empty($class)) {
      $variables['primary'][$key]['#link']['localized_options']['attributes']['class'][] = $class;
    }
  }

  return theme_menu_local_tasks($variables);
}
