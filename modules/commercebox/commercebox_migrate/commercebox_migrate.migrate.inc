<?php

/**
 * @file
 *  Contains CommerceBox migration classes.
 */

/**
 * Common features for all the migrations.
 */
abstract class CommerceBoxMigration extends Migration {

  public function processImport(array $options = array()) {
    parent::processImport($options);
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // in each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }
}

class CommerceBoxPages extends CommerceBoxMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import pages nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commercebox_migrate') . '/import/pages.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('page');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'excerpt');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  function csvcolumns() {
    // "Title", "Path", "Body"
    $columns[0] = array('title', 'Title');
    $columns[1] = array('path', 'Path');
    $columns[2] = array('body', 'Body');
    $columns[3] = array('menu_link', 'Menu link');
    return $columns;
  }

  function complete($entity, $row) {
    // Add links to main menu.
    if ($row->menu_link) {
      $item = array(
        'link_path' => 'node/' . $entity->nid,
        'link_title' => $entity->title,
        'menu_name' => 'main-menu',
        'weight' => $entity->nid,
      );
      menu_link_save($item);
    }
  }
}

class CommerceBoxBanners extends CommerceBoxMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import banner nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commercebox_migrate') . '/import/banners.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('banner');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'excerpt');
    // Image.
    $this->addFieldMapping('field_image', 'image');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'commercebox_migrate') . '/import/images');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  function csvcolumns() {
    // "Title", "Body", "Image"
    $columns[0] = array('title', 'Title');
    $columns[1] = array('body', 'Body');
    $columns[2] = array('image', 'Image');
    return $columns;
  }
}

class CommerceBoxNews extends CommerceBoxMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import banner nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commercebox_migrate') . '/import/news.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('news');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'excerpt');
    // Image.
    $this->addFieldMapping('field_image', 'image');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'commercebox_migrate') . '/import/images');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  function csvcolumns() {
    // "Title", "Body", "Image"
    $columns[0] = array('title', 'Title');
    $columns[1] = array('body', 'Body');
    $columns[2] = array('image', 'Image');
    return $columns;
  }
}

class CommerceBoxProductBase extends CommerceBoxMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import base products from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sku' => array(
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_product', 'product')
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commercebox_migrate') . '/import/products.csv', $this->csvcolumns(), array('header_rows' => 1), $this->fields());

    $this->destination = new MigrateDestinationEntityAPI('commerce_product', 'product');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('sku', 'sku');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('commerce_price', 'price');
    $this->addFieldMapping('field_description', 'description');
    // Images
    $this->addFieldMapping('field_images', 'product_images');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_images:source_dir')
      ->defaultValue(drupal_get_path('module', 'commercebox_migrate') . '/import/images');

    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('language', 'language');
  }

  function csvcolumns() {
    $columns[0] = array('title', 'title');
    $columns[1] = array('category', 'category');
    $columns[2] = array('description', 'description');
    $columns[3] = array('price', 'price');
    $columns[4] = array('sku', 'sku');
    $columns[5] = array('images', 'images');
    return $columns;
  }

  function fields() {
    return array(
      'product_images' => 'An array of images, populated during prepareRow().',
    );
  }

  function prepareRow($row) {
    $row->product_images = explode(', ', $row->images);
    $row->uid = 1;
    $row->language = LANGUAGE_NONE;
    $row->created = rand((REQUEST_TIME - 30 * 24 * 3600), REQUEST_TIME);
  }
}


class CommerceBoxProductDisplay extends DynamicMigration {

  public function __construct(array $arguments) {
    $this->arguments = $arguments;
    parent::__construct();
    $this->description = t('Import product nodes.');
    $this->dependencies = array('CommerceBoxProductBase');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commercebox_migrate') . '/import/products.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('product');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('field_catalog_reference', 'category');
    $this->addFieldMapping('field_catalog_reference:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_product', 'skus');
  }

  public function prepareRow($row) {
    $products = array();
    foreach(explode(', ', $row->sku) as $sku) {
      $product = commerce_product_load_by_sku($sku);
      $products[] = $product->product_id;
    }
    $row->skus = $products;
    $row->created = rand((REQUEST_TIME - 30 * 24 * 3600), REQUEST_TIME);
  }

  function csvcolumns() {
    $columns[0] = array('title', 'title');
    $columns[1] = array('category', 'category');
    $columns[2] = array('description', 'description');
    $columns[3] = array('price', 'price');
    $columns[4] = array('sku', 'sku');
    $columns[5] = array('images', 'images');
    $columns[6] = array('promote', 'promote');
    return $columns;
  }

  public function processImport(array $options = array()) {
    parent::processImport($options);
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // in each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }
}

class CommerceBoxCatalog extends Migration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import catalog terms.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commercebox_migrate') . '/import/catalog.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm('catalog');

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('parent_name', 'parent_name');
    // Images
    $this->addFieldMapping('field_image', 'images');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'commercebox_migrate') . '/import/images');
  }

  function csvcolumns() {
    // "Name", "Images"
    $columns[0] = array('name', 'Name');
    $columns[1] = array('description', 'Description');
    $columns[2] = array('images', 'Images');
    $columns[3] = array('parent_name', 'Parent');
    return $columns;
  }
}
