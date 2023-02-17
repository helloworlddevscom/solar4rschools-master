; This is the actual project make file that should be edited for a
; given project. This text should be replaced with a brief description
; of the project.
api = 2

; Set contrib directory.
defaults[projects][subdir] = "contrib"

; Drupal core.
core = "7.x"
projects[drupal][type] = "core"
projects[drupal][version] = "7.31"
; Ensure plain text fields evaluate line breaks. https://drupal.org/node/1152216
projects[drupal][patch][] = "http://drupal.org/files/text-plain-1152216-24.patch"
; Resolve php notice thrown by the way PHP 5.4 handles array indexes vs 5.3. https://drupal.org/node/1824820#comment-6656728
projects[drupal][patch][] = "https://drupal.org/files/issues/string-offset-cast-1824820-56-D7-do-not-test.patch"
; PHP Fatal error: Call to undefined function db_table_exists().
projects[drupal][patch][1093420] = http://drupal.org/files/1093420-22.patch

; Base installation profile
includes[base] = "base.make"

; Image and media handling.
includes[media] = "media.make"

; Uncomment this to enable demo content. Do not use on production.
;includes[demo] = "demo.make"

includes[panels] = "panels.make"
includes[panopoly_lite] = "panopoly_lite.make"

; Theme and theme-related modules.
includes[locations] = "locations.make"

; Uncomment to use Solr Search.
includes[solr] = "solr.make"

; Theme and theme-related modules.
includes[theme] = "theme.make"

; Network redux modules
includes[network_redux] = "network_redux.make"

; Profiler
libraries[profiler][download][type] = "git"
libraries[profiler][download][branch] = "7.x-2.x"
libraries[profiler][download][revision] = "2ed2140"
; https://drupal.org/comment/7878427#comment-787842 Add support for FPP.
libraries[profiler][patch][] = "https://drupal.org/files/fieldable-panels-panes-support-2093337-01.patch"

; DEVELOPMENT - to assist D7 code upgrading.
projects[coder][subdir] = "development"
projects[coder][version] = "2.1"

projects[grammar_parser_lib][subdir] = "development"
projects[grammar_parser_lib][version] = "1.1"

libraries[grammar_parser][download][type] = file
libraries[grammar_parser][download][url] = http://ftp.drupal.org/files/projects/grammar_parser-7.x-1.2.tar.gz

; Project-specific modules, and overrides.

; Superfish
projects[superfish][download][branch] = "7.x-1.x"
projects[superfish][download][revision] = "bdd7cbd"

; Special Menu Items
projects[special_menu_items][version] = "2.0"

projects[book_helper][download][branch] = "7.x-1.x"
projects[book_helper][download][revision] = "8d4d1d5"

projects[cache_actions][version] = "2.0-alpha5"

projects[basic_cart][version] = "3.0"
; Add number as dependency
projects[basic_cart][patch][] = "https://drupal.org/files/issues/basic_cart-add_number_as_dependency-2189793-1.patch"
; Fix broken hook_token_info
; https://drupal.org/comment/8584185#comment-8584185
projects[basic_cart][patch][] = "https://drupal.org/files/issues/basic_cart-fix-hook_token_info-implementation-2194715-1.patch"
; Fix double buttons https://drupal.org/node/2244021
projects[basic_cart][patch][] = "http://drupal.org/files/issues/basic_cart-double_buttons-2244021-1.patch"

projects[chosen][version] = "2.0-beta4"

projects[computed_field][version] = "1.0"
; Recalculate on page load https://drupal.org/node/332200
projects[computed_field][patch][] = "http://drupal.org/files/issues/computed_field-recalculate-332200-26.patch"

projects[conditional_fields][version] = "3.0-alpha1"
projects[context][version] = "3.2"
projects[context_condition_theme][version] = "1.0"
projects[context][patch][] = "https://drupal.org/files/issues/context-795058-override-block-titles-72.patch"

; Context Change Theme
projects[context_reaction_theme][subdir] = "contrib"
projects[context_reaction_theme][version] = "1.x-dev"
projects[context_reaction_theme][revision] = "9e119e08"

; Custom Add Another
projects[custom_add_another][version] = "1.0-rc3"

projects[date][version] = "2.8"

projects[eck][version] = "2.0-rc3"
; Syntax error breaking db queries. https://drupal.org/node/2255239
projects[eck][patch][] = "http://drupal.org/files/issues/eck-positive_integer-2255239-1.patch"

projects[email][version] = "1.2"
projects[email_registration][version] = "1.1"
projects[empty_fields][version] = "2.0"

projects[entity][version] = "1.4"
; Add contextual links for entities.
projects[entity][patch][] = "http://drupal.org/files/issues/entity-n1598652-16.patch"

projects[entityform][version] = "1.4"
projects[entityreference][version] = "1.1"
projects[entityreference_prepopulate][version] = "1.5"
projects[entityreference_filter][version] = "1.2"

projects[entity_view_mode][version] = "1.0-rc1"

projects[feeds][version] = "2.0-alpha8"

projects[field_collection][version] = "1.0-beta7"
projects[field_collection_fieldset][version] = "2.3"

projects[field_default_token][version] = "1.2"

projects[field_group][version] = "1.3"
projects[field_permissions][version] = "1.0-beta2"
projects[fivestar][version] = "2.1"

projects[flag][download][branch] = "7.x-3.x"
; Includes fix for #2093285.
projects[flag][download][revision] = "8ff54f9"
; Allow flags to be altered: https://drupal.org/node/2027091#comment-8012263
projects[flag][patch][] = "https://drupal.org/files/flag-default-flags-alter-hook-2027091-03.patch"
; Static cache user permission issue: https://drupal.org/node/2193947#comment-8473575
projects[flag][patch][] = "https://drupal.org/files/issues/flag-permissions-2193947-03.patch"

projects[follow][version] = "2.0-alpha1"

projects[job_scheduler][version] = "2.0-alpha3"

projects[libraries][version] = "2.2"
projects[link][version] = "1.2"

; Sandbox module
projects[link_pane][type] = module
projects[link_pane][download][type] = git
projects[link_pane][download][branch] = "master"
projects[link_pane][download][url] = http://git.drupal.org/sandbox/mansspams/1989992.git
projects[link_pane][download][revision] = 30be3f3

projects[login_destination][version] = '1.1'

projects[markup][version] = "1.1-beta1"

projects[masquerade][version] = "1.0-rc7"

projects[maxlength][version] = "3.0-beta1"
; Grippie shows up under word count. https://drupal.org/node/2167275
projects[maxlength][patch][] = https://drupal.org/files/issues/maxlength-grippie.patch

projects[uuid][version] = "1.0-alpha5"
projects[menu_token][download][branch] = "7.x-1.x"
projects[menu_token][download][revision] = "eda6188"

projects[menu_attributes][version] = "1.0-rc2"

projects[migrate][version] = "2.6-rc1"
projects[migrate_d2d][download][branch] =  "7.x-2.x"
projects[migrate_d2d][download][revision] = "f88afdd"
; Erroneous alt field created. https://drupal.org/node/2021413
projects[migrate_d2d][patch][] = https://drupal.org/files/migrate_d2d-use-cck-image-alt-field-2021413-15.patch

projects[migrate_extras][version] = "2.5"
; Votingapi inserts new votes with every update https://drupal.org/node/2151725
projects[migrate_extras][patch][] = "https://drupal.org/files/issues/migrate_extras-votingapi_duplicating_votes-2151725-1.patch"

projects[mollom][download][branch] =  "7.x-2.x"
projects[mollom][download][revision] = "e8b5758"
projects[mollom][patch][] = "http://drupal.org/files/issues/717874-47-exportables_for_mollom.patch"

projects[og][version] = "2.7"

projects[persistent_login][version] = "1.0-beta1"

projects[privatemsg][version] = "1.4"

projects[profile2][version] = "1.3"
; https://drupal.org/node/1387268#comment-6983504
projects[profile2][patch][] = "https://drupal.org/files/profile2-1387268-30.patch"
; https://drupal.org/node/1011370#comment-6884220
projects[profile2][patch][] = "https://drupal.org/files/1011370-profile2-ctools-54.patch"

projects[profile2_privacy][download][branch] = "7.x-1.x"
projects[profile2_privacy][download][revision] = "dd5edb8"
; Use a static cache: https://drupal.org/node/2153421
projects[profile2_privacy][patch][] = "https://drupal.org/files/issues/profile2-privacy-static-cache.patch"
; Separate out form functions: https://drupal.org/comment/8258095#comment-8258095
projects[profile2_privacy][patch][] = "https://drupal.org/files/issues/profile2_privacy-form-methods-2144981-05.patch"

projects[r4032login][version] = "1.7"
projects[realname][version] = "1.2"

projects[references_dialog][version] = "1.0-alpha4"
; References_dialog patch for FPP.  https://drupal.org/comment/8200307#comment-8200307
projects[references_dialog][patch][] = "https://drupal.org/files/issues/references_dialog_fieldable_panels_pane_support-2140535-3.patch"
; Error about entity_access() https://drupal.org/node/1780626
projects[references_dialog][patch][] = "http://drupal.org/files/references_dialog-wrong-call-to-entity_access-1780626-6.patch"

projects[rules][download][branch] = "7.x-2.x"
projects[rules][download][revision] = "8db91e5"

projects[sharethis][download][branch] = "7.x-2.x"
projects[sharethis][download][revision] = "6bc4fdd"

projects[smart_trim][version] = "1.4"

projects[taxonomy_field_menu][download][branch] = "7.x-1.0"
projects[taxonomy_field_menu][download][revision] = "bcb315d"
projects[taxonomy_field_menu][patch][] = "https://drupal.org/files/issues/taxonomy_field_menu-using-args-for-bundle-2233703_0.patch"

projects[timeperiod][download][branch] = "7.x-1.x"
projects[timeperiod][download][revision] = "e32b1ce"

projects[tzfield][version] = "1.0"
; Allow tzfield to be added programmatically. https://drupal.org/node/1824306
projects[tzfield][patch][] = "http://drupal.org/files/allow_tzfield_to_work_with_entity_api-1824306-1.patch"

projects[subpathauto][version] = "1.3"
projects[superfish][version] = "1.9"

projects[views_bulk_operations] = "3.2"
projects[views_data_export][version] = "3.0-beta7"

projects[views_rules][version] = "1.0"
projects[votingapi][version] = "2.11"
projects[viewfield][version] = "2.0"

projects[workbench][version] = "1.2"

projects[workbench_moderation][download][branch] = "7.x-1.x"
projects[workbench_moderation][download][revision] = "a90378d"
; Toggle state when other means are used to publish: https://drupal.org/comment/8147851#comment-8147851
projects[workbench_moderation][patch][] = "https://drupal.org/files/issues/1436260-workbench_moderation-states-vbo-38.patch"


; Libraries

; Pull a pull-request branch for jQuery < 1.6 support. See:
; * https://github.com/harvesthq/chosen/pull/1555
; * https://github.com/harvesthq/chosen/pull/1702
libraries[chosen][download][type] = "git"
libraries[chosen][download][branch] = "with-built-assets"
libraries[chosen][download][revision] = "ae2ef5d"
libraries[chosen][download][url] = "https://github.com/opensourcery/chosen.git"

libraries[highstock][download][type] = "get"
libraries[highstock][download][url] = "http://code.highcharts.com/zips/Highstock-1.3.7.zip"

; Magnific Popup
libraries[magnific-popup][download][type] = "git"
libraries[magnific-popup][download][url] = "https://github.com/dimsemenov/Magnific-Popup.git"
libraries[magnific-popup][destination] = "libraries"
libraries[magnific-popup][directory_name] = "magnific-popup"

libraries[superfish][download][type] = "git"
libraries[superfish][download][branch] = "master"
libraries[superfish][download][revision] = "2670a36"
libraries[superfish][download][url] = "https://github.com/mehrpadin/Superfish-for-Drupal.git"
libraries[superfish][destination] = "libraries"
libraries[superfish][directory_name] = "superfish"

; qTip2 doesn't seem to have a package download (sigh) without using their
; "builder." The GitHub releases contain source only (requiring a build step).
libraries[qtip2-js-min][download][type] = "file"
libraries[qtip2-js-min][download][url] = "http://cdn.jsdelivr.net/qtip2/2.2.0/basic/jquery.qtip.min.js"
libraries[qtip2-js-min][directory_name] = "qtip2"
libraries[qtip2-css-min][download][type] = "file"
libraries[qtip2-css-min][download][url] = "http://cdn.jsdelivr.net/qtip2/2.2.0/basic/jquery.qtip.min.css"
libraries[qtip2-css-min][directory_name] = "qtip2"

libraries[qtip2-js][download][type] = "file"
libraries[qtip2-js][download][url] = "http://cdn.jsdelivr.net/qtip2/2.2.0/basic/jquery.qtip.js"
libraries[qtip2-js][directory_name] = "qtip2"
libraries[qtip2-css][download][type] = "file"
libraries[qtip2-css][download][url] = "http://cdn.jsdelivr.net/qtip2/2.2.0/basic/jquery.qtip.css"
libraries[qtip2-css][directory_name] = "qtip2"
