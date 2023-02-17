core = "7.x"
api = 2

;
; Panopoly Lite
;
projects[panopoly_admin][download][url] = "https://github.com/opensourcery/panopoly_admin.git"
projects[panopoly_admin][download][branch] = "7.x-1.x"
projects[panopoly_admin][download][revision] = "a478504"

projects[panopoly_core][download][type] = "git"
projects[panopoly_core][download][url] = "https://github.com/opensourcery/panopoly_core.git"
projects[panopoly_core][download][branch] = "7.x-1.x"
projects[panopoly_core][download][revision] = "5a91e7d"

projects[panopoly_theme][download][type] = "git"
projects[panopoly_theme][download][url] = "https://github.com/opensourcery/panopoly_theme.git"
projects[panopoly_theme][download][branch] = "7.x-1.x"
projects[panopoly_theme][download][revision] = "c648182"

projects[panopoly_widgets][download][type] = "git"
projects[panopoly_widgets][download][url] = "https://github.com/opensourcery/panopoly_widgets.git"
projects[panopoly_widgets][download][branch] = "7.x-1.x"
projects[panopoly_widgets][download][revision] = "523028b"

;
; Panopoly Lite supporting contrib modules that we don't already include.
;
; Panopoly Lite does not bundle makefiles.
;
; Panopoly Widgets also requires menu_block, which is in base.make.
;
projects[admin_views][version] = "1.2"

projects[defaultconfig][version] = "1.0-alpha9"
projects[defaultconfig][patch][2042799] = "http://drupal.org/files/default_config_delete_only_if_overriden.patch"
projects[defaultconfig][patch][2043307] = "http://drupal.org/files/defaultconfig_include_features_file.patch"
projects[defaultconfig][patch][2008178] = "http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch"
projects[defaultconfig][patch][1861054] = "http://drupal.org/files/fix-defaultconfig_rebuild_all.patch"

projects[simple_gmap][version] = "1.0"

projects[tablefield][version] = "2.2"

projects[views_autocomplete_filters][version] = "1.0"
