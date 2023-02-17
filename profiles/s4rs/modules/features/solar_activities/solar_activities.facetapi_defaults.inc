<?php
/**
 * @file
 * solar_activities.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function solar_activities_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::author';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'author';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'author',
  );
  $export['search_api@activities::author'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_activity_education_science';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_activity_education_science';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'field_activity_education_science',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'education_science_practice',
  );
  $export['search_api@activities::field_activity_education_science'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_activity_energy_content';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_activity_energy_content';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'energy-content',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'energy_content',
  );
  $export['search_api@activities::field_activity_energy_content'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_activity_ngss_disciplinary';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_activity_ngss_disciplinary';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'field_activity_ngss_disciplinary',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'ngss_disciplinary_core_idea',
  );
  $export['search_api@activities::field_activity_ngss_disciplinary'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_activity_ngss_science';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_activity_ngss_science';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'field_activity_ngss_science',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'ngss_science_engineering_practice',
  );
  $export['search_api@activities::field_activity_ngss_science'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_activity_other_subjects';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_activity_other_subjects';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'field_activity_other_subjects',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'other_subjects_covered',
  );
  $export['search_api@activities::field_activity_other_subjects'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_grade_levels';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_grade_levels';
  $facet->enabled = FALSE;
  $facet->hash = 'eRXJZHosU6pucxdJd1A9G00WVOZjGbrM';
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
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_grade_levels',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'grade_levels',
  );
  $export['search_api@activities::field_grade_levels'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_next_generation_science_st';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_next_generation_science_st';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'next_generation_science_st',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'next_generation_science_standards',
  );
  $export['search_api@activities::field_next_generation_science_st'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities::field_unit_title';
  $facet->searcher = 'search_api@activities';
  $facet->realm = '';
  $facet->facet = 'field_unit_title';
  $facet->enabled = FALSE;
  $facet->hash = '0';
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
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'pretty_paths_alias' => 'field_unit_title',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'unit',
  );
  $export['search_api@activities::field_unit_title'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:author';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'author';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Author',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
  );
  $export['search_api@activities:block:author'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_activity_education_science';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_education_science';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Pedagogy &amp; Practice',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 1,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'disable_empty' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
  );
  $export['search_api@activities:block:field_activity_education_science'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_activity_energy_content';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_energy_content';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_multiselect',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
    ),
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Energy Content',
    'add_count' => 1,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 1,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'disable_empty' => 0,
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'ajax_multiselect_default_option_label' => 'This is a test',
  );
  $export['search_api@activities:block:field_activity_energy_content'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_activity_ngss_disciplinary';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_ngss_disciplinary';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'NGSS Disciplinary Core Idea',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
  );
  $export['search_api@activities:block:field_activity_ngss_disciplinary'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_activity_ngss_science';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_ngss_science';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'NGSS Science and Engineering Practices',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
  );
  $export['search_api@activities:block:field_activity_ngss_science'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_activity_other_subjects';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_activity_other_subjects';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Other Subjects Covered',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
  );
  $export['search_api@activities:block:field_activity_other_subjects'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_grade_levels';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_grade_levels';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_ajax_ranges',
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Intended Grade Level(s)',
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
      'format' => 'full_html',
    ),
  );
  $export['search_api@activities:block:field_grade_levels'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_next_generation_science_st';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_next_generation_science_st';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Relevant NGSS PE',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
  );
  $export['search_api@activities:block:field_next_generation_science_st'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@activities:block:field_unit_title';
  $facet->searcher = 'search_api@activities';
  $facet->realm = 'block';
  $facet->facet = 'field_unit_title';
  $facet->enabled = TRUE;
  $facet->hash = '0';
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
    'empty_behavior' => 'ajax_facets',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Unit',
    'add_count' => 0,
    'remove_count_on_active' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'optgroups' => 1,
    'placeholder_label' => 'Select some options',
    'reset_link' => 0,
    'show_reset_link' => 0,
    'reset_link_text' => 'Reset filter',
    'ajax_select_default_option_label' => 'Select',
    'disable_empty' => 0,
  );
  $export['search_api@activities:block:field_unit_title'] = $facet;

  return $export;
}
