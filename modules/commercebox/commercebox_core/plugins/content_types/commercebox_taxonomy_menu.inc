<?php

/**
 * @file
 * Create taxonomy menu pane using taxonomy_menu_block module functionality.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title'           => t('Categories menu'),
  'single'          => TRUE,
  'content_types'   => array('no_context_content_type'),
  'render callback' => 'commercebox_taxonomy_menu_render',
  'category'        => array(t('CommerceBox'), -12),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param String $subtype
 *   Panel Pane subtype name.
 * @param Array $conf
 *   Configuration as done at admin time.
 * @param Array $args
 *   Array of arguments.
 * @param String $context
 *   Context - in this case we don't have any.
 *
 * @return Object
 *   An object with at least title and content.
 */
function commercebox_taxonomy_menu_render($subtype, $conf, $args, $context = NULL) {
  $config = taxonomy_menu_block_get_config('commercebox_category_menu');
  if (empty($config)) {
    commercebox_taxonomy_menu_set_config('commercebox_category_menu');
    $config = taxonomy_menu_block_get_config('commercebox_category_menu');
  }
  $block = taxonomy_menu_block_build($config);
  $block['title'] = $block['subject'];
  return (object) $block;
}


/**
 * Set taxonomy menu block config params.
 */
function commercebox_taxonomy_menu_set_config($delta) {
  module_load_include('inc', 'taxonomy_menu_block', 'taxonomy_menu_block.admin');

  $taxonomy_menu_block = array();

  $taxonomy_menu_block['admin_title'] = t('CommerceBox: Catalog menu');
  $taxonomy_menu_block['vid'] = 1;
  $taxonomy_menu_block['parent'] = 0;
  $taxonomy_menu_block['parent_fixed'] = 1;
  $taxonomy_menu_block['parent_dynamic'] = 1;
  $taxonomy_menu_block['depth'] = 0;
  $taxonomy_menu_block['home_link'] = FALSE;
  $taxonomy_menu_block['nodes'] = FALSE;
  $taxonomy_menu_block['nodes_aggregation'] = FALSE;
  $taxonomy_menu_block['hide_empty'] = FALSE;

  taxonomy_menu_block_save_block($delta, $taxonomy_menu_block);
}
