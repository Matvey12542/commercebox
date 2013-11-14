<?php
/**
 * @file
 * commercebox_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function commercebox_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 450x460_retina.
  $styles['450x460_retina'] = array(
    'name' => '450x460_retina',
    'label' => '450x460_retina',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 450,
          'height' => 460,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: x_350.
  $styles['x_350'] = array(
    'name' => 'x_350',
    'label' => 'x*350',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 440,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
