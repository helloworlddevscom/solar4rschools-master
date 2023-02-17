<?php
/**
 * @file
 * solar_applications.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function solar_applications_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_applicant|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_applicant';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Applicant profile',
    'weight' => '3',
    'children' => array(
      0 => 'field_cell_phone',
      1 => 'field_email',
      2 => 'field_first_name',
      3 => 'field_last_name',
      4 => 'field_mailing_address',
      5 => 'field_phone',
      6 => 'field_title',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Applicant profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'In the space below, please provide contact information of the person completing the application. ',
      ),
      'formatter' => 'start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_application';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application',
    'weight' => '0',
    'children' => array(
      0 => 'group_applicant',
      1 => 'group_begin',
      2 => 'group_commitment',
      3 => 'group_cost',
      4 => 'group_faculty_owner',
      5 => 'group_monitoring',
      6 => 'group_narratives',
      7 => 'group_photovoltaic',
      8 => 'group_school',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Application',
      'instance_settings' => array(
        'classes' => 'group-application field-group-multipage-group',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '0',
        'move_additional' => '1',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_begin|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_begin';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Renewable School Application',
    'weight' => '2',
    'children' => array(
      0 => 'field_begin',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Renewable School Application',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-begin',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_classroom_updates|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_classroom_updates';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_commitment';
  $field_group->data = array(
    'label' => 'Classroom Updates',
    'weight' => '59',
    'children' => array(
      0 => 'field_would_the_teacher_champion',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Classroom Updates',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-classroom-updates field-group-fieldset',
        'description' => 'Solar 4R SchoolsTM asks that at least one designated Teacher Champion at each awarded school provide a “Classroom Update” onto your project’s web-based profile at least once per year. Classroom Updates are a narrative description of how the renewable energy education materials and resources are being used within your school and could include information about events the school has hosted, classroom activities, and other relevant news. Teacher Champions simply log into their account, and can post their updates in a blog-like format directly onto the profile page of the project they champion. ',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_commitment|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_commitment';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Applicant’s commitment to renewable energy education',
    'weight' => '9',
    'children' => array(
      0 => 'group_classroom_updates',
      1 => 'group_participation',
      2 => 'group_teacher_champion',
      3 => 'group_utilization',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Applicant’s commitment to renewable energy education',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Optimizing the number of students engaged in hands-on renewable energy education is the primary mission of the Solar 4R SchoolsTM program. Your commitment to bring our resources into your classroom is a significant part of your application. Please answer the questions below to indicate the level of your individual and/or your school community’s commitment to incorporate renewable energy education into your school’s classrooms.
',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cost|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_cost';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Project cost share',
    'weight' => '6',
    'children' => array(
      0 => 'field_amount_support',
      1 => 'field_shared_cost',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Project cost share',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'While not required, funding from the school or school community will often help to leverage other funding for your project.',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faculty_owner|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_faculty_owner';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Facility owner profile',
    'weight' => '5',
    'children' => array(
      0 => 'field_facility_owner_address',
      1 => 'field_faculty_approval',
      2 => 'field_faculty_first_name',
      3 => 'field_faculty_last_name',
      4 => 'field_faculty_title',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Facility owner profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Please enter the contact information and mailing address of the school district or administrative offices (facility owner) where contracts and project correspondence should be sent:
',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interconnecting|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_interconnecting';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_school';
  $field_group->data = array(
    'label' => 'Interconnecting utility: ',
    'weight' => '65',
    'children' => array(
      0 => 'field_faculty_architect',
      1 => 'field_faculty_manager',
      2 => 'field_it_contact',
      3 => 'field_school_principal_or_key_fa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Interconnecting utility: ',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-interconnecting field-group-fieldset',
        'description' => 'Please provide the name of the utility that provides electric service to your school. Please note that BEF does not fund off-grid projects:
',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_monitoring|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_monitoring';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Energy monitoring and touchscreen kiosk',
    'weight' => '8',
    'children' => array(
      0 => 'field_based_on_the_physical_cons',
      1 => 'field_commit_maintenance',
      2 => 'field_confirm_install',
      3 => 'field_data_port',
      4 => 'field_kiosk',
      5 => 'field_please_explain_',
      6 => 'field_where_in_your_building_cou',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Energy monitoring and touchscreen kiosk',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<p>BEF provides solar energy monitoring hardware to all of our Renewable School projects to enable students to study the performance of the photovoltaic system from the Solar4RSchools.org website. In some cases a touchscreen kiosk with real-time solar energy performance display is also provided to the host facility to facilitate community outreach.</p><p>Download and review (with your network administrator) the network requirements and kiosk options (PDF) >></p><p>Next, answer the question below:</p>',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_narratives1|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_narratives1';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_narratives';
  $field_group->data = array(
    'label' => '1)',
    'weight' => '1',
    'children' => array(
      0 => 'field_profile_text1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '1)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'In as much detail as possible, describe your school and surrounding school community demographics, including: the socioeconomic makeup of the school community (i.e., income level, education level, ethnicity); location of school (urban, rural, suburban); number of students; student-to-teacher ratio; level of parental and/or community involvement in the school; type and number (if any) of accelerated programs, alternative education programs, or special programming offered by the school in math and science.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_narratives2|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_narratives2';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_narratives';
  $field_group->data = array(
    'label' => '2)',
    'weight' => '2',
    'children' => array(
      0 => 'field_profile_text2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '2)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-narratives2 field-group-fieldset',
        'description' => 'In as much detail as possible, describe what makes your school’s educational community unique, including: do you have unique educational challenges; do you have a unique or interesting educational culture or school population that you serve; do you have an inspiring educator or school administrators with a unique interest in math, science and/or renewable energy; do you have significantly engaged parents or community members?',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_narratives3|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_narratives3';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_narratives';
  $field_group->data = array(
    'label' => '3) ',
    'weight' => '60',
    'children' => array(
      0 => 'field_profile_text4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '3) ',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-narratives3 field-group-fieldset',
        'description' => 'In as much detail as possible, tell us why receiving a project grant is important to you and your school, including: express your commitment to the Solar 4R SchoolsTM program mission; what about this program excites you and your school community the most; is your application part of a larger district-wide sustainability and/or renewable energy initiatives, and if so, please describe these initiatives and how the program could enhance them; how many students will this program reach annually and how do you envision the program enhancing the education of these students and/or their personal behaviors around energy use and/or energy conservation? ',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_narratives4|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_narratives4';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_narratives';
  $field_group->data = array(
    'label' => '4)',
    'weight' => '61',
    'children' => array(
      0 => 'field_profile_text3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '4)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-narratives4 field-group-fieldset',
        'description' => 'In exchange for your grant award, we ask that educators within the awarded school demonstrate a commitment to use and integrate the renewable energy education teacher training, materials and resources we provide into your classrooms. In the space below, please describe at least 3 meaningful, specific methods for how you intend to educate K-12 students using the materials we provide and/or additional resources available to you. Be sure to include: (1) how many educators in your school are committed to utilize our educational materials in their classroom; (2) what methods will you use to educate students about the science and benefits of renewable energy, such as integration of specific activities and science kits with your science curriculum; and (3) how many classrooms and students (on average) will be reached through this educational programming each year.
',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_narratives|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_narratives';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Applicant narratives:',
    'weight' => '10',
    'children' => array(
      0 => 'field__optional_if_there_is_any_',
      1 => 'group_narratives1',
      2 => 'group_narratives2',
      3 => 'group_narratives3',
      4 => 'group_narratives4',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Applicant narratives:',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'First and foremost, Solar 4R SchoolsTM is a renewable energy education program that relies on passionate educators to bring the science and benefits of clean, renewable energy to life in their classrooms. Our goal is to bring hands-on renewable energy education to every classroom in the nation. To this end, we ask that each applicant submit a narrative response to each of the questions below to help us learn more about your school community, and your interest in renewable energy education. ',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participation|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_participation';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_commitment';
  $field_group->data = array(
    'label' => 'Participation in renewable energy teacher training',
    'weight' => '57',
    'children' => array(
      0 => 'field_participation_in_renewable',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Participation in renewable energy teacher training',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Our awarded schools receive a four to five hour workshop for teachers designed to help participants fully integrate the science kits, activities and hands-on learning materials provided with your award into as many classrooms in the awarded school as possible.  

<label>Which teachers at your school would be interested in attending the teacher training?</label>Please include the teachers’ names, subject areas and grade levels:',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photovoltaic|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_photovoltaic';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'Photovoltaic site considerations',
    'weight' => '7',
    'children' => array(
      0 => 'field_photovoltaic_survey',
      1 => 'field_please_attach_the_study_he',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_school|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_school';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application';
  $field_group->data = array(
    'label' => 'School profile',
    'weight' => '4',
    'children' => array(
      0 => 'field_grade_level_s_served',
      1 => 'field_project_location',
      2 => 'field_school_name',
      3 => 'field_students_reached',
      4 => 'field_type_of_organization',
      5 => 'field_website',
      6 => 'group_interconnecting',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'School profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'In the space below, please provide information about the school that will host the photovoltaic solar energy generation project. ',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teacher_champion|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_teacher_champion';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_commitment';
  $field_group->data = array(
    'label' => 'Teacher Champion contact information',
    'weight' => '52',
    'children' => array(
      0 => 'field_same_as_applicant',
      1 => 'field_teacher_champion_contact_i',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Teacher Champion contact information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-teacher-champion field-group-fieldset',
        'description' => 'To be successful, our program needs at least one local Teacher Champion prepared to inspire educators within their education community to utilize the resources our program provides. Please provide the name(s) of key individuals at your school who are excited and willing to help our program bring solar energy generation and education to your school or campus. In the space below, please identify the designated Teacher Champion for this project.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_utilization|entityform|renewable_school_application|form';
  $field_group->group_name = 'group_utilization';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'renewable_school_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_commitment';
  $field_group->data = array(
    'label' => 'Utilization of educational materials:',
    'weight' => '58',
    'children' => array(
      0 => 'field_among_the_materials_listed',
      1 => 'field_please_provide_a_brief_exp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Utilization of educational materials:',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-utilization field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('1)');
  t('2)');
  t('3) ');
  t('4)');
  t('Applicant narratives:');
  t('Applicant profile');
  t('Applicant’s commitment to renewable energy education');
  t('Application');
  t('Classroom Updates');
  t('Energy monitoring and touchscreen kiosk');
  t('Facility owner profile');
  t('Interconnecting utility: ');
  t('Participation in renewable energy teacher training');
  t('Photovoltaic site considerations');
  t('Project cost share');
  t('Renewable School Application');
  t('School profile');
  t('Teacher Champion contact information');
  t('Utilization of educational materials:');

  return $field_groups;
}
