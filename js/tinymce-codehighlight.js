/**
 * @file
 * Inform the autoloader plugin where to lookup language files.
 */
(function () {
  "use strict";
  if (typeof Prism === 'undefined' || typeof document === 'undefined') {
    return;
  }
  if (typeof Prism.plugins.autoloader === 'undefined') {
    return;
  }
  if (typeof Backdrop.settings.prismjsAutoloaderLangPath === 'undefined') {
    return;
  }
  // Necessary to get lookup working with aggregation turned on.
  Prism.plugins.autoloader.languages_path = Backdrop.settings.prismjsAutoloaderLangPath;
}());
