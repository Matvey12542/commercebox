<?php

/**
 * Page callback: Displays features injection settings form.
 */
function commercebox_core_feature_injection_form($form, &$form_state) {
  $form['feature_inj_dis'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable feature-injection'),
    '#default_value' => variable_get('feature_inj_dis', 0),
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'commercebox_core_feature_injection_form_submit';
  return $form;
}


/**
 * A submit function for commercebox_feature_injection_form to clear view cache.
 */
function commercebox_feature_injection_form_submit($form, &$form_state) {
  views_invalidate_cache();
}


/**
 * CommerceBox filters setting form.
 */
function commercebox_core_filters_settings_form($form, &$form_state) {
  module_load_include('inc', 'facetapi', 'facetapi.admin');

  $searcher = 'search_api@product_display';
  $adapter = facetapi_adapter_load($searcher);
  $facet_info = facetapi_get_facet_info($searcher);
  $realm_name = 'block';
  $realm = facetapi_realm_load($realm_name);

  $cb_filters_settings = variable_get('commercebox_core_filters_settings', array());

  $form['filters'] = array(
    '#tree' => TRUE,
  );

  // Initialize some filters to display rows depending to filters weight.
  foreach ($cb_filters_settings as $key => $value) {
    $form['filters'][$key] = array();
  }

  foreach ($facet_info as $facet_name => $facet) {
    $settings = $adapter->getFacetSettings($facet, $realm);

    if ($settings->enabled) {
      $form['filters'][$facet_name]['drag'] = array();
      $form['filters'][$facet_name]['enabled'] = array(
        '#type' => 'checkbox',
        '#default_value' => empty($cb_filters_settings[$facet_name]) ? FALSE : $cb_filters_settings[$facet_name]['enabled'],
      );
      $form['filters'][$facet_name]['filter'] = array('#markup' => $facet['label']);
      $form['filters'][$facet_name]['title'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('container-inline'),
        ),
        'rewrite' => array(
          '#type' => 'checkbox',
          '#default_value' => isset($cb_filters_settings[$facet_name]) ? $cb_filters_settings[$facet_name]['title']['rewrite'] : 0,
        ),
        'value' => array(
          '#type' => 'textfield',
          '#default_value' => isset($cb_filters_settings[$facet_name]) ? $cb_filters_settings[$facet_name]['title']['value'] : NULL,
          '#size' => 30,
        ),
      );

      // Builds array of operations to use in the dropbutton.
      $destination = drupal_get_destination();
      $operations = array();
      $operations[] = array(
        'title' => t('Display'),
        'href' => facetapi_get_settings_path($searcher, $realm['name'], $facet_name, 'edit'),
        'query' => $destination,
      );
      if ($facet['dependency plugins']) {
        $operations[] = array(
          'title' => t('Dependencies'),
          'href' => facetapi_get_settings_path($searcher, $realm['name'], $facet_name, 'dependencies'),
          'query' => $destination,
        );
      }
      if (facetapi_filters_load($facet_name, $searcher, $realm['name'])) {
        $operations[] = array(
          'title' => t('Filters'),
          'href' => facetapi_get_settings_path($searcher, $realm['name'], $facet_name, 'filters'),
          'query' => $destination,
        );
      }
      $form['filters'][$facet_name]['operations'] = array(
        '#theme' => 'links__ctools_dropbutton',
        '#links' => $operations,
        '#attributes' => array(
          'class' => array('inline', 'links', 'actions', 'horizontal', 'right')
        ),
      );

      // Position (weight, drag&drop)
      $form['filters'][$facet_name]['weight'] = array(
        '#type' => 'textfield',
        '#default_value' => isset($cb_filters_settings[$facet_name]) ? $cb_filters_settings[$facet_name]['weight'] : 0,
        '#size' => 3,
        '#attributes' => array('class' => array('filter-weight')), // needed for table dragging
      );
    }
  }

  $form['additional'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('additional-filter-settings')),
    'value' => array(
      '#theme' => 'link',
      '#path' => 'admin/config/search/search_api/index/product_display',
      '#text' => t('Advanced filters settings'),
      '#options' => array(
        'attributes' => array('class' => array('advanced-filter-settings')),
        'html' => FALSE,
      ),
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  // Attach the same css styles as used on the default facets form.
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'facetapi') . '/facetapi.admin.css' => array(
      'weight' => 1,
    ),
    drupal_get_path('module', 'commercebox') . '/commercebox.css',
  );

  return $form;
}


/**
 * Submit handler for commercebox_filters_settings_form().
 */
function commercebox_core_filters_settings_form_submit($form, $form_state) {
  $values = $form_state['values']['filters'];
  uasort($values, 'drupal_sort_weight');
  variable_set('commercebox_filters_settings', $values);
}
