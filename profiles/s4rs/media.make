; Base image module set
core = "7.x"
api = 2

projects[caption_filter][download][branch] = "7.x-1.x"
projects[caption_filter][download][revision] = "b8097ee"

projects[file_entity][download][branch] = "7.x-2.x"
projects[file_entity][download][revision] = "3661d8b"

projects[image_resize_filter][version] = "1.14"
; Images not resizing if path has query string: https://drupal.org/node/1929710
projects[image_resize_filter][patch][] = https://drupal.org/files/image_resize_filter-remove-query-string-1929710-8.patch

projects[media][download][branch] = "7.x-2.x"
projects[media][download][revision] = "6382429"
; Web tab wasn't working https://www.drupal.org/node/2280941
projects[media][patch][] = "http://www.drupal.org/files/issues/media-oembed-2280941-11.patch"
; Modal under ctools (activated by panels)
projects[media][patch][] = "https://www.drupal.org/files/issues/media-media_browser_under_ctools_modal-2245143-2.patch"

projects[media_vimeo][download][branch] = "7.x-2.x"
projects[media_vimeo][download][revision] = "204cc5f"
projects[media_youtube][download][branch] = "7.x-2.x"
projects[media_youtube][download][revision] = "187283f"

; Picture module for responsive image handling
projects[picture][version] = "1.2"

; Required for multiple file uploads via plupload at `file/add`.
projects[multiform][version] = "1.0"

projects[plupload][version] = "1.4"

projects[videojs][version] = "3.0-alpha2"

; Libraries

libraries[plupload][download][type] = "get"
libraries[plupload][download][url] = "https://codeload.github.com/moxiecode/plupload/zip/v1.5.8"
libraries[plupload][download][directory_name] = "plupload"

libraries[video-js][download][type] = "get"
libraries[video-js][download][url] = "http://www.videojs.com/downloads/video-js-4.3.0.zip"
