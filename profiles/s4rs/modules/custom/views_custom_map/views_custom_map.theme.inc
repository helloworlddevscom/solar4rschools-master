<?php

// $Id: views_custom_map.theme.inc 184 2009-05-27 00:57:57Z jhedstrom $

/**
 * @file
 * Theme functions for the Views Custom Map module.
 */

/**
 * Theme a custom map.
 */
function theme_views_custom_map($variables) {
  $points = $variables['points'];
  $map = $variables['map'];
  // Set div with map for the background.
  $attributes = array(
    'id' => 'views-custom-map',
    'style' => 'width: ' . $map['image_width'] . 'px; height: ' . $map['image_height'] . 'px; background: transparent url(' . url($map['image']) . ') no-repeat left top;',
    'class' => 'views-custom-map-map',
  );

  $map_attributes = drupal_attributes($attributes);

  $popups = $rendered_points = array();
  $i = 0;
  foreach ($points as $point) {
    $point->id = $i;
    $rendered_points[] = theme('views_custom_map_point', array('point' => $point));
    $i++;
  }

  // Add CSS.
  drupal_add_css(drupal_get_path('module', 'views_custom_map') . '/views_custom_map.css');
  drupal_add_js(drupal_get_path('module', 'views_custom_map') . '/views_custom_map.js', array('type' => 'footer', 'scope' => JS_DEFAULT));

  $rendered_points = theme('item_list', array('items' => $rendered_points));

  $map_div = <<<EOL
<div class="views-custom-map">
  <div$map_attributes>
    $rendered_points
  </div>
</div>
EOL;

  return $map_div;
}

/**
 * Theme a point for the map.
 */
function theme_views_custom_map_point($variables) {
  $point = $variables['point'];
  // This link is custom, and should go.
  $href = 'schools/' . strtolower($point->location_province);
  $attributes['style'] = 'left: ' . $point->x . '%; top: ' . $point->y . '%;';
  $attributes['class'] = 'views-custom-map-point';
  $attributes['id'] = 'views-custom-map-point-' . $point->id;
  $popup = theme('views_custom_map_popup', array('point' => $point));
  $title = '<span class="popup"><span class="popup-inner">' . $popup . '</span></span>';
  return l($title, $href, array('attributes' => $attributes, 'html' => TRUE));
}

/**
 * Theme pop-ups.
 */
function theme_views_custom_map_popup($variables) {
  $point = $variables['point'];
  // Also custom, and would need to go prior to release.
  $count = $point->nid;
  $text = format_plural($count, '1 project', '@count projects');
  $province = location_province_name('us', $point->location_province);
  return <<<EOL
    $province
    <span class="state-count">$text</span>
EOL;
}
