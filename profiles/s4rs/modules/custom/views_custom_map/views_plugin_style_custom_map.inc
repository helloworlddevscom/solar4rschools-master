<?php

// $Id: views_plugin_style_custom_map.inc 149 2009-05-11 19:51:00Z jhedstrom $

/**
 * @file
 * Custom map style plugin for Views.
 */

/**
 * Extend the views_plugin_style class for the Custom Map module.
 */
class views_plugin_style_custom_map extends views_plugin_style {

  public $map;

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    // These options are for Mercator projections.
    $options['x_min'] = array('default' => -100);
    $options['y_min'] = array('default' => -40);
    $options['x_max'] = array('default' => 100);
    $options['y_max'] = array('default' => 40);

    // These options are for Lambert Conformal Conic projections.
    $options['lambert_center_lat'] = array('default' => 0);
    $options['lambert_center_lon'] = array('default' => 0);
    $options['lambert_std_parallel_1'] = array('default' => -180);
    $options['lambert_std_parallel_2'] = array('default' => 0);

    $options['map_image_path'] = array('default' => '');
    $options['fields'] = array('default' => array());
    $options['image_width'] = array('default' => FALSE);
    $options['image_height'] = array('default' => FALSE);

    $options['map_projection'] = array('default' => 'mercator');

    return $options;
  }

  /**
   * Options Form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['grouping']);

    $form['image_bounds'] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom image bounding box'),
      '#description' => t('The latitude and longitude corresponding to the boundary defined by the custom image borders.'),
    );
    $form['image_bounds']['x_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Minimum longitude'),
      '#default_value' => $this->options['x_min'],
      '#size' => 10,
      '#required' => TRUE,
    );
    $form['image_bounds']['y_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Minimum latitude'),
      '#default_value' => $this->options['y_min'],
      '#size' => 10,
      '#required' => TRUE,
    );
    $form['image_bounds']['x_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum longitude'),
      '#default_value' => $this->options['x_max'],
      '#size' => 10,
      '#required' => TRUE,
    );
    $form['image_bounds']['y_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum latitude'),
      '#default_value' => $this->options['y_max'],
      '#size' => 10,
      '#required' => TRUE,
    );

    $form['lambert_bounds'] = array(
      '#type' => 'fieldset',
      '#title' => t('Lambert Conformal Conic bounds'),
      '#description' => t('These are only needed if the map is a Lambert Conformal Conic projection.'),
    );
    $form['lambert_bounds']['lambert_center_lat'] = array(
      '#type' => 'textfield',
      '#title' => t('Origin Latitude'),
      '#default_value' => $this->options['lambert_center_lat'],
      '#size' => 10,
    );
    $form['lambert_bounds']['lambert_center_lon'] = array(
      '#type' => 'textfield',
      '#title' => t('Origin Longitude'),
      '#default_value' => $this->options['lambert_center_lon'],
      '#size' => 10,
    );

    $form['lambert_bounds']['lambert_std_parallel_1'] = array(
      '#type' => 'textfield',
      '#title' => t('Standard Parallel 1'),
      '#default_value' => $this->options['lambert_std_parallel_1'],
      '#size' => 10,
    );
    $form['lambert_bounds']['lambert_std_parallel_2'] = array(
      '#type' => 'textfield',
      '#title' => t('Standard Parallel 2'),
      '#default_value' => $this->options['lambert_std_parallel_2'],
      '#size' => 10,
    );

    $form['map_image_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to custom map image'),
      '#description' => t('This should be a Drupal path. For example, %path.', array('%path' => 'sites/all/files/map-image.png')),
      '#required' => TRUE,
      '#default_value' => $this->options['map_image_path'],
    );
    $form['map_projection'] = array(
      '#type' => 'radios',
      '#title' => t('Map Projection'),
      '#description' => t('This must match the projection used to create the map or the points will not line up properly on the map.'),
      '#required' => TRUE,
      '#default_value' => $this->options['map_projection'],
      '#options' => array(
        'mercator' => t('Mercator'),
        'lambert' => t('Lambert Conformal Conic'),
        'custom' => t('Custom'),
      ),
    );

    $form['image_width'] = array(
      '#type' => 'hidden',
      '#value' => $this->options['image_width'],
    );
    $form['image_height'] = array(
      '#type' => 'hidden',
      '#value' => $this->options['image_height'],
    );
  }

  function options_validate(&$form, &$form_state) {
    // Make sure image is readable.
    $path = $form_state['values']['style_options']['map_image_path'];
    if (!file_exists($path)) {
      form_set_error('map_image_path', t('Image does not exist at %path.', array('%path' => $path)));
      return;
    }

    // @todo: Verify that the bounding box has sensible values.
  }

  function options_submit(&$form, &$form_state) {
    foreach ($form_state['values']['style_options']['image_bounds'] as $key => $value) {
      $form_state['values']['style_options'][$key] = $value;
    }
    unset($form_state['values']['style_options']['image_bounds']);
    foreach ($form_state['values']['style_options']['lambert_bounds'] as $key => $value) {
      $form_state['values']['style_options'][$key] = $value;
    }
    unset($form_state['values']['style_options']['lambert_bounds']);

    // Set width and height of image.
    $image = imageapi_image_open($form_state['values']['style_options']['map_image_path']);
    $form_state['values']['style_options']['image_width'] = $image->info['width'];
    $form_state['values']['style_options']['image_height'] = $image->info['height'];
  }

  function render() {

    // Don't allow preview on view building page since it won't work properly
    // due to javascript issues.
    if (arg(0) == 'admin' && arg(1) == 'build' && arg(2) == 'views') {
      $message = t('Preview disabled due to javascript conflicts with views.');
      return '<div class="messages error">' . $message . '</div>';
    }


    $options = $this->view->style_plugin->options;

    switch ($options['map_projection']) {
      case 'custom':
        // Convert width and height to Mercator projection.
        $map = array();
        $map['image_width'] = $options['image_width'];
        $map['image_height'] = $options['image_height'];
        $map['image'] = $options['map_image_path'];
        $this->map = $map;

        $points = $this->view->result;
        // @fixme: this is custom, and should go.
        module_load_include('inc', 'os_state_center');
        foreach ($points as $key => $point) {
          // Some view results may have no location information. Remove them to
          // avoid putting a pin at 0, 0 (off the map).
          if (empty($point->location_province)) {
            unset($points[$key]);
            continue;
          }

          // Get center point.
          list($point->x, $point->y) = os_state_center_center(strtoupper($point->location_province));
          // Convert to percentage.
          $point->x *= 100;
          $point->y *= 100;
        }
        break;

      case 'lambert':
        // Convert to Lambert Conformal Conic projection.

        $map = array();
        $map['origin_lat'] = $options['lambert_center_lat'];
        $map['origin_lon'] = $options['lambert_center_lon'];
        $map['parallel_1'] = $options['lambert_std_parallel_1'];
        $map['parallel_2'] = $options['lambert_std_parallel_2'];

        $map['image_width'] = $options['image_width'];
        $map['image_height'] = $options['image_height'];
        $map['image'] = $options['map_image_path'];
        $map['width'] = deg2rad($options['x_max']) - deg2rad($options['x_min']);
        $map['height'] = asinh(tan(deg2rad($options['y_max']))) - asinh(tan(deg2rad($options['y_min'])));
        $map['origin'] = asinh(tan(deg2rad($options['y_min'])));
        $map['ratio'] = $map['width'] / $map['height'];

        $this->map = $map;

        $points = $this->view->result;
        // @fixme: this is custom, and should go.
        module_load_include('inc', 'os_state_center');
        foreach ($points as $point) {
          // Get center point.
          list($point->latitude, $point->longitude) = os_state_center_center(strtoupper($point->location_province));
          $this->_to_lambert($point);
        }

        break;
      case 'mercator':
      default:
        // Convert width and height to Mercator projection.
        $map = array();
        $map['x_min'] = $options['x_min'];
        $map['y_min'] = $options['y_min'];
        $map['x_max'] = $options['x_max'];
        $map['y_max'] = $options['y_max'];
        $map['image_width'] = $options['image_width'];
        $map['image_height'] = $options['image_height'];
        $map['image'] = $options['map_image_path'];
        $map['width'] = deg2rad($options['x_max']) - deg2rad($options['x_min']);
        $map['height'] = asinh(tan(deg2rad($options['y_max']))) - asinh(tan(deg2rad($options['y_min'])));
        $map['origin'] = asinh(tan(deg2rad($options['y_min'])));
        $map['ratio'] = $map['width'] / $map['height'];

        $this->map = $map;

        $points = $this->view->result;
        // @fixme: this is custom, and should go.
        module_load_include('inc', 'os_state_center');
        foreach ($points as $point) {
          // Get center point.
          list($point->latitude, $point->longitude) = os_state_center_center(strtoupper($point->location_province));
          $this->_to_mercator($point);
        }
    }
    return theme('views_custom_map', array('points' => $points, 'map' => $this->map));
  }

  function _to_lambert($point) {

    $phi = deg2rad($point->latitude);
    $phi_1 = deg2rad($this->map['parallel_1']);
    $phi_2 = deg2rad($this->map['parallel_2']);
    $lamda = deg2rad($point->longitude);
    $phi_o = deg2rad($this->map['origin_lat']);
    $lamda_o = deg2rad($this->map['origin_lon']);
    $e2 = M_E * M_E;
    $equatorial_radius = 6378137; // From WGS 84.

    $m1 = cos($phi_1) / sqrt(( 1 - $e2 * sin($phi_1) * sin($phi_1)));
    $m2 = cos($phi_2) / sqrt(( 1 - $e2 * sin($phi_2) * sin($phi_2)));
    $t1 = tan((M_PI / 4) -($phi_1 / 2)) / pow(( ( 1 - M_E * sin($phi_1) ) / ( 1 + M_E * sin($phi_1) )), M_E / 2);
    $t2 = tan((M_PI / 4) -($phi_2 / 2)) / pow(( ( 1 - M_E * sin($phi_2) ) / ( 1 + M_E * sin($phi_2) )), M_E / 2);
    $to = tan((M_PI / 4) -($phi_o / 2)) / pow(( ( 1 - M_E * sin($phi_o) ) / ( 1 + M_E * sin($phi_o) )), M_E / 2);
    $t  = tan((M_PI / 4) -($phi / 2)) / pow(( ( 1 - M_E * sin($phi ) ) / ( 1 + M_E * sin($phi ) )), M_E / 2);
    $n	= (log($m1) -log($m2)) / (log($t1) -log($t2));
    $F	= $m1 / ($n * pow($t1, $n));
    $rf	= $equatorial_radius * $F * pow($to, $n);
    $r	= $equatorial_radius * $F * pow($t, $n);
    $theta = $n * ($lamda - $lamda_o);

    $lcc_easting = $r * sin($theta);
    $lcc_northing = $rf - $r * cos($theta);

  }

  function _to_mercator($point) {
    $x = $this->_long_to_x($point->longitude);
    $x_ratio = $x / $this->map['width'];
    $point->x = 100 * $x_ratio;

    $y = $this->_lat_to_y($point->latitude);
    $y_ratio = $y / $this->map['height'];
    $point->y = 100 - 100 * $y_ratio;
  }

  function _lat_to_y($lat) {
    $y = asinh(tan(deg2rad($lat))) - $this->map['origin'];
    return $y;
  }

  function _long_to_x($long) {
    $x = deg2rad($long) - deg2rad($this->map['x_min']);
    return $x;
  }
}
