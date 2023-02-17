<?php
/**
 * @file
 * The status behavior makes a property behave like a publishable entity.
 *
 * Options are 0 for unpublished and 1 for published.
 */

$plugin = array(
  'label' => "Status",
  'entity_info' => 'generation_status_property_entity_info',
  'default_widget' => 'generation_status_property_widget',
);

/**
 * How to input a status.
 */
function generation_status_property_widget($property, $vars) {
  $entity = $vars['entity'];
  $status = _generation_status_property_extract_status($entity, $property);
  return array(
    '#type' => 'checkbox',
    '#title' => $vars['properties'][$property]['label'],
    '#default_value' => $status,
    '#required' => FALSE,
  );
}

/**
 * Helper function that gets the status from an entity.
 *
 * @param object $entity
 *   an entity object.
 * @param string $property
 *   the name of the property that contains the status.
 *
 * @return bool
 *   The status of the entity.
 */
function _generation_status_property_extract_status($entity, $property) {
  $status = FALSE;
  if (isset($entity->{$property})) {
    $status = $entity->{$property};
  }

  return $status;
}
