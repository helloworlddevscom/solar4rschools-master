<?php
/**
 * @file
 * Site Equivalents panel pane plugin.
 */

/**
 * Site Equivalents plugin definition.
 */
$plugin = array(
  'title' => t('Graph save'),
  'category' => t('Solar4Rschools elements'),
  'description' => t('Save a link to the current graph.'),
  'required context' => array(
    new ctools_context_required(t('Generation site'), 'generation_site'),
    new ctools_context_required(t('Saved graph'), 'saved_graph'),
  ),
);

/**
 * CTools content type output function.
 */
function explore_data_graph_form_content_type_render($subtype, $conf, $panels_args, $context) {
  if (empty($context) || empty($context[0]->data)) {
    return;
  }

  $content = 'Coming soon.';
  // Build the custom content pane.
  $pane = new stdClass();
  $pane->module  = 'explore_data';
  $pane->title   = '';
  $pane->content = explore_data_graph_form_show($context[1]->data);

  return $pane;
}

/**
 * Pane admin form.
 */
function explore_data_graph_form_content_type_edit_form($form, &$form_state) {
  // No additional config.
  return $form;
}

/**
 * Function that returns a form if applicable, otherwise, a view of the entity.
 */
function explore_data_graph_form_show($saved_graph) {
  global $user;
  $contents = '';

  if (isset($saved_graph) && entity_access('update', 'saved_graph', $saved_graph) && $saved_graph->uid == $user->uid) {
    $contents = eck__entity__edit('saved_graph', 'saved_graph', $saved_graph->id);
  }
  elseif (entity_access('create', 'saved_graph', $saved_graph))
  {
    $contents = eck__entity__add('saved_graph', 'saved_graph');
  }
  elseif (isset($saved_graph) && entity_access('view', 'saved_graph', $saved_graph)) {
    $contents = entity_view('saved_graph', array($saved_graph), 'teaser');
  }

  return $contents;
}
