(function ($) {
  "use strict";

  Backdrop.behaviors.tinymceCodehighlightAdmin = {
    attach: function () {
      $('.form-item-theme .description').on('click', function () {
        $(this).closest('.form-type-radio').find('input').trigger('click');
      });
    }
  };
})(jQuery);
