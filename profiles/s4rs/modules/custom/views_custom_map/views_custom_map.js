/* $Id: views_custom_map.js 88 2009-04-02 01:58:26Z jhedstrom $ */

Drupal.behaviors.viewsCustomMap = function () {
  $('.views-custom-map-point').hover(function() {
    $(this).find('span.popup').show();
    },
    function () {
      $(this).find('span.popup').hide();
    }
  );
}