<?php
/**
 * @file
 * solar_explore.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function solar_explore_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'saved_graph-saved_graph-field_graph_url'.
  $field_instances['saved_graph-saved_graph-field_graph_url'] = array(
    'bundle' => 'saved_graph',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The url this entity is saving.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'saved_graph',
    'fences_wrapper' => 'div',
    'field_name' => 'field_graph_url',
    'label' => 'Graph url',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'urlwidget',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'saved_graph-saved_graph-field_related_project'.
  $field_instances['saved_graph-saved_graph-field_related_project'] = array(
    'bundle' => 'saved_graph',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The project this data is related to.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => FALSE,
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'saved_graph',
    'fences_wrapper' => 'div',
    'field_name' => 'field_related_project',
    'label' => 'Related project',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'match_operator' => 'CONTAINS',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Graph url');
  t('Related project');
  t('The project this data is related to.');
  t('The url this entity is saving.');

  return $field_instances;
}
