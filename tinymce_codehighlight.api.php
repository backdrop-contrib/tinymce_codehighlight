<?php
/**
 * @file
 * Hooks provided by TinyMCE Code Highlight module.
 */

/**
 * Implements hook_tinymce_codehighlight_theme_info().
 *
 * Provide a custom theme to display code snippets. You only need some CSS.
 */
function hook_tinymce_codehighlight_theme_info() {
  $path = backdrop_get_path('module', 'mymodule');
  $themes['default'] = array(
    'name' => 'my_own',
    'label' => t('My Own'),
    'stylesheet_path' => $path . '/themes/myown/styles.css',
    // Optional:
    //'screenshot_path' => $path . '/themes/myown/screenshot.png',
  );

  return $themes;
}
