<?php

$plugin = array(
  'title' => t('Green Technology content listing'),
  'description' => t('List Green Technology content from the current node'),
  'category' => t('Solar4Rschools elements'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Pane admin form.
 */
function solar_kiosk_green_tech_list_content_type_edit_form($form, $form_state) {
  return $form;
}

/**
 * Content type render callback.
 */
function solar_kiosk_green_tech_list_content_type_render($subtype, $conf, $panels_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  drupal_add_js(drupal_get_path('module', 'solar_kiosk') . '/js/green_tech_tabs.js');
  drupal_add_library('system', 'ui.tabs');

  $content = entity_load('fieldable_panels_pane',
             // This is an array of arrays instead of just an array.
             array_map(function($array) {
                 return $array['target_id'];
               }, $context->data->field_kiosk_green_tech_content[LANGUAGE_NONE]));
  $list = '<ul class="green-tech-tabs">';
  $body = '';
  foreach ($content as $id => $data) {
    $list .= "<li class=\"green-tech-tab tab-$id\"><a href=\"#green-tech-id-$id\">";
    $list .= $data->title;
    $list .= "</a></li>";

    $body .= "<div id=\"green-tech-id-$id\">";
    $body .= str_replace('id="renewable-technology"',
             'class="renewable-technology"',
             $data->field_fpp_green_tech_body[LANGUAGE_NONE][0]['value']);
    $body .= "</div>";
  }
  $list .= '</ul>';

  $pane = new stdClass();
  $pane->title = '';
  $pane->content = implode('', array(
                     '<div class="green-tech-tab-block">',
                     $list,
                     $body,
                     '</div>',
                   ));
  return $pane;
}
