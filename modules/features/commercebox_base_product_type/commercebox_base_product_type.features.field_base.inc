<?php
/**
 * @file
 * commercebox_base_product_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function commercebox_base_product_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'cb_features'
  $field_bases['cb_features'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'cb_features',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
