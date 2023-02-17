/**
 * Sticky bottom behavior.
 *
 * Sets the user menu to stick to the bottom of the page until it reaches its
 * natural location.
 */
(function ($) {
  Drupal.behaviors.stickybottom  = {
      attach: function (context) {
        var userMenu = $('#block-system-user-menu');
        var footer = userMenu.parent();

        window.onscroll = function(){
          if ((window.innerHeight + window.pageYOffset) >= (footer.position().top  + userMenu.height())) {
            userMenu.addClass('rock-bottom');
          }
          else {
            userMenu.removeClass('rock-bottom');
          }
        }

        if ((window.innerHeight + window.pageYOffset) >= (footer.position().top  + userMenu.height())) {
          userMenu.addClass('rock-bottom');
        }
    }
  };

})(jQuery);
