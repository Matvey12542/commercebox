<?php

/**
 * @file
 * Panels pane for Facet API blocks set.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title'           => t('Catalog filters'),
  'single'          => TRUE,
  'content_types'   => array('no_context_content_type'),
  'render callback' => 'commercebox_core_catalog_filters_render',
  'category'        => array(t('CommerceBox'), -12),
  'defaults'         => array(),
  'edit form'        => array(
    'commercebox_core_catalog_filters_edit_form' => array('title' => t('Catalog settings')),
  ),
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
function commercebox_core_catalog_filters_render($subtype, $conf, $args, $context = NULL) {
  $adapter = facetapi_adapter_load('search_api@product_display');
  $realm_name = 'block';
  $searcher = $adapter->getSearcher();

  $build = array();
  foreach (variable_get('commercebox_core_filters_settings', array()) as $facet_name => $settings) {
    if ($settings['enabled']) {
      $delta = facetapi_build_delta($searcher, $realm_name, $facet_name);
      $hash = facetapi_hash_delta($delta);
      if ($block = facetapi_block_view($hash)) {
        $build[$facet_name] = array(
          '#type' => 'container',
          '#attributes' => array('class' => array(drupal_html_class($facet_name))),
          'title' => array(
            '#prefix' => '<h2>',
            '#markup' => $settings['title']['rewrite'] ? t($settings['title']['value']) :$block['content']['#title'],
            '#suffix' => '</h2>',
            '#weight' => -1,
          ),
          'content' => $block['content'],
        );
      }
    }
  }

  $panel_pane = new stdClass();
  if ($build) {
    $panel_pane->title = t('Filters');
    $panel_pane->content = $build;
  }

  return $panel_pane;
}

/**
 * Panels pane settings form.
 */
function commercebox_core_catalog_filters_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submit handler for commercebox_catalog_filters_edit_form().
 */
function commercebox_core_catalog_filters_edit_form_submit($form, &$form_state) {
}
