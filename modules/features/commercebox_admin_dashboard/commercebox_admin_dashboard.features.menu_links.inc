<?php
/**
 * @file
 * commercebox_admin_dashboard.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function commercebox_admin_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-admin-menu:admin/appearance
  $menu_links['menu-admin-menu:admin/appearance'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/appearance',
    'router_path' => 'admin/appearance',
    'link_title' => 'Themes',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
  );
  // Exported menu link: menu-admin-menu:admin/apps
  $menu_links['menu-admin-menu:admin/apps'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/apps',
    'router_path' => 'admin/apps',
    'link_title' => 'Apps',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-admin-menu:admin/commerce
  $menu_links['menu-admin-menu:admin/commerce'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce',
    'router_path' => 'admin/commerce',
    'link_title' => 'Store',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-admin-menu:admin/commerce/config
  $menu_links['menu-admin-menu:admin/commerce/config'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce/config',
    'router_path' => 'admin/commerce/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin/commerce',
  );
  // Exported menu link: menu-admin-menu:admin/commerce/customer-profiles
  $menu_links['menu-admin-menu:admin/commerce/customer-profiles'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce/customer-profiles',
    'router_path' => 'admin/commerce/customer-profiles',
    'link_title' => 'Customer profiles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/commerce',
  );
  // Exported menu link: menu-admin-menu:admin/commerce/orders
  $menu_links['menu-admin-menu:admin/commerce/orders'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce/orders',
    'router_path' => 'admin/commerce/orders',
    'link_title' => 'Orders',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/commerce',
  );
  // Exported menu link: menu-admin-menu:admin/commerce/products
  $menu_links['menu-admin-menu:admin/commerce/products'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce/products',
    'router_path' => 'admin/commerce/products',
    'link_title' => 'Products',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-admin-menu:admin/commerce/products/add/product
  $menu_links['menu-admin-menu:admin/commerce/products/add/product'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce/products/add/product',
    'router_path' => 'admin/commerce/products/add/product',
    'link_title' => 'Add a product',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/commerce/products',
  );
  // Exported menu link: menu-admin-menu:admin/commerce/products/variations
  $menu_links['menu-admin-menu:admin/commerce/products/variations'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commerce/products/variations',
    'router_path' => 'admin/commerce/products/variations',
    'link_title' => 'All product variations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/commerce/products',
  );
  // Exported menu link: menu-admin-menu:admin/commercebox/filters
  $menu_links['menu-admin-menu:admin/commercebox/filters'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commercebox/filters',
    'router_path' => 'admin/commercebox/filters',
    'link_title' => 'Catalog filters',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
  );
  // Exported menu link: menu-admin-menu:admin/commercebox/product-type
  $menu_links['menu-admin-menu:admin/commercebox/product-type'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commercebox/product-type',
    'router_path' => 'admin/commercebox/product-type',
    'link_title' => 'Product types',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/commerce/products',
  );
  // Exported menu link: menu-admin-menu:admin/commercebox/product-type/add
  $menu_links['menu-admin-menu:admin/commercebox/product-type/add'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commercebox/product-type/add',
    'router_path' => 'admin/commercebox/product-type/add',
    'link_title' => 'Create product type',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/commercebox/product-type',
  );
  // Exported menu link: menu-admin-menu:admin/commercebox/product-type/product
  $menu_links['menu-admin-menu:admin/commercebox/product-type/product'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/commercebox/product-type/product',
    'router_path' => 'admin/commercebox/product-type/product',
    'link_title' => 'Product',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/commercebox/product-type',
  );
  // Exported menu link: menu-admin-menu:admin/config
  $menu_links['menu-admin-menu:admin/config'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/config',
    'router_path' => 'admin/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -41,
  );
  // Exported menu link: menu-admin-menu:admin/config/search
  $menu_links['menu-admin-menu:admin/config/search'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/config/search',
    'router_path' => 'admin/config/search',
    'link_title' => 'Search and metadata',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: menu-admin-menu:admin/config/search/search_api
  $menu_links['menu-admin-menu:admin/config/search/search_api'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/config/search/search_api',
    'router_path' => 'admin/config/search/search_api',
    'link_title' => 'Search API',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/config/search',
  );
  // Exported menu link: menu-admin-menu:admin/content
  $menu_links['menu-admin-menu:admin/content'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-admin-menu:admin/content/comment
  $menu_links['menu-admin-menu:admin/content/comment'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/content/comment',
    'router_path' => 'admin/content/comment',
    'link_title' => 'Comments',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/content',
  );
  // Exported menu link: menu-admin-menu:admin/dashboard
  $menu_links['menu-admin-menu:admin/dashboard'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-admin-menu:admin/modules
  $menu_links['menu-admin-menu:admin/modules'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/modules',
    'router_path' => 'admin/modules',
    'link_title' => 'Modules',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
  );
  // Exported menu link: menu-admin-menu:admin/people
  $menu_links['menu-admin-menu:admin/people'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
  );
  // Exported menu link: menu-admin-menu:admin/people/create
  $menu_links['menu-admin-menu:admin/people/create'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/people/create',
    'router_path' => 'admin/people/create',
    'link_title' => 'Add user',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/people',
  );
  // Exported menu link: menu-admin-menu:admin/people/permissions
  $menu_links['menu-admin-menu:admin/people/permissions'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/people/permissions',
    'router_path' => 'admin/people/permissions',
    'link_title' => 'Permissions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin/people',
  );
  // Exported menu link: menu-admin-menu:admin/people/permissions/roles
  $menu_links['menu-admin-menu:admin/people/permissions/roles'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/people/permissions/roles',
    'router_path' => 'admin/people/permissions/roles',
    'link_title' => 'Roles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/people',
  );
  // Exported menu link: menu-admin-menu:admin/reports
  $menu_links['menu-admin-menu:admin/reports'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/reports',
    'router_path' => 'admin/reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
  );
  // Exported menu link: menu-admin-menu:admin/structure
  $menu_links['menu-admin-menu:admin/structure'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure',
    'router_path' => 'admin/structure',
    'link_title' => 'Structure',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: menu-admin-menu:admin/structure/block
  $menu_links['menu-admin-menu:admin/structure/block'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: menu-admin-menu:admin/structure/block/add
  $menu_links['menu-admin-menu:admin/structure/block/add'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/block/add',
    'router_path' => 'admin/structure/block/add',
    'link_title' => 'Add block',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/structure/block',
  );
  // Exported menu link: menu-admin-menu:admin/structure/block/add-taxonomy-menu-block
  $menu_links['menu-admin-menu:admin/structure/block/add-taxonomy-menu-block'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/block/add-taxonomy-menu-block',
    'router_path' => 'admin/structure/block/add-taxonomy-menu-block',
    'link_title' => 'Add taxonomy menu block',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/structure/block',
  );
  // Exported menu link: menu-admin-menu:admin/structure/features
  $menu_links['menu-admin-menu:admin/structure/features'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/features',
    'router_path' => 'admin/structure/features',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: menu-admin-menu:admin/structure/menu
  $menu_links['menu-admin-menu:admin/structure/menu'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: menu-admin-menu:admin/structure/menu/add
  $menu_links['menu-admin-menu:admin/structure/menu/add'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/menu/add',
    'router_path' => 'admin/structure/menu/add',
    'link_title' => 'Add menu',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/structure/menu',
  );
  // Exported menu link: menu-admin-menu:admin/structure/taxonomy
  $menu_links['menu-admin-menu:admin/structure/taxonomy'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/taxonomy',
    'router_path' => 'admin/structure/taxonomy',
    'link_title' => 'Taxonomy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: menu-admin-menu:admin/structure/taxonomy/add
  $menu_links['menu-admin-menu:admin/structure/taxonomy/add'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/taxonomy/add',
    'router_path' => 'admin/structure/taxonomy/add',
    'link_title' => 'Add vocabulary',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/structure/taxonomy',
  );
  // Exported menu link: menu-admin-menu:admin/structure/types
  $menu_links['menu-admin-menu:admin/structure/types'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/types',
    'router_path' => 'admin/structure/types',
    'link_title' => 'Content types',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: menu-admin-menu:admin/structure/types/add
  $menu_links['menu-admin-menu:admin/structure/types/add'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/types/add',
    'router_path' => 'admin/structure/types/add',
    'link_title' => 'Add content type',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/structure/types',
  );
  // Exported menu link: menu-admin-menu:admin/structure/views
  $menu_links['menu-admin-menu:admin/structure/views'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/views',
    'router_path' => 'admin/structure/views',
    'link_title' => 'Views',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: menu-admin-menu:admin/structure/views/add
  $menu_links['menu-admin-menu:admin/structure/views/add'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/views/add',
    'router_path' => 'admin/structure/views/add',
    'link_title' => 'Add new view',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/structure/views',
  );
  // Exported menu link: menu-admin-menu:admin/structure/views/settings
  $menu_links['menu-admin-menu:admin/structure/views/settings'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/views/settings',
    'router_path' => 'admin/structure/views/settings',
    'link_title' => 'Settings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/structure/views',
  );
  // Exported menu link: menu-admin-menu:admin/structure/views/settings/advanced
  $menu_links['menu-admin-menu:admin/structure/views/settings/advanced'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/structure/views/settings/advanced',
    'router_path' => 'admin/structure/views/settings/advanced',
    'link_title' => 'Advanced',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin/structure/views',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add a product');
  t('Add block');
  t('Add content type');
  t('Add menu');
  t('Add new view');
  t('Add taxonomy menu block');
  t('Add user');
  t('Add vocabulary');
  t('Advanced');
  t('All product variations');
  t('Apps');
  t('Blocks');
  t('Catalog filters');
  t('Comments');
  t('Configuration');
  t('Content');
  t('Content types');
  t('Create product type');
  t('Customer profiles');
  t('Dashboard');
  t('Features');
  t('Menus');
  t('Modules');
  t('Orders');
  t('Permissions');
  t('Product');
  t('Product types');
  t('Products');
  t('Reports');
  t('Roles');
  t('Search API');
  t('Search and metadata');
  t('Settings');
  t('Store');
  t('Structure');
  t('Taxonomy');
  t('Themes');
  t('Users');
  t('Views');


  return $menu_links;
}
