<?php
/**
 * @file
 * solar_core.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function solar_core_workbench_moderation_export_states() {
  $items = array(
    'draft' => array(
      'name' => 'draft',
      'label' => 'Not Published',
      'description' => 'Save as unpublished',
      'weight' => -10,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Submit for review',
      'weight' => 0,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Publish',
      'weight' => -10,
    ),
  );
  return $items;
}
