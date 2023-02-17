<?php
/**
 * @file
 * Supporting functions for Solar 4R Schools installer.
 */

/**
 * Loads the first result of an EFQ -- or creates a new entity.
 *
 * @return EntityDrupalWrapper
 *   Wrapped entity object.
 */
function entity_load_or_create_wrapped(array $efq_results, $entity_type, $bundle) {
  if (empty($efq_results)) {
    $entity = entity_create($entity_type, array('type' => $bundle));
  }
  else {
    $first = reset($efq_results[$entity_type]);
    $entity = entity_load_single($entity_type, $first->id);
  }
  return entity_metadata_wrapper($entity_type, $entity, array('bundle' => $bundle));
}

/**
 * Loads entities like entity_load(), but wrapped.
 *
 * @return array
 *   Array of EntityDrupalWrapper objects.
 */
function entity_load_wrapped($entity_type, array $entity_ids, $bundle) {
  $entities = array();
  foreach (entity_load($entity_type, $entity_ids) as $entity_id => $entity) {
    $wrapped_entity = entity_metadata_wrapper($entity_type, $entity, array('bundle' => $bundle));
    $entities[$entity_id] = $wrapped_entity;
  }
  return $entities;
}
