<?php
/**
 * @file
 * solar_slideshow.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function solar_slideshow_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'homepage_slideshow';
  $queue->label = 'Homepage Slideshow';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'front_slide' => 'front_slide',
    ),
    'min_size' => '0',
    'max_size' => '5',
    'act_as_queue' => 0,
  );
  $export['homepage_slideshow'] = $queue;

  return $export;
}
