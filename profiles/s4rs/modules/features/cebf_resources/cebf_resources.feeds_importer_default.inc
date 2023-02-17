<?php
/**
 * @file
 * cebf_resources.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function cebf_resources_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'resources_csv';
  $feeds_importer->config = array(
    'name' => 'Resources CSV',
    'description' => 'Import Resources from CSV file.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'csv',
        'delete_uploaded_file' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'legacy' => 'legacy',
          'legtheme' => 'legtheme',
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'resource',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'date',
            'target' => 'field_resource_date:start',
            'timezone' => 'America/Los_Angeles',
            'language' => 'und',
          ),
          3 => array(
            'source' => 'source',
            'target' => 'field_resource_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'link urls',
            'target' => 'field_resource_url:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'link titles',
            'target' => 'field_resource_url:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'body',
            'target' => 'body',
            'format' => 'filtered_html',
            'language' => 'und',
          ),
          7 => array(
            'source' => 'resource type',
            'target' => 'field_resource_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'grade levels',
            'target' => 'field_resource_grade_levels',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'location',
            'target' => 'field_resource_geography',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'energy content',
            'target' => 'field_activity_energy_content',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'ngss disciplinary',
            'target' => 'field_activity_ngss_disciplinary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'pedagogy and practice',
            'target' => 'field_activity_education_science',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'other subjects',
            'target' => 'field_activity_other_subjects',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'input_format' => 'filtered_html',
        'author' => '0',
        'authorize' => 0,
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'skip_hash_check' => 1,
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );
  $export['resources_csv'] = $feeds_importer;

  return $export;
}
