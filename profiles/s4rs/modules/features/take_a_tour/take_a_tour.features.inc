<?php
/**
 * @file
 * take_a_tour.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function take_a_tour_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function take_a_tour_eck_bundle_info() {
  $items = array(
    'tour_video_tour_video' => array(
      'machine_name' => 'tour_video_tour_video',
      'entity_type' => 'tour_video',
      'name' => 'tour_video',
      'label' => 'Tour Video',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function take_a_tour_eck_entity_type_info() {
  $items = array(
    'tour_video' => array(
      'name' => 'tour_video',
      'label' => 'Tour Video',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
  );
  return $items;
}
