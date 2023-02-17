<?php

/**
 * @file
 * Mappings to take care of custom database entries.
 */

/**
 * Maps Generation Variables available on a per-site basis from D6 to D7.
 */
class SolarGeneration extends DrupalMigration {
  protected function query() {
    return parent::$query;
  }

  protected function node_get_site_id($nid) {
    $node = node_load($nid);
    $site_id = isset($node->field_data_collection_site[LANGUAGE_NONE][0]['target_id']) ? $node->field_data_collection_site[LANGUAGE_NONE][0]['target_id'] : NULL;

    return $site_id;
  }
}

/**
 * Maps Generation Variable presets from D6 to D7.
 */
class SolarGenerationPresetsMigration extends DrupalMigration {
  /**
   * General initialization of a Migration object.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'preset_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Id of the preset',
        ),
      ),
      MigrateDestinationPreset::getKeySchema()
    );

    $this->source = new MigrateDrupal6SourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->destination = new MigrateDestinationPreset();

    $this->addSimpleMappings(array('alias', 'description', 'function', 'chart_type', 'units'));
    $this->addFieldMapping('variable_id', 'name')
      ->callbacks(array($this, 'preset_get_variable_id'));
  }

  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('generation_variable_presets', 'gvp')
             ->fields('gvp');
    $query->join('generation_variables', 'gv', 'gv.variable_id=gvp.variable_id');
    $query->addField('gv', 'name');

    $query_real = Database::getConnection('default', $this->sourceConnection)
        ->select($query, 'gv_all')
        ->fields('gv_all');

    return $query_real;
  }

  protected function preset_get_variable_id($name) {
    $query = db_select('generation_variables', 'gv')
      ->fields('gv', array('variable_id'));

    if (!empty($name)) {
      $query->condition('name', $name);
    }

    return $query->execute()->fetchField();
  }
}

/**
 * Maps Generation Variables available on a per-site basis from D6 to D7.
 */
class SolarGenerationSiteVariablesMigration extends SolarGeneration {
  /**
   * General initialization of a Migration object.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'period' => array(
          'type' => 'varchar',
          'length' => 16,
          'not null' => TRUE,
          'description' => 'Day, Week, Month, Year, Lifetime',
        ),
        'preset_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Id of the preset',
        ),
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Node id',
        ),
      ),
      MigrateDestinationSiteVariables::getKeySchema()
    );

    $this->source = new MigrateDrupal6SourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->destination = new MigrateDestinationSiteVariables();

    $this->addFieldMapping('site_id', 'nid')
      ->sourceMigration(array('Decks', 'Schools'))
      ->callbacks(array($this, 'node_get_site_id'));

    $this->addFieldMapping('preset_id', 'preset_id')
      ->sourceMigration('Presets');

    $this->addSimpleMappings(array('period'));
  }

  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('generation_charts_site_presets', 'gcsp')
             ->fields('gcsp');

    return $query;
  }
}

/**
 * Creates a migration destination for the Generation preset.
 */
class MigrateDestinationPreset extends MigrateDestination {
  static public function getKeySchema() {
    return array(
      'preset_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'Id of the preset',
      ),
    );
  }

  public function __toString() {
    return "Preset";
  }

  public function fields(){
    return array(
      'preset_id' => 'Primary identifier for a variable preset.',
      'variable_id' => 'The variable ({generation_variables}.variable_id) for the preset.',
      'alias' => 'Variable display name for this preset.',
      'description' => 'Description for this preset.',
      'function' => 'Data provider Bin Function to use for this preset, if supported.',
      'chart_type' => 'Type of chart to use when graphing the data for this preset.',
      'units' => 'Units to display for this preset.',
      'device_id' => 'Optional device ID for per-device-level variable presets.',
      'module' => 'Required if the device ID is passed.',
    );
  }

  public function import(stdClass $preset, stdClass $row){
    module_load_include('inc', 'generation', 'generation');
    _generation_refresh_variables();

    // Invoke migration prepare handlers
    $this->prepare($preset, $row);

    // Check to see if this is a new preset.
    $update = FALSE;
    if ($data = generation_variable_preset_load($preset->preset_id)) {
      $update = TRUE;
    }

    migrate_instrument_start('generation_variable_preset_save');
    generation_variable_preset_save($preset);
    migrate_instrument_stop('generation_variable_preset_save');

    // Return the new id or FALSE on failure.
    if ($data = generation_variable_preset_load($preset->preset_id)) {
      // Increment the count if the save succeeded.
      if ($update) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      // Return the primary key to the mapping table.
      $return = array($data->preset_id);
    }
    else {
      $return = FALSE;
    }

    // Invoke migration complete handlers.
    $this->complete($data, $row);

    return $return;
  }

  public function __construct() {
    parent::__construct();
  }

  /**
   * Implementation of MigrateDestination::prepare().
   */
  public function prepare($preset, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $preset->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('preset', 'prepare', $preset, $row);
    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($preset, $row);
    }
  }

  public function complete($preset, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $preset->migrate = array(
      'machineName' => $migration->getMachineName(),
    );
    // Call any general handlers.
    migrate_handler_invoke_all('preset', 'complete', $preset, $row);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'complete')) {
      $migration->complete($preset, $row);
    }
  }

  /**
   * Delete a single preset.
   *
   * @param $id
   *  Array of fields representing the key (in this case, just preset_name).
   */
  public function rollback(array $id) {
    $preset_name = reset($id);

    migrate_instrument_start('generation_variable_preset_delete');
    $this->prepareRollback($preset_name);
    if ($preset = generation_variable_preset_load($preset_name)) {
      generation_variable_preset_delete($preset);
    }
    $this->completeRollback($preset_name);
    migrate_instrument_stop('generation_variable_preset_delete');
  }

  /**
   * Give handlers a shot at cleaning up before a preset has been rolled back.
   *
   * @param $preset_name
   *  ID of the preset about to be deleted.
   */
  public function prepareRollback($preset_name) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    // Call any general handlers.
    migrate_handler_invoke_all('preset', 'prepareRollback', $preset_name);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'prepareRollback')) {
      $migration->prepareRollback($preset_name);
    }
  }

  /**
   * Give handlers a shot at cleaning up after a preset has been rolled back.
   *
   * @param $preset_name
   *  ID of the preset which has been deleted.
   */
  public function completeRollback($preset_name) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    // Call any general handlers.
    migrate_handler_invoke_all('preset', 'completeRollback', $preset_name);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'completeRollback')) {
      $migration->completeRollback($preset_name);
    }
  }
}

/**
 * Creates a migration destination for the Generation preset.
 */
class MigrateDestinationSiteVariables extends MigrateDestination {
  static public function getKeySchema() {
    return array(
      'period' => array(
        'type' => 'varchar',
        'length' => 16,
        'not null' => TRUE,
        'description' => 'Day, Week, Month, Year, Lifetime',
      ),
      'preset_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'Id of the preset',
      ),
      'site_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'Node id',
      ),
    );
  }

  public function __toString() {
    return "Site Variable";
  }

  public function fields(){
    return array(
      'period' => 'The period.',
      'preset_id' => 'The variable preset to show on the site chart.',
      'site_id' => 'The Drupal entity ID of the generation site.',
    );
  }

  public function import(stdClass $chart_variable, stdClass $row){
    $applied = FALSE;
    module_load_include('inc', 'generation', 'generation');
    _generation_refresh_variables();

    migrate_instrument_start('generation_charts_add_site_presets');
    $site = generation_site_load($chart_variable->site_id);

    if ($site) {
      $record = array(
        'period' => $chart_variable->period,
        'preset_id' => $chart_variable->preset_id,
        'site_id' => $site->id,
      );
      $applied = drupal_write_record('generation_charts_site_presets', $record);
    }
    migrate_instrument_stop('generation_charts_add_site_presets');

    if ($applied) {
      $this->numCreated++;
      return $record;
    }
  }

  public function __construct() {
    parent::__construct();
  }

  /**
   * Implementation of MigrateDestination::prepare().
   */
  public function prepare($preset, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $preset->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('site_variable', 'prepare', $preset, $row);
    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($preset, $row);
    }
  }

  /**
   * Delete a single preset.
   *
   * @param $id
   *  Array of fields representing the keys.
   */
  public function rollback(array $id) {
    migrate_instrument_start('generation_charts_delete_site_presets');
    db_delete('generation_charts_site_presets')
      ->condition('period', $id['destid1'])
      ->condition('preset_id', $id['destid2'])
      ->condition('site_id', $id['destid3'])
      ->execute();
    migrate_instrument_stop('generation_charts_delete_site_presets');
  }
}

/**
 * Creates a migration destination for the Generation Explore Data chart.
 */
class MigrateDestinationChartVariables extends MigrateDestination {
  static public function getKeySchema() {
    return array(
      'preset_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'Id of the preset',
      ),
      'site_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'Node id',
      ),
    );
  }

  public function __toString() {
    return "Explore Data Variables";
  }

  public function fields(){
    return array(
      'preset_id' => 'The variable preset to show on the site chart.',
      'site_id' => 'The Drupal entity ID of the generation site.',
    );
  }

  public function import(stdClass $chart_variable, stdClass $row){
    $applied = FALSE;
    module_load_include('inc', 'generation', 'generation');
    _generation_refresh_variables();

    migrate_instrument_start('explore_data_add_site_presets');
    $site = generation_site_load($chart_variable->site_id);

    if ($site) {
      $record = array(
        'preset_id' => $chart_variable->preset_id,
        'site_id' => $site->id,
      );
      $applied = drupal_write_record('explore_data_site_presets', $record);
    }
    migrate_instrument_stop('explore_data_add_site_presets');

    if ($applied) {
      $this->numCreated++;
      return $record;
    }
  }

  public function __construct() {
    parent::__construct();
  }

  /**
   * Implementation of MigrateDestination::prepare().
   */
  public function prepare($preset, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $preset->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('chart_variable', 'prepare', $preset, $row);
    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($preset, $row);
    }
  }

  /**
   * Delete a single preset.
   *
   * @param $id
   *  Array of fields representing the keys.
   */
  public function rollback(array $id) {
    migrate_instrument_start('explore_data_delete_site_presets');
    db_delete('explore_data_site_presets')
      ->condition('preset_id', $id['destid1'])
      ->condition('site_id', $id['destid2'])
      ->execute();
    migrate_instrument_stop('explore_data_delete_site_presets');
  }
}

/**
 * Maps Generation Variables available on a per-site basis from D6 to D7.
 */
class SolarGenerationChartVariablesMigration extends SolarGeneration {
  /**
   * General initialization of a Migration object.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'preset_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Id of the preset',
        ),
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Node id',
        ),
      ),
      MigrateDestinationChartVariables::getKeySchema()
    );

    $this->source = new MigrateDrupal6SourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->destination = new MigrateDestinationChartVariables();

    $this->addFieldMapping('site_id', 'nid')
      ->sourceMigration(array('Decks', 'Schools'))
      ->callbacks(array($this, 'node_get_site_id'));

    $this->addFieldMapping('preset_id', 'preset_id')
      ->sourceMigration('Presets');
  }

  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('explore_data_site_presets', 'edsp')
             ->fields('edsp');

    return $query;
  }
}
