; Panels and related modules.
core = "7.x"
api = 2

projects[fape][version] = "1.2"

projects[fieldable_panels_panes][version] = "1.5"
; Title should be displayed using view mode settings.
; https://drupal.org/comment/7876047#comment-7876047
projects[fieldable_panels_panes][patch][] = "https://drupal.org/files/fieldable_panels_panes-title_use_view_modes-2092477-2.patch"
; Fill in admin title with actual title or machine name.  https://drupal.org/comment/7057290#comment-7057290
projects[fieldable_panels_panes][patch][] = "https://drupal.org/files/fieldable_panels_panes-entity_label-1588882-18.patch"
; Default pane category: https://drupal.org/comment/8241873#comment-8241873
projects[fieldable_panels_panes][patch][] = "https://drupal.org/files/issues/fpp-default-category-2149989-02.patch"
; Support FPP in migrate
; https://drupal.org/comment/8346779#comment-8346779
projects[fieldable_panels_panes][patch][] = "https://drupal.org/files/issues/fpp-migrate-destination-handler-2145209-5.patch"

projects[panelizer][version] = "3.1"
; Fix access logic error: https://drupal.org/node/2024831#comment-8496667
projects[panelizer][patch][] = "https://drupal.org/files/issues/panelizer-node-access-2024831-04_2.patch"
; Fix button that should not be displayed: https://drupal.org/node/2199859#comment-8496751
projects[panelizer][patch][] = "https://drupal.org/files/issues/panelizer-ipe-integration-fix-2199859-01.patch"

; Pull latest panels including many fixes since 3.3.
projects[panels][version] = "3.4"

projects[panels_breadcrumbs][version] = "2.1"

projects[panels_style_collapsible][version] = "1.0"

projects[pm_existing_pages][download][branch] = "7.x-1.x"
projects[pm_existing_pages][download][revision] = "e0451cc"
