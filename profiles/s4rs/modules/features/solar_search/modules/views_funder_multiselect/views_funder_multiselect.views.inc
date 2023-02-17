<?php

/**
 * Implements of hook_views_data().
 */
function views_funder_multiselect_views_data() {
  return array(
    'node' => array(
      'title_multiselect' => array(
        'group' => t('Content'),
        'title' => t('Funder Name (multiselect list)'),
        'help' => t('Filter by funder name, choosing from dropdown list.'),
        'filter' => array('handler' => 'FunderAutocompleteMultiselect'),
        'real field' => 'nid',
      )
    )
  );
}
