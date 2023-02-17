<?php
/**
 * @file
 * solar_applications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function solar_applications_default_rules_configuration() {
  $items = array();
  $items['rules_new_application_submitted'] = entity_import('rules_config', '{ "rules_new_application_submitted" : {
      "LABEL" : "New Application submitted",
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
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_status" } },
        { "data_is" : { "data" : [ "entityform:field-status" ], "value" : "in_progress" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "ebarrett@b-e-f.org",
            "subject" : "New application submitted for approval",
            "message" : "New content has been submitted for your approval. To review this content, please go to: \\r\\n[entityform:url]\\r\\n\\r\\nTo view all applications that are under review, visit:\\r\\n[site:url]admin\\/structure\\/entityform_types\\/manage?field_status_value=in_progress\\r\\n\\r\\nAbout the author:\\r\\nEmail: [entityform:user:mail]\\r\\nView more: [entityform:user:url:absolute]",
            "from" : [ "" ],
            "language" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "entityform:field-status" ], "value" : "under_review" } },
        { "mail" : {
            "to" : "[entityform:user:mail]",
            "subject" : "Solar4RSchools.org \\u2014 Application Under Review",
            "message" : "Dear Applicant,\\r\\n\\r\\nThank you for submitting a Renewable Classroom or Renewable School project application to the Solar 4R Schools program. We rely on the passion and commitment of educators like you to champion the integration of our hands-on, high quality STEM renewable energy education into classrooms nationwide.\\r\\n\\r\\nProject funding awards are tied to two designated application review periods\\u2014fall and spring. At the end of each review period, all applicants will be informed of the status of their application by email. In the case where matching funding is not yet available, strong applications may be profiled in the \\u201cProjects Needing Funding\\u201d area of our website until we identify a potential project sponsor.\\r\\n\\r\\nFALL\\u2014Application Deadline: October 15; Communication of Application Status: December 1\\r\\nSPRING\\u2014Application Deadline: April 15; Communication of Application Status: June 1\\r\\n\\r\\nYou can check the status of your application at any time from the \\u201cMy Applications\\u201d area of your account. \\r\\n\\r\\nThanks!\\r\\n\\r\\nThe Solar 4R Schools Team",
            "from" : [ "" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['solar_applications_application_rejected'] = entity_import('rules_config', '{ "solar_applications_application_rejected" : {
      "LABEL" : "Application rejected",
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
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_status" } },
        { "data_is" : { "data" : [ "entityform:field-status" ], "value" : "not_accepted" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "entityform:user:mail" ],
            "subject" : "Solar4RSchools.org \\u2014 Application Status Update",
            "message" : "Dear Applicant,\\r\\n\\r\\nWe have reviewed your Solar 4R Schools project application. On behalf of the entire BEF team, we want to thank you for your time, energy and dedication to renewable energy education. \\r\\n\\r\\n\\r\\nUnfortunately, we are unable to fund your project at this time. The Solar 4R Schools application process is becoming more competitive each year and we receive more strong applications than there are resources to match. The application you submitted is a good starting point for developing a strong application in the future. If you are interested in updating your proposal and reapplying to the program, we encourage you to do so. \\r\\n\\r\\nIf you have any questions about the application process, feel free to contact the Solar4RSchools.org website customer service Monday-Friday from 8:00am-5:00pm toll free at 503-248-1908.\\r\\n\\r\\n\\r\\n \\r\\nThanks!\\r\\n\\r\\nThe Solar 4R Schools Team",
            "from" : [ "" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['solar_applications_new_application_funded'] = entity_import('rules_config', '{ "solar_applications_new_application_funded" : {
      "LABEL" : "New Application funded",
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
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_status" } },
        { "data_is" : { "data" : [ "entityform:field-status" ], "value" : "funded" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[entityform:user:mail]",
            "subject" : "Solar4RSchools.org \\u2014 Application Has Been Funded",
            "message" : "Dear Applicant,\\r\\n\\r\\nCongratulations! Your project application with the Solar 4R Schools program has been funded thanks to the generous support of our corporate, nonprofit and utility funding partners.\\r\\n\\r\\nWe want to take this moment to thank you for your commitment to renewable energy education and welcome you to the Solar 4R Schools program. You join hundreds of schools and educators nationwide who are dedicated to inspiring the next generation of clean energy leaders.\\r\\n\\r\\nPlease watch your email inbox for a formal award letter and details about how your project package will be delivered.\\r\\n\\r\\n \\r\\nThanks!\\r\\n\\r\\n\\r\\nThe Solar 4R Schools Team",
            "from" : [ "" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
