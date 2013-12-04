; Drupal.org release file.
core = 7.x
api = 2

projects[drupal][type] = core

; Basic contributed modules.
projects[addressfield][version] = 1.0-beta4
projects[addressfield][subdir] = "contrib"
projects[admin_menu][version] = 3.0-rc4
projects[admin_menu][subdir] = "contrib"
projects[apps][version] = 1.0-beta7
projects[apps][subdir] = "contrib"

projects[apps][patch][] = "http://drupal.org/files/apps-add_themes_installation-1730160-18.patch"
projects[apps][patch][] = "http://drupal.org/files/apps-fix_illegal_string_offset-1820266-9.patch"

projects[commerce][version] = 1.8
projects[commerce][subdir] = "contrib"
projects[commerce_backoffice][version] = 1.3
projects[commerce_backoffice][subdir] = "contrib"
projects[commerce_fancy_attributes][version] = 1.0
projects[commerce_fancy_attributes][subdir] = "contrib"
projects[commerce_features][version] = 1.0-rc1
projects[commerce_features][subdir] = "contrib"

;! cgenge version
projects[commerce_migrate][version] = 1.1
;!!!!!!!
projects[commerce_migrate][subdir] = "contrib"

projects[ctools][version] = 1.3
projects[ctools][subdir] = "contrib"
projects[date][version] = 2.6
projects[date][subdir] = "contrib"
projects[entity][version] = 1.2
projects[entity][subdir] = "contrib"
projects[eva][version] = 1.2
projects[eva][subdir] = "contrib"
projects[features][version] = 2.0-rc2
projects[features][subdir] = "contrib"
projects[features_extra][version] = 1.0-beta1
projects[features_extra][subdir] = "contrib"
projects[galleryformatter][version] = 1.3
projects[galleryformatter][subdir] = "contrib"
projects[inline_entity_form][version] = 1.3
projects[inline_entity_form][subdir] = "contrib"
projects[jquery_colorpicker][version] = 1.0-rc2
projects[jquery_colorpicker][subdir] = "contrib"
projects[libraries][version] = 2.1
projects[libraries][subdir] = "contrib"
projects[migrate][version] = 2.5
projects[migrate][subdir] = "contrib"
projects[migrate_extras][version] = 2.5
projects[migrate_extras][subdir] = "contrib"
projects[panels][version] = 3.3
projects[panels][subdir] = "contrib"
projects[physical][version] = 1.x-dev
projects[physical][subdir] = "contrib"
projects[rules][version] = 2.3
projects[rules][subdir] = "contrib"
projects[strongarm][version] = 2.0
projects[strongarm][subdir] = "contrib"
projects[taxonomy_menu_block][version] = 1.2
projects[taxonomy_menu_block][subdir] = "contrib"
projects[views][version] = 3.1
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = 3.1
projects[views_bulk_operations][subdir] = "contrib"

projects[views_megarow][version] = 1.1
projects[views_megarow][subdir] = "contrib"

projects[taxonomy_menu_block][version] = 1.2
projects[taxonomy_menu_block][subdir] = "contrib"

projects[wysiwyg][version] = 2.2
projects[wysiwyg][subdir] = "contrib"


