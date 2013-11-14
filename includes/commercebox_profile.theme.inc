<?php

/**
 * Theme function to output checkboxes as table.
 */
function theme_commercebox_profile_options_table($variables) {
  $element = $variables['element'];

  $children = element_children($element);
  $header   = array_merge(array(drupal_render($element['all'])), $element['#header']);
  $rows     = array();
  foreach ($children as $child_id) {
    if (!empty($element[$child_id]['#type_name'])) {
      $type = $element[$child_id]['#type_name'];
      $rows[$type][] = array('data' => drupal_render($element[$child_id]));
    }
  }
  $table = array(
    '#theme'  => 'table',
    '#header' => $header,
    '#rows'   => $rows,
  );

  return theme('table', array('header' => $header, 'rows' => $rows));
}
