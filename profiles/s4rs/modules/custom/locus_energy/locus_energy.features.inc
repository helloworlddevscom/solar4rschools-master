<?php
/**
 * @file
 * locus_energy.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function locus_energy_eck_bundle_info() {
  $items = array(
    'generation_site_locus_energy' => array(
      'machine_name' => 'generation_site_locus_energy',
      'entity_type' => 'generation_site',
      'name' => 'locus_energy',
      'label' => 'Locus Energy',
    ),
    'locus_energy_component_locus_energy_component' => array(
      'machine_name' => 'locus_energy_component_locus_energy_component',
      'entity_type' => 'locus_energy_component',
      'name' => 'locus_energy_component',
      'label' => 'Locus Energy Component',
    ),
  );
  return $items;
}
