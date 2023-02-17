<?php
/**
 * @file
 * solar_data.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function solar_data_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'equivalencies_statistics-equivalencies_statistics-field_calculation_source2'.
  $field_instances['equivalencies_statistics-equivalencies_statistics-field_calculation_source2'] = array(
    'bundle' => 'equivalencies_statistics',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a calculation, or leave blank to show the original, unaltered number.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'generation_equation',
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
        'type' => 'generation_math_equation',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'generation_equation',
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
        'type' => 'generation_math_equation',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'equivalencies_statistics',
    'fences_wrapper' => 'div',
    'field_name' => 'field_calculation_source2',
    'label' => 'Calculation source',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'generation_equation',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'generation_math_equation',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'equivalencies_statistics-equivalencies_statistics-field_equivalency_icon'.
  $field_instances['equivalencies_statistics-equivalencies_statistics-field_equivalency_icon'] = array(
    'bundle' => 'equivalencies_statistics',
    'deleted' => 0,
    'description' => 'Small icon to represent the data that\'s being displayed.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => 'icon',
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
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => 'icon',
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
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'equivalencies_statistics',
    'fences_wrapper' => 'div',
    'field_name' => 'field_equivalency_icon',
    'label' => 'Equivalency icon',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'upload' => 'upload',
          'youtube' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'equivalencies_statistics-equivalencies_statistics-field_widget_categories'.
  $field_instances['equivalencies_statistics-equivalencies_statistics-field_widget_categories'] = array(
    'bundle' => 'equivalencies_statistics',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Which Widget headers should this equivalency appear under? ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
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
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'equivalencies_statistics',
    'fences_wrapper' => 'div',
    'field_name' => 'field_widget_categories',
    'label' => 'Widget categories',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a calculation, or leave blank to show the original, unaltered number.');
  t('Calculation source');
  t('Equivalency icon');
  t('Small icon to represent the data that\'s being displayed.');
  t('Which Widget headers should this equivalency appear under? ');
  t('Widget categories');

  return $field_instances;
}
