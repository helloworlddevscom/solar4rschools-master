<?php
/**
 * @file
 * Provides a custom grouped form exposed form plugin for View 3.x.
 */

/**
 * This class largely stolen from views_exposed_groups_plugin class.
 *
 * The original class does a lot of form-level manipulation, which breaks a lot
 * of functionality created by other modules, which expect the exposed form
 * structure to follow a certain pattern. This module instead provides a theme
 * preprocess function and template to do the real manipulation, which, in the
 * end, is just about display anyway.
 */
class views_exposed_groups_plugin extends views_plugin_exposed_form_basic {

  function summary_title() {
    return t('Grouped form');
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['views_exposed_groups'] = array('default' => array());

	return $options;
  }
  
  /**
   * Implements the option_form method of the plugin.
   *
   * Adds a "div" grouping option.
   */
  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);
    $groups = explode("\n", $this->options['views_exposed_groups']['groups']);
    $groups['no-group'] = t('- No group -');
    array_walk($groups, 'trim');
    $form['views_exposed_groups']['format_groups'] = array(
    	'#type' => 'select',
    	'#title' => 'Render groups as',
    	'#options' => array('div' => 'Div'),
    	'#default_value' => $this->options['views_exposed_groups']['format_groups'],
    );

    $form['views_exposed_groups']['groups'] = array(
    	'#type' => 'textarea',
    	'#title' => 'Groups',
    	'#description' => 'Enter a list of groups to include in this form',
    	'#default_value' => $this->options['views_exposed_groups']['groups'],
    );

    $weight_delta = count($this->display->handler->get_handlers('filter'));

    foreach ($this->display->handler->get_handlers('filter') as $filter_name => $filter) {
      if (!$filter->options['exposed']) {
        continue;
      }
      $label = $filter->options['expose']['identifier'];
      $field_label = ($filter->options['expose']['label']) ? $filter->options['expose']['label'] : $label;
      $form['views_exposed_groups']['group-'. $label]['group'] = array(
      	'#type' => 'select',
      	'#title' => 'Group for '. $field_label,
      	'#filter_field' => $filter,
      	'#options' => $groups,
        '#title_display' => 'invisible',
      	'#default_value' => $this->options['views_exposed_groups']['group-'. $label]['group']
      );
      $form['views_exposed_groups']['group-'. $label]['filter_name'] = array(
        '#type' => 'value',
        '#value' => $filter_name,
      );
      $form['views_exposed_groups']['group-'. $label]['weight'] = array(
        '#type' => 'weight',
      	'#title' => $field_label,
      	'#filter_field' => $filter,
      	'#delta' => $weight_delta,
        '#title_display' => 'invisible',
      	'#default_value' => $this->options['views_exposed_groups']['group-'. $label]['weight']
      );
    }
    $form['views_exposed_groups']['#theme'][] = 'views_exposed_groups_reorder_filter_form';
  }

  /*
   * Tweak the exposed filter form to show grouped form options in a div.
   */
  function exposed_form_alter(&$form, &$form_state) {
    parent::exposed_form_alter($form, $form_state);

    $form['#theme'] = 'views_exposed_groups';

  	$groups = $this->options['views_exposed_groups'];

    foreach ($form['#info'] as $filter_key => $values) {
      if (isset($groups['group-' . $values['value']])) {
        $form['#info'][$filter_key]['group'] = $groups['group-' . $values['value']]['group'];
        $form['#info'][$filter_key]['group-weight'] = $groups['group-' . $values['value']]['weight'];
      }
    }
  }
}