<?php
/**
 * My custom filter handler
 */
class UserAutocompleteMultiselect extends SearchApiViewsHandlerFilterUser {
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
  protected function get_options($string = '') {
    // The user enters a comma-separated list of user name. We only autocomplete the last name.
    $array = drupal_explode_tags($string);

    // Fetch last name
    $last_string = trim(array_pop($array));
    $matches = array();

    $or = db_or();
    $or->condition('fn.field_first_name_value', db_like($last_string) . '%', 'LIKE');
    $or->condition('ln.field_last_name_value', db_like($last_string) . '%', 'LIKE');
    $query = db_select('users', 'u');
    $query->join('field_data_field_first_name', 'fn', 'u.uid=fn.entity_id');
    $query->join('field_data_field_last_name', 'ln', 'u.uid=ln.entity_id');
    $result = $query->fields('u', array('uid', 'name'))
          ->fields('ln', array('field_last_name_value'))
          ->fields('fn', array('field_first_name_value'))
          ->condition($or)
          ->orderBy('ln.field_last_name_value', 'ASC')
          ->execute();

    while ($record = $result->fetchAssoc()) {
      $uid = $record['uid'];
      $fullname = "{$record['field_first_name_value']} {$record['field_last_name_value']}";
      $fullname = trim($fullname);
      $matches[$uid] = check_plain($fullname);
    }

    return $matches;
  }

  /**
   * {@inheritdoc}
   */
  public function value_validate($form, &$form_state) {
    if (!empty($form['value'])) {
      $value = &$form_state['values']['options']['value'];
      if (strlen($value)) {
        $values = $this->isMultiValued($form_state['values']['options']) ? drupal_explode_tags($value) : array($value);
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function exposed_validate(&$form, &$form_state) {
    if (empty($this->options['exposed']) || empty($this->options['expose']['identifier'])) {
      return;
    }

    $input = $form_state['values'][$this->options['expose']['identifier']];
    if ($this->options['is_grouped'] && isset($this->options['group_info']['group_items'][$input])) {
      $input = $this->options['group_info']['group_items'][$input]['value'];
    }

    if ($input != 'All')  {
      $this->validated_exposed_input = (array) $input;
    }
    return;
  }
}
