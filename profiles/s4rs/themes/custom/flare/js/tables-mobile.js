/**
 * Wraps a div around tables so that they can be scrolled
 * for mobile.
 */
(function ($) {
  Drupal.behaviors.tablesMobileWrapper  = {
    attach: function (context) {
      $('.field-name-body').find('table').wrap('<div class="table-wrapper">');
    }
  };

})(jQuery);
