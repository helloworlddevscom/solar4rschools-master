<?php
/**
 * @file
 * cebf_resources.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function cebf_resources_default_rules_configuration() {
  $items = array();
  $items['rules_resource_needs_review'] = entity_import('rules_config', '{ "rules_resource_needs_review" : {
      "LABEL" : "Resource: Needs Review",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "resource" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--resource" : { "bundle" : "resource" } },
      "IF" : [
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "1" : "1" } } } },
        { "data_is" : { "data" : [ "node:status" ], "value" : "0" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[site:mail]",
            "subject" : "CEBF Resource Library: A resource has been created and needs review.",
            "message" : "A new resource has been created using the create resource form.\\r\\n\\r\\nTo review, visit:\\r\\n[node:edit-url]\\r\\n\\r\\nTo see all content that needs review, visit:\\r\\n[site:url]admin\\/workbench\\/needs-review\\r\\n\\r\\nAbout the author:\\r\\nEmail: [node:field-email]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_resource_published'] = entity_import('rules_config', '{ "rules_resource_published" : {
      "LABEL" : "Resource: Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : {
        "node_update--resource" : { "bundle" : "resource" },
        "workbench_moderation_after_moderation_transition" : []
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "resource" : "resource" } }
          }
        },
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "1" : "1" } } } },
        { "data_is" : { "data" : [ "node-unchanged:status" ], "value" : "0" } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:field-email]",
            "subject" : "Your resource has been published!",
            "message" : "The resource you submitted to Clean Energy Bright Futures has been published. Thank you for contributing!\\r\\n\\r\\nSee your resource:\\r\\n[node:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
