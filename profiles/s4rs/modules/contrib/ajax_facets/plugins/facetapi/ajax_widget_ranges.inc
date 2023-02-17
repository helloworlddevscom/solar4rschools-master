<?php

/**
 * @file
 * The facetapi_links and facetapi_checkbox_links widget plugin classes.
 */

/**
 * Widget that renders facets as a range of values.
 */
class FacetapiAjaxWidgetRanges extends FacetapiAjaxWidget {

  /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return [
      'show_reset_link' => 0,
    ];
  }

  /**
   * Transforms the render array for use with theme_item_list().
   */
  function buildListItems($build, $level = 0) {

    // Builds rows.
    $items = [];

    $active_items = [];
    $have_active = FALSE;
    foreach ($build as $value => $item) {
      // Respect current selection.
      if (!empty($item['#active'])) {
        $items['active_value'] = $value;
        $have_active = TRUE;
        $active_items[] = $this->key . ':' . $item['#markup'];
      }

      $items['values'][$item['#indexed_value']] = $item['#indexed_value'];
    }

    $this->jsSettings['haveActiveSelection'] = $this->settings->settings['have_active_selection'] = $have_active;
    sort($active_items);
    $this->jsSettings['activeItems'] = $active_items;
    // Generate reset path on server side to make possible to use aliases.
    if ($have_active) {
      $this->jsSettings['resetPath'] = ajax_facets_facet_build_reset_path($this->facet->getFacet(), $this->facet->getAdapter());
    }
    return $items;
  }

  /**
   * Implements FacetapiWidget::execute().
   *
   * Transforms the render array into something that can be themed by
   * theme_item_list().
   *
   * @see FacetapiWidgetLinks::setThemeHooks()
   * @see FacetapiWidgetLinks::buildListItems()
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    $items = $this->buildListItems($element);

    $slider_attrs = [
      'data-facet-name' => rawurlencode($this->settings->facet),
      'data-raw-facet-name' => $this->settings->facet,
      'class' => ['slider-wrapper'],
    ];

    $raw_values = [];
    $terms = null;
    // @TODO: This should be an admin option
    // but only allowed if the field is a taxonomy term reference.
    $display_value_labels = true;
    $global_min = null;
    $global_max = null;
    $active_min_tid = null;
    $active_max_tid = null;
    $active_min_term_name = null;
    $active_max_term_name = null;

    // If this is a taxonomy term reference field The order of the options
    // should be determined by the order of the taxonomy terms
    // at /admin/structure/taxonomy/*.
    if ($this->build['#facet']['field type'] == 'taxonomy_term') {
      $field = field_info_field($this->build['#facet']['field']);
      $vocab_name = $field['settings']['allowed_values'][0]['vocabulary'];
      $vocabulary = taxonomy_vocabulary_machine_name_load($vocab_name);
      $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));

      // Order terms by weight.
      usort($terms, function ($term1, $term2) {
        return $term1->weight > $term2->weight;
      });
      $terms = array_values($terms);

      if (!empty($terms)) {
        foreach ($terms as $term) {
          $raw_values[] = $term->tid;
        }
      }

      // Set global min and max based on first and last term.
      // However, jQuery UI Slider requires values to be incremental,
      // which term IDs are not usually. To get around this we set
      // global min and max to incremental integers based on the total number of terms.
      if (!empty($raw_values)) {
        $global_min = 1;
        $global_max = count($raw_values);

        // Pass the global min and max term IDs to JS.
        $slider_attrs['data-min-tid'] = $raw_values[0];
        $slider_attrs['data-max-tid'] = end($raw_values);
      }
    }
    // If field is not taxonomy term reference then we can determine
    // global min and max based on field value.
    else {
      $raw_values = array_keys($element);
      $raw_values = array_filter($raw_values, 'is_numeric');

      // Check that we have values for the facet widget.
      if (!empty($raw_values)) {
        $global_min = min($raw_values);
        $global_max = max($raw_values);
      }
    }

    // Set global min and max values.
    if (!empty($global_min)) {
      $slider_attrs['data-min'] = $global_min;
      $slider_attrs['data-max'] = $global_max;
    }

    // Check that we have values for the facet widget.
    if (!empty($raw_values)) {
      // Get selected min and max for active value.
      if (!empty($items['active_value'])) {
        // If field is taxonomy term reference.
        if (!empty($terms)) {
          // Retrieve all args for this facet from URL.
          $selected_values = [];
          if (!empty($_GET['f'])) {
            foreach($_GET['f'] as $arg) {
              if (strpos($arg, $field['field_name']) !== false) {
                $exploded_value = explode($field['field_name'] . ':', $arg);
                $selected_values[] = $exploded_value[1];
              }
            }
          }
          // Find min and max based on ordered list of term IDs.
          $active_min_tid = $selected_values[0];
          $active_max_tid = end($selected_values);
          $active_min = array_search($active_min_tid, $raw_values) + 1;
          $active_max = array_search($active_max_tid, $raw_values) + 1;

          // Render the active min and max term IDs as HTML data attributes for clarity.
          $slider_attrs['data-min-val-tid'] = $active_min_tid;
          $slider_attrs['data-max-val-tid'] = $active_max_tid;

          // Record active min and max term names to use as value of input fields.
          foreach($terms as $term) {
            if ($term->tid == $active_min_tid) {
              $active_min_term_name = $term->name;
            }
            if ($term->tid == $active_max_tid) {
              $active_max_term_name = $term->name;
            }
          }
        }
        else {
          $values = explode(' TO ', $items['active_value']);
          $active_min = preg_replace('/[^0-9\.]/', '', $values[0]);
          $active_max = preg_replace('/[^0-9\.]/', '', $values[1]);
        }
      }
      // Get selected min and max to defaults.
      else {
        $active_min = $global_min;
        $active_max = $global_max;
      }

      $slider_attrs['data-min-val'] = $active_min;
      $slider_attrs['data-max-val'] = $active_max;

      // @todo move it into the other place?
      drupal_add_library('system', 'ui.slider');

      // Construct markup for min max input fields.
      $input_field_markup = '<div class="range-slider__inputs">';

      if (!empty($active_min_term_name)) {
        $min_input_value = $active_min_term_name;
      }
      else {
        $min_input_value = $slider_attrs['data-min-val'];
      }

      $input_field_markup .= theme(
        'ajax_facets_ranges_input',
        [
          'title' => t('From:'),
          'attributes' => ['class' => 'ajax-facets-slider-amount-min'],
          'value' => $min_input_value,
        ]
      );

      if (!empty($active_max_term_name)) {
        $max_input_value = $active_max_term_name;
      }
      else {
        $max_input_value = $slider_attrs['data-max-val'];
      }

      $input_field_markup .= theme(
        'ajax_facets_ranges_input',
        [
          'title' => t('To:'),
          'attributes' => ['class' => 'ajax-facets-slider-amount-max'],
          'value' => $max_input_value,
        ]
      );

      $input_field_markup .= '</div>';

      // If this is a taxonomy term reference field,
      // construct markup to display taxonomy term names
      // horizontally along range slider.
      $values_markup = '';
      if (!empty($terms)) {
        $values_markup = '<div class="range-slider__value-labels">';

        foreach ($terms as $key => $term) {
          $value = $key + 1;
          $values_markup .= '<span class="value-labels__label" data-tid="' . $term->tid . '" data-value="' . $value . '"><span class="label__text">' . $term->name . '</span></span>';
        }

        $values_markup .= '</div>';
      }

      // We cannot use drupal_html_id to save the same id for each facet.
      $wrapper_id = $this->build['#attributes']['id'] . '-wrapper';

      $element = [
        '#markup' => '<div id="' . $wrapper_id . '" class="ajax-facets--range-slider">'
          . '<label>' . $this->build['#title'] . '</label>'
          . $this->getResetLink()
          . '<div class="ajax-facets-controls-wrapper">'
          . $input_field_markup
          . $values_markup
          . '<div ' . drupal_attributes($slider_attrs) . '></div>'
          . '</div>'
          . '</div>'
      ];

      ajax_facets_add_ajax_js($this->facet);
    }
    // We don't have data for facet widget, hide it.
    else {
      $element = [];
    }
  }
}
