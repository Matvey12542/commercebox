; Drupal.org release file.
core = 7.x
api = 2

; Basic contributed modules.
projects[addressfield][version] = 1.0
projects[addressfield][subdir] = "contrib"
projects[admin_menu][version] = 3.0-rc5
projects[admin_menu][subdir] = "contrib"
projects[apps][version] = 1.0-beta7
projects[apps][subdir] = "modified"
projects[apps][patch][] = "http://drupal.org/files/apps-add_themes_installation-1730160-18.patch"
projects[apps][patch][] = "http://drupal.org/files/apps-fix_illegal_string_offset-1820266-9.patch"
projects[commerce][version] = 1.11
projects[commerce][subdir] = "contrib"
projects[commerce_backoffice][version] = 1.4
projects[commerce_backoffice][subdir] = "contrib"
projects[commerce_fancy_attributes][version] = 1.0
projects[commerce_fancy_attributes][subdir] = "contrib"
projects[commerce_features][version] = 1.0
projects[commerce_features][subdir] = "contrib"
projects[commerce_migrate][version] = 1.1
projects[commerce_migrate][subdir] = "contrib"

projects[ctools][version] = 1.4
projects[ctools][subdir] = "contrib"
projects[date][version] = 2.8
projects[date][subdir] = "contrib"
projects[entity][version] = 1.5
projects[entity][subdir] = "contrib"
projects[eva][version] = 1.2
projects[eva][subdir] = "contrib"
projects[features][version] = 2.3
projects[features][subdir] = "contrib"
projects[features_extra][version] = 1.0-beta1
projects[features_extra][subdir] = "contrib"
projects[galleryformatter][version] = 1.3
projects[galleryformatter][subdir] = "contrib"
projects[inline_entity_form][version] = 1.5
projects[inline_entity_form][subdir] = "contrib"
projects[jquery_colorpicker][version] = 1.1
projects[jquery_colorpicker][subdir] = "contrib"
projects[libraries][version] = 2.2
projects[libraries][subdir] = "contrib"
projects[migrate][version] = 2.5
projects[migrate][subdir] = "contrib"
projects[migrate_extras][version] = 2.5
projects[migrate_extras][subdir] = "contrib"
projects[panels][version] = 3.3
projects[panels][subdir] = "contrib"
projects[physical][version] = 1.x-dev
projects[physical][subdir] = "contrib"
projects[rules][version] = 2.8
projects[rules][subdir] = "contrib"
projects[strongarm][version] = 2.0
projects[strongarm][subdir] = "contrib"
projects[taxonomy_menu_block][version] = 1.4
projects[taxonomy_menu_block][subdir] = "contrib"
projects[views][version] = 3.10
projects[views][subdir] = "contrib"
projects[views_bulk_operations][version] = 3.2
projects[views_bulk_operations][subdir] = "contrib"
projects[views_megarow][version] = 1.4
projects[views_megarow][subdir] = "contrib"
projects[wysiwyg][version] = 2.2
projects[wysiwyg][subdir] = "contrib"
projects[search_api][version] = 1.13
projects[search_api][subdir] = "contrib"
projects[search_api_db][version] = 1.4
projects[search_api_db][subdir] = "contrib"
projects[search_api_ranges][version] = 1.x-dev
projects[search_api_ranges][subdir] = "modified"
projects[commerce_search_api][version] = 1.3
projects[commerce_search_api][subdir] = "contrib"
projects[facetapi][version] = 1.5
projects[facetapi][subdir] = "contrib"
projects[charts][version] = 2.0-rc1
projects[charts][subdir] = "contrib"
projects[commerce_reports][version] = 4.0-beta1
projects[commerce_reports][subdir] = "contrib"
projects[facetapi_bonus][version] = 1.1
projects[facetapi_bonus][subdir] = "contrib"
projects[pathauto][version] = 1.2
projects[pathauto][subdir] = "contrib"
projects[token][version] = 1.5
projects[token][subdir] = "contrib"
projects[views_date_format_sql][version] = 3.1
projects[views_date_format_sql][subdir] = "contrib"

projects[features_extra][version] = 1.0-beta1
projects[features_extra][subdir] = "contrib"
projects[nodequeue][version] = 2.0-beta1
projects[nodequeue][subdir] = "contrib"
projects[link][version] = 1.3
projects[link][subdir] = "contrib"
projects[menu_minipanels][version] = 2.0-beta1
projects[menu_minipanels][subdir] = "contrib"
projects[commerce][patch][] = "https://drupal.org/files/undefined-index-amount-1819318-1.patch"
projects[ctools][patch][]   =  "https://www.drupal.org/files/issues/ctools-combined_patch_from_n2195211-15_and_n2195471-29--n2195471-47.patch"






; Libraries.
libraries[colorpicker][download][type] = get
libraries[colorpicker][download][url] = "http://www.eyecon.ro/colorpicker/colorpicker.zip"
libraries[colorpicker][destination] = libraries
