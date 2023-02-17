<?php
/**
 * Implements of hook_views_data_alter().
 */
function views_science_kit_multiselect_views_data_alter(&$data) {
  if (isset($data['search_api_index_default']['field_science_kit_materials_used']['filter']['handler'])) {
    $handler = &$data['search_api_index_default']['field_science_kit_materials_used']['filter']['handler'];
    $handler = 'ScienceKitAutocompleteMultiselect';
  }
}
