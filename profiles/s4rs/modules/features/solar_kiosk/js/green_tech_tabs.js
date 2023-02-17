(function ($) {
  Drupal.behaviors.solarKioskGreenTechTabs = {
    attach: function (context, settings) {
      $('.green-tech-tab-block').once('solarKioskGreenTechTabs').tabs();
    }
  };
}(jQuery));
