<?php
/**
 * @file
 * commercebox_slider_views_queue.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commercebox_slider_views_queue_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'commercebox_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'commercebox_slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'commercebox_slider';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'new';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/data/new" class=\'use-ajax new-slide\'> new </a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'link add';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/data/new/nojs" class="use-ajax new-slide"> new </a>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'commercebox_slider' => 'commercebox_slider',
  );
  /* Field: Global: Commercebox slider */
  $handler->display->display_options['fields']['commercebox_slider']['id'] = 'commercebox_slider';
  $handler->display->display_options['fields']['commercebox_slider']['table'] = 'views';
  $handler->display->display_options['fields']['commercebox_slider']['field'] = 'commercebox_slider';
  $handler->display->display_options['fields']['commercebox_slider']['label'] = '';
  $handler->display->display_options['fields']['commercebox_slider']['element_label_colon'] = FALSE;
  /* Field: Nodequeue: Position */
  $handler->display->display_options['fields']['position']['id'] = 'position';
  $handler->display->display_options['fields']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['fields']['position']['field'] = 'position';
  $handler->display->display_options['fields']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['fields']['position']['label'] = '';
  $handler->display->display_options['fields']['position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['position']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '<span class="settings" id="[nid]" pos="[position]" > [field_image] </span>';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'commercebox_slider',
    'image_link' => '',
  );
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['expose']['label'] = 'Position';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'banner' => 'banner',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'commercebox_slider';
  $translatables['commercebox_slider'] = array(
    t('Master'),
    t('commercebox_slider'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('new'),
    t('<a href="/data/new" class=\'use-ajax new-slide\'> new </a>'),
    t('link add'),
    t('<a href="/data/new/nojs" class="use-ajax new-slide"> new </a>'),
    t('queue'),
    t('.'),
    t(','),
    t('<span class="settings" id="[nid]" pos="[position]" > [field_image] </span>'),
    t('Position'),
    t('Page'),
  );
  $export['commercebox_slider'] = $view;

  return $export;
}
