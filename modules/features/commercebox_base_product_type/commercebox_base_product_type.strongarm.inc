<?php
/**
 * @file
 * commercebox_base_product_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function commercebox_base_product_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_product';
  $strongarm->value = 0;
  $export['comment_anonymous_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_product';
  $strongarm->value = 1;
  $export['comment_default_mode_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_product';
  $strongarm->value = '50';
  $export['comment_default_per_page_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_product';
  $strongarm->value = 1;
  $export['comment_form_location_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_product';
  $strongarm->value = '1';
  $export['comment_preview_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_product';
  $strongarm->value = '2';
  $export['comment_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_product';
  $strongarm->value = 1;
  $export['comment_subject_field_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__product';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'reviews_product' => array(
        'custom_settings' => TRUE,
      ),
      'information_product' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'reviews_product' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'reviews_product' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'reviews_product' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'reviews_product' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'information_product' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'product:field_description' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'reviews_product' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'information_product' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'product:field_image' => array(
          'default' => array(
            'weight' => '-10',
            'visible' => TRUE,
          ),
        ),
        'product:field_images' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'reviews_product' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'information_product' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'product:cb_features' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'reviews_product' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:cb_dimensions' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'reviews_product' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'product:cb_weight' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'reviews_product' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'product:cb_attr_clothing_size' => array(
          'reviews_product' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'product:cb_attr_color' => array(
          'reviews_product' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'information_product' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_product';
  $strongarm->value = '0';
  $export['language_content_type_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_product';
  $strongarm->value = array();
  $export['menu_options_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_product';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_product';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_product';
  $strongarm->value = '1';
  $export['node_preview_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_product';
  $strongarm->value = 0;
  $export['node_submitted_product'] = $strongarm;

  return $export;
}
