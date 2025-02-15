# TinyMCE Code Highlight

TinyMCE's codesample plugin `{;}` already uses Prism.js, but in a limited way.
This module enhances these capabilities.

- Adds an admin form to configure theme, copy button and languages available
  in the editor dropdown
- Adds support for all programming languages supported by Prism.js (not only
  a subset)
- Adds 3 themes compatible with both, the editor and Backdrop themes
- Adds the API to quickly add your own custom theme
- Uses Prism.js also when *displaying content* (not only inside the editor)

![admin interface](https://raw.githubusercontent.com/backdrop-contrib/tinymce_codehighlight/1.x-1.x/screenshots/tinymce-codehighlight-admin.png)

## Installation

- Install this module using the official [Backdrop CMS instructions](https://docs.backdropcms.org/documentation/extend-with-modules)
- Go to admin/config/content/tinymce-codehighlight and tweak as needed

## Dependencies

- TinyMCE

Note that code highlighting will work for any compatible markup, also if
created with CKEditor5.

## Issues

Bugs and feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/tinymce_codehighlight/issues)

## Current Maintainers

- [Indigoxela](https://github.com/indigoxela)

## Credits

Bundles [Prism.js](https://prismjs.com/), a simple, lightweight JavaScript
library to highlight a variety of programming languages. Prism.js is
licensed under MIT.

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
