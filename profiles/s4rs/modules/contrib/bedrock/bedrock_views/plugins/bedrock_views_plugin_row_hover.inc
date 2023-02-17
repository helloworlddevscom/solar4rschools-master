<?php
/**
 * @file
 * Contains the Views Hover row plugin.
 */

/**
 * The 'hover' row plugin.
 */
class bedrock_views_plugin_row_hover extends views_plugin_row_fields {

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['in_dropdown'] = array('default' => array());
    $options['hover'] = array('default' => FALSE);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $fields = $this->display->handler->get_field_labels();
    $form['in_dropdown'] = array(
      '#type' => 'checkboxes',
      '#options' => $fields,
      '#title' => t('In dropdown'),
      '#default_value' => $this->options['in_dropdown'],
      '#description' => t('Select fields that should appear in the dropdown. At least one field must remain unchecked!'),
    );
    $form['hover'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display on hover?'),
      '#default_value' => $this->options['hover'],
      '#description' => t('If selected, contents in the dropdown will appear on hover. Otherwise, on click.'),
    );
  }

  /**
   * {@inheritdoc}
   */
  function options_validate(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // We cannot allow *all* fields to be in the dropdown.
    $in_dropdown = array();
    foreach ($form_state['values']['row_options']['in_dropdown'] as $key => $enabled) {
      if ($enabled) {
        $in_dropdown[$key] = $enabled;
      }
    }
    if (count($in_dropdown) && (count($in_dropdown) == count($form['in_dropdown']['#options']))) {
      form_set_error('in_dropdown', t('At least one field must *not* be in the dropdown.'));
    }
  }

}
