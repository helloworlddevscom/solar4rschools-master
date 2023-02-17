<?php

/**
 * @file
 * Full Width Iframe view.
 * Render iFrame in template.
 * See: full-width-iframe.js
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <?php if (isset($view->result[0])): ?>
    <?php
    // Pass value of field_hide_title_body to JS.
    if (!empty($view->result[0]->field_field_hide_title_body) && $view->result[0]->field_field_hide_title_body[0]['raw']['value']) {
      drupal_add_js(array('hide_title_body' => true), 'setting');
    }
    ?>

    <?php if (!empty($view->result[0]->field_field_full_width_iframe_url) && isset($view->result[0]->field_field_full_width_iframe_url[0]['raw']['url'])): ?>
      <div class="view-content">
        <?php $iframe_url = $view->result[0]->field_field_full_width_iframe_url[0]['raw']['url']; ?>
        <?php $iframe_width = ($view->result[0]->field_field_full_width_iframe_width[0]['raw']['value'] ? $view->result[0]->field_field_full_width_iframe_width[0]['raw']['value'] : '15'); ?>
        <?php $iframe_height = ($view->result[0]->field_field_full_width_iframe_height[0]['raw']['value'] ? $view->result[0]->field_field_full_width_iframe_height[0]['raw']['value'] : '9'); ?>
        <?php $iframe_width_mobile = ($view->result[0]->field_field_full_width_iframe_width_m[0]['raw']['value'] ? $view->result[0]->field_field_full_width_iframe_width_m[0]['raw']['value'] : '3'); ?>
        <?php $iframe_height_mobile = ($view->result[0]->field_field_full_width_iframe_height_m[0]['raw']['value'] ? $view->result[0]->field_field_full_width_iframe_height_m[0]['raw']['value'] : '3'); ?>
        <iframe src="<?php print $iframe_url; ?>" width="<?php print $iframe_url; ?>" height="<?php print $iframe_height; ?>" data-set-width="<?php print $iframe_width; ?>" data-set-height="<?php print $iframe_height; ?>"  data-set-width-mobile="<?php print $iframe_width_mobile; ?>" data-set-height-mobile="<?php print $iframe_height_mobile; ?>"></iframe>
      </div>
    <?php elseif (!empty($empty)): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>

</div><?php /* class view */ ?>
