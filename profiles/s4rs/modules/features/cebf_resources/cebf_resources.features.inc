<?php
/**
 * @file
 * cebf_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cebf_resources_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cebf_resources_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cebf_resources_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('Resources that appear in the Resource Library'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function cebf_resources_default_search_api_index() {
  $items = array();
  $items['resources'] = entity_import('search_api_index', '{
    "name" : "Resources",
    "machine_name" : "resources",
    "description" : "Index of Resource nodes for Resource Library search.",
    "server" : "default",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "resource" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text", "boost" : "2.0" },
        "body:value" : { "type" : "text", "boost" : "2.0" },
        "field_activity_education_science" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_energy_content" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_ngss_disciplinary" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_other_subjects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resource_date" : { "type" : "date" },
        "field_resource_file:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_resource_geography" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resource_grade_levels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resource_source" : { "type" : "text" },
        "field_resource_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resource_url:display_url" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_resource_workshop_id" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resource_workshop_id:name" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "3.0" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : [] }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title - string",
                "type" : "first",
                "separator" : "\\n\\n",
                "fields" : [ "title" ],
                "description" : "A First aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "mode" : "full", "global_language_switch" : 1 }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_elasticsearch_natural_sort" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        }
      },
      "processors" : {
        "solar_search_save_recent" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_resource_source" : true } }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "type" : true,
              "title" : true,
              "field_activity_education_science" : true,
              "field_activity_energy_content" : true,
              "field_activity_ngss_disciplinary" : true,
              "field_activity_other_subjects" : true,
              "field_resource_geography" : true,
              "field_resource_grade_levels" : true,
              "field_resource_source" : true,
              "field_resource_type" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_resource_file:file" : true,
              "field_resource_url:display_url" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true, "body:summary" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_resource_source" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_resource_source" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : { "title" : true, "field_resource_source" : true },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
