<?php

/**
 * Theme function for commercebox filters settings form.
 *
 * @param $vars
 * @return string
 */
function theme_commercebox_filters_settings_form($vars) {
  $form = $vars['form'];

  $header = array(
    'drag' => t('Position'),
    'enabled' => t('Enabled'),
    'filter' => t('filter'),
    'title' => t('Rewrite title'),
    'operations' => t('Configure'),
    'weight' => t('Weight'),
  );

  $rows = array();
  foreach (element_children($form['filters']) as $key) {
    $row = array();
    $row['data'] = array();
    foreach ($header as $fieldname => $title) {
      if ($fieldname == 'operations') {
        $row['data'][] = array(
          'data' => drupal_render($form['filters'][$key][$fieldname]),
          'class' => 'facetapi-operations',
        );
      }
      else {
        $row['data'][] = drupal_render($form['filters'][$key][$fieldname]);
      }
    }
    $row['class'] = array('draggable'); // needed for table dragging
    $rows[] = $row;
  }

  $table_id = 'cb-filters-table';

  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id), // needed for table dragging
  ));

  $output .= drupal_render_children($form);
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'filter-weight'); // needed for table dragging

  return $output;
}
