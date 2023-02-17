<?php
/**
 * My custom filter handler
 */
class FunderAutocompleteMultiselect extends views_handler_filter {
  public function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    if (empty($form_state['exposed'])) {
      return;
    }

    $default_value = array();
    $options = $this->get_options();

    $identifier = $this->options['expose']['identifier'];
    $this->options['expose']['multiple'] = TRUE;

    $form['value']['#type'] = 'select';
    $form['value']['#multiple'] = TRUE;
    $form['value']['#options'] = $options;
    $form['value']['#size'] = min(9, count($options));
    $form['value']['#default_value'] = $default_value;
    $form['value']['#empty_value'] = '';

    if (isset($identifier) && !isset($form_state['input'][$identifier])) {
      $form_state['input'][$identifier] = $default_value;
    }
  }

  /**
   * Helper function used to generate form options.
   */
  protected function get_options() {
    $matches = array();
    $nodes = node_load_multiple(array(), array('type' => 'funder'));

    foreach ($nodes as $nid => $node) {
      $matches[$nid] = check_plain($node->title);
    }

    asort($matches);
    return $matches;
  }
}
