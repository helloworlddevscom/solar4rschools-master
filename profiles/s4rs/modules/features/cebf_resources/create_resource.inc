<?php

/**
 * @file
 */

/*
 * Loads all taxonomy terms from vocabulary 'Resource Type'
 */
function get_resource_types() {
  $resource_types = array('0' => 'Select Resource Type');
  $resource_types = $resource_types + load_vocabulary_terms('resource_type');
  return $resource_types;
}

/*
 * Generic load taxonomy terms function, takes one parameter: vocabulary
 */
function load_vocabulary_terms($vocabulary_machine_name) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name);
  $tree = taxonomy_get_tree($vocabulary->vid);
  $vterms = array();
  foreach ($tree as $term) {
    $skip = FALSE;
    if (!$skip) {
      $vterms[$term->tid] = $term->name;
    }
  }
  return $vterms;
}

function form_create_resource($form, &$form_state) {
  $resource_types = get_resource_types();

  // Required for forms with file inputs.
  //$form['#attributes'] = array('enctype' => "multipart/form-data");

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Please provide your contact information and a brief description of the resource along with any relevant links or files.'),
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of Resource'),
    '#required' => true,
  );

  $form['first'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
  );

  $form['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
  );

  $form['email'] = array(
   '#type' => 'textfield',
   '#title' => t('Email'),
   '#required' => TRUE,
  );

  $form['resource_type'] = array(
    '#type' => 'select',
    '#title' => t('Resource Type'),
    '#options' => $resource_types,
    //'#description' => t('Select resource type'),
  );

  $form['resource_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Enter description of Resource'),
    '#rows' => 10,
    '#cols' => 60,
    '#resizable' => TRUE,
  );

  $form['resource_file'] = array(
      '#type'   => "managed_file",
      '#title'  => t("Resource File"),
      '#description' => t("Only doc, docx, pdf, ,png, jpg format files are allowed."),
      '#upload_location'    => "private://resource/",
      "#upload_validators"  => array("file_validate_extensions" => array("doc docx pdf png jpg")),
      '#progress_indicator' => 'bar',
      '#required'=>FALSE,
  );

  $form['resource_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Resource Link/URL'),
    '#description' => t('Enter link/URL to Resource'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#weight' => 50,
  );

  // Captcha
  $form['captcha'] = array(
    '#type' => 'captcha',
    '#prefix' => 'CAPTCHA<br>This question prevents automated spam submissions.',
  );


  return $form;
}

function form_create_resource_validate($form, &$form_state) {
 // dpm($form_state);
  $values = $form_state['values'];

  if (empty($values['resource_link']) && empty($values['resource_file'])) {

//if (empty($values['resource_link']) && (!isset($values['file']) || !is_numeric($values['file']))) {

    $error_elements = array('resource_link' , 'resource_file');
    foreach ($error_elements as $element) {
      form_set_error($element);
    }
    drupal_set_message(t('You must submit either the resource link or resource file field'), 'error');
  }
}

/**
 * Submit handler.
 *
 */
function form_create_resource_submit($form, &$form_state) {
  //dpm($form_state);

  global $user;

  $node = new stdClass();
  $node->title = $form_state['values']['title'];
  $node->type = "resource"; //content type
  $node->language = LANGUAGE_NONE;
  $node->field_first_name[LANGUAGE_NONE][0]['value'] = $form_state['values']['first'];
  $node->field_last_name[LANGUAGE_NONE][0]['value'] = $form_state['values']['last'];
  $node->field_email[LANGUAGE_NONE][0]['value'] = $form_state['values']['email'];

  //Resource Type
  $node->field_resource_type[LANGUAGE_NONE][0]['tid'] = $form_state['values']['resource_type'];

  //Resource Description - stored in body field
  $node->body[LANGUAGE_NONE][0]['value'] = $form_state['values']['resource_body'];

  //Resource Link
  $node->field_resource_url[LANGUAGE_NONE][0]['url'] = $form_state['values']['resource_link'];

  if ($form_state['values']['resource_file'] != 0) {

    // Make the file permanent.
    $file = file_load($form_state['values']['resource_file']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);

    // add referenced file to file field
    $node->language = LANGUAGE_NONE;
    // attach file to the file field.
    $node->field_resource_file[$node->language][0] = (array) $file;
    // Default file type field comes with this extra properties.
    $node->field_resource_file[$node->language][0]['display'] = 1;
    //$node->field_file[$node->language][0]['description'] = 'File Description';

    // add an entry in the file_usage table.
    file_usage_add($file, 'create_resource', 'resource_file', 1);
  }

  $node->uid = $user->uid;
  // Set to unpublished.
  $node->status = 0;
  $node->promote = 0;

  // Set workbench moderation state to needs review.
  $node->workbench_moderation_state_new = 'needs_review';
  $node->revision = 1;

  // Prepare node for saving.
  $node = node_submit($node);
  // Save node.
  node_save($node);

  // Redirect user to confirmation page.
  $form_state['redirect'] = 'create/resource/confirmation';

  // NOTE: Rules module will now send CEBF an email with link to new resource.
  // See: /admin/config/workflow/rules/reaction/manage/rules_resource_needs_review
}
