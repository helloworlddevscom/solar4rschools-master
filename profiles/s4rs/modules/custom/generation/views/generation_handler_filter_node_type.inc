<?php
/**
 * @file
 * Views filter handler to allow filtering by whether nodes are generation
 * sites.
 */

/**
 * @todo: Filter by generation site node types.
 */
class generation_handler_filter_node_type extends views_handler_filter_in_operator {
  function construct() {
    parent::construct();
    $this->value_title = t('Generation site node types');
    $this->value_options = array(
      '1' => t('Yes'),
      '0' => t('No'),
    );
  }

  function get_value_options() { }

}
