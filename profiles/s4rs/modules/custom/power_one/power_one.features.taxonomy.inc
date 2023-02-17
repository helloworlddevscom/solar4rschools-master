<?php
/**
 * @file
 * power_one.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function power_one_taxonomy_default_vocabularies() {
  return array(
    'power_one_device_categories' => array(
      'name' => 'Power One device categories',
      'machine_name' => 'power_one_device_categories',
      'description' => 'Categories for Power One loggers and devices',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
