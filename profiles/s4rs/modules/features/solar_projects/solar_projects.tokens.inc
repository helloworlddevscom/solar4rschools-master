<?php

/**
 * @file
 * Builds tokens related to projects.
 */

/**
 * Implements hook_token_info().
 *
 * Adds tokens for project-specific information.
 */
function solar_projects_token_info() {
  $info = array();

  // Add any new tokens.
  $info['tokens']['site']['project-count'] = array(
    'name' => 'Project count',
    'description' => t('Total count of projects currently referenced in the url.'),
  );

  $info['tokens']['site']['project-count-states'] = array(
    'name' => 'States count',
    'description' => t('Total count of states for projects currently referenced in the url.'),
  );

  $info['tokens']['site']['project-count-classrooms'] = array(
    'name' => 'Classroom count',
    'description' => t('Total count of classrooms for projects currently referenced in the url.'),
  );

  $info['tokens']['site']['project-generation'] = array(
    'name' => 'Total generation',
    'description' => t('Total lifetime generation for projects currently referenced in the url.'),
  );

  // Return them.
  return $info;
}

/**
 * Implements hook_tokens().
 *
 * Displays tokens for project-specific information.
 */
function solar_projects_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      $element = FALSE;

      switch ($name) {
        case 'project-count':
          $element = 0;

          $query = db_select('node', 'node')
            ->condition('node.type', 'project')
            ->condition('node.status', '1');

          $query->addExpression('COUNT(nid)', 'value');

          $element = $query->execute()->fetchField();

          break;

        case 'project-count-states':
          $element = _generation_equation_query('', 'field_data_field_project_location', 'fpl', 'COUNT(DISTINCT field_project_location_administrative_area)');
          break;

        case 'project-count-classrooms':
          $element = _generation_equation_query('', 'field_data_field_classrooms_reached', 'fcr', 'SUM(field_classrooms_reached_value)');
          break;

        case 'project-generation':
          $data = _generation_stats_get_instant_summary(NULL, TRUE);
          $element = isset($data['formatted']['generation']) ? $data['formatted']['generation'] : 0;
          break;
      }

      if ($element) {
        $render = array(
          '#theme' => 'html_tag',
          '#tag' => 'span',
          '#attributes' => array('class' => array('value')),
          '#value' => $element,
        );
        $replacements[$original] = drupal_render($render);
      }
    }
  }

  // Return the replacements.
  return $replacements;
}
