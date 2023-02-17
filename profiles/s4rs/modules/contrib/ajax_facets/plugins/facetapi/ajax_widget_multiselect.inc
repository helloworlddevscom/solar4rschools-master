<?php

/**
 * @file
 * Defines a plugin for a multiselect facet API widget.
 */

/**
 * Widget that renders facets as a multiselect element.
 */
class FacetapiAjaxMultiSelectWidget extends FacetapiAjaxWidget {

  /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return [
      "show_reset_link" => 0,
    ];
  }

  /**
   * Transforms the render array for use with theme_item_list().
   *
   * The recursion allows this function to act on the various levels of a
   * hierarchical data set.
   *
   * @param array $build
   *   The items in the facet's render array being transformed.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  function buildListItems($build, $level = 0) {
    $settings = $this->settings->settings;

    // Builds rows.
    $items = [
      '#disabled_items' => [],
    ];

    // Note that for a multiselect element it doesn't make sense to
    // have a default value so we're not setting one here.

    $prefix = str_repeat('-', $level);
    $level++;

    $active_items = [];
    $items['active_items'] = [];
    $have_active = FALSE;
    foreach ($build as $value => $item) {
      // Respect current selection.
      if (!empty($item['#active'])) {
        $have_active = TRUE;
        $active_items[] = $this->key . ':' . $item['#markup'];
        $items['active_items'][] = $item['#indexed_value'];
      }

      $items['options'][$item['#indexed_value']] = $prefix . $item['#markup'];

      // Mark as disabled if count is 0.
      if ($item['#count'] == 0) {
        $items['#disabled_items'][$item['#indexed_value']] = TRUE;
      }

      // Show/hide counts according to the settings.
      if (!empty($this->settings->settings['display_count'])) {
        $items['options'][$item['#indexed_value']] .= ' ' . theme('facetapi_count',(['count' => $item['#count']]));
      }

      // @TODO: Not sure that a multiselect can have children.
      // Copied from FacetapiAjaxSelectWidget::BuildListItems().
      if (!empty($item['#item_children'])) {
        $childrens = $this->buildListItems($item['#item_children'], $level);
        if (!empty($childrens['active_value'])) {
          $items['active_value'] = $childrens['active_value'];
        }
        $items['options'] = $items['options'] + $childrens['options'];
      }
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

    // If name is empty - use label.
    if (empty($items['name'])) {
      $facet = $this->facet->getFacet();
      $items['name'] = $facet['label'];
    }

    $select = [
      '#type' => 'multiselect',
      '#title' => $this->build['#title'],
      '#options' => $items['options'],
      '#name' => rawurlencode($this->settings->facet),
      '#attributes' => [
        'data-facet-name' => rawurlencode($this->settings->facet),
        'data-raw-facet-name' => $this->settings->facet,
      ],
      '#theme' => 'ajax_facets_multiselect',
      '#disabled_items' => $items['#disabled_items'],
      '#value' => $items['active_items'],
    ];

    if (!empty($items['active_value'])) {
      $select['#value'] = $items['active_value'];
    }

    // We cannot use drupal_html_id to save the same id for each facet.
    $wrapper_id = $this->build['#attributes']['id'] . '-wrapper';

    $element = [
      '#markup' => '<div id="' . $wrapper_id . '">'
        . $this->getResetLink()
        . render($select)
        . '</div>'
    ];

    ajax_facets_add_ajax_js($this->facet);
  }
}
