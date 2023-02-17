<?php

/**
 * @file
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Links'),
  'description' => t('Insert links in pane.'),
  'single' => TRUE,
  'content_types' => array('links_pane'),
  'render callback' => 'links_pane_render',
  'defaults' => array(),
  'edit form' => 'links_pane_edit_form',
  'required context' => array(
    new ctools_context_optional(t('Node'), 'node'),
    new ctools_context_optional(t('User'), 'user'),
  ),
  'icon' => 'icon_link.png',
  'category' => array(t('Links')),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *
 * @return
 *   An object with at least title and content members.
 */
function links_pane_render($subtype, $conf, $args, $context) {
  $links = array();
  foreach ($conf['links_pane'] as $link_name) {
    if ($link_name) {
      $data = array();
      foreach ($context as $delta => $ctools_context) {
        if ($ctools_context->keyword) {
          $data[$ctools_context->keyword] = $ctools_context->data;
        }
      }

      ctools_include('export');
      $link = ctools_export_crud_load('link_pane', $link_name);

      $token = FALSE;
      if (module_exists('token')) {
        $token = TRUE;
        $link->text = token_replace($link->text, $data);
        $link->path = token_replace($link->path, $data);
      }

      $options = array();
      if (!empty($link->id)) {
        if ($token) {
          $link->id = token_replace($link->id, $data);
        }
        $options['attributes']['id'][] = $link->id;
      }

      if ($token && !empty($link->class)) {
        $link->class = token_replace($link->class, $data);
      }
      $options['attributes']['class'][] = 'link-pane-link';
      $options['attributes']['class'][] = $link->class;

      if (!empty($link->title)) {
        if ($token) {
          $link->title = token_replace($link->title, $data);
        }
        $options['attributes']['title'] = $link->title;
      }

      if (!empty($link->query)) {
        if ($token) {
          $link->query = token_replace($link->query, $data);
        }
        // Decode to array for building link.
        parse_str($link->query, $options['query']);
      }

      if (!empty($link->fragment)) {
        if ($token) {
          $link->fragment = token_replace($link->fragment, $data);
        }
        $options['fragment'] = $link->fragment;
      }

      if ($router_item = menu_get_item($link->path)) {
        if ($router_item['access']) {
          // The user has access to the path, proceed.
          $links[]['data'] = l($link->text, $link->path, $options);
        }
      }
      else {
        // Some external path, proceed.
        $links[]['data'] = l($link->text, $link->path, $options);
      }

    }
  }

  // @TODO See how I can utilize Advanced help here.
  $ctools_help = theme('advanced_help_topic', 'ctools', 'plugins', 'title');
  $ctools_plugin_example_help = theme('advanced_help_topic', 'ctools_plugin_example', 'Chaos-Tools--CTools--Plugin-Examples', 'title');

  $block = new stdClass();
  $block->title = t('Links');

  $block->content = '';
  if ($conf['links_pane_render'] == 'unformatted') {
    foreach ($links as $link) {
       $block->content .= $link['data'];
    }
  }
  else {
    $block->content = theme('item_list', array('items' => $links));
  }

  return $block;

}

/**
 * 'Edit form' callback for the content type.
 */
function links_pane_edit_form($form, &$form_state) {
  ctools_include('export');
  $items = ctools_export_crud_load_all('link_pane');
  $options = array();
  foreach ($items as $name => $item) {
    $options[$name] = $name;
  }

  $conf = $form_state['conf'];

  $form['links_pane'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Links'),
    '#description' => t('Choose links to display on this pane.'),
    '#options' => $options,
    '#default_value' => !empty($conf['links_pane']) ? $conf['links_pane'] : '',
  );

  $form['links_pane_render'] = array(
    '#type' => 'radios',
    '#title' => t('Links'),
    '#description' => t('Choose links to display on this pane.'),
    '#options' => array('unformatted' => t('Unformatted'), 'list' => t('HTML list')),
    '#default_value' => !empty($conf['links_pane_render']) ? $conf['links_pane_render'] : 'list',
  );

  return $form;
}

function links_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array('links_pane', 'links_pane_render') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Create option list.
 */
function links_pane_options() {
  ctools_include('export');
  $items = ctools_export_crud_load_all('link_pane');
  $options = array();
  foreach ($items as $name => $item) {
    $options[$name] = $name;
  }
  return $options;
}
