<?php

/**
 * @file
 * Theme functions for the Flare theme.
 */


/**
 * Preprocess Functions
 */

/**
 * Helper function to alter inputs labels to be placeholders.
 *
 * @param array $element
 *   The element in the form
 * @param array $label_default
 *   The default location of the label in the form, to be unset.
 * @param string $label
 *   What the label should say.
 */
function _flare_alter_search_labels(&$element, &$label_default, $label) {
  $hide_label = FALSE;

  if (isset($element['#type'])) {
    if ($element['#type'] === 'select') {
      $element['#attributes']['data-placeholder'] = t($label_default[$label]);
      // Because of the fact that Chosen does not work on IOS, we should not hide the label at all times.
      // IOS will display a multi-select with "x items" instead of the placeholder text. This means
      // that the user does not not know the purpose of the field. Instead, we should hide the label with
      // CSS at desktop breakpoints and show the label with CSS at smaller breakpoints.
//      $hide_label = TRUE;
    }
    elseif ($element['#type'] === 'textfield') {
      $element['#attributes']['placeholder'] = t($label_default[$label]);
//      $hide_label = TRUE;
    }

    if ($hide_label) {
      if ($label_default['value'] === 'activity_low') {
        $label_default[$label] = t('Activity Length');
      } else {
        unset($label_default[$label]);
      }
    }
  }
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_maintenance_page(&$vars) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  // flare_preprocess_html($variables, $hook);
  // flare_preprocess_page($variables, $hook);
  //
  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'flare';
  // Also, check $vars['db_is_active'] before doing any db queries.
}

/**
 * Implements hook_preprocess_html()
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function flare_preprocess_html(&$vars) {

}
*/

/**
 * Override or insert variables into the page template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_page(&$vars) {
  drupal_add_js(libraries_get_path('qtip2') . '/jquery.qtip.min.js', array(
    'group' => JS_THEME,
    'every_page' => TRUE,
  ));
  drupal_add_css(libraries_get_path('qtip2') . '/jquery.qtip.min.css');
  drupal_add_js('jQuery(".tooltip[title]").qtip();', array(
    'type' => 'inline',
    'scope' => 'footer',
    'weight' => 15,
  ));

  if (isset($vars['page']['main_prefix']['blockify_blockify-page-title']) && drupal_static('hide_title')) {
    unset($vars['page']['main_prefix']['blockify_blockify-page-title']);
  }
}

/**
 * Override or insert variables into the region templates.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function flare_preprocess_region(&$vars) {

}
*/

/**
 * Override or insert variables into the block templates.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_block(&$vars) {
  // Add dropdown markup if needed.
  if (_flare_use_dropdown_button($vars['block'])) {
    $vars['theme_hook_suggestions'][] = 'block__collapsible';
    $vars['title_attributes_array']['class'][] = 'ctools-collapsible-handle';
    $vars['title_attributes_array']['class'][] = 'button';
    ctools_add_js('collapsible-div');
    ctools_add_css('collapsible-div');
  }
}

function flare_preprocess_fieldable_panels_pane(&$vars) {
  // This is a duplicate of the pane title and breaks things like jcarousel.
  unset($vars['content']['title']);
}

/**
 * Implements hook_block_view_alter().
 *
 * Puts the title of the page into a foundation dropdown block.
 */
function flare_block_view_alter(&$data, $block) {
  // Add dropdown markup if needed.
  if (_flare_use_dropdown_button($block)) {
    $title = drupal_get_title();
    $title_themed = theme('blockify_page_title', array('page_title' => $title));
    $data['content']['#markup'] = '<div class="title-wrapper">' . $title_themed . '</div>' . $data['content']['#markup'];
    drupal_static('hide_title', TRUE);
  }
}

/**
 * Override or insert variables into the panels pane templates.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_panels_pane(&$vars) {
  // Add dropdown markup if needed.
  if (_flare_use_dropdown_button($vars['pane'])) {
    // Append `-dropdown` and re-use pane subtype for dropdown content area.
    $id = drupal_html_class($vars['pane']->subtype) . '-dropdown';
    $vars['classes'] .= " foundation-dropdown";
    $vars['title_attributes_array']['data-dropdown'] = $id;
    $vars['title_attributes_array']['class'][] = 'button';
    $vars['content_attributes_array']['data-dropdown-content'] = NULL;
    $vars['content_attributes_array']['id'] = $id;

    _flare_add_foundation('dropdown');
  }
  if (isset($vars['pane']->type) && $vars['pane']->type == 'page_title') {
    drupal_static('hide_title', TRUE);
  }
}

/**
 * Override or insert variables into the entity template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_entity(&$vars) {
  if ($vars['elements']['#view_mode'] == 'teaser' && $vars['elements']['#entity_type'] == 'profile2') {
    if ($vars['profile2']->label) {
      unset($vars['profile2']->label);
    }
    if (isset($vars['title'])) {
      $vars['title'] = '';
    }
    if (isset($vars['url'])) {
      $vars['url'] = '';
    }
  }
}

/**
 * Override or insert variables into the node template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_node(&$vars) {
  // Break out type-specific preprocessors into their own functions.
  $function = '_' . __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars);
  }

  // Add class based on view mode.
  if (isset($vars['view_mode'])) {
    $vars['classes_array'][] = 'view-mode--' . drupal_html_class($vars['view_mode']);
  }

  if (isset($vars['title_attributes_array'])) {
    $title_class = 'node--title';
    if (empty($vars['title_attributes_array']['class'])) {
      $vars['title_attributes_array']['class'] = $title_class;
    }
    else {
      $vars['title_attributes_array']['class'][] = $title_class;
    }
  }


  // Move flag links to a separate location for separate rendering.
  if (isset($vars['content']['links']) && isset($vars['content']['links']['flag'])) {
    $vars['content']['flag_link'] = $vars['content']['links'];
    unset($vars['content']['flag_link']['node']);
    unset($vars['content']['flag_link']['comment']);
    unset($vars['content']['links']['flag']);
  }

  // If teaser remove comment links.
  if ($vars['view_mode'] === 'teaser' && isset($vars['content']['links']['comment'])) {
    unset($vars['content']['links']['comment']);
  }

  // If classroom update teaser change Submitted text.
  if ($vars['view_mode'] === 'teaser' && $vars['node']->type === 'classroom_updates') {
    $vars['submitted'] = t('Posted by') . ': ' . l($vars['node']->name, 'user/' . $vars['node']->name);
  }

  // Remove Read more link. We'll add it to the body field instead.
  if (isset($vars['content']['links']['node']['#links']['node-readmore'])) {
    unset($vars['content']['links']['node']['#links']['node-readmore']);
  }
}

/**
 * Override or insert variables into the field template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_field(&$vars) {
  $field = $vars['element'];
  $field_name = $field['#field_name'];

  switch ($field_name) {
    case 'field_slideshow_cslide':
      // Add Foundation library components for Orbit Slider.
      drupal_add_js(drupal_get_path('theme', 'flare') . '/js/jquery.jcarousel.min.js');
      drupal_add_js(drupal_get_path('theme', 'flare') . '/js/jcarousel_implement.js');
      $vars['classes_array'][] = 'carousel-ul';
      break;

    case 'field_video_gallery':
    case 'field_photo_gallery':
    case 'field_tour_video':
      $entity_type = $field['#entity_type'];
      $entity = $field['#object'];

      if (!entity_access('update', $entity_type, $entity)) {
        $field_object = field_info_field($field_name);
        if (field_access('edit', $field_object, $entity_type, $entity)) {
          list($id, $rid, $bundle) = entity_extract_ids($entity_type, $entity);
          $vars['update_link'] = l(
            t('Update !field', array('!field' => $field['#title'])),
            "admin/field/edit/$entity_type/$id/$field_name",
            array('query' => drupal_get_destination(), 'attributes' => array('class' => array('button')))
          );
        }
      }

      $rendered_links = element_children($vars['items'][0]);
      foreach ($rendered_links as $key => $link_key) {
        // If we're just displaying one link, make the link indicate that.
        if ($vars['items'][0][$link_key]['#text'] == '') {
          $vars['items'][0]['item-0']['#text'] = t('View @label', array('@label' => $vars['label']));
          break;
        }
        $vars['items'][0][$link_key]['#text'] = $field['#items'][$key]['title'];
      }

      // Photo galleries link themselves in their title.
      if ($field_name == 'field_photo_gallery') {
        $vars['items'][0]['item-0']['#text'] = $vars['label'];
      }

      // We're showing the entity title on tour videos.
      if ($field_name == 'field_tour_video') {
        $vars['items'][0]['item-0']['#text'] = $vars['element']['#title'];
      }
      break;

    case 'field_project_location':
      // Remove unnecessary project address info from displaying.
      $vars['items'][0]['#address']['postal_code'] = FALSE;
      $vars['items'][0]['#address']['thoroughfare'] = FALSE;
      $vars['items'][0]['#address']['postal_code'] = FALSE;
      $vars['items'][0]['#address']['premise'] = FALSE;
      $vars['items'][0]['#address']['country'] = FALSE;
      $vars['items'][0]['locality_block']['#attributes']['class'] = array();

      break;

    case 'field_number_of_projects_funded':
      // Customizations to put the states field into the projects field instead
      // of separate.
      if ($field['#view_mode'] == 'teaser' && $field['#entity_type'] == 'profile2') {
        $vars['items'][0]['#markup'] .= ' projects in ' . $field['#object']->field_sum_states[LANGUAGE_NONE][0]['value'] . ' states';
      }
      break;

    case 'field_sum_classrooms':
      // Customizations to add flavor text to classrooms while we're at it.
      if ($field['#view_mode'] == 'teaser' && $field['#entity_type'] == 'profile2') {
        $vars['items'][0]['#markup'] .= ' classrooms per year';
      }
      break;
  }
}

/**
 * Implements theme_superfish().
 *
 * Slightly modified to add an extra list level around the superfish menus.
 */
function flare_superfish($variables) {
  global $user, $language;

  $id = $variables['id'];
  $menu_name = $variables['menu_name'];
  $mlid = $variables['mlid'];
  $sfsettings = $variables['sfsettings'];

  $menu = menu_tree_all_data($menu_name);

  if (function_exists('i18n_menu_localize_tree')) {
    $menu = i18n_menu_localize_tree($menu);
  }

  // For custom $menus and menus built all the way from the top-level we
  // don't need to "create" the specific sub-menu and we need to get the title
  // from the $menu_name since there is no "parent item" array.
  // Create the specific menu if we have a mlid.
  if (!empty($mlid)) {
    // Load the parent menu item.
    $item = menu_link_load($mlid);
    $title = check_plain($item['title']);
    $parent_depth = $item['depth'];
    // Narrow down the full menu to the specific sub-tree we need.
    for ($p = 1; $p < 10; $p++) {
      if ($sub_mlid = $item["p$p"]) {
        $subitem = menu_link_load($sub_mlid);
        $key = (50000 + $subitem['weight']) . ' ' . $subitem['title'] . ' ' . $subitem['mlid'];
        $menu = (isset($menu[$key]['below'])) ? $menu[$key]['below'] : $menu;
      }
    }
  }
  else {
    $result = db_query("SELECT title FROM {menu_custom} WHERE menu_name = :a", array(':a' => $menu_name))->fetchField();
    $title = check_plain($result);
  }

  $output['content'] = '';
  $output['subject'] = $title;
  if ($menu) {
    // Set the total menu depth counting from this parent if we need it.
    $depth = $sfsettings['depth'];
    $depth = ($sfsettings['depth'] > 0 && isset($parent_depth)) ? $parent_depth + $depth : $depth;

    $var = array(
      'id' => $id,
      'menu' => $menu,
      'depth' => $depth,
      'trail' => superfish_build_page_trail(menu_tree_page_data($menu_name)),
      'clone_parent' => FALSE,
      'sfsettings' => $sfsettings,
    );
    if ($menu_tree = theme('superfish_build', $var)) {
      if ($menu_tree['content']) {
        // Add custom HTML codes around the main menu.
        if ($sfsettings['wrapmul'] && strpos($sfsettings['wrapmul'], ',') !== FALSE) {
          $wmul = explode(',', $sfsettings['wrapmul']);
          // In case you just wanted to add something after the element.
          if (drupal_substr($sfsettings['wrapmul'], 0) == ',') {
            array_unshift($wmul, '');
          }
        }
        else {
          $wmul = array();
        }
        $output['content'] = isset($wmul[0]) ? $wmul[0] : '';
        $output['content'] .= '<ul id="superfish-' . $id . '"';
        $output['content'] .= ' class="menu sf-menu sf-' . $menu_name . ' sf-' . $sfsettings['type'] . ' sf-style-' . $sfsettings['style'];
        $output['content'] .= ($sfsettings['itemcounter']) ? ' sf-total-items-' . $menu_tree['total_children'] : '';
        $output['content'] .= ($sfsettings['itemcounter']) ? ' sf-parent-items-' . $menu_tree['parent_children'] : '';
        $output['content'] .= ($sfsettings['itemcounter']) ? ' sf-single-items-' . $menu_tree['single_children'] : '';
        $output['content'] .= ($sfsettings['ulclass']) ? ' ' . $sfsettings['ulclass'] : '';
        $output['content'] .= ($language->direction == 1) ? ' rtl' : '';
        $output['content'] .= '">' . $menu_tree['content'] . '</ul>';
        $output['content'] .= isset($wmul[1]) ? $wmul[1] : '';
      }
    }
  }
  return $output;
}

/**
 * Implements theme_superfish_menu_item_link().
 */
function flare_superfish_menu_item_link($variables) {
  $menu_item = $variables['menu_item'];
  $link_options = $variables['link_options'];
  if (isset($menu_item['link']['title']) && isset($menu_item['link']['href'])) {
    return l($menu_item['link']['title'], $menu_item['link']['href'], $link_options);
  }
}

/**
 * Override or insert variables into textarea form elements.
 *
 * @param(array) $element
 *   An array of variables to pass to the theme template.
 */
function flare_textarea($element) {
  // If the textarea is specifically for comments, make them non-resizable.
  if ($element['element']['#entity_type'] === 'comment') {
    $element['element']['#resizable'] = 0;
  }

  return theme_textarea($element);
}

/**
 * Override or insert variables into the comment template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
function flare_preprocess_comment_wrapper(&$vars) {
  $comment_form = &$vars['content']['comment_form'];

  if (isset($comment_form['comment_body'][LANGUAGE_NONE][0]['value'])) {
    $comment_form['comment_body'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Add comment');
  }
}

/**
 * Override or insert variables into the views template.
 *
 * @param (array) $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function flare_preprocess_views_view(&$vars) {
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
function flare_modernizr_load_alter(&$load) {

}
*/

/**
 * Override or insert css on the site.
 *
 * @param (array) $css
 *   An array of all CSS items being requested on the page.
 */
/* -- Delete this line if you want to use this function
function flare_css_alter(&$css) {

}
*/

/**
 * Override or insert javascript on the site.
 *
 * @param (array) $js
 *   An array of all JavaScript being presented on the page.
 */
/* -- Delete this line if you want to use this function
function flare_js_alter(&$js) {

}
*/

/**
 * Implements hook_form_alter().
 */
function flare_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'user_register_form':
      // Add custom validation to user registration form.
      array_unshift( $form['#validate'], '_flare_user_registration_form_validate_name');
      break;

    case 'user_login_block':
      $form['name']['#weight'] = 0;
      $form['pass']['#weight'] = 0.001;
      $form['actions']['#weight'] = 0.002;
      break;

    case 'views_exposed_form':
      // Put the labels into the placeholder text for select and textfields.
      if (isset($form['filters'])) {
        foreach (element_children($form['filters']) as $element_key) {
          foreach (element_children($form['filters'][$element_key]) as $key) {
            $element = &$form['filters'][$element_key][$key];
            _flare_alter_search_labels($element, $element, '#title');
          }
        }
      }
      else {
        foreach ($form['#info'] as $element_key => $element) {
          _flare_alter_search_labels($form[$element['value']], $form['#info'][$element_key], 'label');

          // For Teacher Activity Center view exposed filter fulltext search field,
          // set custom placeholder text.
          if ($element['value'] == 'search' && $element_key == 'filter-search_api_views_fulltext') {
            $form['search']['#attributes']['placeholder'] = t('Enter search text');
          }
        }
      }

      // Remove sort by label within this theme.
      if (isset($form['sort_by'])) {
        unset($form['sort_by']['#title']);
      }
      break;

    case 'cartcontents':
      // Remove the total price from the cart list.
      unset($form['totalprice']);
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
function flare_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  // Bail out if there is no remaining breadcrumb.
  if (empty($breadcrumb)) {
    return;
  }

  // Append page title.
  $item = menu_get_item();
  if (!empty($item['tab_parent'])) {
    // On a non-default tab, do nothing.
    $breadcrumb[] = '<span class="current">' . check_plain($item['title']) . '</span>';
  }
  elseif ($item['path'] != 'home') {
    $breadcrumb[] = '<span class="current">' . drupal_get_title() . '</span>';
  }

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' > ', $breadcrumb) . '</div>';
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
function flare_container($variables) {
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
 * Helper function.
 *
 * Determines if a block or pane should be displayed as a Foundation drop down.
 */
function _flare_use_dropdown_button($object) {
  $dropdown_blocks = array(
    'views--exp-node_search-panel_pane_1',
    'views--exp-node_search-panel_pane_2',
    'views--exp-node_search-panel_pane_3',
    'explore_data-explore_data_form',
    'views--exp-node_search-panel_pane_7',
    'views--exp-node_search-panel_pane_6',
    'views-092f0b2a8ab9c7c34d5f07ecdfeb7271',
    'views-920a216bab2878c242538bc079fc8f1c',
    // Project Map Filter.
  );
  $dropdown_panes = array();

  // Block.
  if (property_exists($object, 'bid')) {
    if (in_array($object->bid, $dropdown_blocks)) {
      return TRUE;
    }
  }
  // Pane.
  elseif (property_exists($object, 'subtype')) {
    if (in_array($object->subtype, $dropdown_panes)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Add the necessary Foundation JS files and functions.
 *
 * @param (string) $library
 *   A foundation.js library included in the theme's js folder.
 */
function _flare_add_foundation($library = FALSE) {
  // Add standard Foundation library.
  drupal_add_js(drupal_get_path('theme', 'flare') . '/vendor/alphecca/js/foundation.js', array(
    'type' => 'file',
    'scope' => 'footer',
    'weight' => 8,
  ));
  if ($library) {
    // Add custom Foundation library components for Dropdown.
    drupal_add_js(drupal_get_path('theme', 'flare') . "/js/foundation.$library.js", array(
      'type' => 'file',
      'scope' => 'footer',
      'weight' => 9,
    ));
  }
  // Apply foundation to the document.
  drupal_add_js('jQuery(document).foundation();', array(
    'type' => 'inline',
    'scope' => 'footer',
    'weight' => 10,
  ));
}

/**
 * Implements hook_preprocess_views_exposed_form().
 *
 * Adds a superfish menu after the form's submit button.
 */
function flare_preprocess_views_exposed_form(&$vars) {
  if (isset($vars['form']['#id']) && $vars['form']['#id'] == 'views-exposed-form-node-search-panel-pane-7') {
    $vars['widgets']['button'] = new stdClass();
    $vars['widgets']['button']->widget = $vars['button'];
    $vars['widgets']['button']->id = 'fake-button';

    $vars['button'] = '';
  }
}

/**
 * Implements hook_field_group_pre_render_alter().
 *
 * Adds theming overwrite.
 */
function flare_field_group_build_pre_render_alter(&$element, $group, &$form) {
  // For now, we're going to only customize buttons on forms that contian the
  // field_group "group_application".
  if (isset($element['group_application'])) {
    $element['#attached']['js'][] = drupal_get_path('theme', 'flare') . '/js/flare-multipage.js';
  }
}

/**
 * Implements theme_basic_cart_render_cart_element.
 *
 * Removes prices from displaying.
 */
function flare_basic_cart_render_cart_element($variables) {
  // Element name and nid.
  $name = $variables['form']['#name'];
  $nid = (int) str_replace(array('cartcontents[', ']'), '', $name);
  if (empty($nid)) {
    return '';
  }
  // Delete image.
  $vars = array(
    'path' => base_path() . drupal_get_path('module', 'basic_cart') . '/images/delete2.png',
    'alt' => t('Remove from cart'),
    'title' => t('Remove from cart'),
    'attributes' => array('class' => 'basic-cart-delete-image-image'),
  );
  $delete_link = l(theme('image', $vars), 'cart/remove/' . $nid, array('html' => TRUE));
  // Getting the node for it's title and description.
  $node = basic_cart_get_cart($nid);
  // Node description.
  $desc = '';
  if (isset($node->basic_cart_node_description)) {
    $desc = drupal_strlen($node->basic_cart_node_description) > 50 ?
                truncate_utf8($node->basic_cart_node_description, 50) : $node->basic_cart_node_description;
  }
  // Price and currency.
  $unit_price = isset($node->basic_cart_unit_price) ? $node->basic_cart_unit_price : 0;
  $unit_price = basic_cart_price_format($unit_price);

  // Prefix.
  $prefix  = '<div class="basic-cart-cart-contents row">';
  $prefix .= '  <div class="basic-cart-delete-image cell">' . $delete_link . '</div>';
  $prefix .= '  <div class="basic-cart-cart-node-title cell">' . l($node->title, 'node/' . $nid) . '<br />';
  $prefix .= '    <span class="basic-cart-cart-node-summary">' . $desc . '</span>';
  $prefix .= '  </div>';
  $prefix .= '  <div class="basic-cart-cart-quantity cell">';
  $prefix .= '    <div class="cell">';
  // Suffix.
  $suffix  = '    </div>';
  $suffix .= '  </div>';
  $suffix .= '</div>';

  // Rendering the element as textfield.
  $quantity = theme('textfield', $variables['form']);
  // Full view return.
  return $prefix . $quantity . $suffix;
}


/**
 * Implements hook_hook_alter().
 *
 * Manually set timezone for addtocal module widget. Sure I'll regret this later...
 */
function flare_addtocal_extract_event_info_alter(&$info, &$entity_type, &$entity) {
  $info['timezone'] = 'America/Los_Angeles';
}


/**
 * Custom validation for user registration form to prevent first and last name
 * from being equal. This is to hopefully prevent some spam bots that are registering
 * with the same first and last name.
 * @param $form
 * @param $form_state
 */
function _flare_user_registration_form_validate_name($form, &$form_state) {
  $first_name = $form_state['values']['field_first_name'][LANGUAGE_NONE][0]['value'];
  $last_name = $form_state['values']['field_last_name'][LANGUAGE_NONE][0]['value'];

  if ($first_name == $last_name) {
    form_set_error('field_first_name', 'First name and last name cannot be the same.');
    form_set_error('field_last_name', '');
  }
}
