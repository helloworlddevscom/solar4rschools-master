<?php
/**
 * @file
 * Administrative forms and pages for Generation API.
 */

/**
 * Helper to set breadcrumb trail on our admin pages.
 *
 * @param array $generation_crumb
 *   Array of crumb-links that go after 'Generation API'. Should not include
 *   the current page.
 */
function _generation_set_admin_breadcrumb($generation_crumb = array()) {
  $breadcrumb = array_merge(array(
    l(t('Administration'), 'admin'),
    l(t('Configuration'), 'admin/config'),
    l(t('Generation API'), 'admin/config/generation'),
  ), $generation_crumb);
  drupal_set_breadcrumb($breadcrumb);
}

/**
 * Helper for provider modules to set breadcrumb trail on admin pages.
 *
 * @param array $provider_crumb
 *   Array of crumb-links that go after 'Providers'. Should not include
 *   the current page.
 */
function _generation_set_admin_provider_breadcrumb($provider_crumb = array()) {
  $breadcrumb = array_merge(array(
    l(t('Providers'), 'admin/config/generation/providers'),
  ), $provider_crumb);
  _generation_set_admin_breadcrumb($breadcrumb);
}

/**
 * Page callback: Top-level admin page.
 *
 * Path: admin/config/generation
 */
function generation_admin_page() {
  $links = array(
    'variables' => array(
      'title' => t('Variables'),
      'href' => 'admin/config/generation/variables',
    ),
    'variable-presets' => array(
      'title' => t('Variable presets'),
      'href' => 'admin/config/generation/variable-presets/list',
    ),
  );
  _generation_set_admin_breadcrumb(array());
  return theme('links', array('links' => $links, 'attributes' => array('class' => 'admin-list')));
}

/**
 * Page callback: Provider listing page.
 *
 * Path: admin/config/generation/providers
 */
function generation_provider_list_page() {
  $links = array();
  foreach (generation_get_provider_info_all() as $module => $info) {
    $links[$module] = array(
      'title' => $info['name'],
      'href' => $info['configure'],
    );
  }
  _generation_set_admin_breadcrumb(array());
  return theme('links', array('links' => $links, 'attributes' => array('class' => 'admin-list')));
}

/**
 * Page callback: Variable listing page.
 *
 * Path: admin/config/generation/variables
 */
function generation_variable_list_page() {
  $per_page = 30;
  $header = array(t('Provider'), t('Variable name'), t('Type'));
  $rows = array();

  drupal_set_title(t('All variables'));

  // Refresh variables first. This acts to bootstrap variables table and to add
  // new variables later.
  module_load_include('inc', 'generation');
  _generation_refresh_variables();

  $providers = generation_get_provider_info_all();
  foreach (_generation_get_variables($per_page) as $variable_id => $variable) {
    $row = array(
      check_plain($providers[$variable->module]['name']),
      l($variable->name, 'admin/config/generation/variables/' . $variable_id),
      check_plain($variable->type),
    );
    $rows[] = $row;
  }
  _generation_set_admin_breadcrumb(array());
  return theme('table', array('header' => $header, 'rows' => $rows)) . theme('pager', array('tags' => NULL, 'element' => 0));
}

/**
 * Page callback: Variable detail page.
 *
 * @param object $variable
 *   Variable object.
 *
 * Path: admin/config/generation/variables/%generation_variable
 */
function generation_variable_detail_page($variable) {
  drupal_set_title($variable->name);

  // Basic variable information.
  $providers = generation_get_provider_info_all();
  $output = '<h2>' . t('Variable provider') . '</h2>';
  $output .= '<p>' . $providers[$variable->module]['name'] . '</p>';
  $output .= '<h2>' . t('Presets for variable %name', array('%name' => $variable->name)) .
    '</h2>';

  // Add table of presets that exist for this variable.
  $table = generation_variable_preset_table($variable);
  if ($table) {
    $output .= $table;
  }
  else {
    $output .= '<p>' . t('No presets yet created for %variable.', array('%variable' => $variable->name)) . '<p>';
  }
  $output .= '<p>' . l(t('Add new preset for this variable'), 'admin/config/generation/variable-presets/add',
    array('query' => array('variable_id' => $variable->variable_id))) . '</p>';
  _generation_set_admin_breadcrumb(array(l(t('Variables'), 'admin/config/generation/variables')));
  return $output;
}

/**
 * Page callback: Variable preset listing page.
 *
 * Path: admin/config/generation/variables/presets/list
 */
function generation_variable_preset_list_page() {
  drupal_set_title(t('All presets'));
  $output = generation_variable_preset_table();
  if (!$output) {
    $output = '<p>' . t('No presets yet created.') . '</p>';
    $output .= '<p>' . l(t('Add new preset'), 'admin/config/generation/variable-presets/add') . '</p>';
  }
  _generation_set_admin_breadcrumb(array(l(t('Variable presets'), 'admin/config/generation/variable-presets')));
  return $output;
}

/**
 * Page callback: Charts clicks/usage log table page.
 *
 * Path: admin/config/generation/kiosks-log-table-active
 */
function generation_charts_log_table_active_page() {

  // Load all generation_site entities.
  $all_sites = db_select('eck_generation_site', 's')
    ->fields('s', array(
      'id',
      'title',
      'type'
    ))
//    ->condition('status', 1, '=')
    ->execute()
    ->fetchAll();

  // Load generation_site entities that have clicks/usage data.
  $active_sites = db_select('generation_charts_log', 'l')
    ->fields('l')
    ->execute()
    ->fetchAll();

  // Loop over all generation_site entities and loop over all
  // generation_site entities that have clicks/usage data.
  // Get site name.
  foreach ($all_sites as $site) {
    foreach ($active_sites as $active_site) {
      if ($site->id == $active_site->site_id) {
        // Get site name.
        $active_site->site_name = $site->title;

        // Get site type.
        $active_site->site_type = $site->type;

        // Construct path to generation_site entity.
        $active_site->site_url_path = '/admin/structure/entity-type/generation_site/' . $site->type . '/' . $site->id . '/edit';

        break;
      }
    }
  }

  // Return no results message if empty.
  if (empty($active_sites)) {
    return '<p>There are no active sites/kiosks.</p>';
  }

  // Get kiosk node entities associated with generation_site entities via field_data_collection_site.
  foreach ($active_sites as $active_site) {
    $kiosks = db_select('field_data_field_data_collection_site', 'f')
      ->fields('f', array(
        'entity_id',
      ))
      ->condition('bundle', 'kiosk', '=')
      ->condition('field_data_collection_site_target_id', $active_site->site_id, '=')
      ->execute()
      ->fetchAll();

    // Load kiosk nodes.
    if (!empty($kiosks)) {
      $kiosks_data = array();

      foreach ($kiosks as $kiosk) {
        $kiosk_data = new stdClass();

        $kiosk_node = node_load($kiosk->entity_id);

        // Get title of kiosk node.
        $kiosk_data->kiosk_name = $kiosk_node->title;

        // Construct path to kiosk node.
        $kiosk_data->kiosk_url_path = '/node/' . $kiosk->entity_id . '/edit';

        array_push($kiosks_data, $kiosk_data);
      }

      $active_site->kiosks = $kiosks_data;
    }
  }


  // Order generation_sites/kiosks alphabetically.
  usort($active_sites, function($a, $b) {return strcmp($a->kiosks[0]->kiosk_name, $b->kiosks[0]->kiosk_name);});

  // Construct table for active generation_sites/kiosks.
  $output = '<table>';
  $output .= '<thead>Active Generation Sites/Kiosks</thead>';
  $output .= '<tbody>';
  $output .= '<tr>';
  $output .= '<th>Kiosk(s)</th>';
  $output .= '<th>Generation Site</th>';
  $output .= '<th>Type</th>';
  $output .= '<th>Clicks on Today tab</th>';
  $output .= '<th>Clicks on Week tab</th>';
  $output .= '<th>Clicks on Month tab</th>';
  $output .= '<th>Clicks on Year tab</th>';
  $output .= '<th>Clicks on Lifetime tab</th>';
  $output .= '</tr>';

  foreach ($active_sites as $active_site) {
    $output .= '<tr>';
    if (isset($active_site->kiosks)) {
      $output .= '<td>';
      foreach($active_site->kiosks as $kiosk) {
        $output .= '<a href="' . $kiosk->kiosk_url_path . '" target="_blank">' . $kiosk->kiosk_name . '</a><br>';
      }
      $output .= '</td>';
    }
    else {
      $output .= '<td>No Kiosks are associated with this Generation Site.</td>';
    }
    $output .= '<td><a href="' . $active_site->site_url_path . '" target="_blank">' . $active_site->site_name . '</a></td>';
    $output .= '<td>' . $active_site->site_type . '</td>';
    $output .= '<td>' . $active_site->load_count_today . '</td>';
    $output .= '<td>' . $active_site->load_count_week . '</td>';
    $output .= '<td>' . $active_site->load_count_month . '</td>';
    $output .= '<td>' . $active_site->load_count_year . '</td>';
    $output .= '<td>' . $active_site->load_count_lifetime . '</td>';
    $output .= '</tr>';
  }

  $output .= '</tbody>';
  $output .= '</table>';

  return $output;
}

/**
 * Page callback: Inactive kiosks/sites based on no clicks/usage in log table page.
 *
 * Path: admin/config/generation/kiosks-log-table-inactive
 */
function generation_charts_log_table_inactive_page() {

  // Load all generation_site entities.
  $all_sites = db_select('eck_generation_site', 's')
    ->fields('s', array(
      'id',
      'title',
      'type'
    ))
//    ->condition('status', 1, '=')
    ->execute()
    ->fetchAll();

  // Load generation_site entities that have clicks/usage data.
  $active_sites = db_select('generation_charts_log', 'l')
    ->fields('l')
    ->execute()
    ->fetchAll();

  // Loop over all generation_site entities and loop over all
  // generation_site entities that have clicks/usage data.
  $inactive_sites = array();
  foreach ($all_sites as $site) {
    $site_active = false;
    foreach ($active_sites as $active_site) {
      // generation_site is in logs.
      if ($site->id == $active_site->site_id) {
        $site_active = true;

        break;
      }
    }
    // If generation_site is not in logs that means it has no clicks.
    // Add it to list of unused generation_sites/kiosks.
    if (!$site_active) {
      $inactive_site = new stdClass;
      $inactive_site->site_id = $site->id;
      $inactive_site->site_name = $site->title;
      $inactive_site->site_type = $site->type;
      // Construct path to generation_site entity.
      $inactive_site->site_url_path = '/admin/structure/entity-type/generation_site/' . $site->type . '/' . $site->id . '/edit';
      $inactive_site->load_count_today = '0';
      $inactive_site->load_count_week = '0';
      $inactive_site->load_count_month = '0';
      $inactive_site->load_count_year = '0';
      $inactive_site->load_count_lifetime = '0';
      $inactive_sites[] = $inactive_site;
    }
  }

  // Return no results message if empty.
  if (empty($inactive_sites)) {
    return '<p>There are no inactive sites/kiosks.</p>';
  }

  // Get kiosk node entities associated with generation_site entities via field_data_collection_site.
  foreach ($inactive_sites as $inactive_site) {
    $kiosks = db_select('field_data_field_data_collection_site', 'f')
      ->fields('f', array(
        'entity_id',
      ))
      ->condition('bundle', 'kiosk', '=')
      ->condition('field_data_collection_site_target_id', $inactive_site->site_id, '=')
      ->execute()
      ->fetchAll();

    // Load kiosk nodes.
    if (!empty($kiosks)) {
      $kiosks_data = array();

      foreach ($kiosks as $kiosk) {
        $kiosk_data = new stdClass();

        $kiosk_node = node_load($kiosk->entity_id);

        // Get title of kiosk node.
        $kiosk_data->kiosk_name = $kiosk_node->title;

        // Construct path to kiosk node.
        $kiosk_data->kiosk_url_path = '/node/' . $kiosk->entity_id . '/edit';

        array_push($kiosks_data, $kiosk_data);
      }

      $inactive_site->kiosks = $kiosks_data;
    }
  }


  // Order generation_sites/kiosks alphabetically.
  usort($inactive_sites, function($a, $b) {return strcmp($a->site_name, $b->site_name);});

  // Construct table for inactive geneartion_sites/kiosks.
  $output = '<table>';
  $output .= '<thead>Inactive Generation Sites/Kiosks</thead>';
  $output .= '<tbody>';
  $output .= '<tr>';
  $output .= '<th>Kiosk(s)</th>';
  $output .= '<th>Generation Site</th>';
  $output .= '<th>Type</th>';
  $output .= '<th>Clicks on Today tab</th>';
  $output .= '<th>Clicks on Week tab</th>';
  $output .= '<th>Clicks on Month tab</th>';
  $output .= '<th>Clicks on Year tab</th>';
  $output .= '<th>Clicks on Lifetime tab</th>';
  $output .= '</tr>';

  foreach ($inactive_sites as $inactive_site) {
    $output .= '<tr>';
    if (isset($inactive_site->kiosks)) {
      $output .= '<td>';
      foreach($inactive_site->kiosks as $kiosk) {
        $output .= '<a href="' . $kiosk->kiosk_url_path . '" target="_blank">' . $kiosk->kiosk_name . '</a><br>';
      }
      $output .= '</td>';
    }
    else {
      $output .= '<td>No Kiosks are associated with this Generation Site.</td>';
    }
    $output .= '<td><a href="' . $inactive_site->site_url_path . '" target="_blank">' . $inactive_site->site_name . '</a></td>';
    $output .= '<td>' . $inactive_site->site_type . '</td>';
    $output .= '<td>' . $inactive_site->load_count_today . '</td>';
    $output .= '<td>' . $inactive_site->load_count_week . '</td>';
    $output .= '<td>' . $inactive_site->load_count_month . '</td>';
    $output .= '<td>' . $inactive_site->load_count_year . '</td>';
    $output .= '<td>' . $inactive_site->load_count_lifetime . '</td>';
    $output .= '</tr>';
  }

  $output .= '</tbody>';
  $output .= '</table>';

  return $output;
}

/**
 * Generates HTML table of variable presets, optionally filtered.
 *
 * Includes either all presets, or just the presets for a specific variable (if
 * $variable is supplied).
 *
 * @param object $variable
 *   (optional) Variable object.
 *
 * @return string
 *   Themed output of table, or FALSE if no presets exist.
 */
function generation_variable_preset_table($variable = NULL) {
  module_load_include('inc', 'generation');
  $presets = _generation_get_variable_presets($variable);
  if (count($presets) > 0) {
    $header = array(
      t('Alias'),
      t('Function'),
      t('Chart type'),
      t('Units'),
      array(
        'data' => t('Operations'),
        'colspan' => '2',
      ),
    );

    // If we're not listing for a specific variable, include a Variable column.
    if (!isset($variable)) {
      array_unshift($header, t('Variable'));
    }

    $rows = array();
    foreach ($presets as $preset) {
      $edit_link = l(t('edit'), 'admin/config/generation/variable-presets/' . $preset->preset_id . '/edit');
      $delete_link = l(t('delete'), 'admin/config/generation/variable-presets/' . $preset->preset_id . '/delete');
      $row = array(
        check_plain($preset->alias),
        check_plain($preset->function),
        check_plain($preset->chart_type),
        check_plain($preset->units),
        $edit_link,
        $delete_link,
      );

      // If we're not listing for a specific variable, include the variable
      // name in the first column.
      if (!isset($variable)) {
        $variable = generation_variable_load($preset->variable_id);
        array_unshift($row, check_plain($variable->name));
        unset($variable);
      }

      $rows[] = $row;
    }
    return theme('table', array('header' => $header, 'rows' => $rows));
  }
  return FALSE;
}

/**
 * Page callback: Form constructor for variable preset creation form.
 *
 * Path: admin/config/generation/variable-presets/add
 */
function generation_variable_preset_add_form_page() {
  $preset = generation_variable_preset_new();
  $variable = NULL;
  if (isset($_GET['variable_id']) && is_numeric($_GET['variable_id'])) {
    $variable = generation_variable_load($_GET['variable_id']);
    $preset->variable_id = $variable->variable_id;
    drupal_set_title(t('Create new variable preset for %name', array('%name' => $variable->name)), PASS_THROUGH);
  }
  else {
    drupal_set_title(t('Create new variable preset'));
  }
  _generation_set_admin_breadcrumb(array(l(t('Variable presets'), 'admin/config/generation/variable-presets')));
  return drupal_get_form('generation_variable_preset_edit_form', $preset);
}

/**
 * Page callback: Variable preset edit page.
 *
 * Path:
 * admin/config/generation/variable-presets/%generation_variable_preset/edit
 */
function generation_variable_preset_edit_form_page($preset) {
  _generation_set_admin_breadcrumb(array(l(t('Variable presets'), 'admin/config/generation/variable-presets')));
  return drupal_get_form('generation_variable_preset_edit_form', $preset);
}

/**
 * Form constructor for variable preset edit form.
 *
 * @see generation_variable_preset_edit_form_page()
 */
function generation_variable_preset_edit_form($form, $form_state, $preset) {
  module_load_include('inc', 'generation');

  // TODO: Port AHAH.
  $form = array();
  $form['#submit'][] = 'generation_variable_preset_edit_form_submit';

  $form['preset'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
    '#prefix' => '<div id="variable-preset-wrapper">',
    '#suffix' => '</div>',
  );

  $form['preset']['preset_id'] = array(
    '#type' => 'hidden',
    '#value' => $preset->preset_id,
  );
  $form['preset']['variable_id'] = array(
    '#type' => 'select',
    '#title' => t('Variable'),
    '#required' => TRUE,
    '#ahah' => array(
      'event' => 'change',
      // This is the "magical path". Note that the parameter is an array of
      // the parents of the form item of the wrapper div!
      // @todo: Port to D7!
      'path' => '',
      'wrapper' => 'variable-preset-wrapper',
      'keypress' => TRUE,
    ),
    '#options' => array(0 => t('Please select a variable')),
  );
  $provider_info_all = generation_get_provider_info_all();
  foreach (_generation_get_variables() as $variable) {
    $provider_name = $provider_info_all[$variable->module]['name'];
    $display = t('@provider: @variable', array(
      '@provider' => $provider_name,
      '@variable' => $variable->name,
    ));
    $form['preset']['variable_id']['#options'][$variable->variable_id] = $display;
  }

  $variable = NULL;
  $variable_id = FALSE;
  if (isset($preset->variable_id)) {
    $variable_id = $preset->variable_id;
  }
  elseif (isset($form_state['storage']['preset']['variable_id'])) {
    $variable_id = (int) $form_state['storage']['preset']['variable_id'];
  }

  if ($variable_id && $variable = generation_variable_load($variable_id)) {
    // We don't want the AHAH reloading most of the form with the variable
    // dropdown selection being changed, to keep this form logic simple.
    $form['preset']['variable_id']['#default_value'] = $variable_id;
    $form['preset']['variable_id']['#disabled'] = TRUE;
  }

  if (is_object($variable)) {
    $form['preset']['alias'] = array(
      '#type' => 'textfield',
      '#title' => t('Alias'),
      '#description' => t('The name you wish to show to site visitors.'),
      '#required' => TRUE,
      '#maxlength' => 96,
      '#default_value' => $preset->alias,
    );

    $form['preset']['description'] = array(
      '#type' => 'textarea',
      '#title' => t('Description'),
      '#description' => t('A description for this alias to show site visitors.'),
      '#required' => FALSE,
      '#default_value' => $preset->description,
    );

    $form['preset']['function'] = array(
      '#type' => 'select',
      '#title' => t('Function'),
      '#required' => TRUE,
      '#options' => _generation_get_possible_functions($variable),
      '#default_value' => $preset->function,
    );

    $form['preset']['chart_type'] = array(
      '#type' => 'select',
      '#title' => t('Chart type'),
      '#required' => TRUE,
      '#default_value' => $preset->chart_type,
    );
    if (module_exists('generation_charts')) {
      $form['preset']['chart_type']['#options'] = generation_charts_chart_types();
    }
    else {
      $form['preset']['chart_type']['#options'] = array($preset->function => t('Current setting'));
    }

    // Build options for units.
    $raw_units = _generation_get_possible_units($variable);
    $unit_options = array();
    foreach ($raw_units as $key => $raw_unit) {
      $unit_options[$key] = t('!unit (!label)', array('!unit' => $key, '!label' => $raw_unit['label']));
    }

    $form['preset']['units'] = array(
      '#type' => 'select',
      '#title' => t('Display units'),
      '#options' => $unit_options,
      '#description' => t('Units to request from the data provider API for the variable.'),
      '#default_value' => $preset->units,
    );
  }

  $form['preset']['actions'] = array();
  $form['preset']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Form validation handler for generation_variable_preset_edit_form().
 */
function generation_variable_preset_edit_form_validate($form, &$form_state) {
  $preset = (object) $form_state['values']['preset'];
  if (!generation_variable_load((int) $preset->variable_id)) {
    form_set_error('variable_id', t('Unable to load selected variable.'));
  }
}

/**
 * Form submission handler for generation_variable_preset_edit_form().
 */
function generation_variable_preset_edit_form_submit($form, &$form_state) {
  $preset = (object) $form_state['values']['preset'];
  if (!empty($preset->alias) && !empty($preset->function) && !empty($preset->units)) {
    generation_variable_preset_save($preset);
    $form_state['redirect'] = 'admin/config/generation/variable-presets/' . $preset->preset_id . '/edit';
  }
}

/**
 * Page callback: Form constructor for variable preset deletion form.
 *
 * Path:
 * admin/config/generation/variable-presets/%generation_variable_preset/delete
 */
function generation_variable_preset_delete_form($form, &$form_state, $preset) {
  $form['#preset'] = $preset;
  $variable = generation_variable_load($preset->variable_id);
  $form['#variable'] = $variable;

  $question = t('Are you sure you want to delete preset %alias for the %module variable %variable?', array(
    '%alias' => $preset->alias,
    '%module' => $variable->module,
    '%variable' => $variable->name,
    '!id' => $preset->preset_id,
  ));
  $path = 'admin/config/generation/variables/' . $variable->variable_id;
  $description = t('Any references to this preset will be removed. All sites collecting data using this preset will stop doing so.');
  $yes = t('Delete preset');
  $no = t('Cancel');
  return confirm_form($form, $question, $path, $description, $yes, $no);
}

/**
 * Form submission handler for generation_variable_preset_delete_form().
 */
function generation_variable_preset_delete_form_submit($form, &$form_state) {
  generation_variable_preset_delete($form['#preset']);
  $variable_id = $form['#variable']->variable_id;
  $form_state['redirect'] = 'admin/config/generation/variables/' . $variable_id;
}

/**
 * Theme the device presets form into a table.
 */
function theme_generation_device_presets($variables) {
  $form = $variables['form'];
  drupal_add_css(drupal_get_path('module', 'generation') . '/css/admin.css');

  $output = '';
  $header = array(
    t('Delete'),
    t('Device'),
    t('Variable'),
    t('Alias'),
    t('Function'),
    t('Chart type'),
    t('Units'),
    t('Description'),
  );

  foreach (element_children($form['device_id']) as $key) {
    $row = array();
    $row[] = drupal_render($form['delete'][$key]);
    $row[] = drupal_render($form['device_id'][$key]);
    $row[] = drupal_render($form['variable_id'][$key]);
    $row[] = drupal_render($form['alias'][$key]);
    $row[] = drupal_render($form['function'][$key]);
    $row[] = drupal_render($form['chart_type'][$key]);
    $row[] = drupal_render($form['units'][$key]);
    $row[] = drupal_render($form['description'][$key]);
    $rows[] = $row;
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form);
  return $output;
}

