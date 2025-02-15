<?php
/**
 * @file
 * Hooks provided by TinyMCE Code Highlight module.
 */

/**
 * Implements hook_tinymce_codehighlight_theme_info().
 *
 * Provide a custom theme to display code snippets the way you like it.
 */
function hook_tinymce_codehighlight_theme_info() {
  $path = backdrop_get_path('module', 'mymodule');
  $themes['my_own'] = array(
    'name' => 'my_own',
    'label' => t('My Own'),
    // Have a look at the existing themes - only some lines of CSS.
    'stylesheet_path' => $path . '/themes/myown/styles.css',
    // Optional: a small preview image. Can be omitted.
    'screenshot_path' => $path . '/themes/myown/screenshot.png',
  );

  return $themes;
}
