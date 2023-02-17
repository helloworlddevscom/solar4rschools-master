<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
class SolarProjectsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_technology_type', 'field_school_data_types');
    $this->addFieldMapping('field_technology_type:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_technology_type:ignore_case')
        ->defaultValue(TRUE);

    $this->addFieldMapping('field_data_collection_site', 'data_collection');

    $this->addFieldMapping('field_project_location', 'country');
    $this->addFieldMapping('field_project_location:administrative_area', 'province');
    $this->addFieldMapping('field_project_location:locality', 'city');
    $this->addFieldMapping('field_project_location:postal_code', 'postal_code');
    $this->addFieldMapping('field_project_location:thoroughfare', 'street');
    $this->addFieldMapping('field_project_location:premise', 'additional');

    $this->addFieldMapping('field_geolocation:lat', 'latitude');
    $this->addFieldMapping('field_geolocation:lon', 'longitude');

    $this->addFieldMapping('field_photo_gallery', 'images')
      ->sourceMigration(array('Files'))
      ->separator(',');
    $this->addFieldMapping('field_photo_gallery:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_project_type')
         ->defaultValue('Renewable school');

    $this->addFieldMapping('group_register', 'status');
  }

  /**
   * Augments the default query by also finding the data collection site.
   */
  protected function query() {
    $query = parent::query();

    if($this->sourceType == 'deck_monitoring_location') {
      $field = 'location_id';
    }
    else {
      $field = 'entity_id';
    }

    $query->leftJoin($this->sourceType, 'st', 'n.vid=st.vid');
    $query->addField('st', $field, 'data_collection');

    // Join location table, which is not CCK
    $query->join('location_instance', 'i', 'i.nid = n.nid AND i.vid = n.vid');
    $query->join('location', 'l', 'l.lid = i.lid');
    $query->fields('l', array('name', 'street', 'additional', 'city', 'province', 'postal_code', 'country', 'latitude', 'longitude', 'source'));

    // Get related images.
    // $query->addExpression('(SELECT group_concat(field_image_fid) FROM content_type_image cti LEFT JOIN content_field_site cfs USING (vid) WHERE cfs.field_site_nid = n.nid)', 'images');

    return $query;
  }

  public function prepare ($node, stdClass $row) {
    $new_entityid = NULL;

    if($this->sourceType == 'deck_monitoring_location') {
      $field = 'deck_lid';
      $bundle = 'deck';
    }
    else {
      $field = 'pow_eid';
      $bundle = 'power_one';
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'generation_site')
      ->entityCondition('bundle', $bundle)
      ->fieldCondition($field, 'value', $row->data_collection, '=');

    $result = $query->execute();

    if(isset($result['generation_site'])) {
      $new_entityid = current(array_keys($result['generation_site']));
      $entity = entity_load_single('generation_site', $new_entityid);
      $wrapper = entity_metadata_wrapper('generation_site', $entity);
    }
    else {
      $entity = entity_create('generation_site', array('type' => $bundle));
      $wrapper = entity_metadata_wrapper('generation_site', $entity);
      $wrapper->{$field}->set($row->data_collection);
      $wrapper->title->set($row->title);

      $wrapper->save();

      $new_entityid = $wrapper->getIdentifier();
    }

    if (isset($row->field_school_module_tilt[0])) {
      $wrapper->field_school_module_tilt->set($row->field_school_module_tilt[0]);
    }
    if (isset($row->field_school_module_orientation[0])) {
      $wrapper->field_school_module_orientation->set($row->field_school_module_orientation[0]);
    }
    if (isset($row->field_school_shading_percent[0])) {
      $wrapper->field_school_shading_percent->set($row->field_school_shading_percent[0]);
    }
    if (isset($row->field_school_system_size[0])) {
      $wrapper->field_school_system_size->set($row->field_school_system_size[0]);
    }
    if (isset($row->field_school_timezone[0])) {
      $wrapper->field_timezone->set($row->field_school_timezone[0]);
    }
    if (isset($row->latitude[0]) && isset($row->longitude[0]) && is_numeric($row->latitude[0]) && is_numeric($row->longitude[0])) {
      $wrapper->field_geolocation->set(array('lat' => $row->latitude[0], 'lon' => $row->longitude[0]));
    }
    if ($bundle == 'power_one' && isset($row->field_school_system_size_acdc[0])) {
      $wrapper->pow_system_size_units->set($row->field_school_system_size_acdc[0]);
    }
    if ($bundle == 'power_one' && isset($row->field_school_install_date[0]) && !empty($row->field_school_install_date[0])) {
      $date = date_create($row->field_school_install_date[0]);
      $wrapper->pow_install_date->set(date_format($date, 'U'));
    }
    if ($bundle == 'power_one' && isset($row->uses_rgpvenergy[0]) && !empty($row->uses_rgpvenergy[0])) {
      $wrapper->pow_is_rgpv->set($row->uses_rgpvenergy[0]);
    }

    $wrapper->save();

    $node->field_data_collection_site[LANGUAGE_NONE][0]['target_id'] = $new_entityid;
  }
}

/**
 * Common mappings for the Drupal 6 node migrations.
 */
class SolarClassroomsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('og_group_ref', 'field_school_site')
      ->sourceMigration(array('Decks','Schools'));

    $this->addFieldMapping('field_project_location', 'country');
    $this->addFieldMapping('field_project_location:administrative_area', 'province');
    $this->addFieldMapping('field_project_location:locality', 'city');
    $this->addFieldMapping('field_project_location:postal_code', 'postal_code');
    $this->addFieldMapping('field_project_location:thoroughfare', 'street');
    $this->addFieldMapping('field_project_location:premise', 'additional');

    $this->addFieldMapping('field_geolocation:lat', 'latitude');
    $this->addFieldMapping('field_geolocation:lon', 'longitude');

    $this->addFieldMapping('field_project_type')
         ->defaultValue('Renewable classroom');
  }

  /**
   * Add the location information to the array.
   */
  protected function query() {
    $query = parent::query();
    // Join location table, which is not CCK
    $query->join('location_instance', 'i', 'i.nid = n.nid AND i.vid = n.vid');
    $query->join('location', 'l', 'l.lid = i.lid');
    $query->fields('l', array('name', 'street', 'additional', 'city', 'province', 'postal_code', 'country', 'latitude', 'longitude', 'source'));
    return $query;
  }
}

/**
 * Common mappings for the Drupal 6 node migrations.
 */
class SolarKiosksMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_kiosk_subtitle', 'field_kiosk_subtitle');
    $this->addFieldMapping('field_data_collection_site', 'field_kiosk_school')
      ->sourceMigration(array('Decks', 'Schools'))
      ->callbacks(array($this, 'getGenerationSite'));
    $this->addFieldMapping('field_kiosk_logo', 'field_kiosk_header_logo_right')
      ->sourceMigration(array('Files'));
    $this->addFieldMapping('field_kiosk_footer', 'field_kiosk_footer');
    $this->addFieldMapping('field_kiosk_how_it_works_body', 'field_kiosk_how_it_works');
    $this->addFieldMapping('field_kiosk_how_it_works_body:format', 'field_kiosk_how_it_works:format')
      ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('field_kiosk_about_project_body', 'field_kiosk_about_project');
    $this->addFieldMapping('field_kiosk_about_project_body:format', 'field_kiosk_about_project:format')
      ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('field_kiosk_about_partners_body', 'field_kiosk_about_partners');
    $this->addFieldMapping('field_kiosk_about_partners_body:format', 'field_kiosk_about_partners:format')
      ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('field_kiosk_about_partners_thx', 'field_kiosk_about_partners_thx');
    $this->addFieldMapping('field_kiosk_about_partners_thx:format', 'field_kiosk_about_partners_thx:format')
      ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('field_kiosk_green_tech_content', 'field_kiosk_pages')
      ->sourceMigration('KioskPage');
    $this->addFieldMapping('field_kiosk_call_to_action_body', 'field_kiosk_call_to_action');
    $this->addFieldMapping('field_kiosk_call_to_action_body:format', 'field_kiosk_call_to_action:format')
      ->callbacks(array($this, 'mapFormat'));

    $this->addFieldMapping('field_system_specs', 'field_school_system_specs_value');
    $this->addFieldMapping('field_system_specs:format', 'field_school_system_specs_format')
        ->callbacks(array($this, 'mapFormat'));
  }

  /**
   * Move the System Specs from the School page to the Kiosk page.
   */
  protected function query() {
    $query = parent::query();

    $query->leftJoin('content_field_school_system_specs', 'cfsss', 'f.field_kiosk_school_nid=cfsss.nid');
    $query->fields('cfsss', array('field_school_system_specs_value', 'field_school_system_specs_format'));

    return $query;
  }

  /**
   * Callback that gets the generation site of a given project.
   */
  protected function getGenerationSite($project_id) {
    return db_select('field_data_field_data_collection_site', 'project')
      ->fields('project', array('field_data_collection_site_target_id'))
      ->condition('bundle', 'project')
      ->condition('entity_id', $project_id)
      ->execute()
      ->fetchField();
  }
}

/**
 * Common mappings for the Drupal 6 node migrations.
 */
class SolarFunderNodesMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_funder_body', 'body')
      ->arguments(array('format' => 'full_html'));
    $this->addFieldMapping('field_website_url', 'field_funder_url');
    $this->addFieldMapping('field_website_url:title', 'field_funder_url:title');
    $this->addFieldMapping('field_website_url:attributes', 'field_funder_url:attributes');
    $this->addFieldMapping('field_funder_logo', 'field_funder_logo')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_funder_logo:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_funder_logo:alt', 'field_funder_logo:alt');
    $this->addFieldMapping('field_funder_logo:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_funder_logo:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addUnmigratedSources(array('nid', 'uid', 'revision', 'log', 'revision_uid', 'field_weight', 'field_funder_logo:list', 'field_funder_schools'));
    $this->addUnmigratedDestinations(array('nid', 'field_website_url:language', 'field_funder_body:summary', 'field_funder_body:language', 'field_show_widgets', 'my_projects_to_explore', 'field_funder_schools'));
  }

  /**
   * Move the System Specs from the School page to the Kiosk page.
   */
  protected function query() {
    $query = parent::query();

    return $query;
  }

  /**
   * Fill in the appropriate funder schools here, because we check multiple
   * mapping tables.
   */
  public function prepare($node, stdClass $row) {
    // Query the mapping tables for Decks, Schools, and Classrooms
    // We do this because Decks / Schools use the same migration class and thus
    // if we used ->sourceMigration it would only check one mapping table.
    $project_nodes_query = db_query('SELECT d.sourceid1, d.destid1 FROM {migrate_map_decks} d UNION SELECT s.sourceid1, s.destid1
      FROM {migrate_map_schools} s UNION SELECT c.sourceid1, c.destid1 FROM {migrate_map_classrooms} c');
    $project_nodes = $project_nodes_query->fetchAll();

    // Build out an array for all the destination nids from the source nids.
    $dest = array();
    foreach ($row->field_funder_schools as $source_school) {
      foreach ($project_nodes as $pnid) {
        if ($pnid->sourceid1 == $source_school) {
          array_push($dest, $pnid->sourceid1);
        }
      }
    }

    // Determine the number of destination nids
    $num_of_nodes = count($dest);

    // For all the destination nids save them into the entity reference funder schools
    // fields (allows multiple values per field)
    for ($i = 0; $i < $num_of_nodes; $i++) {
      $node->field_funder_schools[LANGUAGE_NONE][$i]['target_id'] = $dest[$i];
    }
  }
}

/**
 * Mapping Drupal 6 Kiosk Page nodes into Drupal 7 Fieldable Panels Panes.
 */
class SolarKioskPagesMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationFieldablePanelsPanes(
      'green_tech_content',
      $arguments
    );

    $this->addFieldMapping('field_fpp_green_tech_body', 'body');
    $this->addFieldMapping('field_fpp_green_tech_body:format', 'body:format')
      ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('field_fpp_green_tech_images', 'field_footer_images')
      ->sourceMigration(array('Files'));
    $this->addFieldMapping('admin_title', 'title');
  }
}

/**
 * Mapping Drupal 6 Custom Kiosk Page nodes into Drupal 7 Fieldable Panels Panes.
 */
class SolarKioskCustomPagesMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationFieldablePanelsPanes(
      'green_tech_content',
      $arguments
    );

    $this->addFieldMapping('field_fpp_green_tech_body', 'body');
    $this->addFieldMapping('field_fpp_green_tech_body:format', 'body:format')
      ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('field_fpp_green_tech_images', 'field_footer_images')
      ->sourceMigration(array('Files'));
    $this->addFieldMapping('admin_title', 'title');
  }

  /**
   * Reverse the direction of Custom Kiosk Page nodereferences.
   *
   * On the D6 site, Custom Kiosk Pages had a nodereference field to their
   * corresponding Kiosk. On the D7 site, Custom Kiosk Pages and Kiosk Pages
   * are both implemented as a single FPP bundle referenced by their Kiosk. This
   * means we need to reverse the direction of the reference field.
   */
  public function complete($entity, stdClass $row) {
    $kiosk_id = parent::handleSourceMigration('Kiosk', $row->field_kiosk_page_custom_kiosk);
    $kiosk = node_load($kiosk_id);
    if (isset($kiosk->nid)) {
      $kiosk->field_kiosk_green_tech_content[$kiosk->language][] = array(
        'target_id' => $entity->vid,
      );
      node_save($kiosk);
    }
  }
}

