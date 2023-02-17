<?php
/**
 * @file
 * Slick style plugin for the Views module.
 */

/**
 * Implements a style type plugin for the Views module.
 */
class SlickViews extends views_plugin_style {

  /**
   * Provides default options.
   */
  public function option_definition() {
    module_load_include('inc', 'slick_views', 'includes/admin');
    $options = _slick_views_option_definition() + parent::option_definition();

    return $options;
  }

  /**
   * Shows a form to edit the style options.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    ctools_form_include($form_state, 'slick.admin', 'slick');
    ctools_form_include($form_state, 'admin', 'slick_views');

    $view = $this->view;
    $settings = $this->options;
    $elements = _slick_views_options_form($form, $form_state, $view, $settings);

    $form['slick'] = array(
      '#type' => 'fieldset',
      '#title' => t('Slick carousel'),
      '#attributes' => array('class' => array('form--slick form--compact form--field has-tooltip')),
      '#description' => t('Leave anything empty/unchecked, except Optionset and Skin, if working with custom markups. <br /><small>Otherwise only relevant markups are added like Field formatter ones, and you have to add supported fields to appear here. Views preview works with jQuery > 1.7.</small>'),

    );

    $no_wrappers = array(
      'optionset',
      'skin',
      'skin_arrows',
      'skin_dots',
      'id',
      'asnavfor_main',
      'grid',
      'grid_medium',
      'grid_small',
      'visible_slides',
      'preserve_keys',
      'slide_field_wrapper',
      'override',
      'overridables',
    );

    $grids = array(
      'grid_medium',
      'grid_small',
      'visible_slides',
      'preserve_keys',
    );

    foreach ($elements as $key => $element) {
      $form['slick'][$key] = $element;
      if (!in_array($key, $no_wrappers)) {
        $form['slick'][$key]['#states'] = array(
          'visible' => array(
            ':input[name*="[slide_field_wrapper]"]' => array('checked' => TRUE),
          ),
        );
      }

      if (in_array($key, array('thumbnail_caption', 'asnavfor_auto'))) {
        $form['slick'][$key]['#states'] = array(
          'invisible' => array(
            array('select[name*="[optionset_thumbnail]"]' => array('value' => '')),
            array(':input[name*="[slide_field_wrapper]"]' => array('checked' => FALSE)),
          ),
        );
      }

      if (in_array($key, array('asnavfor_main', 'asnavfor_thumbnail'))) {
        $form['slick'][$key]['#states'] = array(
          'invisible' => array(
            array('select[name*="[optionset_thumbnail]"]' => array('value' => '')),
            array(':input[name*="[slide_field_wrapper]"]' => array('checked' => FALSE)),
            array(':input[name*="[asnavfor_auto]"]' => array('checked' => TRUE)),
          ),
        );
      }

      if (in_array($key, $grids)) {
        $form['slick'][$key]['#states'] = array(
          'invisible' => array(
            array('select[name$="[grid]"]' => array('value' => '')),
          ),
        );
      }

      if ($key == 'overridables') {
        $form[$key]['#states'] = array(
          'visible' => array(
            ':input[name$="[override]"]' => array('checked' => TRUE),
          ),
        );
      }
    }

    $form['#attached']['library'][] = array('slick', 'slick.admin');
  }

  /**
   * Performs some cleanup tasks on the options array before saving it.
   */
  public function options_submit(&$form, &$form_state) {
    $options = &$form_state['values']['style_options'];

    // The form is a #tree, but the expected output is a flattened array.
    if (!empty($options['slick'])) {
      // Pull the fieldset values one level up.
      $options += $options['slick'];
      unset($options['slick']);
    }
  }

  /**
   * Gets renderable array of field containing rendered and raw data.
   */
  public function getFieldData($row, $field_name) {
    $field = $this->view->field[$field_name]->handler_type . '_' . $field_name;
    return isset($row->{$field}[0]) ? $row->{$field}[0] : '';
  }

  /**
   * Renders the display in this style.
   */
  public function render() {
    $view = $this->view;
    $settings = $this->options;
    $view_name = $view->name;
    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($view->result, $settings['grouping']);
    $keys = array_keys($view->field);
    $settings['view_name'] = $view_name;
    $slick_markups = $settings['slide_field_wrapper'];

    $attach = array(
      'attach_skin' => $settings['skin'],
      'attach_skin_arrows' => $settings['skin_arrows'],
      'attach_skin_dots' => $settings['skin_dots'],
    );

    $build = array();
    foreach ($sets as $rows) {
      $items = $thumbs = array();
      foreach ($rows as $index => $row) {
        $view->row_index = $index;

        $thumb = array();
        $item = array(
          'type' => 'views',
          'caption' => array(),
        );

        if ($slick_markups) {
          // Add main image field if so configured.
          // @todo map raw values to work with lazyLoad.
          if ($slide_image = $settings['slide_image']) {
            $image = $this->getFieldData($row, $slide_image);

            // Not-empty behavior and filter fail, so add own check here.
            if (isset($image['raw']) && $image_rendered = $this->get_field($index, $slide_image)) {
              $bg_type = isset($image['raw']['type']) ? $image['raw']['type'] : 'image';
              $item['type'] = $bg_type;
              $item['slide'] = $image_rendered;
              $attach['attach_media'] = in_array($bg_type, array('video', 'audio'));
            }

            // Add thumbnail navigation if so configured.
            if ($slide_thumbnail = $settings['slide_thumbnail']) {
              $thumbnail = $this->getFieldData($row, $slide_thumbnail);
              if (isset($thumbnail['raw']) && $thumbnail_rendered = $this->get_field($index, $slide_thumbnail)) {
                $thumb['slide'] = $thumbnail_rendered;
              }
            }

            // Allows text-only thumbnail navigation, like regular tabs.
            if ($thumbnail_caption = $settings['thumbnail_caption']) {
              // Use Views UI "Rewrite results" to sanitize the caption.
              $thumb['caption']['data']['#markup'] = $this->get_field($index, $thumbnail_caption);
              if (!isset($thumb['slide'])) {
                $thumb['slide'] = array();
              }
            }
          }

          // Add all caption fields if so configured.
          if ($slide_captions = $settings['slide_caption']) {
            $slide_captions = is_array($slide_captions) ? array_filter($slide_captions) : (array) $slide_captions;

            $caption_items = array();
            foreach ($slide_captions as $key => $slide_caption) {
              $slide_caption_rendered = $this->get_field($index, $slide_caption);
              if (empty($slide_caption_rendered)) {
                continue;
              }

              if (in_array($slide_caption, array_values($keys))) {
                $caption_items[$key]['#markup'] = $slide_caption_rendered;
              }
            }
            if ($caption_items) {
              $item['caption']['data'] = $caption_items;
            }
          }

          // Add overlay field if so configured.
          if ($slide_overlay = $settings['slide_overlay']) {
            $overlay = $this->getFieldData($row, $slide_overlay);
            $overlay_type = isset($overlay['raw']['type']) ? $overlay['raw']['type'] : 'image';
            $attach['attach_media'] = in_array($overlay_type, array('video', 'audio'));
            $item['caption']['overlay']['#markup'] = $this->get_field($index, $slide_overlay);
          }

          // Add title field if so configured.
          if ($slide_title = $settings['slide_title']) {
            $item['caption']['title'] = filter_xss_admin($this->get_field($index, $slide_title));
          }

          // Add link field if so configured.
          if ($slide_link = $settings['slide_link']) {
            $item['caption']['link'] = $this->get_field($index, $slide_link);
          }

          // Add editor link field, Views takes care of the access control.
          if ($editor_link = $settings['editor_link']) {
            $item['caption']['editor']['#markup'] = $this->get_field($index, $editor_link);
          }

          // Add layout field if so configured.
          if ($slide_layout = $settings['slide_layout']) {
            // Slide layout may be a list field, or builtin layout options.
            if (strpos($slide_layout, 'field_') !== FALSE) {
              $item['caption']['layout'] = check_plain($this->get_field($index, $slide_layout));
            }
            else {
              $item['caption']['layout'] = check_plain($slide_layout);
            }
          }
        }
        else {
          $item['slide'] = $view->style_plugin->row_plugin->render($row);
        }

        // Main slide items.
        $items[] = $item;

        // Thumbnail slide items.
        if ($thumb) {
          $thumbs[] = $thumb;
        }
      }

      unset($view->row_index);

      // Build the Slick attributes.
      $slick_id = &drupal_static('slick_id', 0);
      $id = $settings['id'] ? $settings['id'] : drupal_clean_css_identifier("slick-views-{$view_name}-" . ++$slick_id);
      $thumbnail_id = $id . '-thumbnail';

      // Enforce ID for easy asNavFor selectors.
      $settings['attributes']['id'] = $id;
      $settings['content_attributes']['id'] = $id . '-slider';
      $settings['attributes']['class'][] = drupal_clean_css_identifier('slick--view--' . $view_name);

      // Add the settings.
      $settings['current_display'] = 'main';
      $settings['count'] = count($items);
      $is_asnavfor = $settings['optionset_thumbnail'] && $thumbs;
      $is_asnavfor_auto = $settings['asnavfor_auto'];

      if ($is_asnavfor) {
        $attach['attach_skin_thumbnail'] = $settings['skin_thumbnail'];
        $settings['asnavfor_target'] = $is_asnavfor_auto ? '#' . $thumbnail_id . '-slider' : $settings['asnavfor_main'];
      }

      // Build the Slick grid.
      if ($settings['grid']) {
        $visible_slides = $settings['visible_slides'];
        // Only if we do have a reasonable amount of grid items.
        if ($visible_slides && count($view->result) > $visible_slides) {
          $grid_items = array_chunk($items, $visible_slides, $settings['preserve_keys']);

          $grids = array();
          foreach ($grid_items as $delta => $grid_item) {
            $grids[] = array(
              '#theme' => 'slick_grid',
              '#items' => $grid_item,
              '#delta' => $delta,
              '#settings' => $settings,
            );
          }

          // Update the $items with grid chunks.
          $items = $grids;
        }
      }

      // Build the Slick single/main display.
      $slick[0] = array(
        '#theme' => 'slick',
        '#items' => $items,
        '#settings' => $settings,
        '#attached' => slick_attach($attach),
      );

      // Overrides common options to re-use a single optionset.
      if ($settings['override']) {
        $overridables = array();
        // Respect empty values, meaning FALSE.
        foreach ($settings['overridables'] as $key => $override) {
          $override = empty($override) ? FALSE : TRUE;
          $overridables[$key] = $override;
        }
        $slick[0]['#options'] = $overridables;
      }

      if ($is_asnavfor) {
        $settings['attributes']['id'] = $thumbnail_id;
        $settings['content_attributes']['id'] = $thumbnail_id . '-slider';
        $settings['asnavfor_target'] = $is_asnavfor_auto ? '#' . $id . '-slider' : $settings['asnavfor_thumbnail'];
        $settings['optionset'] = $settings['optionset_thumbnail'];
        $settings['current_display'] = 'thumbnail';

        // Build the Slick thumbnail/text navigation.
        $slick[1] = array(
          '#theme' => 'slick',
          '#items' => $thumbs,
          '#settings' => $settings,
        );
      }

      // Build the Slick.
      $build = array(
        '#theme' => $this->theme_functions(),
        '#view' => $view,
        '#options' => $this->options,
        '#rows' => $slick,
      );
    }

    return $build;
  }

}
