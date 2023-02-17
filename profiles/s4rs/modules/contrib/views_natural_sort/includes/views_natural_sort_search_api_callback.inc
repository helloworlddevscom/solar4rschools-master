<?php

/**
 * @file
 * Contains SearchApiAlterAddHierarchy.
 */

/**
 * Add new field that contains value, that could be naturally sorted.
 */
class ViewsNaturalSortSearchApiCallback extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function configurationForm() {
    $form['#attached']['css'][] = drupal_get_path('module', 'search_api') . '/search_api.admin.css';

    $fields = $this->index->getFields();
    $field_options = array();
    $default_fields = array();
    if (isset($this->options['fields'])) {
      $default_fields = drupal_map_assoc(array_keys($this->options['fields']));
    }
    foreach ($fields as $name => $field) {
      if (strpos($name, 'sort_') !== false) {
        continue;
      }

      $field_options[$name] = check_plain($field['name']);
      if (!empty($default_fields[$name]) || (!isset($this->options['fields']) && $this->testField($name, $field))) {
        $default_fields[$name] = $name;
      }
    }

    $form['fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields to run on'),
      '#options' => $field_options,
      '#default_value' => $default_fields,
      '#attributes' => array('class' => array('search-api-checkboxes-list')),
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    $fields = array_filter($values['fields']);
    if ($fields) {
      $fields = array_fill_keys($fields, TRUE);
    }
    $values['fields'] = $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    $this->options = $values;
    return $values;
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    if (empty($this->options['fields'])) {
      return;
    }

    foreach ($items as &$item) {
      foreach ($this->options['fields'] as $field => $active) {
        if (is_string($item->{$field})) {
          $item->{'sort_' . $field} = views_natural_sort_transform(array(
            'content' => $item->{$field}
          ));
        }
        elseif (!empty($item->{$field}[$item->language][0]['value'])) {
          $item->{'sort_' . $field} = views_natural_sort_transform(array(
            'content' => $item->{$field}[$item->language][0]['value']
          ));
        }
        else {
          $item->{'sort_' . $field} = "";
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    if (empty($this->options['fields'])) {
      return array();
    }

    $properties = array();
    $fields = $this->index->getFields();
    foreach ($this->options['fields'] as $field => $active) {
      $properties['sort_' . $field] = array(
        'label' => t('Sort by !label', array('!label' => $fields[$field]['name'])),
        'description' => t('Field processed by Views Natural Sort module for natural sorting.'),
        'type' => 'string',
      );
    }

    return $properties;
  }

  /**
   * Determines whether to process data from the given field.
   *
   * @param $name
   *   The field's machine name.
   * @param array $field
   *   The field's information.
   *
   * @return bool
   *   TRUE, if the field should be processed, FALSE otherwise.
   */
  protected function testField($name, array $field) {
    if (empty($this->options['fields'])) {
      return $this->testType($field['type']);
    }
    return !empty($this->options['fields'][$name]);
  }

  /**
   * Determines whether fields of the given type should normally be processed.
   *
   * Defaults to processing text types, but can easily be overridden by
   * subclasses.
   *
   * @return bool
   *   TRUE, if the type should be processed, FALSE otherwise.
   */
  protected function testType($type) {
    return search_api_is_text_type($type, array('text', 'tokens'));
  }

}
