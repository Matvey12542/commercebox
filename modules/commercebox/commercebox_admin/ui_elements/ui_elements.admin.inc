<?php

/**
 * @file
 * Admin page callback file for the ui_elements module.
 */


/**
 * Form constructor for the background style settings.
 *
 * @see ui_elements_bg_form_submit()
 * @ingroup forms
 */
function ui_elements_bg_form($form, &$form_state) {
  $image = 'commercebox_bacground.png';
  $path = drupal_get_path('module', 'ui_elements') . "/images/$image";
  if (sizeof(module_implements('ui_elements_change_bacground_image')) > 0) {
    $path = module_invoke_all('ui_elements_change_bacground_image');
    $path = $path[0];
  }
  $repeat = variable_get('ui_settings_bg_repeat');
  $form['ui_settings']['preview-image'] = array(
    '#type' => 'item',
    '#title' => t('Preview'),
    '#markup' => theme('image', array('path' => $path)),
  );
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#attributes' => array(
      'class' => array('settings'),
    ),
  );
  $form['settings']['ui_settings']['bg_image'] = array(
    '#title' => t('Background image'),
    '#type' => 'managed_file',
    '#description' => t('Please upload an image!'),
    '#progress_indicator' => 'bar',
    '#upload_location' => 'public://bg_images/',
    '#default_value' => variable_get('ui_settings_bg_image_fid'),
  );

  $form['settings']['ui_settings']['bg_repeat'] = array(
    '#type' => 'checkbox',
    '#title' => t('Background repeat'),
    '#default_value' => !empty($repeat)&&($repeat!='no-repeat') ? 1:0,
  );
  $form['settings']['ui_settings']['bg_repeat_x'] = array(
    '#type' => 'checkbox',
    '#title' => t('Repeat X'),
    '#default_value' => variable_get('repeat-x'),
    '#states' => array(
      'visible' => array(
        ':input[name="bg_repeat"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['settings']['ui_settings']['bg_repeat_y'] = array(
    '#type' => 'checkbox',
    '#title' => t('Repeat Y'),
    '#default_value' => variable_get('repeat-y'),
    '#states' => array(
      'visible' => array(
        ':input[name="bg_repeat"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['settings']['ui_settings']['bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#suffix' => '<div id="color-picker"></div>',
    '#default_value' => variable_get('ui_settings_bg_color', '#FFFFFF'),
    '#maxlength' => 7,
    '#size' => 7,
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array(
        array(
          'type' => 'inline',
          'data' =>
            '(function($) {
              $(document).ready(function() {
                $("#color-picker").farbtastic("#edit-bg-color");
              });
            }) (jQuery);'
        ),
      )
    )
  );

  $form['settings']['ui_settings']['default'] = array(
    '#type' => 'submit',
    '#value' => t('Default value'),
  );

  $form['settings']['ui_settings']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Form submit callback
 */
function ui_elements_bg_form_submit($form, &$form_state) {
  global $user;
  if (!empty($form_state['values']['bg_image'])) {
    $file_obj = file_load($form_state['values']['bg_image']);
    if ($file_obj) {
      $file_obj->status = FILE_STATUS_PERMANENT;
      file_save($file_obj);
      file_usage_add($file_obj, 'user', 'user', $user->uid);
    }
    $bg_image = $form_state['values']['bg_image'];
  }
  else {
    $bg_image = 0;
  }
  $repeat = $form_state['values']['bg_repeat'];
  $repeat_x = $form_state['values']['bg_repeat_x'];
  $repeat_y = $form_state['values']['bg_repeat_y'];


  if (empty($repeat)) {
    $repeat = 'no-repeat';
  }
else {
    if ((!empty($repeat_x) && !empty($repeat_y)) || (empty($repeat_x) && empty($repeat_y))) {
      $repeat = 'repeat';
    }
  elseif (!empty($repeat_x)) {

      $repeat = 'repeat-x';
    }
  elseif (!empty($repeat_y)) {
      $repeat = 'repeat-y';

    }
  }
  variable_set('repeat-y',$repeat_y);
  variable_set('repeat-x',$repeat_x);

  variable_set('ui_settings_bg_image_fid', $bg_image);
  variable_set('ui_settings_bg_repeat', $repeat);
  variable_set('ui_settings_bg_color', $form_state['values']['bg_color']);
  if ($form_state['values']['op'] == 'Default value') {
    $repeat = 'auto';
    variable_set('ui_settings_bg_image_fid', '');
    variable_set('ui_settings_bg_color', '#ffffff');
    variable_set('repeat-y','');
    variable_set('repeat-x','');
    variable_set('ui_settings_bg_repeat', '');
  }
}

/**
 * Form constructor for the form submit style settings.
 *
 * @see ui_elements_button_form_submit()
 * @ingroup forms
 */
function ui_elements_button_form($form, &$form_state) {
  $image = 'buttons.png';
  $path = drupal_get_path('module', 'ui_elements') . "/images/$image";
  if (sizeof(module_implements('ui_elements_change_buttons_image')) > 0) {
    $path = module_invoke_all('ui_elements_change_buttons_image');
    $path = $path[0];
  }
  $active = array(
    'default' => t('Default'),
    '263248' => t('Dark'),
    '2CC36B' => t('Green'),
    '4AA3DF' => t('Blue'),
    'F16E3F' => t('Orange'),
    'EA6153' => t('Red'),
    'other' => t('Other'),
    'none' => t('None')
  );
  $form['ui_settings']['preview-image'] = array(
    '#type' => 'item',
    '#title' => t('Preview'),
    '#markup' => theme('image', array('path' => $path)),
  );
  $form['ui_settings']['form_button'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('form-button-settings'),
    ),
  );

  $form['ui_settings']['form_button']['bg_default'] = array(
    '#type' => 'radios',
    '#title' => t('Default Buttons'),
    '#options' => $active,
  );
  $form['ui_settings']['form_button']['bg_color_button'] = array(          //color picker fo rdefault button
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#suffix' => '<div id="color-picker-default"></div>',
    '#default_value' => variable_get('ui_settings_button_color', '#479ec2'),
    '#maxlength' => 7,
    '#size' => 7,
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array(
        array(
          'type' => 'inline',
          'data' =>
            '(function($) {
              $(document).ready(function() {
                $("#color-picker-default").farbtastic("#edit-bg-color-button");
              });
            }) (jQuery);'
        ),
      )
    )
  );

  $form['ui_settings']['form_button']['bg_rounded'] = array(
    '#type' => 'radios',
    '#title' => t('Rounded Buttons'),
    '#options' => $active,
  );
  $form['ui_settings']['form_button']['bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#suffix' => '<div id="color-picker"></div>',
    '#default_value' => variable_get('ui_settings_button_color', '#479ec2'),
    '#maxlength' => 7,
    '#size' => 7,
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array(
        array(
          'type' => 'inline',
          'data' =>
            '(function($) {
              $(document).ready(function() {
                $("#color-picker").farbtastic("#edit-bg-color");
              });
            }) (jQuery);'
        ),
      )
    )
  );


  $form['ui_settings']['form_button']['bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#suffix' => '<div id="color-picker"></div>',
    '#default_value' => variable_get('ui_settings_button_color', '#479ec2'),
    '#maxlength' => 7,
    '#size' => 7,
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array(
        array(
          'type' => 'inline',
          'data' =>
            '(function($) {
              $(document).ready(function() {
                $("#color-picker").farbtastic("#edit-bg-color");
              });
            }) (jQuery);'
        ),
      )
    )
  );
  // Pager!!!
  $form['ui_settings']['pager_style'] = array(
    '#type' => 'radios',
    '#title' => t('Pager color'),
    '#options' => $active,
  );

  $form['ui_settings']['pager_other_style'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#suffix' => '<div id="color-picker-pager"></div>',
    '#default_value' => variable_get('ui_settings_pager_style', '#479ec2'),
    '#maxlength' => 7,
    '#size' => 7,
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array(
        array(
          'type' => 'inline',
          'data' =>
            '(function($) {
              $(document).ready(function() {
                $("#color-picker-pager").farbtastic("#edit-pager-other-style");
              });
            }) (jQuery);'
        ),
      )
    )
  );

  // Page style.

  $form['ui_settings']['bg_default_page'] = array(
    '#type' => 'radios',
    '#title' => t('Page elements'),
    '#options' => $active,
  );
  $form['ui_settings']['default_bg_default_page'] = array(
    '#type' => 'hidden',
    '#default_value' => variable_get('ui_settings_page_style_color'),
  );
  $form['ui_settings']['page_style_color_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#suffix' => '<div id="color-picker-page-style"></div>',
    '#default_value' => variable_get('ui_settings_page_style_color'),
    '#maxlength' => 7,
    '#size' => 7,
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array(
        array(
          'type' => 'inline',
          'data' =>
            '(function($) {
              $(document).ready(function() {
                $("#color-picker-page-style").farbtastic("#edit-page-style-color-page");
              });
            }) (jQuery);'
        ),
      )
    )
  );

  $form['ui_settings']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#attributes' => array(
      'round' => array(variable_get('ui_settings_button_rounded',0)),
      'color' => array(variable_get('ui_settings_button_color')),
      'pagercolor' => array(variable_get('ui_settings_pager_style')),
      'pageelemcolor' => array(variable_get('ui_settings_page_style_color')),

    ),
  );
  return $form;
}

/**
 * Form submission handler for ui_elements_button_form().
 */
function ui_elements_button_form_submit($form, &$form_state) {

  $pager_style = $form_state['values']['pager_style'];

  $bg_rounded = $form_state['values']['bg_rounded'];
  $bg_default = $form_state['values']['bg_default'];

  $bg_color = 'none';
  if (!empty($bg_default) && $bg_default != 'none') {
    $bg_color = $bg_default;
    variable_set('ui_settings_button_rounded', 0);
  }
  elseif (!empty($bg_rounded) && $bg_rounded != 'none') {
    $bg_color = $bg_rounded;
    variable_set('ui_settings_button_rounded', 7);
  }
  switch ($bg_color) {
    case 'none':
      $color = $form_state['values']['bg_color'];
      break;

    case 'other':
      $color = $form_state['values']['bg_color_button']; //
      if ($bg_rounded == 'other') {
        $color = $form_state['values']['bg_color']; //
      }
      break;

    case 'default':
//      $color = '#67B4E6';
      $color = '#';
      break;

    default:
      $color = '#' . $bg_color;
      break;
  }
  switch ($pager_style) {
    case 'other':
      $pager_style = $form_state['values']['pager_other_style'];
      break;

    case 'default':
      $pager_style = '#';
      break;
    case '':
      $pager_style = variable_get('ui_settings_pager_style');
      break;

    default:
      $pager_style = '#' . $pager_style;
      break;
  }
  variable_set('ui_settings_pager_style', $pager_style);
  variable_set('ui_settings_button_color', $color);

  // Page style

  if ($form_state['values']['bg_default_page'] == 'other') {
    $style_color = $form_state['values']['page_style_color_page'];
  }
else {
    $style_color = '#' . $form_state['values']['bg_default_page'];
    if ($form_state['values']['bg_default_page'] == 'default') {
//      $style_color = '#67B4E6';
      $style_color = '#';
    }
  if ($form_state['values']['bg_default_page'] == '') {
    $style_color = variable_get('ui_settings_page_style_color');
  }
  }
  variable_set('ui_settings_page_style_color', $style_color);
}