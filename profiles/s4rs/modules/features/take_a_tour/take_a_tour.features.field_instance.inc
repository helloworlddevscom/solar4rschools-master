<?php
/**
 * @file
 * take_a_tour.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function take_a_tour_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'tour_video-tour_video-field_tour_video'.
  $field_instances['tour_video-tour_video-field_tour_video'] = array(
    'bundle' => 'tour_video',
    'deleted' => 0,
    'description' => 'Add a video via Vimeo or YouTube.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'magnific_popup',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'gallery_style' => 'first_item',
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
        'type' => 'magnific_popup_file_field_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'tour_video',
    'fences_wrapper' => 'div',
    'field_name' => 'field_tour_video',
    'label' => 'Tour video',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 0,
          'vimeo' => 'vimeo',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 0,
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 'media_internet',
          'upload' => 0,
          'youtube' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'tour_video-tour_video-field_tour_video_pages'.
  $field_instances['tour_video-tour_video-field_tour_video_pages'] = array(
    'bundle' => 'tour_video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Specify pages you wish to attach this video to by using their paths. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. No tours will appear on the front page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'tour_video',
    'fences_wrapper' => 'div',
    'field_name' => 'field_tour_video_pages',
    'label' => 'Tour video pages',
    'required' => 0,
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
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a video via Vimeo or YouTube.');
  t('Specify pages you wish to attach this video to by using their paths. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. No tours will appear on the front page.');
  t('Tour video');
  t('Tour video pages');

  return $field_instances;
}
