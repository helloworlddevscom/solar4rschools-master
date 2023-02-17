<?php
/**
 * @file
 * cebf_resources.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function cebf_resources_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_activity_education_science';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_activity_education_science';
  $facet->enabled = FALSE;
  $facet->hash = 'f0s19xfwIlcOyiEPVOF1fLPShjnU3XMa';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'activity_education_science',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'education_science_practice',
  );
  $export['search_api@resources::field_activity_education_science'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_activity_energy_content';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_activity_energy_content';
  $facet->enabled = FALSE;
  $facet->hash = 'BoZPrTXgJzWh7K06EQa5XY1pNkf9rBXp';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'activity_energy_content',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'energy_content',
  );
  $export['search_api@resources::field_activity_energy_content'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_activity_ngss_disciplinary';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_activity_ngss_disciplinary';
  $facet->enabled = FALSE;
  $facet->hash = '1bFct02gEax0KByjm9hMg9DIF4CzndNq';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'activity_ngss_disciplinary',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'ngss_disciplinary_core_idea',
  );
  $export['search_api@resources::field_activity_ngss_disciplinary'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_activity_other_subjects';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_activity_other_subjects';
  $facet->enabled = FALSE;
  $facet->hash = 'd4AeAnMXbKUm3Zq7RBB3qTlCRD3LGHFB';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'activity_other_subjects',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'other_subjects_covered',
  );
  $export['search_api@resources::field_activity_other_subjects'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_resource_geography';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_resource_geography';
  $facet->enabled = FALSE;
  $facet->hash = 'xkvRXXyfBpG0x75kZKR7DV9kcN0BUavq';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'geography',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'geography',
  );
  $export['search_api@resources::field_resource_geography'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_resource_grade_levels';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_resource_grade_levels';
  $facet->enabled = FALSE;
  $facet->hash = 'E6dObjY9NcVCD3jwCHiyhYPY5Nb62jo9';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'grade_levels',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'grade_levels_resource',
  );
  $export['search_api@resources::field_resource_grade_levels'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources::field_resource_type';
  $facet->searcher = 'search_api@resources';
  $facet->realm = '';
  $facet->facet = 'field_resource_type';
  $facet->enabled = FALSE;
  $facet->hash = 'gr4riORj3uB4G6ceLnY1smpxzBQfSs1q';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'resource_type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'resource_type',
  );
  $export['search_api@resources::field_resource_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_activity_education_science';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_education_science';
  $facet->enabled = TRUE;
  $facet->hash = 'HBSWwgK0vcVrxAl47x3fAU4N0AP4kjnL';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Pedagogy &amp; Practice',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_activity_education_science'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_activity_energy_content';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_energy_content';
  $facet->enabled = TRUE;
  $facet->hash = 'bklDVeycudj44v0wX301ATBYodcaYHev';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Energy Content',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_activity_energy_content'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_activity_ngss_disciplinary';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_ngss_disciplinary';
  $facet->enabled = TRUE;
  $facet->hash = 'sCUZ3xWUHSFErHqsQdwe87cIBw0QfJZO';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'NGSS Disciplinary Core Idea',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_activity_ngss_disciplinary'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_activity_other_subjects';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_other_subjects';
  $facet->enabled = TRUE;
  $facet->hash = 'zN6XWL40YIZ7SycwrgGw01ogdEKNYMEk';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Other Subjects Covered',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_activity_other_subjects'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_resource_geography';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_resource_geography';
  $facet->enabled = TRUE;
  $facet->hash = 'pnsC86BpIdrsHvByyY2NBj07YQCTSct1';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 1,
    'title' => 'Location',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_resource_geography'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_resource_grade_levels';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_resource_grade_levels';
  $facet->enabled = TRUE;
  $facet->hash = 'ZkNIc1aqWaAqX1DxOK10bQwtPb7G08jY';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 1,
    'title' => 'Intended Grade Level',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_resource_grade_levels'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@resources:block:field_resource_type';
  $facet->searcher = 'search_api@resources';
  $facet->realm = 'block';
  $facet->facet = 'field_resource_type';
  $facet->enabled = TRUE;
  $facet->hash = 'BTwaoQK0shIAZIMKWaX4hoNlqsrvnJmf';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Resource Type',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@resources:block:field_resource_type'] = $facet;

  return $export;
}
