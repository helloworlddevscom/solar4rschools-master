<?php

/**
 * @file
 * Preprocessors and helper functions to make theming easier.
 */

/**
 * Default theme function for all filter forms.
 */
function template_preprocess_views_exposed_groups(&$vars) {
  $form = &$vars['form'];

  // Put all single checkboxes together in the last spot.
  $checkboxes = '';

  if (!empty($form['q'])) {
    $vars['q'] = drupal_render($form['q']);
  }

  $vars['groups'] = array();
  foreach ($form['#info'] as $id => $info) {
    // Set aside checkboxes.
    if (isset($form[$info['value']]['#type']) && $form[$info['value']]['#type'] == 'checkbox') {
      $checkboxes .= drupal_render($form[$info['value']]);
      continue;
    }
    $widget = new stdClass;
    // set up defaults so that there's always something there.
    $widget->label = $widget->operator = $widget->widget = $widget->description = NULL;

    $widget->id = isset($form[$info['value']]['#id']) ? $form[$info['value']]['#id'] : '';

    if (!empty($info['label'])) {
      $widget->label = check_plain($info['label']);
    }
    if (!empty($info['operator'])) {
      $widget->operator = drupal_render($form[$info['operator']]);
    }

    $widget->widget = drupal_render($form[$info['value']]);

    if (!empty($info['description'])) {
      $widget->description = check_plain($info['description']);
    }

    $vars['groups'][$info['group']][$info['group-weight']] = $widget;
  }

  // Wrap up all the checkboxes we set aside into a widget.
  if ($checkboxes) {
    $widget = new stdClass;
    // set up defaults so that there's always something there.
    $widget->label = $widget->operator = $widget->widget = NULL;
    $widget->id = 'checkboxes';
    $widget->widget = $checkboxes;
    $vars['widgets']['checkboxes'] = $widget;
  }

  if (isset($form['sort_by'])) {
    $vars['sort_by'] = drupal_render($form['sort_by']);
    $vars['sort_order'] = drupal_render($form['sort_order']);
  }
  if (isset($form['items_per_page'])) {
    $vars['items_per_page'] = drupal_render($form['items_per_page']);
  }
  if (isset($form['offset'])) {
    $vars['offset'] = drupal_render($form['offset']);
  }
  if (isset($form['reset'])) {
    $vars['reset_button'] = drupal_render($form['reset']);
  }
  // This includes the submit button.
  $vars['button'] = drupal_render_children($form);
}

/**
 * Theme callback to render the option form as a draggable table.
 */
function theme_views_exposed_groups_reorder_filter_form($vars) {
  $form = $vars['form'];
  $rows = array();
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['weight'])) {
      $group = (is_numeric($form[$key]['group']['#default_value']))
               ? $form[$key]['group']['#default_value']
               : 0;
      $row = array();
      $row[] = $form[$key]['weight']['#title'];

      $form[$key]['weight']['#attributes']['class'] = array('weight', 'weight-'. $group);
      $form[$key]['group']['#attributes']['class'] = array('group-select', 'field-group-'. $group);
      $row[] = drupal_render($form[$key]['group']);
      $row[] = drupal_render($form[$key]['weight']);
      $class = array('draggable');
      $styles = array();
      $rows[$group][] = array('data' => $row, 'class' => $class, 'id' => 'display-row-' . $key, 'style' => $styles);
    }
  }
  $groups = explode("\n", $form['groups']['#default_value']);
  $groups['no-group'] = t('- No group -');

  $table_rows = array();
  foreach($groups as $k => $group) {
    $table_rows[] = array(array('data' => '<strong>'. $group .'</strong>', 'colspan' => 3, 'attributes' => array('class' => array('field-group-header'))));
    foreach($rows[$k] as $row) {
      $table_rows[] = $row;
    }
  }
  foreach($groups as $k => $group) {
    drupal_add_tabledrag('reorder-group-filters', 'match', 'sibling', 'group-select', 'field-group-' . $k, NULL, FALSE);
    drupal_add_tabledrag('reorder-group-filters', 'order', 'sibling', 'weight', 'weight-' . $k);
  }

  $header = array(t('Filter'), t('Group'), t('Weight'));
  $output = '';


  $output = drupal_render($form['override']);
  $output .= theme('table',
    array('header' => $header,
    'rows' => $table_rows,
    'attributes' => array('id' => 'reorder-group-filters'),
  ));
  $output .= drupal_render_children($form);

  return $output;
}