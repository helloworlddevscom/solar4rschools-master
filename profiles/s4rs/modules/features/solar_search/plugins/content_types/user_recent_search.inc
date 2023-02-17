<?php

$plugin = array(
  'title' => t('User recent searches'),
  'description' => t('The last 4 searches performed by the current user.'),
  'category' => t('Solar4Rschools elements'),
);

/**
 * Pane admin form.
 */
function solar_search_user_recent_search_content_type_edit_form($form, $form_state) {
  return $form;
}

/**
 * Content type render callback.
 */
function solar_search_user_recent_search_content_type_render($subtype, $conf, $panels_args, $context) {
  $recent_searches = isset($_COOKIE['Drupal_visitor_recent_searches']) ? drupal_json_decode($_COOKIE['Drupal_visitor_recent_searches']) : array();
  $items = array();

  foreach ($recent_searches as $search) {
    $options = drupal_parse_url($search['path']);
    $items[] = l($search['title'], $options['path'], $options);
  }
  $pane = new stdClass();
  $pane->title = t('Recent searches');
  $pane->content = theme('item_list', array('items' => $items));
  return $pane;
}
