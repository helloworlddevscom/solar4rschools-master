<?php
/**
 * @file
 * solar_activities.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_activities_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
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
function solar_activities_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function solar_activities_default_entityform_type() {
  $items = array();
  $items['request_removal_of_an_activity'] = entity_import('entityform_type', '{
    "type" : "request_removal_of_an_activity",
    "label" : "Request removal of an activity",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submission_rules" : { "rules_activity_removal_requested" : "rules_activity_removal_requested" },
      "validation_rules" : [],
      "submit_button_text" : "",
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "user_submissions_view" : "user_entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "6" : "6",
        "7" : "7",
        "1" : 0,
        "2" : 0,
        "5" : 0,
        "8" : 0,
        "4" : 0,
        "3" : 0
      },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003EAdministrator approval is required to delete an activity from our site, but if you\\u0027re the author of a given Teacher Activity and would like to remove the activity, you may request that here.\\u003C\\/p\\u003E",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function solar_activities_flag_default_flags() {
  $flags = array();
  // Exported flag: "My Saved Activities".
  $flags['my_saved_activities'] = array(
    'entity_type' => 'node',
    'title' => 'My Saved Activities',
    'global' => 0,
    'types' => array(
      0 => 'activity',
    ),
    'flag_short' => 'Add to My Saved Activities',
    'flag_long' => 'Add to My Saved Activities',
    'flag_message' => 'Added',
    'unflag_short' => 'Remove from My Saved Activities',
    'unflag_long' => 'Remove from My Saved Activities',
    'unflag_message' => 'Removed',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => 'teaser',
      'full' => 0,
      'rss' => 0,
      'reference' => 0,
      'diff_standard' => 0,
      'map_bubble_teaser' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'solar_activities',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function solar_activities_image_default_styles() {
  $styles = array();

  // Exported image style: activity_thumbnail.
  $styles['activity_thumbnail'] = array(
    'label' => 'Activity Thumbnail',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 358,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function solar_activities_node_info() {
  $items = array(
    'activity' => array(
      'name' => t('Activity'),
      'base' => 'node_content',
      'description' => t('Activities for teaching about solar technologies that appear in the Teacher Activity Center.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'science_kit' => array(
      'name' => t('Science Kit'),
      'base' => 'node_content',
      'description' => t('Science kits contain materials to educate on solar power.'),
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
function solar_activities_default_search_api_index() {
  $items = array();
  $items['activities'] = entity_import('search_api_index', '{
    "name" : "Activities",
    "machine_name" : "activities",
    "description" : "Index of Activities for Teacher Activity Center search.",
    "server" : "default",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "activity" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text", "boost" : "2.0" },
        "body:value" : { "type" : "text", "boost" : "2.0" },
        "field_activity_education_science" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_energy_content" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_length2" : { "type" : "integer" },
        "field_activity_ngss_disciplinary" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_ngss_science" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_activity_other_subjects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_common_core_standard_s_met" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_grade_levels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_learning_goals_met:value" : { "type" : "text" },
        "field_lesson_number" : { "type" : "string" },
        "field_next_generation_science_st" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_other_materials_used" : { "type" : "text" },
        "field_science_kit_materials_used" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_unit_title" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_unit_title:name" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "sort_field_lesson_number" : { "type" : "string" },
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
                "name" : "Lesson Number",
                "type" : "fulltext",
                "separator" : "\\n\\n",
                "fields" : [ "field_lesson_number" ],
                "description" : "A Fulltext aggregation of the following fields: Lesson Number."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "mode" : "full", "global_language_switch" : 0 }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_elasticsearch_natural_sort" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_lesson_number" : true } }
        }
      },
      "processors" : {
        "solar_search_save_recent" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_other_materials_used" : true,
              "field_lesson_number" : true,
              "field_learning_goals_met:value" : true
            }
          }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "type" : true,
              "title" : true,
              "status" : true,
              "author" : true,
              "field_activity_length2" : true,
              "field_grade_levels" : true,
              "field_common_core_standard_s_met" : true,
              "field_next_generation_science_st" : true,
              "field_other_materials_used" : true,
              "field_science_kit_materials_used" : true,
              "field_unit_title" : true,
              "field_activity_education_science" : true,
              "field_activity_energy_content" : true,
              "field_activity_ngss_disciplinary" : true,
              "field_activity_other_subjects" : true,
              "field_lesson_number" : true,
              "field_activity_ngss_science" : true,
              "search_api_language" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_learning_goals_met:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_other_materials_used" : true,
              "field_lesson_number" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_learning_goals_met:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_other_materials_used" : true,
              "field_learning_goals_met:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_other_materials_used" : true,
              "field_lesson_number" : true,
              "field_learning_goals_met:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_other_materials_used" : true,
              "field_lesson_number" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_learning_goals_met:value" : true
            },
            "exceptions" : "texan=texa"
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
