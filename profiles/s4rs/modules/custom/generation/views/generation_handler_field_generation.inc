<?php
/**
 * @file
 * A handler to provide a field that draws generation data via ajax.
 */

class generation_handler_field_generation extends views_handler_field {

  /**
   * Constructor.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  /**
   * Implements views_handler_field::allow_advanced_render().
   */
  function allow_advanced_render() {
    return FALSE;
  }

  /**
   * Implements views_handler_field::option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();

    // Override the alter text option to always alter the text.
    $options['alter']['contains']['alter_text'] = array('default' => TRUE);
    return $options;
  }

  /**
   * Implements views_handler_field::options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove the checkbox.
    unset($form['alter']['alter_text']);
    unset($form['alter']['text']['#dependency']);
    unset($form['alter']['text']['#process']);
  }

  /**
   * Implements views_handler_field::query().
   */
  function query() {
    // Do nothing.
  }

  /**
   * Implements views_handler_field::render().
   */
  function render($values) {
    static $js_added = FALSE;
    if (!$js_added) {
      drupal_add_js(drupal_get_path('module', 'generation') . '/generation.js');
      $js_added = TRUE;
    }

    // @todo: Is loading the whole node here a performance bottleneck?
    $node = node_load($values->nid);
    if (!generation_is_site($node)) {
      return '<span>' . t('N/A') . '</span>';
    }

    $name_for_js = array(
      'generation_lifetime_energy' => 'generation',
      'generation_current_power' => 'power',
    );

    return '<span class="generation-placeholder" data-nid="' . $values->nid
      . '" data-type="' . $name_for_js[$this->field] . '"></span>';
  }
}
