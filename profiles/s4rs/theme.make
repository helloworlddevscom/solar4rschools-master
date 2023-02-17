; Base theme make file, including theme-related modules
core = "7.x"
api = 2

; Modules

; Blockify
projects[blockify][version] = "1.2"

; Magic
projects[magic][version] = "1.5"

; Magnific popup
projects[magnific_popup][version] = "1.0-rc1"

; Modernizr
projects[modernizr][version] = "3.2"

; Field Formatter Settings
projects[field_formatter_settings][version] = "1.1"

; Linked field
projects[linked_field][version] = "1.9"

; Bedrock
projects[bedrock][version] = "1.0-alpha4"
projects[bedrock][patch][] = https://drupal.org/files/issues/bedrock--jadeite-content-header--2248161-1.patch

; Libraries

; Modernizr
libraries[modernizr][download][type] = "get"
libraries[modernizr][download][url] = "http://modernizr.com/downloads/modernizr-latest.js"
libraries[modernizr][download][filename] = "modernizr.js"
libraries[modernizr][destination] = "libraries"
libraries[modernizr][directory_name] = "modernizr"

; Alphecca Sass Framework
libraries[alphecca][download][type] = "git"
libraries[alphecca][download][tag] = "0.1.2"
libraries[alphecca][download][url] = "https://github.com/opensourcery/alphecca.git"
libraries[alphecca][destination] = "themes/custom/flare/vendor"
libraries[alphecca][download][directory_name] = "alphecca"

; Jcarousel at release 0.3.1
libraries[jcarousel][download][type] = "get"
libraries[jcarousel][download][url] = "https://raw.githubusercontent.com/jsor/jcarousel/6720a8f44876ba76632212d97cb7d00ab701e360/dist/jquery.jcarousel.min.js"

; Themes

; Aurora
projects[aurora][type] = "theme"
projects[aurora][version] = "3.2"
