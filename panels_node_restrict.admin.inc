<?php
/*Settings form for panel node restrict*/
function panels_node_restrict_settings() {  
  panels_load_include('plugins');
  panels_load_include('common');

  $layouts = panels_common_get_allowed_layouts('panels_node');
  $options = array();
  foreach ($layouts as $key => $layout){
    $options[$key] = $layout['title']; 
  }
  $form['panels_node_restrict_default_layout'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get("panels_node_restrict_default_layout",'flexible'), 
    '#title' => t('Default layout'),
    '#description' => t("When a user cannot access the layout for adding panel nodes or always use default layout is checked, this is the layout that will be used."),
    '#options'=>$options,
  );
  
  $form['panels_node_restrict_always_use_default'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get("panels_node_restrict_always_use_default",FALSE), 
    '#title' => t('Always use default layout on creation'),
    '#description' => t("On creation of panel nodes, the default layout will be set, so the layout selection screen will be skipped.. This will not be effect anything after creation."),
  );
  if (module_exists('translation')) {
    $form['panels_node_restrict_translation_parent'] = array(
      '#type' => 'checkbox',
      '#default_value' => variable_get("panels_node_restrict_translation_parent",TRUE), 
      '#title' => t('Share panel content display for translated nodes.'),
      '#description' => t("Instead of translated nodes having different panel contents, they will share the panel content of the original node."),
    );
  }
  
  return  system_settings_form($form);
}