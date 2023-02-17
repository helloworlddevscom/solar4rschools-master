<?php
/**
 * @file
 * tigo_energy.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function tigo_energy_eck_bundle_info() {
  $items = array(
    'generation_site_tigo_energy' => array(
      'machine_name' => 'generation_site_tigo_energy',
      'entity_type' => 'generation_site',
      'name' => 'tigo_energy',
      'label' => 'Tigo Energy',
    ),
  );
  return $items;
}
