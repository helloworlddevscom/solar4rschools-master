<?php

/**
 * @file
 * Classes for Generation API.
 * So far, if one of these is needed, likely all are, so splitting these up
 * into separate files isn't necessary.
 */

/**
 * Interface for energy generation data providers, such as Power-One and DECK
 * Monitoring.
 */
interface GenerationProvider {

  /**
   * Dynamically queries for bin data for one or more fields.
   *
   * @param object $site
   *   Site entity.
   * @param array $presets
   *   Variable preset objects.
   * @param DateTime $start
   *   Start date and time for the query.
   * @param DateTime $end
   *   End date and time for the query.
   *
   * @return array
   *   Format:
   *   array(
   *     // For each field
   *     array(
   *       'name' => 'Field/Variable Name',
   *       'type' => 'area', // Chart type: line, area, column, etc.
   *       'data' => array(
   *         array(
   *           UNIX timestamp,
   *           Raw scalar value,
   *         ),
   *         array(
   *           UNIX timestamp,
   *           Raw scalar value,
   *         ),
   *         ...
   *       ),
   *     ),
   *     ...
   *   )
   */
  public function queryBin(Entity $site, array $presets, DateTime $start, DateTime $end, $bin = 'hour');

  /**
   * Dynamically query a single device.
   */
  public function queryBinDevice($device_id, array $variables, DateTime $date_start, DateTime $date_end, $options = array());

  /**
   * Get bin data from API response.
   */
  public function getBinData(stdClass $response);

  /**
   * Get value in the provider's device name field.
   */
  public function getDeviceName(EntityMetadataWrapper $device);

  /**
   * Dynamically queries for summaries for one or all of the provider's sites.
   *
   * @param object $site
   *   (optional) Omit this parameter to get summary data for all generation
   *   sites.
   *
   * @return array
   *   Instant summaries contain: An array with these keys and values:
   *   - // Current cell temperature, in Fahrenheit.
   *     'cell_temperature' => <value, degrees F>,
   *   - // Lifetime generation energy, in kilowatt hours.
   *     'generation' => <value, kWh>,
   *   - // Current irradiance, in Watts per square meter.
   *     'irradiance' => <value, W/m^2>,
   *   - // Current power output, in Watts.
   *     'power' => <value, W>,
   *   - // Current ambient temperature, in Fahrenheit.
   *     'temperature' => <value, degrees F>,
   */
  public function queryInstantSummary($site = NULL);

  /**
   * Dynamically queries for windowed data.
   *
   * Queries one or all of the provider's generation sites.
   *
   * @param object $site
   *   Give NULL for this parameter to get windowed data for all generation
   *   sites.
   *
   * @return array
   *   Format:
   *   array(
   *     // Cell temperature, in Fahrenheit.
   *     'cell_temperature' => <value, degrees F>,
   *     // Generation energy, in kilowatt hours.
   *     'generation' => <value, kWh>,
   *     // Irradiance, in Watts per square meter.
   *     'irradiance' => <value, W/m^2>,
   *     // Power output, in Watts.
   *     'power' => <value, W>,
   *     // Ambient temperature, in Fahrenheit.
   *     'temperature' => <value, degrees F>,
   *   )
   */
  public function queryWindowSummary(Entity $site, DateTime $start, DateTime $end);

  /**
   * Requests all sites from data provider and creates entities for new sites.
   *
   * Called periodically from within a cron job; this will generally be a
   * pretty slow method.
   */
  public function updateSites();

  /**
   * Updates a given site or inserts it if unknown.
   *
   * The site is represented by the object $location, as defined by the
   * given provider's API (or internally).
   */
  public function updateSite(stdClass $location);

  /**
   * Returns installation date of the given site.
   *
   * @param object $site
   *   Site entity.
   *
   * @return DateTime
   *   Date when the site was installed.
   */
  public function getInstallDate(Entity $site);

  /**
   * Retrieves all variable functions; optionally filters to a variable.
   *
   * @return array
   *   Array of function ids (keys) and function display names (values).
   */
  public function getVariableFunctions($variable = NULL);

  /**
   * Retrieves all variable units applicable to this provider.
   *
   * @return array
   *   Array of units arrays, keyed by unit machine name. Example unit array:
   *     'kilowatt-hours' => array('label' => 'kWh),
   *     ...
   *   );
   */
  public function getVariableUnits();

  /**
   * Returns all variables applicable to this provider.
   *
   * @return array
   *   Array of variable objects, keyed by variable id.
   */
  public function getVariables();

  /**
   * Returns all variables applicable to a specific site.
   *
   * Results may vary from getVariables() method's.
   */
  public function getSiteVariables(Entity $site);

  /**
   * Returns all devices specific to a given site entity.
   */
  public function getSiteDevices(Entity $site);
}

/**
 * A substitute for "$date_start" arguments. Indicates the "start date" or
 * "first recorded" date should be used. Used for "lifetime" data queries.
 */
class GenerationLifetimeStartDateTime extends DateTime {

  /**
   * Constructor.
   */
  public function __construct() {
    parent::__construct('@0');
  }

  /**
   * Overrides DateTime::format().
   */
  public function format($format) {
    // Store in the database as 0.
    return 0;
  }
}

/**
 * Exception types.
 */
class GenerationNotImplementedException extends Exception {
}

/**
 * Provides a wrapper around running GenerationProvider methods on all
 * registered providers.
 */
class GenerationGlobalProvider implements GenerationProvider {

  /**
   * Implements GenerationProvider::getInstallDate().
   */
  public function getInstallDate(Entity $site) {
    throw new GenerationNotImplementedException();
  }

  /**
   * Helper function to invoke a method and merge results for all providers.
   */
  protected function invokeAll($method /* , ... */) {
    $args = func_get_args();
    array_shift($args);

    $data = array();
    foreach (generation_get_providers() as $provider) {
      $return = call_user_func_array(array($provider, $method), $args);
      $data = array_merge_recursive($return, $data);
    }
    return $data;
  }

  /**
   * Implements GenerationProvider::getVariableFunctions().
   */
  public function getVariableFunctions($variable = NULL) {
    return $this->invokeAll('getVariableFunctions', $variable);
  }

  /**
   * Implements GenerationProvider::getVariables().
   */
  public function getVariables() {
    return $this->invokeAll('getVariables');
  }

  /**
   * Implements GenerationProvider::getSiteVariables().
   */
  public function getSiteVariables(Entity $site) {
    return $this->invokeAll('getSiteVariables');
  }

  /**
   * Implements GenerationProvider::getSiteDevices().
   */
  public function getSiteDevices(Entity $site) {
    return $this->invokeAll('getSiteDevices');
  }

  /**
   * Get value in the provider's device name field.
   */
  public function getDeviceName(EntityMetadataWrapper $device) {
    return isset($device->name) ? $device->name->value() : '';
  }

  /**
   * Implements GenerationProvider::getVariableUnits().
   */
  public function getVariableUnits($variable = NULL) {
    return $this->invokeAll('getVariableUnits', $variable);
  }

  /**
   * Implements GenerationProvider::queryBin().
   */
  public function queryBin(Entity $site, array $presets, DateTime $start, DateTime $end, $bin = 'hour') {
    throw new GenerationNotImplementedException();
  }

  /**
   * {@inheritdoc}
   */
  public function queryBinDevice($device_id, array $variables, DateTime $date_start, DateTime $date_end, $options = array()) {
    throw new GenerationNotImplementedException();
  }

  /**
   * {@inheritdoc}
   */
  public function getBinData(stdClass $response) {
    throw new GenerationNotImplementedException();
  }

  /**
   * Implements GenerationProvider::queryInstantSummary().
   */
  public function queryInstantSummary($site = NULL) {
    return $this->querySummary('instant', $site, NULL, NULL);
  }

  /**
   * Implements GenerationProvider::queryWindowSummary().
   */
  public function queryWindowSummary(Entity $site, DateTime $date_start, DateTime $date_end) {
    return $this->querySummary('window', $site, $date_start, $date_end);
  }

  /**
   * Performs a global summary query and aggregates the results.
   */
  protected function querySummary($type, $site, $date_start, $date_end) {
    $providers = generation_get_providers();
    $summaries = array();
    foreach ($providers as $provider) {
      if ($provider instanceof GlobalGenerationProvider) {
        // This special-case class should never be returned by
        // generation_get_providers() -- if it were, we'd recurse forever.
        assert(FALSE);
        continue;
      }

      if ($type === 'instant') {
        $summary = $provider->queryInstantSummary(NULL);
      }
      else {
        assert($type === 'window');
        $summary = $provider->queryWindowSummary(NULL, $date_start, $date_end);
      }

      if ($summary) {
        $summaries[] = $summary;
      }
    }

    if (empty($summaries)) {
      return FALSE;
    }

    $aggregate = array_pop($summaries);
    foreach ($summaries as $summary) {
      $aggregate['generation'] += $summary['generation'];
      $aggregate['irradiance'] += $summary['irradiance'];
      $aggregate['power'] += $summary['power'];

      // @todo: If we ever need to use temperatures, we'll need to deal with
      // them here (by averaging them, presumably).
    }
    return $aggregate;
  }

  /**
   * Implements GenerationProvider::updateSites().
   */
  public function updateSites() {
    foreach (generation_get_providers() as $provider) {
      $provider->updateSites();
    }
  }

  /**
   * Implements GenerationProvider::updateSite().
   */
  public function updateSite(stdClass $location) {
    throw new GenerationNotImplementedException();
  }
}
