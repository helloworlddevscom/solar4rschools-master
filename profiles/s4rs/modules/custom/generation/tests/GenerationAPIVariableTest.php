<?php
/**
 * @file
 * Tests for Generation API module.
 */

abstract class GenerationAPITestCase extends PHPUnit_Framework_TestCase {
  protected $flushTables;

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    $this->resetDatabase();
  }

  /**
   * Wipe all data from applicable tables before each test.
   */
  protected function resetDatabase() {
    foreach ($this->flushTables as $table) {
      db_delete($table)->execute();
    }
  }

  /**
   * Construct a new variable fixture.
   */
  protected function newVariable($overrides = array()) {
    // Name the variable something new each time to avoid DB constraint errors
    // without wiping the DB for *each* test.
    static $count = 0;
    return (object) ($overrides + array(
      'name' => 'TestVar_' . $count++,
      'module' => 'TestModule',
      'type' => 'Energy',
    ));
  }
}


class GenerationAPIVariableTests extends GenerationAPITestCase {

  /**
   * Constructor.
   */
  public function __construct() {
    $this->flushTables = array('generation_variables');
  }

  /**
   * Tests saving and loading a variable.
   */
  public function testVariableSaveLoad() {
    $saved = $this->newVariable();
    generation_variable_save($saved);
    $this->assertAttributeNotEmpty('variable_id', $saved, 'Variable should have ID after saving');

    $loaded = generation_variable_load($saved->variable_id);
    $this->assertEquals($loaded, $saved, 'Loading just-saved variable should give same data');
  }

  /**
   * Tests re-saving (updating) a variable.
   */
  public function testVariableUpdate() {
    $original = $this->newVariable();
    generation_variable_save($original);

    $revision = clone $original;
    $revision->name = 'Revised';
    generation_variable_save($revision);
    $this->assertEquals($original->variable_id, $revision->variable_id, 'Resaving variable should not change ID');

    $loaded = generation_variable_load($original->variable_id);
    $this->assertEquals($loaded->name, 'Revised', 'Changes to resaved variable should persist');
  }

}

class GenerationAPIPresetTests extends GenerationAPITestCase {

  /**
   * Constructor.
   */
  public function __construct() {
    $this->flushTables = array(
      'generation_variable_presets',
      'generation_preset_override',
    );
  }

  /**
   * Construct a new variable preset fixture.
   */
  protected function newPreset($variable_id) {
    static $count = 0;

    $preset = generation_variable_preset_new();
    $preset->alias = 'TestPreset_' . $count++;
    $preset->description = 'TestPresetDescription';
    $preset->variable_id = $variable_id;
    return $preset;
  }

  /**
   * Tests saving presets and loading multiple presets at once.
   */
  public function testPresetSaveLoadMultiple() {
    $variable = $this->newVariable();
    generation_variable_save($variable);

    $presets = array();
    for ($i = 0; $i < 10; ++$i) {
      $preset = $this->newPreset($variable->variable_id);
      generation_variable_preset_save($preset);
      $presets[$preset->preset_id] = $preset;
    }

    $loaded_presets = generation_variable_preset_load_multiple(array_keys($presets));
    $this->assertEquals($presets, $loaded_presets, 'load multiple should load all presets');
    $this->assertEquals(count($presets), count($loaded_presets), 'load multiple should load same number of presets');
  }

  /**
   * Tests saving and loading a preset.
   */
  public function testPresetSaveLoad() {
    $preset = $this->newPreset($arbitrary = 0);
    generation_variable_preset_save($preset);

    $test = generation_variable_preset_load($preset->preset_id);
    $this->assertEquals($test, $preset, 'Loading just-saved preset should give same data');
  }

  /**
   * Tests saving and loading a site preset override.
   */
  public function testPresetOverrideSaveLoad() {
    $node = (object) array('nid' => 1);
    $preset = $this->newPreset($arbitrary = 0);
    generation_variable_preset_save($preset);

    $test = generation_get_site_preset_override($node, $preset->preset_id);
    $this->assertFalse($test, 'Loading non-existent preset override should fail');

    // Save an override.
    $override = (object) array(
      'nid' => $node->nid,
      'preset_id' => $preset->preset_id,
      'alias' => 'Overridden name',
      'description' => 'Overridden description',
      'units' => 'Overridden units',
    );
    drupal_write_record('generation_preset_override', $override);

    $test = generation_get_site_preset_override($node, $preset->preset_id);
    $this->assertEquals($override, $test, 'Loading just-saved preset override should give same data');
  }
}
