(function ($) {

/**
 * Provides a "Back" link.
 */
  Drupal.behaviors.backButton = {
    attach: function (context, settings) {
    $('a.back-button').click(function(){
        parent.history.back();
        return false;
     });
    }
  };
}(jQuery));
