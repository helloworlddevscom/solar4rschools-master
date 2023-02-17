<?php
/**
 * Implements of hook_views_data_alter().
 */
function views_author_multiselect_views_data_alter(&$data) {
  if (isset($data['search_api_index_default']['author']['filter']['handler'])) {
    $data['search_api_index_default']['author']['filter']['handler'] = 'UserAutocompleteMultiselect';
  }
}
