/**
 * JS for Full Width Iframe field/view/block.
 * See: views-view--full-width-iframe.tpl.php
 */

(function ($) {

  /**
   * Adjust height of iFrame to maintain aspect ratio.
   */
  Drupal.behaviors.fullWidthIframeAdjustHeight = {
    attach: function (context) {
      var $iframe = $('.view-full-width-iframe iframe');
      if ($iframe.length) {
        adjustHeight();

        $(window).on('resize', function() {
          adjustHeight();
        });
      }

      function adjustHeight() {
        if ($(window).width() <= 800) {
          var setWidth = $iframe.data('set-width-mobile');
          var setHeight = $iframe.data('set-height-mobile');
        }
        else {
          var setWidth = $iframe.data('set-width');
          var setHeight = $iframe.data('set-height');
        }

        var width = $iframe.width();
        var newHeight = ((setHeight * width) / setWidth);
        $iframe.height(newHeight);
      }
    }
  };

  /**
   * Hides Title and Body field based on value of field_hide_title_body.
   */
  Drupal.behaviors.hideTitleBody = {
    attach: function (context, settings) {
      if (settings.hide_title_body) {
        $('#block-easy-breadcrumb-easy-breadcrumb').hide();
        $('#page-title').hide();
        $('#block-system-main').hide();
      }
    }
  };

})(jQuery);
