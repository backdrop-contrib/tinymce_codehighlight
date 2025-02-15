<?php
/**
 * @file
 * Settings form for TinyMCE Code Highlight.
 */

/**
 * Settings form callback.
 */
function tinymce_codehighlight_settings_form($form, $form_state) {
  $form['#config'] = 'tinymce_codehighlight.settings';
  $config = config('tinymce_codehighlight.settings');

  $all_themes = _tinymce_codehighlight_get_all_themes();
  $active_theme = _tinymce_codehighlight_get_active_theme();
  $theme_options = array();
  foreach ($all_themes as $name => $theme) {
    $theme_options[$name] = $theme['label'];
  }
  $form['theme'] = array(
    '#type' => 'radios',
    '#title' => t('Prism.js theme'),
    '#default_value' => $active_theme['name'],
    '#options' => $theme_options,
    '#required' => TRUE,
  );
  foreach ($all_themes as $name => $theme) {
    if (!empty($theme['screenshot_path'])) {
      $img_url = base_path() . $theme['screenshot_path'];
      $form['theme'][$name]['#description'] = '<img src="' . $img_url . '" alt="">';
    }
    else {
      $form['theme'][$name]['#description'] = t('No screenshot provided');
    }
  }

  $form['copybutton'] = array(
    '#type' => 'checkbox',
    '#title' => t('Copy button'),
    '#default_value' => $config->get('copybutton'),
    '#description' => t('Adds a small icon button in the top right corner to copy the code to clipboard.'),
  );

  $help = t('Prism.js supports a variety of programming languages. This setting has no influence on actual highlighting, only sets the dropdown options.');
  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Languages'),
    '#description' => $help,
  );

  $module_path = backdrop_get_path('module', 'tinymce_codehighlight');
  $file_path = BACKDROP_ROOT . base_path() . $module_path . '/libraries/prismjs/components.json';
  $data = file_get_contents($file_path);
  $json = json_decode($data, TRUE);
  $languages = $language_options = array();
  if ($json) {
    $languages = $json['languages'];
    unset($languages['meta']);

    foreach ($languages as $key => $info) {
      $language_options[$key] = check_plain($info['title']);
    }
  }
  else {
    backdrop_set_message(t('Reading available language options failed.'), 'error');
  }
  // Be careful with missing or broken config.
  $default_values = $config->get('languages') ? $config->get('languages') : array();
  $form['wrapper']['languages'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Options for TinyMCE codesample plugin'),
    '#default_value' => $default_values,
    '#options' => $language_options,
  );
  foreach ($languages as $key => $info) {
    if (!empty($info['aliasTitles'])) {
      $form['wrapper']['languages'][$key]['#description'] = implode(', ', array_values($info['aliasTitles']));
    }
  }

  // Hidden form item to get the enabled languages with labels as an extra
  // config item. Actual values will be set on form submission.
  $form['#language_options'] = $language_options;
  $form['#submit'][] = '_tinymce_codehighlight_settings_form_submit';
  $form['enabled_with_labels'] = array(
    '#type' => 'value',
    '#value' => array(),
  );

  $form['#attached']['css'] = array($module_path . '/css/tinymce-codehighlight-admin.css');
  $form['#attached']['js'] = array($module_path . '/js/tinymce-codehighlight-admin.js');

  return system_settings_form($form);
}

/**
 * Additional submission callback to add a config item.
 */
function _tinymce_codehighlight_settings_form_submit($form, &$form_state) {
  $enabled_with_labels = array();
  $selected = array_filter($form_state['values']['languages']);
  // Add name => label key/value pairs, which can't be made available via
  // FormAPI items.
  foreach ($selected as $name) {
    $enabled_with_labels[$name] = $form['#language_options'][$name];
  }
  $form_state['values']['enabled_with_labels'] = $enabled_with_labels;
}
