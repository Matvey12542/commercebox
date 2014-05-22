<?php
/**
 * @file
 * commercebox_slider_views_queue.features.inc
 */

/**
 * Implements hook_views_api().
 */
function commercebox_slider_views_queue_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function commercebox_slider_views_queue_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: commercebox_slider
  $nodequeues['commercebox_slider'] = array(
    'name' => 'commercebox_slider',
    'title' => 'commercebox_slider',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'Add slide',
    'link_remove' => 'Remove slide',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'banner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
