<?php

/**
* Define this Export UI plugin.
*/
$plugin = array(
  'schema' => 'link_pane',  // As defined in hook_schema().
  'access' => 'administer link_pane',  // Define a permission users must have to access these pages.

  // Define the menu item.
  'menu' => array(
    'menu item' => 'link_pane',
    'menu title' => 'Link panes',
    'menu description' => 'Administer link panes.',
  ),

  // Define user interface texts.
  'title singular' => t('preset'),
  'title plural' => t('presets'),
  'title singular proper' => t('link pane link preset'),
  'title plural proper' => t('link pane link presets'),

  // Define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'link_pane_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
  ),
);

/**
* Define the preset add/edit form.
*/
function link_pane_ctools_export_ui_form(&$form, &$form_state) {
  $preset = $form_state['item'];

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('The human readable name or description of this link pane.'),
    '#default_value' => $preset->description,
  );

  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#description' => t('Link text.'),
    '#default_value' => $preset->text,
    '#required' => true,
  );

  $form['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Link path'),
    '#description' => t('Link path.'),
    '#default_value' => $preset->path,
    '#required' => true,
  );

  $form['other'] = array(
  '#title' => t('More options'),
  '#type' => 'fieldset',
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );

  // @TODO Add some form validation? Format is important. Things might brake if user is not careful.
  $form['other']['query'] = array(
    '#type' => 'textfield',
    '#title' => t('Link query'),
    '#description' => t('Query string to append to the URL. In form of <em>query=value&query=value</em>. Do not prepend <em>?</em>'),
    '#default_value' => $preset->query,
  );

  $form['other']['fragment'] = array(
    '#type' => 'textfield',
    '#title' => t('Link fragment'),
    '#description' => t('A fragment identifier (named anchor) to append to the URL. Do not include the leading <em>#</em> character.'),
    '#default_value' => $preset->fragment,
  );
  $form['other']['id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#description' => t('ID of link tag.'),
    '#default_value' => $preset->id,
  );

  $form['other']['class'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#description' => t('Classes of link tag. Separated by space.'),
    '#default_value' => $preset->class,
  );

  $form['other']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Title attribute of link tag.'),
    '#default_value' => $preset->title,
  );

  if (module_exists('token')) {
    $form['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      // '#description' => t('Prefer raw-text replacements for text to avoid problems with HTML entities!'),
      );

    $form['token_help']['help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node'),
      );
  }

}
