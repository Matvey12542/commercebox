<?php

/************* Payment method ******************/
/**
 * Menu callback function.
 */
function commercebox_payment_settings_callback() {
  $output['paypal'] = array(
    '#type' => 'fieldset',
    '#title' => 'Paypal',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attached' => array(
      'js' => array(
        'misc/form.js',
        'misc/collapse.js',
      ),
    ),
    '#attributes' => array(
      'class' => array('collapsible', 'collapsed'),
    ),
  );
  $output['robokassa'] = array(
    '#type' => 'fieldset',
    '#title' => 'Robokassa',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attached' => array(
      'js' => array(
        'misc/form.js',
        'misc/collapse.js',
      ),
    ),
    '#attributes' => array(
      'class' => array('collapsible', 'collapsed'),
    ),
  );

  $methods = commerce_payment_methods();
  if (!empty($methods['paypal_ec'])) {

    $items = drupal_get_form('commercebox_payment_settings_paypal_ec_settings_form');
    $output['paypal']['payment'] = array(
      '#markup' => drupal_render($items),
    );
  }
  if (!empty($methods['commerce_robokassa'])) {
    $items = drupal_get_form('commercebox_payment_settings_robokassa_settings_form');
    $output['robokassa']['payment'] = array(
      '#markup' => drupal_render($items),
    );
  }

  return $output;
}

/**
 * Settings form().
 */
function commercebox_payment_settings_paypal_ec_settings_form() {
  $paypal = commerce_payment_method_instance_load("paypal_ec|commerce_payment_paypal_ec");
  $settings = $paypal['settings'];

  $form = array();

// Merge default settings into the stored settings array.
  $settings = (array) $settings + commerce_paypal_ec_default_settings();

  $form['service_description'] = array(
    '#markup' => '<div>' . commerce_paypal_ec_service_description() . ' '
      . t('Refer to the <a href="!url" target="_blank">module documentation</a> to find your API credentials and ensure your payment method and account settings are configured properly.', array('!url' => 'http://drupal.org/node/1901466')) . '</div>',
  );

  $form['api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('API username'),
    '#default_value' => $settings['api_username'],
  );
  $form['api_password'] = array(
    '#type' => 'textfield',
    '#title' => t('API password'),
    '#default_value' => $settings['api_password'],
  );
  $form['api_signature'] = array(
    '#type' => 'textfield',
    '#title' => t('Signature'),
    '#default_value' => $settings['api_signature'],
  );
  $form['server'] = array(
    '#type' => 'radios',
    '#title' => t('PayPal server'),
    '#options' => array(
      'sandbox' => ('Sandbox - use for testing, requires a PayPal Sandbox account'),
      'live' => ('Live - use for processing real transactions'),
    ),
    '#default_value' => $settings['server'],
  );
  $form['currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Default currency'),
    '#description' => t('Transactions in other currencies will be converted to this currency, so multi-currency sites must be configured to use appropriate conversion rates.'),
    '#options' => commerce_paypal_currencies('paypal_ec'),
    '#default_value' => $settings['currency_code'],
  );
  $form['allow_supported_currencies'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow transactions to use any currency in the options list above.'),
    '#description' => t('Transactions in unsupported currencies will still be converted into the default currency.'),
    '#default_value' => $settings['allow_supported_currencies'],
  );
  $form['txn_type'] = array(
    '#type' => 'radios',
    '#title' => t('Default transaction type'),
    '#description' => t('The default will be used to process transactions during checkout.'),
    '#options' => array(
      COMMERCE_CREDIT_AUTH_CAPTURE => t("Sale (direct debit from the customer's PayPal account)"),
      COMMERCE_CREDIT_AUTH_ONLY => t('Authorization only (requires manual or automated capture after checkout)'),
    ),
    '#default_value' => $settings['txn_type'],
  );
  $form['ec_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Express Checkout mode'),
    '#description' => t('Express Checkout Account Optional (ECAO) where PayPal accounts are not required for payment may not be available in all markets.'),
    '#options' => array(
      'Mark' => t('Require a PayPal account (this is the standard configuration).'),
      'SoleLogin' => t('Allow PayPal AND credit card payments, defaulting to the PayPal form.'),
      'SoleBilling' => t('Allow PayPal AND credit card payments, defaulting to the credit card form.'),
    ),
    '#default_value' => $settings['ec_mode'],
  );
  $form['shipping_prompt'] = array(
    '#type' => 'radios',
    '#title' => t('Shipping address collection'),
    '#description' => t('Express Checkout will only request a shipping address if the Shipping module is enabled to store the address in the order.'),
    '#options' => array(
      '0' => t('Do not ask for a shipping address at PayPal.'),
    ),
    '#default_value' => '0',
  );

  if (module_exists('commerce_shipping')) {
    $form['shipping_prompt']['#options'] += array(
      '1' => t('Ask for a shipping address at PayPal if the order does not have one yet.'),
      '2' => t('Ask for a shipping address at PayPal even if the order already has one.'),
    );
    $form['shipping_prompt']['#default_value'] = $settings['shipping_prompt'];
  }

  $form['log'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Log the following messages for debugging'),
    '#options' => array(
      'request' => t('API request messages'),
      'response' => t('API response messages'),
    ),
    '#default_value' => $settings['log'],
  );
  $form['ipn_logging'] = array(
    '#type' => 'radios',
    '#title' => t('IPN logging'),
    '#options' => array(
      'notification' => t('Log notifications during IPN validation and processing.'),
      'full_ipn' => t('Log notifications with the full IPN during validation and processing (used for debugging).'),
    ),
    '#default_value' => $settings['ipn_logging'],
  );
  $form['receiver_emails'] = array(
    '#type' => 'textfield',
    '#title' => t('PayPal receiver e-mail addresses'),
    '#description' => t('Enter the primary e-mail address for your PayPal account where you receive Express Checkout payments or a comma separated list of valid e-mail addresses.') . '<br />' . t('IPNs that originate from payments made to a PayPal account whose e-mail address is not in this list will not be processed.'),
    '#default_value' => $settings['receiver_emails'],
  );
  $form['reference_transactions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable reference transactions for payments captured through Express Checkout.'),
    '#description' => t('Contact PayPal if you are unsure if this option is available to you.'),
    '#default_value' => $settings['reference_transactions'],
  );
  $form['ba_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Express Checkout billing agreement description'),
    '#description' => t('If you have a PayPal account that supports reference transactions and need them, you must specify a billing agreement description.'),
    '#default_value' => $settings['ba_desc'],
  );
  $form['show_payment_instructions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show a message on the checkout form when PayPal EC is selected telling the customer to "Continue with checkout to complete payment via PayPal."'),
    '#default_value' => $settings['show_payment_instructions'],
  );
  $form['update_billing_profiles'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update billing customer profiles with address information the customer enters at PayPal.'),
    '#default_value' => $settings['update_billing_profiles'],
  );

  if (module_exists('commerce_shipping')) {
    $form['update_shipping_profiles'] = array(
      '#type' => 'checkbox',
      '#title' => t('Update shipping customer profiles with address information the customer enters at PayPal.'),
      '#default_value' => $settings['update_shipping_profiles'],
    );
  }

// Add that scripts that manage the PayPal BML popin.
  drupal_add_library('system', 'ui.dialog');

  $form['enable_bml'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable PayPal Bill Me Later™ button on the shopping cart page.'),
    '#description' => t('By selecting PayPal, you also receive Bill Me Later™ absolutely FREE. Bill Me Later™ enables customers to pay you now and pay us later. Still not sure? <a href="#" class="paypal-bml-popin">Learn More</a>.'),
    '#default_value' => $settings['enable_bml'],
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'commerce_paypal_ec') . '/theme/commerce_paypal_ec.popin.js'
      ),
    ),
  );

  $form['paypal_bml_help_text'] = array(
    '#markup' => commerce_paypal_ec_bml_help_text(),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Form submit.
 */
function commercebox_payment_settings_paypal_ec_settings_form_submit(&$form, &$form_state) {
  $settings = rules_config_load('commerce_payment_paypal_ec');
  $pay_settings = NULL;
  $actions = $settings->actions();

  foreach ($actions as $action) {
    $pay_settings = & $action->settings['payment_method']['settings'];
    break;
  }
  $pay_settings['api_username'] = $form_state['values']['api_username'];
  $pay_settings['api_password'] = $form_state['values']['api_password'];
  $pay_settings['api_signature'] = $form_state['values']['api_signature'];
  $pay_settings['server'] = $form_state['values']['server'];
  $pay_settings['currency_code'] = $form_state['values']['currency_code'];
  $pay_settings['allow_supported_currencies'] = $form_state['values']['allow_supported_currencies'];
  $pay_settings['txn_type'] = $form_state['values']['txn_type'];
  $pay_settings['ec_mode'] = $form_state['values']['ec_mode'];
  $pay_settings['shipping_prompt'] = $form_state['values']['shipping_prompt'];

  $pay_settings['log']['request'] = $form_state['values']['log']['request'];
  $pay_settings['log']['response'] = $form_state['values']['log']['response'];

  $pay_settings['ipn_logging'] = $form_state['values']['ipn_logging'];
  $pay_settings['receiver_emails'] = $form_state['values']['receiver_emails'];
  $pay_settings['reference_transactions'] = $form_state['values']['reference_transactions'];
  $pay_settings['ba_desc'] = $form_state['values']['ba_desc'];
  $pay_settings['show_payment_instructions'] = $form_state['values']['show_payment_instructions'];
  $pay_settings['update_billing_profiles'] = $form_state['values']['update_billing_profiles'];
  $pay_settings['enable_bml'] = $form_state['values']['enable_bml'];

  db_update('rules_config')
    ->fields(array(
      'data' => serialize($settings),
    ))
    ->condition('name', 'commerce_payment_paypal_ec')
    ->execute();
}

/**
 * Robokasa Payment method callback: settings form.
 */
function commercebox_payment_settings_robokassa_settings_form() {
  $robo = commerce_payment_method_instance_load("commerce_robokassa|commerce_payment_commerce_robokassa");
  $settings = $robo['settings'];
  $form = array();

  $settings = (array) $settings + array(
      'login' => '',
      'pass1' => '',
      'pass2' => '',
      'status' => array('pending'),
      'server' => 'test',
      'success_message' => '',
      'fail_message' => '',
    );

  $form['login'] = array(
    '#type' => 'textfield',
    '#title' => t('login'),
    '#description' => t(' Your robokassa login'),
    '#default_value' => $settings['login'],
  );

  $form['pass1'] = array(
    '#type' => 'textfield',
    '#title' => t('First password'),
    '#description' => t(' Password 1'),
    '#default_value' => $settings['pass1'],
  );

  $form['pass2'] = array(
    '#type' => 'textfield',
    '#title' => t('Second password'),
    '#description' => t(' Password 2'),
    '#default_value' => $settings['pass2'],
  );

  $form['server'] = array(
    '#type' => 'radios',
    '#title' => t('Robokassa server'),
    '#options' => array(
      'test' => ('Test - use for testing.'),
      'live' => ('Live - use for processing real transactions'),
    ),
    '#default_value' => $settings['server'],
  );

  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#description' => t('Choose order status after customer sent the order'),
    '#options' => commerce_robokassa_statuses(),
    '#default_value' => $settings['status'],
  );

  $form['success_message'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Success message'),
    '#description' => t('Enter optional text that will be displayed when payment succesful'),
    '#default_value' => $settings['success_message'],
  );

  $form['fail_message'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Fail message'),
    '#description' => t('Enter optional text that will be displayed when payment fail'),
    '#default_value' => $settings['fail_message'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
// $form['#submit'][] = variable_set('commerce_robokassa_settings', $form);

  return $form;
}

/**
 * Form submit.
 */
function commercebox_payment_settings_robokassa_settings_form_submit(&$form, &$form_state) {
  $data = db_select('rules_config', 'rc')
    ->fields('rc', array('data'))
    ->condition('rc.name', 'commerce_payment_commerce_robokassa')
    ->execute()
    ->fetchField();
  $settings = unserialize($data);

  $rule = '{ "commerce_payment_commerce_robokassa" : {
    "LABEL" : "Robokassa",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "Commerce Payment" ],
    "REQUIRES" : [ "commerce_payment" ],
    "ON" : [ "commerce_payment_methods" ],
    "DO" : [
      { "commerce_payment_enable_commerce_robokassa" : {
          "commerce_order" : [ "commerce-order" ],
          "payment_method" : { "value" : {
              "method_id" : "commerce_robokassa",
              "settings" : {
                "login" : "",
                "pass1" : "",
                "pass2" : "",
                "server" : "test",
                "status" : "pending",
                "success_message" : "Succes",
                "fail_message" : "Fail"
              }
            }
          }
        }
      }
    ]
  }
}';
  $rules_config = rules_import($rule);
  if ($existing_config = rules_config_load($rules_config->name)) {
    // Copy DB id and remove the new indicator to overwrite the existing record.
    $rules_config->id = $existing_config->id;
    unset($rules_config->is_new);
  }


  $settings = $rule = rules_config_load('commerce_payment_commerce_robokassa');
  $actions = $settings->actions();

  $pay_settings = NULL;
  foreach ($actions as $action) {
    if (empty($action->settings['payment_method']['settings'])) {
      $rules_config->save();
    }
    $pay_settings = &$action->settings['payment_method']['settings'];

    break;
  }
    //break;
  $pay_settings['login'] = $form_state['values']['login'];
  $pay_settings['pass1'] = $form_state['values']['pass1'];
  $pay_settings['pass2'] = $form_state['values']['pass2'];
  $pay_settings['server'] = $form_state['values']['server'];
  $pay_settings['status'] = $form_state['values']['status'];
  $pay_settings['success_message'] = $form_state['values']['success_message'];
  $pay_settings['fail_message'] = $form_state['values']['fail_message'];

  db_update('rules_config')
    ->fields(array(
      'data' => serialize($settings),
    ))
    ->condition('name', 'commerce_payment_commerce_robokassa')
    ->execute();
}