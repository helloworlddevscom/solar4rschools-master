<?php
/**
 * @file
 * Fieldable Panels Panes module integration.
 */

/**
 * Implementation of hook_profiler_components() on behalf of fieldable panels panes.
 */
function fieldable_panels_panes_profiler_components() {
  return array(
    'fieldable_panels_panes' => array(
      'callback' => 'profiler_install_fieldable_panels_panes',
      'weight' => 10,
    ),
  );
}

/**
 * Component install callback for 'fieldable_panels_panes'.
 */
function profiler_install_fieldable_panels_panes($fieldable_panels_panes, $config, &$identifiers) {
  foreach (array_filter($fieldable_panels_panes) as $pid => $properties) {
    $default = array(
      'title' => '',
      'link' => 0,
      'bundle' => 'fieldable_panels_pane',
      'reusable' => TRUE,
      'admin_title' => '',
      'admin_description' => '',
      'category' => '',
      'view_access' => NULL,
      'edit_access' => NULL,
    );
    $fieldable_panels_pane = (object) array_merge($default, $properties);
    fieldable_panels_panes_save($fieldable_panels_pane);
  }
}
