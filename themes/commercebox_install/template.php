<?php

/**
 * Override or insert variables into the maintenance page template.
 */
function commercebox_install_preprocess_maintenance_page(&$vars) {
  global $install_state;
  $vars['head_title'] = "{$vars['title']} | CommerceBox";
  $vars['state']     = $install_state['active_task'];
  $vars['site_name'] = 'CommerceBox';
  $vars['footer'] = l('InternetDevels.com', 'http://internetdevels.com/', array(
    'attributes' => array('target' => '_blank'),
  ));
}
