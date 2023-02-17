<?php
/**
 * @file
 * solar_homepage.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function solar_homepage_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'fieldable_panels_pane-carousel_slide-field_slideshow_slide_image'.
  $field_instances['fieldable_panels_pane-carousel_slide-field_slideshow_slide_image'] = array(
    'bundle' => 'carousel_slide',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => 'funder_icon',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '[fieldable_panels_pane:field-slideshow-slide-link:url]',
            'linked' => 1,
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'slide' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => 'funder_icon',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '[fieldable_panels_pane:field_slideshow_slide_link:url]',
            'linked' => 1,
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_slideshow_slide_image',
    'label' => 'Slide image',
    'required' => 0,
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
          'private' => 0,
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
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-carousel_slide-field_slideshow_slide_link'.
  $field_instances['fieldable_panels_pane-carousel_slide-field_slideshow_slide_link'] = array(
    'bundle' => 'carousel_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_slideshow_slide_link',
    'label' => 'Link',
    'required' => FALSE,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => -2,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-carousel_slideshow-field_slideshow_cslide'.
  $field_instances['fieldable_panels_pane-carousel_slideshow-field_slideshow_cslide'] = array(
    'bundle' => 'carousel_slideshow',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
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
          'links' => 0,
          'use_content_language' => TRUE,
          'view_mode' => 'full',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'slide' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
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
          'links' => 0,
          'use_content_language' => TRUE,
          'view_mode' => 'full',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'ul',
    'field_name' => 'field_slideshow_cslide',
    'label' => 'Slide',
    'required' => 1,
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
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'references_dialog_add' => 1,
        'references_dialog_edit' => 1,
        'references_dialog_search' => 1,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-homepage_callouts-field_body'.
  $field_instances['fieldable_panels_pane-homepage_callouts-field_body'] = array(
    'bundle' => 'homepage_callouts',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Supply more details about this callout.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
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
        'weight' => 2,
      ),
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -2,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-homepage_callouts-field_button'.
  $field_instances['fieldable_panels_pane-homepage_callouts-field_button'] = array(
    'bundle' => 'homepage_callouts',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'Add a link another page. Text will appear as a button.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
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
        'type' => 'link_default',
        'weight' => 3,
      ),
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_button',
    'label' => 'Button',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'link_field',
      'weight' => -1,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-homepage_callouts-field_callout_image'.
  $field_instances['fieldable_panels_pane-homepage_callouts-field_callout_image'] = array(
    'bundle' => 'homepage_callouts',
    'deleted' => 0,
    'description' => 'This image will be configured to fit with a box XX pixels wide and XX pixels tall.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => 'homepage_callout',
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
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_callout_image',
    'label' => 'Callout image',
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
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-homepage_callouts-field_subhead'.
  $field_instances['fieldable_panels_pane-homepage_callouts-field_subhead'] = array(
    'bundle' => 'homepage_callouts',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Give this callout a subheader.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
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
        'weight' => 1,
      ),
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_subhead',
    'label' => 'Subhead',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a link another page. Text will appear as a button.');
  t('Body');
  t('Button');
  t('Callout image');
  t('Give this callout a subheader.');
  t('Link');
  t('Slide');
  t('Slide image');
  t('Subhead');
  t('Supply more details about this callout.');
  t('This image will be configured to fit with a box XX pixels wide and XX pixels tall.');

  return $field_instances;
}
