<?php
/**
 * @file
 * solar_kiosk.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function solar_kiosk_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'fieldable_panels_pane-green_tech_content-field_fpp_green_tech_body'.
  $field_instances['fieldable_panels_pane-green_tech_content-field_fpp_green_tech_body'] = array(
    'bundle' => 'green_tech_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_fpp_green_tech_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-green_tech_content-field_fpp_green_tech_images'.
  $field_instances['fieldable_panels_pane-green_tech_content-field_fpp_green_tech_images'] = array(
    'bundle' => 'green_tech_content',
    'deleted' => 0,
    'description' => 'Images shown in the lower content area.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'slide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'fences_wrapper' => 'div',
    'field_name' => 'field_fpp_green_tech_images',
    'label' => 'Lower content area images',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_data_collection_site'.
  $field_instances['node-kiosk-field_data_collection_site'] = array(
    'bundle' => 'kiosk',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => FALSE,
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_data_collection_site',
    'label' => 'Data collection site',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_about_partners_body'.
  $field_instances['node-kiosk-field_kiosk_about_partners_body'] = array(
    'bundle' => 'kiosk',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => '<div id="about-partners"><div class="wide-column"><img alt="Bonneville Environmental Foundation logo" class="mceItem" src="/profiles/s4rs/themes/custom/kiosk/images/bef-logo.png"><p><strong>Bonneville Environmental Foundation</strong> provided educational materials and project management services for this project through its Solar 4R Schools program. BEF, a non-profit organization, was established in 1998 to restore watershed ecosystems and further the development and use of renewable energy resources. Through revenues generated from the sales of green power products, BEF funds and manages projects that restore damaged watersheds and support new renewable energy.</p></div><hr><div class="narrow-column-left"><img alt="Energy Trust logo" class="mceItem" src="/profiles/s4rs/themes/custom/kiosk/images/energy-trust-logo.png"><p><strong>Energy Trust of Oregon</strong> is a nonprofit organization dedicated to changing the way Oregonians use and generate energy by promoting energy efficiency and clean renewable energy. Through its support of Solar 4R Schools, Energy Trust supports Oregon\\\'s clean energy future.</p></div><div class="narrow-column-right"><img alt="Portland General Electric logo" class="mceItem" src="/profiles/s4rs/themes/custom/kiosk/images/pge-logo.png"><p><strong>PGE</strong>\'s leadership in renewable power dates back to the 1990s when the company agreed to purchase the entire output of Oregon\'s first major wind farm. In 1999, PGE was one of the first utilities to voluntarily offer a renewable power product to customers and later became the first utility in the nation to include a fish habitat option. Portland General Electric (PGE) has operated one of the most successful Green Power Programs in the nation, and offers a renewable option to all customers. The program has grown to more than 70,000 customers. In 2008, PGE\'s renewable energy power program was ranked #1 in the U.S. for sales of renewable power to residential customers and #2 for overall sales by the U.S. DOE\'s National Renewable Energy Labs.</p></div></div>',
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'Content shown on the kiosk\'s <em>About Partners</em> page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_about_partners_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_about_partners_thx'.
  $field_instances['node-kiosk-field_kiosk_about_partners_thx'] = array(
    'bundle' => 'kiosk',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => '<div id="about-partners-thx"><img alt="Thanks!" src="/profiles/s4rs/themes/custom/kiosk/images/thanks.png"><p><strong>Through strong partnerships, local communities are having a position of influence on global issues.</strong></p><p>SCHOOL-NAME would like to thank <em>The Energy Trust of Oregon</em> for funding this project and Bonneville Environmental Foundation for providing project management and educational materials. By choosing non-polluting, renewable energy and protecting important natural resources, we are making a difference in the health of our community and environment, now and for generations to come. It is our hope that this project will inspire students to pursue careers and make decisions that make our world a better place.</p></div>',
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'Content shown in the <em>Thanks!</em> area of the kiosk\'s <em>About Partners</em> page. <strong>Make sure to change SCHOOL-NAME to the name of your school.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_about_partners_thx',
    'label' => 'Thanks text',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_about_project_body'.
  $field_instances['node-kiosk-field_kiosk_about_project_body'] = array(
    'bundle' => 'kiosk',
    'default_value' => array(
      0 => array(
        'value' => '<div id="about-project"><h2>SCHOOL-NAME</h2><p>The solar panels project at SCHOOL-NAME represents the first time the school will be able to generate electricity for its own use.</p></div>',
        'format' => 'filtered_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'Content shown on the kiosk\'s <em>About Project</em> page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_about_project_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_about_project_image'.
  $field_instances['node-kiosk-field_kiosk_about_project_image'] = array(
    'bundle' => 'kiosk',
    'deleted' => 0,
    'description' => 'Image shown on the About This Project page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_about_project_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_call_to_action_body'.
  $field_instances['node-kiosk-field_kiosk_call_to_action_body'] = array(
    'bundle' => 'kiosk',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => '<div id="call-to-action"><h2>A Call to Action</h2><hr><img alt="Turn off unnecessary lights. Replace old lightbulbs with compact fluorescents.Buy green power. Use public transit. Ride your bike. Buy Energy Star windows, doors, and appliances." src="/profiles/s4rs/themes/custom/kiosk/images/call-to-action.png" height="502" width="487"><p>Increased carbon dioxide levels, air and water pollution, habitat destruction and species extinction are all evidence that human activities are operating beyond the capacity of natural systems to maintain balance. Evidence of global warming shows that human impacts on the biosphere are now reaching planetary proportions. Institutions of public learning should play an important role in responding to these issues by helping educate a citizenry that has the knowledge, skills and attitudes necessary to become active participants in developing and carrying out solutions. SCHOOL-NAME strives to create good stewards of the future, by exposing students to programs and buildings that promote suitability.</p><p><strong>Every step you take to minimize your environmental footprint makes a difference. </strong></p></div>',
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'Content shown on the kiosk\'s <em>A Call to Action</em> page. <strong>Make sure to change SCHOOL-NAME to the name of your school.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_call_to_action_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_footer'.
  $field_instances['node-kiosk-field_kiosk_footer'] = array(
    'bundle' => 'kiosk',
    'default_value' => array(
      0 => array(
        'value' => 'SCHOOL-NAME | ADDRESS | CITY, STATE ZIP',
      ),
    ),
    'deleted' => 0,
    'description' => 'Content shown in teh footer area of every kiosk page. Usually this is the address of the school.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_footer',
    'label' => 'Footer line',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_green_tech_content'.
  $field_instances['node-kiosk-field_kiosk_green_tech_content'] = array(
    'bundle' => 'kiosk',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'target_id' => 63,
      ),
    ),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Pages to include in the <em>Green Technology</em> section.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => FALSE,
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_green_tech_content',
    'label' => 'Content',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'references_dialog_add' => 1,
        'references_dialog_edit' => 1,
        'references_dialog_search' => 1,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_how_it_works_body'.
  $field_instances['node-kiosk-field_kiosk_how_it_works_body'] = array(
    'bundle' => 'kiosk',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_how_it_works_body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_logo'.
  $field_instances['node-kiosk-field_kiosk_logo'] = array(
    'bundle' => 'kiosk',
    'deleted' => 0,
    'description' => 'Optionally upload an image here, and it will be displayed on the right side of the page header on each page of this kiosk.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'image_link' => '',
          'image_style' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_kiosk_logo',
    'label' => 'Header logo (right)',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_kiosk_subtitle'.
  $field_instances['node-kiosk-field_kiosk_subtitle'] = array(
    'bundle' => 'kiosk',
    'default_value' => array(
      0 => array(
        'value' => 'Live Solar Electric Generation',
      ),
    ),
    'deleted' => 0,
    'description' => 'The subtitle that displays below the title in the kiosk page header.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'h2',
    'field_name' => 'field_kiosk_subtitle',
    'label' => 'Subtitle',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-kiosk-field_system_specs'.
  $field_instances['node-kiosk-field_system_specs'] = array(
    'bundle' => 'kiosk',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field tells the users a bit more about this site. It will appear on the right sidebar on the kiosk pages.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_system_specs',
    'label' => 'System Specs',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Content');
  t('Content shown in teh footer area of every kiosk page. Usually this is the address of the school.');
  t('Content shown in the <em>Thanks!</em> area of the kiosk\'s <em>About Partners</em> page. <strong>Make sure to change SCHOOL-NAME to the name of your school.</strong>');
  t('Content shown on the kiosk\'s <em>A Call to Action</em> page. <strong>Make sure to change SCHOOL-NAME to the name of your school.</strong>');
  t('Content shown on the kiosk\'s <em>About Partners</em> page.');
  t('Content shown on the kiosk\'s <em>About Project</em> page.');
  t('Data collection site');
  t('Footer line');
  t('Header logo (right)');
  t('Image');
  t('Image shown on the About This Project page.');
  t('Images shown in the lower content area.');
  t('Lower content area images');
  t('Optionally upload an image here, and it will be displayed on the right side of the page header on each page of this kiosk.');
  t('Pages to include in the <em>Green Technology</em> section.');
  t('Subtitle');
  t('System Specs');
  t('Thanks text');
  t('The subtitle that displays below the title in the kiosk page header.');
  t('This field tells the users a bit more about this site. It will appear on the right sidebar on the kiosk pages.');

  return $field_instances;
}
