<?php
/**
 * @file
 * Catch-all for everything that isn't needed on every page load but doesn't
 * belong in any of the other include files.
 */

/**
 * Rounds downward the given datetime to a 15 minute multiple.
 */
function _generation_round_date($date, $minutes = 15) {
  // "0 - (...)" below because CodeSniffer doesn't like -(...), nor - (...).
  $stamp = $date->format('U');
  $diff = 0 - ($stamp % (60 * $minutes));

  $rounded = clone $date;
  $rounded->modify($diff . ' seconds');
  return $rounded;
}

/**
 * Convert absolute direction (degrees North) to common terminology.
 *
 * @param float $direction
 *   Compass direction, in degrees North.
 */
function _generation_compass_to_fuzzy($direction) {
  if ($direction < 0) {
    // Nothing to do.
  }
  elseif (($direction > 337.5) || ($direction <= 22.5)) {
    $fuzzy = 'N';
  }
  elseif (($direction > 22.5) && ($direction <= 67.5)) {
    $fuzzy = 'NE';
  }
  elseif (($direction > 67.5) && ($direction <= 112.5)) {
    $fuzzy = 'E';
  }
  elseif (($direction > 112.5) && ($direction <= 157.5)) {
    $fuzzy = 'SE';
  }
  elseif (($direction > 157.5) && ($direction <= 202.5)) {
    $fuzzy = 'S';
  }
  elseif (($direction > 202.5) && ($direction <= 247.5)) {
    $fuzzy = 'SW';
  }
  elseif (($direction > 247.5) && ($direction <= 292.5)) {
    $fuzzy = 'W';
  }
  elseif (($direction > 292.5) && ($direction <= 337.5)) {
    $fuzzy = 'NW';
  }
  else {
    // Error handling.
  }

  // @todo: break this out into a separate function.
  $directions = array(
    'N' => t('North'),
    'NE' => t('Northeast'),
    'E' => t('East'),
    'SE' => t('Southeast'),
    'S' => t('South'),
    'SW' => t('Southwest'),
    'W' => t('West'),
    'NW' => t('Northwest'),
  );
  return t('<abbr title="@direction_full">@direction</abbr>', array('@direction_full' => $directions[$fuzzy], '@direction' => $fuzzy));
}

/**
 * Retrieves bin data for the given site and given variable presets.
 *
 * Uses local data if possible; otherwise makes a (blocking) API call to the
 * remote data provider.
 *
 * @param Entity $site
 *   Generation site.
 * @param array $presets
 *   Variable presets for which to retrieve generation data.  Must be keyed by
 *   preset_id (e.g., loaded via generation_variable_preset_load_multiple()).
 * @param DateTime $date_start
 *   Interval start.
 * @param DateTime $date_end
 *   Interval end.
 * @param string $bin
 *   (optional) If given, determines what bin size to query for. Otherwise, bin
 *   size will be determined automatically.
 *
 * @return array
 *   Big data array in the GenerationProvider::queryBin() format.
 */
function _generation_get_bin_data($site, $presets, $date_start, $date_end, $bin = NULL) {
  if (!$bin) {
    $bin = _generation_get_bin_from_range($date_start, $date_end);
  }
  
  switch ($bin) {
    case 'year':
    case 'month':
    case 'day':
    case 'hour':
      $date_start = _generation_round_date($date_start, 60);
      $date_end = _generation_round_date($date_end, 60);
      break;
    default:
      $date_start = _generation_round_date($date_start);
      $date_end = _generation_round_date($date_end);
  }

  // Generate a cache ID for the query.
  $preset_ids_encoded = generation_urlencode_preset_ids(array_keys($presets));
  $cid = $site->id . ':' . $preset_ids_encoded . ':';
  $cid .= $date_start->format('U') . ':' . $date_end->format('U') . ':' . $bin;

  // Have we cached the data for this exact query?
  if ($cache = cache_get($cid, 'cache_generation_bin')) {

    if ($site->type == 'locus_energy') {
      $has_data = TRUE;
      
      foreach ($cache->data as $data) {
        if (empty($data['data'])) {
          $has_data = FALSE;
        }
      }
      if ($has_data) {
        return $cache->data;
      }

    } else {
      return $cache->data;
    }
  }

  // We haven't cached this exact query; let's dynamically query for the data
  // from the data provider.
  $provider = generation_get_provider($site);
  $data = $provider->queryBin($site, $presets, $date_start, $date_end, $bin);

  // Cache the results for an hour.
  $expire = REQUEST_TIME + 3600;

  cache_set($cid, $data, 'cache_generation_bin', $expire);
  return $data;
}

/**
 * Retrieves window data for the given site and variable presets.
 *
 * Uses local data if possible; otherwise makes a (blocking) API call to the
 * remote data provider.
 *
 * @param Entity $site
 *   Generation site.
 * @param DateTime $date_start
 *   Interval start.
 * @param DateTime $date_end
 *   Interval end.
 * @param int $age_limit
 *   Maximum age for cached data. @see _generation_get_instant_summary()
 *
 * @return array
 *   Data array in the GenerationProvider::queryWindowSummary() format.
 */
function _generation_get_window_summary($site, DateTime $date_start, DateTime $date_end, $age_limit = 1800) {
  $date_start = _generation_round_date($date_start, 30);
  $date_end = _generation_round_date($date_end, 30);
  return _generation_get_summary('window', $site, $date_start, $date_end, $age_limit);
}

/**
 * Fetches current data (instantaneous readings).
 *
 * Will fetch either a specific node's data, or a global aggregate.
 *
 * @param object|NULL $site
 *   Omit this parameter to get current data for all generation sites.
 * @param int $age_limit
 *   Indicates the threshold to use, in seconds, to determine whether we should
 *   make an actual API call to get the latest data. If the current data we
 *   have is older than this value, the instant_summary data will get refreshed.
 *   The default threshold is 30 minutes. Pass 0 to force a refresh.
 *
 * @return array
 *   Always includes a count of sites summarized in ['site_count'].
 *   Otherwise, return array follows the format of
 *   GenerationProvider::queryInstantSummary().
 */
function _generation_get_instant_summary($site = NULL, $age_limit = 1800) {
  return _generation_get_summary('instant', $site, new GenerationLifetimeStartDateTime, new DateTime(), $age_limit);
}

/**
 * Retrieves a summary dynamically or from cache.
 */
function _generation_get_summary($type, $site, DateTime $date_start, DateTime $date_end, $age_limit) {
  // Check the cache.
  if ($summary = _generation_summary_cache_get($type, $site, $date_start, $date_end)) {
    // Only use the cached data if it's not too old.
    $age = $_SERVER['REQUEST_TIME'] - $summary['collected']->format('U');
    if ($age < $age_limit) {
      // Cache hit!
      return $summary;
    }
    // Our data is too old and must be refreshed.
  }

  // We haven't cached this exact query, or our cached data is too old.
  // Let's dynamically query for the data from the data provider(s).
  $provider = generation_get_provider($site);
  if ($type === 'instant') {
    $summary = $provider->queryInstantSummary($site);
  }
  else {
    assert($type === 'window');
    $summary = $provider->queryWindowSummary($site, $date_start, $date_end);
  }

  if (!$summary || empty($summary)) {
    return FALSE;
  }

  $summary['collected'] = generation_new_datetime_local('now');

  if ($type === 'window') {
    $summary['date_start'] = $date_start;
    $summary['date_end']   = $date_end;
  }

  $summary['site_count'] = $site ? 1 : _generation_get_site_count();

  // Cache the results.
  _generation_summary_cache_set($type, $site, $summary);

  return $summary;
}

/**
 * Retrieves an item from the summary data cache, if possible.
 *
 * @param string $type
 *   'instant' or 'window'.
 * @param object|NULL $site
 *   Omit this parameter to get global summary data.
 * @param DateTime $date_start
 *   Interval start.
 * @param DateTime $date_end
 *   Interval end.
 *
 * @return array|FALSE
 *   Format: @see _generation_get_instant_summary_data()'s return format.
 */
function _generation_summary_cache_get($type, $site, DateTime $date_start = NULL, DateTime $date_end = NULL) {
  assert(in_array($type, array('window', 'instant')));

  // For global summaries, we store id as 0.
  $id = $site ? $site->id : 0;
  $table = 'generation_summary_' . $type;

  $query = db_select($table)
    ->fields($table)
    ->condition('site_id', $id);

  if ($type === 'window') {
    assert(is_object($date_start));
    assert(is_object($date_end));
    $query
      ->condition('start', $date_start->format('U'))
      ->condition('end', $date_end->format('U'));
  }
  $summary = $query->execute()->fetchAssoc();

  if ($summary) {
    $summary['collected'] = generation_new_datetime_local($summary['collected']);
    if ($type == 'window') {
      // We store the start timestamp for 'lifetime' queries as 0.
      if ($summary['start'] === 0) {
        $summary['date_start'] = new GenerationLifetimeStartDateTime();
      }
      else {
        $summary['date_start'] = generation_new_datetime_local($summary['start']);
      }
      $summary['date_end'] = generation_new_datetime_local($summary['end']);
    }
    return $summary;
  }
  return FALSE;
}

/**
 * Sets an item in the summary data cache.
 *
 * @param string $type
 *   'instant' or 'window'.
 * @param object|NULL $site
 *   Omit this parameter to set global instant_summary data.
 * @param array $summary
 *   Summary data to store.
 */
function _generation_summary_cache_set($type, $site, array $summary) {
  assert(is_array($summary) && is_object($summary['collected']));
  assert(in_array($type, array('instant', 'window')));

  // For global summaries, we store id as 0.
  $id = $site ? $site->id : 0;
  $table = 'generation_summary_' . $type;

  $query = db_select($table)
    ->fields($table)
    ->condition('site_id', $id);

  // Serialize DateTimes as UNIX timestamps.
  $collected = $summary['collected']->format('U');
  if ($type === 'window') {
    $date_start = $summary['date_start']->format('U');
    $date_end   = $summary['date_end']->format('U');
    $query
      ->condition('start', $date_start)
      ->condition('end', $date_end);
  }

  // Prepare the either updated or new record.
  $record = array(
    'site_id' => $id,
    'collected' => $collected,
    'site_count' => isset($summary['site_count']) ? $summary['site_count'] : NULL,
    'cell_temperature' => isset($summary['cell_temperature']) ? $summary['cell_temperature'] : NULL,
    'generation' => isset($summary['generation']) ? $summary['generation'] : NULL,
    'irradiance' => isset($summary['irradiance']) ? $summary['irradiance'] : NULL,
    'power' => isset($summary['power']) ? $summary['power'] : NULL,
    'temperature' => isset($summary['temperature']) ? $summary['temperature'] : NULL,
    'wind_direction' => isset($summary['wind_direction']) ? $summary['wind_direction'] : NULL,
    'wind_speed' => isset($summary['wind_speed']) ? $summary['wind_speed'] : NULL,
  );
  if ($type === 'window') {
    $record['start'] = $date_start;
    $record['end'] = $date_end;
  }

  // Check to see if we're updating or inserting a new row.
  $result = $query->execute()->fetchAssoc();
  if (!$result || is_null($result)) {
    $primary_keys = array();
  }
  else {
    // We're updating an existing entry.
    $primary_keys = array('site_id');
    if ($type === 'window') {
      $primary_keys[] = 'start';
      $primary_keys[] = 'end';
    }
  }

  drupal_write_record($table, $record, $primary_keys);
}

/**
 * Returns a map of summary variables to unit of measure display strings.
 *
 * @return array
 *   Returns an array of unit display strings.
 */
function _generation_summary_display_units() {
  return array(
    'cell_temperature' => '°F',
    'generation' => 'kWh',
    'irradiance' => 'W/m²',
    'power' => 'W',
    'temperature' => '°F',
  );
}

/**
 * Calculates bin size to be used for a date range.
 *
 * @param DateTime $date_start
 *   Beginning of date range.
 * @param DateTime $date_end
 *   End of date range.
 *
 * @return string
 *   The name of the bin.
 */
function _generation_get_bin_from_range(DateTime $date_start, DateTime $date_end) {
  // Always use month bins for lifetime queries.
  if ($date_start instanceof GenerationLifetimeStartDateTime) {
    return 'month';
  }

  $start = $date_start->format('U');
  $end = $date_end->format('U');
  assert($end > $start);

  $diff = $end - $start;
  $minutes = $diff / 60;
  $hours = $minutes / 60;
  $days = $hours / 24;
  if ($days >= 62) {
    return 'month';
  }
  if ($days > 31) {
    // Use day bins for months (PowerOne) dropped support for the 'Week' bin.
    return 'day';
  }
  if ($days > 7) {
    return 'day';
  }
  if ($days > 1) {
    return 'hour';
  }
  return 'min15';
}

/**
 * Determines how many total generation sites exist.
 *
 * @return int|FALSE
 *   Number of generation site nodes in the database or FALSE on error.
 */
function _generation_get_site_count() {
  return db_select('node')
    ->condition('type', generation_get_site_types())
    ->countQuery()
    ->execute()
    ->fetchField();
}

/**
 * Determines which functions are applicable to the given variable.
 *
 * @return array
 *   Array of function display values keyed by provider-dependent function
 *   machine name.
 */
function _generation_get_possible_functions($variable = NULL) {
  $providers = generation_get_providers();
  $provider = isset($variable) ? $providers[$variable->module] : generation_get_global_provider();
  if (is_object($provider)) {
    return $provider->getVariableFunctions($variable);
  }
  return NULL;
}

/**
 * Determines which units are applicable to the given variable.
 *
 * @return array
 *   Array of units arrays, keyed by unit machine name.
 */
function _generation_get_possible_units($variable = NULL) {
  $providers = generation_get_providers();
  $provider = isset($variable) ? $providers[$variable->module] : generation_get_global_provider();
  if (is_object($provider)) {
    return $provider->getVariableUnits($variable);
  }
  return NULL;
}

/**
 * Selects variables from the database.
 *
 * @param int $pager_limit
 *   (optional) Maximum number of variables to return. If not supplied, all
 *   variables will be returned.
 *
 * @return array
 *   Array of variable objects, keyed by variable id.
 */
function _generation_get_variables($pager_limit = NULL) {
  $query = db_select('generation_variables', 'gv');
  if (isset($pager_limit)) {
    $query = $query->extend('PagerDefault');
    $query->limit($pager_limit);
  }

  $result = $query
    ->fields('gv')
    ->orderBy('module')
    ->orderBy('name')
    ->execute();

  foreach ($result as $v) {
    $variables[$v->variable_id] = $v;
  }
  return $variables;
}

/**
 * Fetches all presets (or just for the given variable, if specified).
 *
 * @return array
 *   Array of variable preset objects, keyed by preset id.
 */
function _generation_get_variable_presets($variable = NULL) {
  $query = db_select('generation_variable_presets', 'gvp')
    ->fields('gvp');

  if (isset($variable) && is_object($variable)) {
    $query->condition('variable_id', $variable->variable_id);
  }

  return _generation_fetch_all_keyed($query->execute(), 'preset_id');
}

/**
 * Returns a list of variables names, optionally filtered.
 *
 * @param Entity $site
 *   Generation site node whose variables are wanted.
 * @param array $names
 *   (optional) If given, only variables with these names will be included.
 *
 * @return array
 *   Array of variable names, keyed by variable ID.
 */
function _generation_get_variable_options(Entity $site, array $names = array()) {
  $provider_info = generation_get_provider_info($site);

  $query = db_select('generation_variables', 'gv')
    ->fields('gv', array('variable_id', 'name'))
    ->condition('module', $provider_info['module']);
  if (!empty($names)) {
    $query->condition('name', $names);
  }

  return $query->execute()->fetchAllKeyed();
}

/**
 * Returns a list of all variable presets, for use in FAPI select #options.
 *
 * @param Entity $site
 *   (optional) Generation site node object.
 * @param array $names
 *   (optional) Names of wanted variables.
 *
 * @return array
 *   Array of presets keyed by preset_id.
 */
function _generation_get_variable_presets_options(Entity $site = NULL, array $names = array()) {
  if ($site) {
    $provider_info = generation_get_provider_info($site);

    $query = db_select('generation_variable_presets', 'gvp')
      ->fields('gvp')
      ->condition('v.module', $provider_info['module']);
    $query->innerJoin('generation_variables', 'v', 'gvp.variable_id = v.variable_id');

    if (!empty($names)) {
      $query->condition('v.name', $names);
    }

    // Need to further restrict by devices specific to this site.
    $provider = generation_get_provider($site);
    $devices = $provider->getSiteDevices($site);
    if (empty($devices)) {
      $query->condition('gvp.device_id', NULL);
    }
    else {
      $or = db_or()
        ->condition('gvp.device_id', NULL)
        ->condition('gvp.device_id', array_keys($devices));
      $query->condition($or);
    }

    // @todo: use fetchAllKeyed() here?
    $result = $query->execute();

    $presets = array();
    foreach ($result as $preset) {
      $presets[$preset->preset_id] = $preset;
    }
  }
  else {
    $presets = _generation_get_variable_presets();
  }
  return _generation_variable_presets_to_options($presets);
}

/**
 * Adds presets for variables which have none.
 *
 * @param Entity $site
 *   Generation site.
 *
 * @return array
 *   Array of variables available for this site.
 */
function _generation_update_variable_presets_location($site) {
  $provider = generation_get_provider($site);
  $location_variables = $provider->getSiteVariables($site);
  $provider_info = generation_get_provider_info($site);
  foreach ($location_variables as $name => $variable) {
    // Check if this exists.
    if (!$existing = _generation_get_variable($provider_info['module'], $name)) {
      // Write the variable record and add a preset.
      generation_variable_save(array(
        'module' => $provider_info['module'],
        'name' => $name,
        'type' => $name,
      ));
      _generation_add_preset($provider_info['module'], $name, $name, 'neutral', $variable['unit']);
    }
  }
  return array_keys($location_variables);
}

/**
 * Finds a variable preset applicable to a given node by a criterion.
 *
 * @param Entity $site
 *   Generation site.
 * @param string $value
 *   The value to search for -- either the variable name or the alias. For
 *   variable name it's possible there are multiple matches, so the first
 *   result from the database is returned.
 * @param string $find_by
 *   Should be 'alias' or 'variable_name'.
 *
 * @return int
 *   Variable ID, or NULL if not found.
 */
function _generation_find_preset_id($site, $value, $find_by = 'alias') {
  assert(in_array($find_by, array('alias', 'variable_name')));

  $provider_info = generation_get_provider_info($site);
  $field = $find_by === 'alias' ? 'vp.alias' : 'v.name';

  $query = db_select('generation_variable_presets', 'vp');
  $query->innerJoin('generation_variables', 'v', 'vp.variable_id = v.variable_id');
  return $query
    ->fields('vp', array('preset_id'))
    ->condition('v.module', $provider_info['module'])
    ->condition($field, $value)
    ->range(0, 1)
    ->execute()
    ->fetchField();
}

/**
 * Converts an array of variable presets for use in FAPI select #options.
 */
function _generation_variable_presets_to_options(array $presets) {
  $options = array();
  foreach ($presets as $preset_id => $preset) {
    $options[$preset_id] = $preset->alias;
  }
  return $options;
}

/**
 * Returns all variables of a specific provider module from the database.
 *
 * @return array
 *   Array of variable objects, keyed by $key (e.g., variable_id, name).
 */
function _generation_get_variables_module($module, $key = 'variable_id') {
  $result = db_select('generation_variables', 'gv')
    ->fields('gv')
    ->condition('module', $module)
    ->orderBy('name')
    ->execute();

  foreach ($result as $v) {
    $variables[$v->$key] = $v;
  }
  return $variables;
}

/**
 * Updates DB to include previously-unknown variables.
 */
function _generation_refresh_variables() {
  foreach (generation_get_providers() as $module => $provider) {
    $variables = $provider->getVariables();

    if (count($variables) > 0) {
      // Out of the list of variables we just got from the provider, select all
      // of those variables that are already in the database.
      $result = db_select('generation_variables', 'gv')
        ->fields('gv')
        ->condition('module', $module)
        ->condition('name', array_keys($variables))
        ->execute();

      // Remove all variables that are already in the database from our list.
      foreach ($result as $row) {
        unset($variables[$row->name]);
      }

      // Any variables left over? If so, add to variables table.
      foreach ($variables as $key => $type) {
        generation_variable_save(array(
          'module' => $module,
          'name' => $key,
          'type' => $type,
        ));
      }
    }
  }
}

/**
 * Creates a variable preset.
 */
function _generation_add_preset($module, $variable_name, $alias, $function, $units, $chart_type = 'line') {
  if (($variable = _generation_get_variable($module, $variable_name))) {
    $preset = (object) array(
      'variable_id' => $variable->variable_id,
      'alias' => $alias,
      'function' => $function,
      'units' => $units,
      'chart_type' => $chart_type,
      'description' => '',
    );
    generation_variable_preset_save($preset);
  }
  else {
    $message = __FUNCTION__ . ": Can't find variable @module:@name";
    $values = array(
      '@module' => $module,
      '@name' => $variable_name,
    );
    watchdog('generation', $message, $values, 'error');
  }
}

/**
 * Returns a variable from its provider module name and API name.
 */
function _generation_get_variable($module, $variable_name) {
  $variables = _generation_get_variables_module($module, 'name');

  if (isset($variables[$variable_name])) {
    return $variables[$variable_name];
  }

  return FALSE;
}

/**
 * Clear cached bin data for a given node.
 */
function generation_cache_clear($id) {
  cache_clear_all($id . ':', 'cache_generation_bin', TRUE);
}
