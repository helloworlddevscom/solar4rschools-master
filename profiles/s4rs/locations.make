; Modules and libraries needed for geolocation and mapping.
core = "7.x"
api = 2

projects[geophp][version] = "1.7"
; Undefined error
projects[geophp][patch][] = "https://drupal.org/files/issues/absolute-path_0.patch"


;; Address field
projects[addressfield][version] = "1.0-beta5"

;; Address Field Tokens
projects[addressfield_tokens][version] = "1.4"

;; Geocoder
projects[geocoder][version] = "1.2"

;; Geofield
projects[geofield][version] = "2.1"

;; Views GeoJSON (map data feeds)
projects[views_geojson][download][branch] = "7.x-1.x"
projects[views_geojson][download][revision] = "cc2bc0b"
;; Allow other entities besides nodes to have description field.
;; @see https://drupal.org/node/2082143
projects[views_geojson][patch][] = "https://drupal.org/files/views_geojson-description_property-2082143-1.patch"
;; Geeofield WKT incompatibility.
;; @see http://drupal.org/node/1794848
projects[views_geojson][patch][] = https://drupal.org/files/1794848-geofield20.patch
;; Bounding box for general entities
;; see http://drupal.org/node/2060197
projects[views_geojson][patch][] = https://drupal.org/files/bbox_on_all_views.patch
;; Bounding argument not exported correctly
;; @see https://drupal.org/node/1864972
projects[views_geojson][patch][] = https://drupal.org/files/issues/views_geojson--bbox-arg-export--1864972-5.patch
;; Strict error fix https://www.drupal.org/node/2170641
projects[views_geojson][patch][] = https://www.drupal.org/files/issues/bbox-query-signature--2170641-3.patch

;; Leaflet GeoJSON (Views GeoJSON to Leaflet connector)
projects[leaflet_geojson][download][branch] = "7.x-2.x"
projects[leaflet_geojson][download][revision] = "f8146e2"
;; Bounding argument keys should come from their respective data layers.
;; @see https://drupal.org/node/2267687
projects[leaflet_geojson][patch][] = https://drupal.org/files/issues/leaflet_geojson--bounding-argument-key--2267687-1.patch
;; Allow more alter flexibiltiy including access to pane config.
;; @see https://drupal.org/node/2276097
projects[leaflet_geojson][patch][] = https://drupal.org/files/issues/leaflet_geojson--more-alter-flexibiltiy--2276097-1.patch

;; Leaflet integration (display engine)
projects[leaflet][download][branch] = "7.x-1.x"
projects[leaflet][download][revision] = "94a9b65"

;; Leaflet More Maps (base layers)
projects[leaflet_more_maps][version] = "1.9"

;; Libraries

;; GeoPHP
libraries[geoPHP][download][type] = "git"
libraries[geoPHP][download][url] = "https://github.com/phayes/geoPHP.git"
libraries[geoPHP][download][revision] = "478a1a0"

;; Leaflet (display engine)
libraries[leaflet][download][type] = get
libraries[leaflet][download][url] = http://leaflet-cdn.s3.amazonaws.com/build/leaflet-0.7.1.zip
libraries[leaflet][directory_name] = leaflet
libraries[leaflet][destination] = libraries

;; Leaflet.fullscreen plugin
libraries[leaflet_fullscreen][download][type] = "git"
libraries[leaflet_fullscreen][download][revision] = "2becb29"
libraries[leaflet_fullscreen][download][url] = "https://github.com/Leaflet/Leaflet.fullscreen.git"
libraries[leaflet_fullscreen][directory_name] = "leaflet.fullscreen"

;; Leaflet.markercluster plugin (client-side clustering).
libraries[leaflet_markercluster][download][type] = "git"
libraries[leaflet_markercluster][download][url] = "https://github.com/Leaflet/Leaflet.markercluster.git"
libraries[leaflet_markercluster][download][revision] = "254198a"
libraries[leaflet_markercluster][directory_name] = "leaflet_markercluster"

;; Sprite animation for loading spinners.
libraries[animate_sprite][download][type] = "git"
libraries[animate_sprite][download][revision] = "46fe3e1"
libraries[animate_sprite][download][url] = "https://github.com/blaiprat/jquery.animateSprite.git"
