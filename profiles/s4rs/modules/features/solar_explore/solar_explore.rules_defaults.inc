<?php
/**
 * @file
 * solar_explore.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function solar_explore_default_rules_configuration() {
  $items = array();
  $items['rules_flag_project_when_saving_graph'] = entity_import('rules_config', '{ "rules_flag_project_when_saving_graph" : {
      "LABEL" : "Flag project when saving graph",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag", "eck" ],
      "ON" : { "saved_graph_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "saved-graph" ],
            "type" : "saved_graph",
            "bundle" : { "value" : { "saved_graph" : "saved_graph" } }
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "my_projects_to_explore",
            "node" : [ "saved-graph:field-related-project" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
