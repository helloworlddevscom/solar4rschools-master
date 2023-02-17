<?php
/**
 * @file
 * solar_data.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function solar_data_taxonomy_default_vocabularies() {
  return array(
    'widget_types' => array(
      'name' => 'Widget types',
      'machine_name' => 'widget_types',
      'description' => 'Ways of categorizing widgets',
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
