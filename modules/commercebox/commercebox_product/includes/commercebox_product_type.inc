<?php


/**
 * Product add/update form.
 */
function commercebox_product_type_form($form, &$form_state, $type) {
  if (!is_array($type)) {
    $type = commerce_product_type_load($type);
  }

  // Return a message if the product variation type is not governed by Product UI.
  if (!empty($type['type']) && $type['module'] != 'commerce_product_ui') {
    return t('This product variation type cannot be edited, because it is not defined by the Product UI module.');
  }

  // Include the forms file from the Product module.
  module_load_include('inc', 'commercebox_product', 'includes/commercebox_product.field_base');
  module_load_include('inc', 'commercebox_product', 'includes/commercebox_product.field_instance');

  form_load_include($form_state, 'inc', 'commerce_product_ui', 'includes/commerce_product_ui.forms');
  form_load_include($form_state, 'inc', 'commerce_backoffice', 'includes/commerce_backoffice_product.product_variation_types');

  $form = commerce_product_ui_product_type_form($form, $form_state, $type);
  commerce_backoffice_product_form_commerce_product_ui_product_type_form_alter($form, $form_state);

  $product_type = $form_state['product_type'];

  $form_state['instances'] = array();
  $form_state['registry_rebuild'] = FALSE;
  $catalog_access = TRUE;
  if (!empty($product_type['type'])) {
    $form_state['instances'] = field_info_instances('commerce_product', $product_type['type']);
    $form_state['display_instances'] = field_info_instances('node', $product_type['type']);
    $catalog_access = (bool) node_type_load($product_type['type']);
  }

  $form['product_type']['catalog'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add product to catalog'),
    '#default_value' => isset($form_state['display_instances']['field_catalog_reference']),
    '#access' => $catalog_access,
  );

  $form['information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Product information'),
    '#collapsible' => TRUE,
    '#collapsed' => empty($form_state['instances']),
    '#tree' => TRUE,
  );

  $options = _get_options('information');
  $form['information']['fields'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => array_keys(array_intersect_key($form_state['instances'], $options)),
  );

  $form['attribute'] = array(
    '#type' => 'fieldset',
    '#title' => t('Product attributes'),
    '#collapsible' => TRUE,
    '#collapsed' => empty($form_state['instances']),
    '#tree' => TRUE,
  );

  $options = _get_options('attribute');
  $form['attribute']['fields'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => array_keys(array_intersect_key($form_state['instances'], $options)),
  );

  $form['actions']['submit']['#submit'][] = 'commercebox_product_create_basic_fields_submit';
  $form['actions']['submit']['#submit'][] = 'commercebox_product_product_type_form_submit';
  $form['actions']['save_continue']['#submit'][] = 'commercebox_product_create_basic_fields_submit';
  $form['actions']['save_continue']['#submit'][] = 'commercebox_product_product_type_form_submit';

  $form['create_product_display']['#type'] = 'value';
  return $form;
}


/**
 * Submit handler for commercebox_add_product_type_form().
 *
 * Create catalog vocabulary reference field in the product display node.
 */
function commercebox_product_create_basic_fields_submit($form, &$form_state) {
  $bundle = _get_bundle_name($form_state);
  if ($form_state['values']['product_type']['catalog']) {
    _create_product_cb_fields(array('field_catalog_reference' => TRUE), $bundle, 'node', $form_state);
  }
  else {
    $instance = field_info_instance('node', 'field_catalog_reference', $bundle);
    field_delete_instance($instance);
  }
  // Create default fields for commerce product display.
  $fields = array('field_images' => TRUE, 'field_description' => TRUE);
  _create_product_cb_fields($fields, $bundle, 'commerce_product', $form_state);

  // We need to update default display setting of newly created product display
  // node type, using settings defined in the base product display node type.
  if(empty($form_state['product_type']['type'])) {
    if (module_load_include('inc', 'commercebox_base_product_type', 'commercebox_base_product_type.strongarm')) {
      $strongarms = commercebox_base_product_type_strongarm();
      if (isset($strongarms['field_bundle_settings_node__product'])) {
        variable_set("field_bundle_settings_node__{$bundle}", $strongarms['field_bundle_settings_node__product']->value);
      }
    }
    if (module_load_include('inc', 'commercebox_base_product_type', 'commercebox_base_product_type.features.field_instance')) {
      $instances = commercebox_base_product_type_field_default_field_instances();
      if (isset($instances['node-product-field_product'])) {
        $instance = field_info_instance('node', 'field_product', $bundle);
        $instance['display']['default'] = $instances['node-product-field_product']['display']['default'];
        field_update_instance($instance);
      }
    }
  }

  if (!empty($form_state['values']['product_type']['name'])) {
    $item = array(
      'link_path' => 'admin/commercebox/product-type/' . $form_state['values']['product_type']['name'],
      'link_title' => $form_state['values']['product_type']['name'],
      'menu_name' => 'menu-admin-menu', // Menu machine name, for example: main-menu
      'weight' => 0,
      'language' => LANGUAGE_NONE,
      'plid' => 562, // Parent menu item, 0 if menu item is on top level
      'module' => 'menu',
    );
    menu_link_save($item);
  }
}


/**
 * Submit handler for commercebox_add_product_type_form().
 */
function commercebox_product_product_type_form_submit($form, &$form_state) {
  field_cache_clear();
  field_associate_fields('commercebox_product');

  $type = _get_bundle_name($form_state);
  $fields = array_filter(array_merge($form_state['values']['information']['fields'], $form_state['values']['attribute']['fields']));

  if (empty($form_state['instances'])) {
    _create_product_cb_fields($fields, $type, 'commerce_product', $form_state);
  }
  else {
    // Filter instances to process only fields with cb_ prefix.
    $instances = array_filter($form_state['instances'], '_filter_instances');
    $enabled = array_diff_key($fields, $instances);
    if (!empty($enabled)) {
      _create_product_cb_fields($enabled, $type, 'commerce_product', $form_state);
    }
    $disabled = array_diff_key($instances, $fields);
    if (!empty($disabled)) {
      _delete_product_cb_fields($disabled);
      $form_state['registry_rebuild'] = TRUE;
    }
  }

  // Rebuild registry only if some field was added or deleted.
  if ($form_state['registry_rebuild']) {
    module_load_include('inc', 'admin_menu', 'admin_menu');
    _admin_menu_flush_cache('registry');

    $message = t('You need to update your !index to apply new changes in the product fields configuration.', array('!index' => l(t('Product display index'), 'admin/config/search/search_api/index/product_display')));
    drupal_set_message($message, 'warning');
  }

  $form_state['redirect'] = current_path();
}


/**
 * Create fields for specific bundle.
 *
 * @todo: Rewrite to use $fields array values instead of keys.
 */
function _create_product_cb_fields($fields, $bundle, $entity_type, &$form_state) {
  $base_product_instances = array();
  if (module_load_include('inc', 'commercebox_base_product_type', 'commercebox_base_product_type.features.field_instance')) {
    $base_product_instances = commercebox_base_product_type_field_default_field_instances();
  }
  $field_bases = commercebox_product_field_bases();
  $field_instances = commercebox_product_field_instances($bundle);

  if (is_array($fields)) {
    foreach ($fields as $name => $value) {
      $field = field_info_field($name);
      if (empty($field) && isset($field_bases[$name])) {
        $field = field_create_field($field_bases[$name]);
      }
      // Create taxonomy vocabulary if not exists,
      if ($field['type'] == 'taxonomy_term_reference') {
        $v_name = $field['settings']['allowed_values'][0]['vocabulary'];
        if (!taxonomy_vocabulary_machine_name_load($v_name)) {
          drupal_set_message(t('Missed vocabulary !name for field !field', array('!name' => $v_name, '!field' => $name)), 'warning');
          continue;
        }
      }
      if (!field_info_instance($entity_type, $name, $bundle)) {
        if (isset($base_product_instances["{$entity_type}-product-{$name}"])) {
          $instance = $base_product_instances["{$entity_type}-product-{$name}"];
          $instance['bundle'] = $bundle;
          field_create_instance($instance);
          $form_state['registry_rebuild'] = TRUE;
        }
        else {
          field_create_instance($field_instances[$name]);
          $form_state['registry_rebuild'] = TRUE;
        }
      }
    }
  }
}


/**
 * Delete field instances.
 */
function _delete_product_cb_fields($instances) {
  foreach ($instances as $key => $instance) {
    field_delete_instance($instance);
  }
}


/**
 * Return an options array of information or attribute fields.
 */
function _get_options($type) {
  $options = array(
    'information' => array(
      'cb_features' => t('Features'),
      'cb_dimensions' => t('Dimensions'),
      'cb_weight' => t('Weight'),
    ),
    'attribute' => array(
      'cb_attr_clothing_size' => t('Clothing size'),
      'cb_attr_color' => t('Color'),
    ),
  );
  return isset($options[$type]) ? $options[$type] : array();
}


/**
 * Callback function for array_filter().
 */
function _filter_instances($var) {
  return (strpos($var['field_name'], 'cb_') === 0);
}


/**
 * Get bundle name from $form_state.
 */
function _get_bundle_name($form_state) {
  return empty($form_state['product_type']['type']) ? $form_state['values']['product_type']['type'] : $form_state['product_type']['type'];
}
