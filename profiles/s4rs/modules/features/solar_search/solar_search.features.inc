<?php
/**
 * @file
 * solar_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function solar_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function solar_search_default_search_api_index() {
  $items = array();
  $items['default'] = entity_import('search_api_index', '{
    "name" : "default",
    "machine_name" : "default",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "default",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : { "kiosk" : "kiosk", "order" : "order" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_2" : {
                "name" : "String title",
                "type" : "first",
                "fields" : [ "title" ],
                "description" : "A First aggregation of the following fields: Title."
              }
            }
          }
        }
      },
      "processors" : {
        "solar_search_save_recent" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "search_api_viewed" : true, "body:value" : true } }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "search_api_viewed" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "field_activity_length2" : { "type" : "decimal" },
        "field_common_core_standard_s_met" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_equipment_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_funding_level" : { "type" : "string" },
        "field_geolocation:latlon" : { "type" : "text" },
        "field_grade_levels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_next_generation_science_st" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_next_generation_science_st:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_project_location:administrative_area" : { "type" : "string", "boost" : "0.8" },
        "field_project_type" : { "type" : "string" },
        "field_science_kit_materials_used" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_science_kit_materials_used:field_common_core_standard_s_met" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_science_kit_materials_used:field_next_generation_science_st" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_science_kit_materials_used:title" : { "type" : "list\\u003Ctext\\u003E", "boost" : "5.0" },
        "field_subject_area_s_" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_system_size" : { "type" : "decimal" },
        "field_technology_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "members__1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_2" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['users'] = entity_import('search_api_index', '{
    "name" : "Users",
    "machine_name" : "users",
    "description" : "User index",
    "server" : "default",
    "item_type" : "user",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "name" : { "type" : "string" },
        "og_membership__1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "og_membership" },
        "og_user_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_user_node:field_common_core_standard_s_met" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "og_user_node:field_equipment_types" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "og_user_node:field_grade_levels" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "og_user_node:field_next_generation_science_st" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "og_user_node:field_project_location:administrative_area" : { "type" : "list\\u003Cstring\\u003E" },
        "og_user_node:field_project_type" : { "type" : "list\\u003Cstring\\u003E" },
        "og_user_node:field_system_size" : { "type" : "list\\u003Cdecimal\\u003E" },
        "og_user_node:field_technology_type" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "og_user_node:nid" : { "type" : "list\\u003Cinteger\\u003E" },
        "og_user_node__og_membership__1:id" : { "type" : "list\\u003Cinteger\\u003E" },
        "profile_funder:field_show_funder" : { "type" : "boolean" },
        "roles" : { "type" : "list\\u003Cinteger\\u003E" },
        "search_api_language" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function solar_search_default_search_api_server() {
  $items = array();
  $items['default'] = entity_import('search_api_server', '{
    "name" : "default",
    "machine_name" : "default",
    "description" : "This is a Solr server.",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "727f67e7-eb02-409e-bae8-83c38874da94-live",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
