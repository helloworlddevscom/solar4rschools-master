<?php
/**
 * My custom filter handler
 */
class ScienceKitAutocompleteMultiselect extends SearchApiViewsHandlerFilter {
  /**
   * {@inheritdoc}
   */
  public function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    $default_value = array();
    $options = $this->get_options();

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];

      if (empty($this->options['expose']['multiple'])) {
        if (empty($this->options['expose']['required']) && empty($default_value)) {
          $default_value = 'All';
        }
        elseif (empty($default_value)) {
          $keys = array_keys($options);
          $default_value = array_shift($keys);
        }
        // Due to #1464174 there is a chance that array('') was saved in the
        // admin ui. Let's choose a safe default value.
        elseif ($default_value == array('')) {
          $default_value = 'All';
        }
        else {
          $copy = $default_value;
          $default_value = array_shift($copy);
        }
      }
    }

    $form['value']['#type'] = 'select';
    $form['value']['#multiple'] = TRUE;
    $form['value']['#options'] = $options;
    $form['value']['#size'] = min(9, count($options));
    $form['value']['#default_value'] = $default_value;

    if (!empty($form_state['exposed']) && isset($identifier) && !isset($form_state['input'][$identifier])) {
      $form_state['input'][$identifier] = $default_value;
    }
  }

  /**
   * Helper function used to generate form options.
   */
  protected function get_options() {
    $matches = array();
    $nodes = node_load_multiple(array(), array('type' => 'science_kit'));

    foreach ($nodes as $nid => $science_kit) {
      $matches[$nid] = check_plain($science_kit->title);
    }

    return $matches;
  }
}
