<?php
/**
 * @file
 * solar_activities.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function solar_activities_default_rules_configuration() {
  $items = array();
  $items['rules_activity_removal_requested'] = entity_import('rules_config', '{ "rules_activity_removal_requested" : {
      "LABEL" : "Activity removal requested",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entityform submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Submitted Entityform", "type" : "entityform" },
        "entityform_type" : { "label" : "Entityform Type", "type" : "entityform_type" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "entityform-type" ],
            "type" : "entityform_type",
            "bundle" : { "value" : { "entityform_type" : "entityform_type" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_activities_to_remove" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "ebarrett@b-e-f.org",
            "subject" : "Activity removal requested",
            "message" : "The author ([entityform:user:mail]) of an activity ([entityform:field-activities-to-remove:title]) has requested it be removed from the website with the following text\\r\\n\\r\\n---\\r\\n\\r\\n[entityform:field-freeform-html]\\r\\n\\r\\n---\\r\\nTo edit this activity, visit\\r\\n[entityform:field-activities-to-remove:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['solar_core_activity_approved'] = entity_import('rules_config', '{ "solar_core_activity_approved" : {
      "LABEL" : "Activity approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "activity" : "activity" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Solar4RSchools.org \\u2014 Your Activity Has Been Published",
            "message" : "Dear Educator,\\r\\n\\r\\nCongratulations! Your activity or activity extension has been successfully published to the Teacher Activity Center on the Solar4RSchools.org website.\\r\\n\\r\\nYou can make future edits to your activity or add extensions at any time from \\u201cMy Uploaded Activities\\u201d section of your account.  \\r\\n\\r\\nHelp get the word out about your activity with educators in your network. Click the link below and share your activity page to your Facebook profile, or by email to your colleagues to encourage them to review, use, rate or comment on your activity now!\\r\\n\\r\\nGO TO YOUR ACTIVITY NOW \\u2014 [node:url:absolute]\\r\\n\\r\\nThanks!\\r\\n\\r\\nThe Solar 4R Schools Team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['solar_core_activity_needs_work'] = entity_import('rules_config', '{ "solar_core_activity_needs_work" : {
      "LABEL" : "Activity needs work",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "activity" : "activity" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Solar4RSchools.org \\u2014 Please Edit Your Activity",
            "message" : "Dear Educator,\\r\\n\\r\\nThank you for your submission of an activity or activity extension to the Solar4RSchools.org Teacher Activity Center. We rely on the contributions of educators like you to bring hands-on, high quality renewable energy education into classrooms nationwide.\\r\\n\\r\\nWhile we greatly appreciate your contribution, we need your help to complete some edits to your activity before it is published to our site. The notes below from our Education Manager describe the edits requested. Please edit your activity and resubmit it for publication at your convenience. \\r\\n\\r\\n---\\r\\n\\r\\n[node:log]\\r\\n\\r\\n---\\r\\nGO TO YOUR ACTIVITY NOW \\u2014 [node:url]\\r\\n\\r\\nThanks!\\r\\n\\r\\nThe Solar 4R Schools Team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['solar_core_activity_submitted_for_approval'] = entity_import('rules_config', '{ "solar_core_activity_submitted_for_approval" : {
      "LABEL" : "Activity submitted for approval",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "activity" : "activity" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Solar4RSchools.org \\u2014 Your Activity Is Under Review",
            "message" : "Dear Educator,\\r\\n\\r\\nThank you for uploading an activity or activity extension to the Solar4RSchools.org Teacher Activity Center. We rely on the contributions of educators like you to bring hands-on, high quality renewable energy education into classrooms nationwide.\\r\\n\\r\\nYour activity or activity extension has been successfully uploaded and is under review by the Solar 4R Schools team. You will see this status reflected in the \\u201cMy Uploaded Activities\\u201d section of your account.\\r\\n\\r\\nOnce our review is complete and we\\u2019ve approved your activity for publication, you will receive a confirmation email notifying you that the activity is now accessible from the Teacher Activity Center on our website. You can make future edits to your activity or add extensions at any time from your account area. \\r\\n\\r\\nOn occasion, we are unable to publish activities to our site without further edit from our partner educators. Should we have a request for edits to your activity prior to publication, we will notify you by email with detailed feedback from our Education Manager.\\r\\n\\r\\n \\r\\nThanks!\\r\\n\\r\\n\\r\\nThe Solar 4R Schools Team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
