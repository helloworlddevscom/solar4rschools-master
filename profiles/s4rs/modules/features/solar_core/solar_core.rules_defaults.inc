<?php
/**
 * @file
 * solar_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function solar_core_default_rules_configuration() {
  $items = array();
  $items['rules_classroom_update_submitted'] = entity_import('rules_config', '{ "rules_classroom_update_submitted" : {
      "LABEL" : "Content submitted for approval",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "ebarrett@b-e-f.org",
            "subject" : "New content submitted for approval",
            "message" : "New content has been submitted for your approval. To review this content, please go to: \\r\\n[node:edit-url]\\r\\n\\r\\nTo see all content awaiting approval, visit:\\r\\n[site:url]admin\\/workbench\\/needs-review\\r\\n\\r\\nAbout the author:\\r\\nEmail: [node:author:mail]\\r\\nView more: [node:author:url:absolute]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_content_approved'] = entity_import('rules_config', '{ "rules_content_approved" : {
      "LABEL" : "Content approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "NOT entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "activity" : "activity" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Your content has been approved",
            "message" : "New content approved. To review this content, please go to: \\r\\n[node:url:absolute]\\r\\n\\r\\nYou may login and edit this content at:\\r\\n[node:edit-url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_content_needs_work'] = entity_import('rules_config', '{ "rules_content_needs_work" : {
      "LABEL" : "Content needs work",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "NOT entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "activity" : "activity" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Changes have been requested for your content.",
            "message" : "Your content located at [node:url:absolute] has been sent back to draft with the following comments:\\r\\n\\r\\n---\\r\\n\\r\\n[node:log]\\r\\n\\r\\n---\\r\\nYou may login and edit this content at:\\r\\n[node:edit-url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_set_user_as_educator'] = entity_import('rules_config', '{ "rules_set_user_as_educator" : {
      "LABEL" : "Set user as educator",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "NOT list_contains" : { "list" : [ "account:roles" ], "item" : "5" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "account:roles" ], "value" : { "value" : { "6" : "6" } } } }
      ]
    }
  }');
  return $items;
}
