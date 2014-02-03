<?php
// $Id$

/**
 * Implements hook_form_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function commercebox_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Set a default name for the dev site.
  $form['site_information']['site_name']['#default_value'] = t('CommerceBox');
  // Set default country.
  $country_relation = array(
    'en' => 'GB',
    'uk' => 'UA',
    'ru' => 'RU',
  );

  // Get array of all currencies.
  foreach (commerce_currencies(FALSE, TRUE) as $currency_code => $currency) {
    $options[$currency_code] = t('@code - !name', array('@code' => $currency['code'], '@symbol' => $currency['symbol'], '!name' => $currency['name']));
    if (!empty($currency['symbol'])) {
      $options[$currency_code] .= ' - ' . check_plain($currency['symbol']);
    }
  }
  $form['currencies'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default currency'),
    '#weight' => 14,
  );
  $form['currencies']['commerce_default_currency'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $options['RUB'],
  );
  $form['actions']['submit']['#validate'][] = 'commercebox_profile_form_install_configure_form_validate';

  $form['server_settings']['site_default_country']['#default_value'] = $country_relation['en'];
  if (isset($_GET['locale']) && $_GET['locale']) {
    $form['server_settings']['site_default_country']['#default_value'] = $country_relation[$_GET['locale']];
  }

  $form['country'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default country for orders'),
    '#weight' => 15,
  );
  $form['country']['default_country'] = array(
    '#type' => 'select',
    '#title' => t('Choose default country for orders'),
    '#options' => country_get_list(),
  );
}

/**
 * Set default currency.
 */
function commercebox_profile_form_install_configure_form_validate($form, &$form_state) {
  if (!form_get_errors()) {
    $default_currency = $form_state['values']['commerce_default_currency'];
    $currencies = array_keys($form['currencies']['commerce_default_currency']['#options']);
    $currencies = array_fill_keys($currencies, 0);
    $currencies[$default_currency] = $default_currency;
    $default_country = $form_state['values']['default_country'];

    variable_set('commerce_enabled_currencies', $currencies);
    variable_set('commerce_default_currency', $default_currency);
    variable_set('commercebox_default_country', $default_country);
  }
}
