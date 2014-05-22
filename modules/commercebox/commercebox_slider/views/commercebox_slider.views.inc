<?php

/**
 * @file
 * Include file for defining views handlers and data.
 */

/**
 * Implements hook_views_data().
 */
function commercebox_slider_views_data() {
  $data['views']['commercebox_slider'] = array(
    'title' => t('Commercebox slider'),
    'help' => t('Add edit link for popup'),
    'field' => array(
      'handler' => 'commercebox_slider_handler_link',
    ),
  );

  return $data;
}
