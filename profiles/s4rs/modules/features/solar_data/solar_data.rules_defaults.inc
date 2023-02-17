<?php
/**
 * @file
 * solar_data.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function solar_data_default_rules_configuration() {
  $items = array();
  $items['rules_add_widget_to_all_projects'] = entity_import('rules_config', '{ "rules_add_widget_to_all_projects" : {
      "LABEL" : "Add widget to all projects",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "widgets" ],
      "REQUIRES" : [ "views_rules", "rules" ],
      "USES VARIABLES" : { "widget" : { "label" : "Widget", "type" : "equivalencies_statistics" } },
      "DO" : [
        { "VIEW LOOP" : {
            "VIEW" : "projects",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : { "node" : { "project" : "Projects" } },
            "DO" : [
              { "component_rules_add_widget_to_one_project" : { "widget" : [ "widget" ], "project" : [ "project" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_add_widget_to_one_project'] = entity_import('rules_config', '{ "rules_add_widget_to_one_project" : {
      "LABEL" : "Add widget to one project",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "widget" : { "label" : "Widget", "type" : "equivalencies_statistics" },
        "project" : { "label" : "Project", "type" : "node" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "project" ],
            "type" : "node",
            "bundle" : { "value" : { "project" : "project" } }
          }
        }
      ],
      "DO" : [
        { "list_add" : {
            "list" : [ "project:field-show-realtime" ],
            "item" : [ "widget" ],
            "unique" : 1
          }
        }
      ]
    }
  }');
  $items['solar_data_add_widget_to_all_funders'] = entity_import('rules_config', '{ "solar_data_add_widget_to_all_funders" : {
      "LABEL" : "Add widget to all funders",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "widgets" ],
      "REQUIRES" : [ "views_rules", "rules" ],
      "USES VARIABLES" : { "widget" : { "label" : "Widget", "type" : "equivalencies_statistics" } },
      "DO" : [
        { "VIEW LOOP" : {
            "VIEW" : "funders",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : { "uid" : { "user" : "User: Uid" } },
            "DO" : [
              { "component_solar_data_add_widget_to_one_project_cloned_" : { "widget" : [ "widget" ], "funder" : [ "user:profile-funder" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['solar_data_add_widget_to_one_project_cloned_'] = entity_import('rules_config', '{ "solar_data_add_widget_to_one_project_cloned_" : {
      "LABEL" : "Add widget to one funder",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "widgets" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "widget" : { "label" : "Widget", "type" : "equivalencies_statistics" },
        "funder" : { "label" : "Funder", "type" : "profile2" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "funder" ],
            "type" : "profile2",
            "bundle" : { "value" : { "funder" : "funder" } }
          }
        }
      ],
      "DO" : [
        { "list_add" : {
            "list" : [ "funder:field-show-funder-widgets" ],
            "item" : [ "widget" ],
            "unique" : 1
          }
        }
      ]
    }
  }');
  return $items;
}
