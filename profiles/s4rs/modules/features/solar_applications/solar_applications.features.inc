<?php
/**
 * @file
 * solar_applications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solar_applications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
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
function solar_applications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function solar_applications_default_entityform_type() {
  $items = array();
  $items['renewable_school_application'] = entity_import('entityform_type', '{
    "type" : "renewable_school_application",
    "label" : "Renewable School Application",
    "data" : {
      "draftable" : 1,
      "draft_button_text" : "SAVE AND SUBMIT LATER \\u003E\\u003E",
      "draft_save_text" : {
        "value" : "\\u003Cp\\u003EYour draft is saved.\\u003C\\/p\\u003E",
        "format" : "full_html"
      },
      "submission_rules" : {
        "rules_new_application_submitted" : "rules_new_application_submitted",
        "solar_applications_application_rejected" : "solar_applications_application_rejected",
        "solar_applications_new_application_funded" : "solar_applications_new_application_funded"
      },
      "validation_rules" : [],
      "submit_button_text" : "Submit application \\u003E\\u003E",
      "submission_page_title" : "Your submissions",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 1,
      "submissions_view" : "filterable_entityforms",
      "user_submissions_view" : "user_entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "4" : "4",
        "3" : "3",
        "1" : 0,
        "2" : 0,
        "5" : 0,
        "8" : 0,
        "6" : 0,
        "7" : 0
      },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "\\/you-apply-0",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/renewable-school-application",
        "alias" : "apply\\/start-new-application",
        "language" : "und"
      }
    }
  }');
  return $items;
}
