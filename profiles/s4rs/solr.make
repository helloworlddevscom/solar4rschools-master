; Base Solr search module set
core = "7.x"
api = 2

; Facet API
projects[facetapi][version] = "1.3"

; Facet API Pretty Paths
projects[facetapi_pretty_paths][version] = "1.0"

; Facets as multiselect
projects[facetapi_multiselect][version] = "1.0-beta1"

; Search API
projects[search_api][version] = "1.12"
; Caching doesn't work for views 3.8+ https://drupal.org/node/2281535
projects[search_api][patch][] = "https://www.drupal.org/files/issues/search_api_views-patch_views_cache-2281535-11.patch"

; Search API Attachments
;projects[search_api_attachments][version] = "1.3"

; Search locations
projects[search_api_location][version] = "2.0-beta1"

; Search API Solr
projects[search_api_solr][version] = "1.4"

; Search API
projects[search_api_autocomplete][version] = "1.0"


; ApacheSolr
;projects[apachesolr][version] = "1.3"

; ApacheSolr Attachments
;projects[apachesolr_attachments][version] = "1.2"

; ApacheSolr Panels
; projects[apachesolr_panels][version] = "1.1"

; ApacheSolr Views
;projects[apachesolr_views][version] = "1.0-beta2"
