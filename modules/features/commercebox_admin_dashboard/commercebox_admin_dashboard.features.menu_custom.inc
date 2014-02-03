<?php
/**
 * @file
 * commercebox_admin_dashboard.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function commercebox_admin_dashboard_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin-menu.
  $menus['menu-admin-menu'] = array(
    'menu_name' => 'menu-admin-menu',
    'title' => 'Admin menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin menu');


  return $menus;
}
