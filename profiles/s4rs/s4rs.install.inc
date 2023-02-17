<?php
/**
 * @file
 * Installation tasks for the S4RS install profile.
 */

/**
 * Setup slides with a default image.
 */
function _s4rs_install_placeholder_images() {

  // Save our placeholder slide.
  $image = dirname(__FILE__) . '/images/placeholder-slide.gif';
  $file = (object) array(
    'uid' => 1,
    'uri' => $image,
    'filemime' => file_get_mimetype($image),
    'status' => 1,
  );
  $file = file_copy($file, 'public://');

  // Load all FPPs of type 'slide'.
  $result = db_select('fieldable_panels_panes', 'fpp')
    ->fields('fpp', array('fpid'))
    ->condition('bundle', 'homepage_callouts')
    ->execute();

  foreach ($result as $row) {
    $fpp = fieldable_panels_panes_load($row->fpid);
    $fpp->field_callout_image[LANGUAGE_NONE][0] = (array) $file;
    fieldable_panels_panes_save($fpp);
  }
}


/**
 * Pre-config Magic module settings.
 *
 * The info file method of storing settings in code works for
 * already-installed sites. When the initial install takes place
 * the include/exclude CSS expressions use regex and break when
 * read from the theme's .info. We give them initial values on
 * install so install deployments work.
 *
 * @see https://drupal.org/node/2076061
 * @see https://drupal.org/node/2045073
 */
function s4rs_init_magic() {
  $css_directives = array(
    'system/*.css',
    '~system/system.base.css',
    '~system/system.messages.css',
  );

  $magic_settings = array(
    'magic_embedded_mqs' => '0',
    'magic_css_excludes' => implode("\n", $css_directives),
    'magic_footer_js' => '0',
    'magic_library_head' => '0',
    'magic_experimental_js' => '0',
    'magic_js_excludes' => '',
    'magic_rebuild_registry' => '0',
    'magic_viewport_indicator' => '0',
    'magic_modernizr_debug' => '0',
    'magic_performance__active_tab' => 'edit-dev',
    'magic_css_excludes_regex' => array(
      'exclude' => '/^(modules\/system\/(.*)\.css)$/',
      'include' => '/^(modules\/system\/system\.base\.css|modules\/system\/system\.messages\.css)$/',
    ),
    'magic_js_excludes_regex' => '',
  );

  $config = profiler_v2_load_config('s4rs');
  $theme_name = $config['theme'];
  variable_set('theme_' . $theme_name . '_settings', $magic_settings);
}


/**
 * Create menu items.
 */
function _s4rs_install_menu_items() {
  // Add a create account link to the user menu.
  $menu_item = array(
    'link_path' => 'user/register',
    'link_title' => t('Create a New Account'),
    'menu_name' => 'user-menu',
    'weight' => '1',
  );
  menu_link_save($menu_item);

  $menu_item = array(
    'link_path' => 'user/login',
    'link_title' => t('Login'),
    'menu_name' => 'user-menu',
  );
  menu_link_save($menu_item);

  // Add the Learn and Teach menu structures.
  $menu_item = array(
    'link_path' => '<nolink>',
    'link_title' => t('Teach'),
    'menu_name' => 'main-menu',
  );
  $teach_mlid = menu_link_save($menu_item);

  $menu_item = array(
    'link_path' => 'teach/teacher-activity-center',
    'link_title' => t('Search Teacher Activity Center'),
    'menu_name' => 'main-menu',
    'plid' => $teach_mlid,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'teach/science-kits',
    'link_title' => t('Find Science Kit Materials for Your Classroom'),
    'menu_name' => 'main-menu',
    'plid' => $teach_mlid,
  );
  menu_link_save($menu_item);

  $menu_item = array(
    'link_path' => '<nolink>',
    'link_title' => t('Learn'),
    'menu_name' => 'main-menu',
  );
  $learn_mlid = menu_link_save($menu_item);

  $menu_item = array(
    'link_path' => 'learn',
    'link_title' => t('Learn Renewable Energy 101 in the Teacher Learning Center'),
    'menu_name' => 'main-menu',
    'plid' => $learn_mlid,
  );
  menu_link_save($menu_item);

  // Add the BEF menu structure.
  $menu_item = array(
    'link_path' => 'http://www.b-e-f.org/',
    'link_title' => t('Bonneville Environmental Foundation'),
    'menu_name' => 'menu-bef-websites',
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'http://www.b-e-f.org/watersheds',
    'link_title' => t('Model Watershed Program'),
    'menu_name' => 'menu-bef-websites',
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'http://www.shrinkyourfoot.org/',
    'link_title' => t('Shrink Your Foot'),
    'menu_name' => 'menu-bef-websites',
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'http://www.skigreen.org/',
    'link_title' => t('SkiGreen™'),
    'menu_name' => 'menu-bef-websites',
  );
  menu_link_save($menu_item);

  // Add extra links to the footer menu.
  $year = date('Y', REQUEST_TIME);
  $menu_item = array(
    'link_path' => '<nolink>',
    'link_title' => t('©' . $year . ' Bonneville Environmental Foundation'),
    'menu_name' => 'menu-footer-menu',
    'weight' => -1,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'user/login',
    'link_title' => t('Account Login'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 4,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'user/register',
    'link_title' => t('Create a New Account'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 5,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'learn',
    'link_title' => t('Learn'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 6,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'teach/science-activity-center',
    'link_title' => t('Teach'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 7,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'explore-data',
    'link_title' => t('Explore Data'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 8,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'browse-projects',
    'link_title' => t('Browse Projects'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 9,
  );
 menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'browse-funders',
    'link_title' => t('Browse Funders'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 10,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'fund/funding-partner-options-and-benefits',
    'link_title' => t('Fund'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 11,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'apply/start-new-application',
    'link_title' => t('Apply'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 12,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'about',
    'link_title' => t('About the Program'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 13,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'content/media',
    'link_title' => t('Pressroom'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 14,
  );
  menu_link_save($menu_item);
  $menu_item = array(
    'link_path' => 'contact-us',
    'link_title' => t('Contact'),
    'menu_name' => 'menu-footer-menu',
    'weight' => 200,
  );
  menu_link_save($menu_item);

  // Create user menu links to tokenized content lists
  module_enable(array('menu_token'));
}

/**
 * Adds the default settings for the source of the feed.
 */
function _s4rs_install_feeds() {
  module_load_include('inc', 'feeds', 'feeds.pages');
  $form = array('#importer_id' => 'wiki_pages');
  $form_state = array(
    'values' => array (
      'feeds' => array(
        'FeedsHTTPFetcher' => array (
          'source' => 'http://sfrswiki.ezheidtmann.com/rss.xml',
        ),
      ),
    ),
  );
  feeds_import_form_submit($form, $form_state);
}

/**
 * Enables the menu automatically built from article categories
 */
function _s4rs_taxonomy_menu() {
  module_load_include('module', 'taxonomy_field_menu');
  $form = array(
    "#field" => array(
      'field_name' => 'field_articles_category',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'article_categories',
          ),
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'articles',
        ),
      ),
    ),
  );
  $vocabulary = taxonomy_vocabulary_machine_name_load('article_categories');
  $taxonomy_field_menu = (object) array(
    'field_name' => 'field_articles_category',
    'vid' => $vocabulary->vid,
    'menu_name' => 'menu-field-articles-category',
    'custom_page' => 0,
    'child_node' => 0,
    'sync_node' => 1,
    'sync_term' => 1,
    'node_type' => 'articles',
    'url_alias' => 0,
    'link_expanded' => 0,
  );
  $form_state = array(
    'values' => array(
      'menu_objects' => (object) array(),
      'menu_flag' => '1',
      'menu_machine_name' => 'field-articles-category',
      'custom_page' => $taxonomy_field_menu->custom_page,
      'child_node' => $taxonomy_field_menu->child_node,
      'sync_node' => $taxonomy_field_menu->sync_node,
      'sync_term' => $taxonomy_field_menu->sync_term,
      'url_alias' => $taxonomy_field_menu->url_alias,
      'link_expanded' => $taxonomy_field_menu->link_expanded,
    )
  );
  taxonomy_field_menu_field_menu_submit($form, $form_state);
  //We need to also make the menu because the batch functions don't get run for
  //whatever reason.
  $context = array(
    'sandbox' => array(
      'progress' => 0,
    ),
  );
  taxonomy_field_menu_initialize_taxonomy_field_menu($taxonomy_field_menu, $context);
}

/**
 * Creates multiple entities for the widgets.
 */
function _s4rs_install_entities() {
  $entity_type = 'equivalencies_statistics';
  $realtime_data = current(taxonomy_get_term_by_name('Real-time data', 'widget_types'));
  $lifetime_data = current(taxonomy_get_term_by_name('System lifetime data', 'widget_types'));
  $funders_reach = current(taxonomy_get_term_by_name("This funder's reach", 'widget_types'));
  $system_specs = current(taxonomy_get_term_by_name('System specs', 'widget_types'));

  $entities[] = array(
    'title' => 'Power output',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'kW',
          'format' => 'plain_text',
        ),
        'source' => 'power',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'power.gif',
    'field_widget_categories' => array($realtime_data),
  );

  $entities[] = array(
    'title' => 'Irradiance',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'Wm<sup>2</sup>',
          'format' => 'filtered_html',
        ),
        'source' => 'irradiance',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'irradiance.gif',
    'field_widget_categories' => array($realtime_data),
  );

  $entities[] = array(
    'title' => 'Temperature',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => '<sup>&deg;</sup> Celsius cell',
          'format' => 'filtered_html',
        ),
        'source' => 'temperature',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'temperature.gif',
    'field_widget_categories' => array($realtime_data),
  );

  $entities[] = array(
    'title' => 'Lifelong clean energy monitored',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'kWh',
          'format' => 'plain_text',
        ),
        'source' => 'generation',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'clean-energy.gif',
    'field_widget_categories' => array($lifetime_data),
  );

  $entities[] = array(
    'title' => 'Equivalent homes powered',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => '',
          'format' => 'plain_text',
        ),
        'source' => 'generation',
        'equation' => '/30.22',
      ),
    ),
    'field_equivalency_icon' => 'house.gif',
    'field_widget_categories' => array($lifetime_data, $funders_reach),
  );

  $entities[] = array(
    'title' => 'Carbon dioxide emissions contained',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'metric tons',
          'format' => 'plain_text',
        ),
        'source' => 'generation',
        'equation' => '*1.4',
      ),
    ),
    'field_equivalency_icon' => 'co2.gif',
    'field_widget_categories' => array($lifetime_data, $funders_reach),
  );

  $entities[] = array(
    'title' => 'Equivalent cars off the road',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'passenger vehicles',
          'format' => 'plain_text',
        ),
        'source' => 'generation',
        'equation' => '*1.4/5.8',
      ),
    ),
    'field_equivalency_icon' => 'car.gif',
    'field_widget_categories' => array($lifetime_data, $funders_reach),
  );

  $entities[] = array(
    'title' => 'System Size',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'unit',
          'format' => 'plain_text',
        ),
        'source' => 'field_school_system_size',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'clean-energy.gif',
    'field_widget_categories' => array($system_specs),
  );

  $entities[] = array(
    'title' => 'Lifelong clean energy generated for all sponsored projects',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'kWh',
          'format' => 'plain_text',
        ),
        'source' => 'generation',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'power.gif',
    'field_widget_categories' => array($funders_reach),
  );

  $entities[] = array(
    'title' => 'Total classrooms reached to date',
    'field_calculation_source2' => array(
      0 => array(
        'label' => array(
          'value' => 'classrooms in',
          'format' => 'plain_text',
        ),
        'source' => 'field_sum_classrooms',
        'equation' => '',
      ),
      1 => array(
        'label' => array(
          'value' => 'states',
          'format' => 'plain_text',
        ),
        'source' => 'field_sum_states',
        'equation' => '',
      ),
    ),
    'field_equivalency_icon' => 'classrooms.gif',
    'field_widget_categories' => array($funders_reach),
  );

  foreach ($entities as $values) {
    $entity = entity_create($entity_type, array('type' => $entity_type));
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $wrapper->title->set($values['title']);
    $wrapper->field_calculation_source2->set($values['field_calculation_source2']);
    $file = current(file_load_multiple(array(), array('uri' => 'public://' . $values['field_equivalency_icon'])));
    $wrapper->field_equivalency_icon->set(array('fid' => $file->fid));
    $wrapper->field_widget_categories->set($values['field_widget_categories']);
    $wrapper->save();
  }
}

/**
 * Creates default tooltip help info for flags.
 */
function _s4rs_install_tooltip_help() {
  variable_set('flag_tooltip_activity', 'This activity will be saved to your "My Saved Activities" list for future reference.');
  variable_set('flag_tooltip_articles', 'This background topic will be saved to your list of saved background topics.');
  variable_set('flag_tooltip_project', 'This project will be saved to "My Projects" for later use or exploration.');
}
