<?php
/**
 * @file
 * Theme functions for Generation Stats module.
 */

/**
 * Returns a beginning-of-a-sentence word or words describing the given period.
 */
function _generation_stats_over_period_text($period) {
  if ($period === 'day') {
    return t('Today');
  }
  elseif ($period === 'lifetime') {
    return t('Over all time');
  }
  return t('This @period', array('@period' => $period));
}

/**
 * Generates "As of [current time]" label for site data block.
 *
 * @see template_preprocess_generation_stats_site_summary()
 */
function _generation_stats_as_of_now_text($site) {
  $now = generation_new_datetime_site($site, 'now');
  return t('As of @now', array('@now' => $now->format('g:ia T')));
}

/**
 * Implements hook_preprocess_HOOK() for theme_generation_stats_site_equivalents().
 */
function template_preprocess_generation_stats_site_equivalents(&$vars) {
  $instant     = $vars['data']['instant']['formatted'];
  $period      = $vars['data']['period']['formatted'];
  $site        = $vars['data']['site'];

  $over_period = _generation_stats_over_period_text($vars['data']['period']['period']);

  if ($vars['data']['period']['period'] === 'lifetime') {
    // For lifetime period, use the value from the instant summary; it's more
    // accurate than a lifetime window query.
    $period_generation = $instant['generation'];
    $equivalents = generation_stats_get_equivalents($vars['data']['instant']);
  }
  else {
    $period_generation = $period['generation'];
    $equivalents = generation_stats_get_equivalents($vars['data']['period']);
  }

  $headline = t('!over_period, %site generated <span class="!class">!amount Kilowatt-hours of electricity.</span>',
    array(
    '!over_period' => $over_period,
    '%site' => $site->title,
    '!class' => 'fat-spaniel-data-value fat-spaniel-data-energy',
    '!amount' => $period_generation,
  ));
  $carbon_equivalent = t('From fossil-fueled sources, this amount of electricity would have emitted <span class="!class">!amount lbs of CO<sub>2</sub></span> into the atmosphere.',
    array(
    '!class' => 'fat-spaniel-data-value fat-spaniel-data-carbon',
    '!amount' => $equivalents['formatted']['carbon'],
  ));

  $vars['css_id'] = $vars['data']['cssId'];
  $vars['summary'] = $headline . $carbon_equivalent;
  $vars['equivalents'] = array();

  $messages = array(
    'toothbrush' => 'An electric toothbrush for <span class="!class">!time</span>',
    'plasma-screen' => 'A 42" plasma-screen television for <span class="!class">!time</span>',
    'video-game' => 'A typical video game system for <span class="!class">!time</span>',
  );
  foreach ($messages as $type => $message) {
    if ( ! empty($equivalents['placeholder'])) {
      $time = $equivalents[$type];
    }
    else {
      $time = $equivalents['formatted'][$type];
    }
    $vars['equivalents'][$type] = t($message, array('!class' => 'fat-spaniel-data-value', '!time' => $time));
  }

  // Beginning of kiosk_preprocess_generation_stats_site_equivalents function.

  // Chart heading titles by interval.
  $chart_titles = array(
    'day' => t('Today: Hourly Energy Production for Today'),
    'week' => t('Week: Energy Production for this Week'),
    'month' => t('Month: Energy Production for this Month'),
    'year' => t('Year: Energy Production for this Year'),
    'lifetime' => t('Lifetime: Energy Production Total'),
  );
  $nice_intervals = array(
    'day' => t('Today'),
    'week' => t('This Week'),
    'month' => t('This Month'),
    'year' => t('This Year'),
    'lifetime' => t('Lifetime'),
  );

  $data = &$vars['data'];
  $period = $data['period']['period'];

  $formatted_datetime = format_date(time(), 'custom', 'g\:iA\, F j\, Y', $site->field_timezone['und'][0]['value']);

  $vars['as_of'] = t('As of @date', array('@date' => $formatted_datetime));
  $vars['title'] = $chart_titles[$period];
  $vars['current_power_label'] = t('Currently:');
  $vars['current_power'] = t('!watts Watts', array('!watts' => $data['instant']['formatted']['power']));

  $vars['period_label'] = $nice_intervals[$period];
  if ($period === 'day') {
    // @todo remove hard-coded units.
    $generation_wh = _generation_stats_number_format($data['period']['generation']);
    $vars['period_energy'] = t('!wh Kilowatt-hours', array('!wh' => $generation_wh));
  }
  else {
    $vars['period_energy'] = t('!kwh Kilowatt-hours', array('!kwh' => $data['period']['formatted']['generation']));
  }
}

/**
 * Implements hook_preprocess_HOOK() for theme_generation_stats_site_summary().
 */
function template_preprocess_generation_stats_site_summary(&$vars) {
  $instant     = $vars['data']['instant']['formatted'];
  $site        = $vars['data']['site'];
  $equivalents = generation_stats_get_equivalents($vars['data']['instant']);

  $vars['as_of'] = _generation_stats_as_of_now_text($site);
  $vars['css_id'] = $vars['data']['cssId'];

  // Set up common value for many t() calls to follow.
  $values = array('@site_id' => $site->id);

  // Power Creation/usage
  $vars['power_energy_label'] = t('Power');
  if (isset($instant['power'])) {
    $values['!value'] = $instant['power'];
    $values['!unit'] = ' W';
  }
  else {
    $values['!value'] = t('?');
    $values['!unit'] = '';
  }

  $vars['power_value'] = t(
    '<div class="fat-spaniel-data-power-label">Output</div>
    <div class="fat-spaniel-data-power-value fat-spaniel-data-power-ratio fat-spaniel-data-power-ratio-100">
    <span id="fat-spaniel-data-GenerationPower@site_id">!value</span>!unit</div>',
    $values
  );

  // Irradiance.
  $vars['irradiance_label'] = t('Irradiance');
  if (isset($instant['irradiance'])) {
    $values['!value'] = $instant['irradiance'];
    $vars['irradiance_value'] = t(
      '<span id="fat-spaniel-data-Irradiance@site_id">!value</span> W/m<sup>2</sup>',
      $values
    );
  }
  else {
    $vars['irradiance_value'] = t('N/A');
  }

  // Temperature.
  $vars['temperature_label'] = t('Temperature');
  if (isset($instant['cell_temperature'])) {
    $values['!value'] = $instant['cell_temperature'];
    $vars['cell_temperature_value'] = t(
      '<div class="fat-spaniel-data-temperature-label">Cell</div>
    <div class="fat-spaniel-data-temperature-value">
    <span id="fat-spaniel-data-CellTemp@site_id">!value</span>&deg;F</div>',
      $values
    );
  }
  else {
    $vars['cell_temperature_value'] = '<div class="fat-spaniel-data-temperature-label">Cell</div><div class="fat-spaniel-data-temperature-value">' . t('N/A') . '</div>';
  }

  if (isset($instant['temperature'])) {
    $values['!value'] = $instant['temperature'];
    $vars['ambient_temperature_value'] = t(
      '<div class="fat-spaniel-data-temperature-label">Ambient</div>
    <div class="fat-spaniel-data-temperature-value">
    <span id="fat-spaniel-data-AmbientTemp@site_id">!value</span>&deg;F</div>',
      $values
    );
  }
  else {
    $vars['ambient_temperature_value'] = '<div class="fat-spaniel-data-temperature-label">Ambient</div><div class="fat-spaniel-data-temperature-value">' . t('N/A') . '</div>';
  }

  $vars['wind_label'] = t('Wind');
  if (isset($instant['wind_speed'])) {
    $values['!value'] = isset($instant['wind_direction']) ? $instant['wind_direction'] : '';
    $vars['wind_direction_value'] = t(
      '<div class="fat-spaniel-data-wind-label">Local Direction</div>
      <div class="fat-spaniel-data-wind-value">
      <span id="fat-spaniel-data-WindDirection@site_id">!value</span></div>',
      $values
    );

    $values['!value'] = $instant['wind_speed'];
    $vars['wind_speed_value'] = t(
      '<div class="fat-spaniel-data-wind-label">Local Speed</div>
      <div class="fat-spaniel-data-wind-value">
      <span id="fat-spaniel-data-WindSpeed@site_id">!value</span>mph</div>',
      $values
    );
  }
  else {
    $vars['wind_error_value'] = t('No data available for this site.');
  }

  // CO2 Avoidance. We use the lifetime generation in the label; use the instant
  // summary's value for this; it's more accurate than lifetime window period.
  $vars['carbon_label'] = t('!value kWh', array('!value' => $instant['generation']));

  $values['!value'] = $equivalents['formatted']['carbon'];
  $vars['carbon_value'] = t(
    '<span id="fat-spaniel-data-CarbonOffset@site_id">!value</span> lbs of CO<sub>2</sub> Avoided',
    $values
  );

  // Beginning kiosk_preprocess_generation_stats_site_summary function.
  $data = &$vars['data'];

  $vars['title'] = t('Environmental Benefits: Since Installation');
  $vars['subtitle'] = t('Greenhouse Gases Avoided by use of Solar Energy.');

  $vars += generation_stats_get_equivalents($data['instant']);
  if (isset($vars['placeholder']) && $vars['placeholder']) {
    $vars['eq_carbon_digits'] = str_split('....');
  }
  else {
    $carbon = number_format($vars['carbon'], 0, '', '');
    $vars['eq_carbon_digits'] = str_split($carbon);
  }

  $vars['eqs']['home'] = t('The CO2 avoidance is equivalent to the energy to power a home for <span class="fat-spaniel-data-value">!time</span>', array('!time' => $vars['formatted']['home']));
  $vars['eqs']['tv'] = t('The energy to power a TV for <span class="fat-spaniel-data-value">!time</span>', array('!time' => $vars['formatted']['tv']));
}

/**
 * Implements hook_preprocess_HOOK() for theme_generation_stats_global_equivalents().
 */
function template_preprocess_generation_stats_global_equivalents(&$vars) {
  // Create short alias; use a reference to avoid copying these arrays.
  $summary = &$vars['data']['instant'];
  $equivalents = generation_stats_get_equivalents($summary);
  $equivalents['formatted']['carbon'] = _generation_stats_number_format($equivalents['carbon'], 0);

  // Don't include any decimal places when formatting the totals (front page) block.
  $summary['formatted'] = generation_stats_format_values($summary, 0);

  $vars['css_id'] = $vars['data']['cssId'];

  $values = array(
    '!value' => $summary['formatted']['power'],
    '!total' => isset($summary['site_count']) ? $summary['site_count'] : 0,
  );
  $vars['current_power'] = t('<span class="fat-spaniel-value">!total</span> photovoltaic systems are currently generating <span class="fat-spaniel-value"><span id="fat-spaniel-data-GenerationPower">!value</span> Watts</span>.', $values);

  $values['!value'] = $summary['formatted']['generation'];
  $vars['total_energy'] = t('<span class="fat-spaniel-value"><span id="fat-spaniel-data-GenerationEnergy">!value</span> Kilowatt Hours (kWh)</span> have been generated to date.', $values);

  $vars['carbon'] = t('This amount of electricity from fossil-fueled sources would have emitted <span class="fat-spaniel-value"><span id="fat-spaniel-data-CarbonOffset">!value</span> lbs CO<sub>2</sub></span> into the atmosphere.', array('!value' => $equivalents['formatted']['carbon']));
}

/**
 * Implements hook_preprocess_HOOK() for theme_generation_stats_global_summary().
 */
function template_preprocess_generation_stats_global_summary(&$vars) {
  $summary = &$vars['data']['instant'];
  $equivalents = generation_stats_get_equivalents($summary);
  $equivalents['formatted']['carbon'] = _generation_stats_number_format($equivalents['carbon'], 0);

  $vars['css_id'] = $vars['data']['cssId'];

  $values = array(
    '%energy' => $summary['formatted']['generation'],
    '%count' => $summary['site_count'],
    '%carbon' => $equivalents['formatted']['carbon'],
  );

  $vars['summary'] = t('%count photovoltaic systems have generated %energy kWh of solar electricity, avoiding about %carbon lbs of CO<sub>2</sub> emissions into the atmosphere. <br /><br />This is equivalent to the electricity it would take to...', $values);

  $vars['eqs'] = array(
    'toothbrush' => t('Power an electric toothbrush for !time', array('!time' => $equivalents['formatted']['toothbrush'])),
    'plasma-screen' => t('Power a 42" plasma-screen television for !time', array('!time' => $equivalents['formatted']['plasma-screen'])),
    'video-game' => t('Power a typical video game system for !time', array('!time' => $equivalents['formatted']['video-game'])),
    'home' => t('Power an average US home for !time', array('!time' => $equivalents['formatted']['home'])),
  );
}
