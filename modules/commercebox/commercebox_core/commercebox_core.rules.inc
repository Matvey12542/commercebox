<?php

/**
 * @file
 * commerce_immediate_login.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function commercebox_core_rules_action_info() {
  return array(
    'commercebox_core_log_user_in' => array(
      'label' => 'Log in user commercebox',
      'parameter' => array(
        'account' => array('type' => 'user', 'label' => t('User')),
      ),
      'group' => t('System'),
    ),
  );
}

/**
 * Rules action callback to login the user provided in the function parameter.
 */
function commercebox_core_log_user_in($account) {
  global $user;
  $user = user_load($account->uid);
  user_login_finalize();
}

/**
 * Implements hook_default_rules_configuration_alter().
 */
function commercebox_core_default_rules_configuration_alter(&$configs) {

  if (!empty($configs['commerce_checkout_new_account'])) {
    $configs['commerce_checkout_new_account']->
      action(rules_action('commercebox_core_log_user_in', array('account:select' => 'account-fetched:0')));
  }
}
