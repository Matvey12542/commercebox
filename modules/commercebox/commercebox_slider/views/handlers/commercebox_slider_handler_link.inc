<?php

/**
 * @file
 * Add edit link for slider.
 */

class commercebox_slider_handler_link extends views_handler_field {

  function query() {
    // do nothing -- to override the parent query.
  }

  /**
   * Renders output.
   */
  public function render($values) {
    $output = t('e');
    //_bh_training_include_modal();
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_library('system', 'jquery.form');

    //$output = ctools_modal_text_button(t('Sign up for training'), 'form/subscribers/nojs/'. $values->nid,t('Sign up for training'),'ctools-modal-subscriber-modal-style');
    $output = l('e', "data/" . $values->nid . "/nojs", array(
        'attributes' => array(
          'class' => array('use-ajax', 'edit-slide'),
        ),
      ));
    $output .= l('x', "data/delete/" . $values->nid . "/nojs", array(
        'attributes' => array(
          'class' => array('use-ajax', 'delete-slide'),

        ),
      ));
    return $output;
  }
}
