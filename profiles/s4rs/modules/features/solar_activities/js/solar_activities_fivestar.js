/**
 * @file
 *
 * Fivestar AJAX for updating fivestar widgets.
 */

/**
 * Create a degradeable star rating interface out of a simple form structure. Overwritten to reload page after submission.
 */
(function($){ // Create local scope.

if (Drupal.ajax) {
  Drupal.ajax.prototype.commands.fivestarUpdate = function (ajax, response, status) {
    response.selector = $('.fivestar-form-item', ajax.element.form);
    location.reload();
    ajax.commands.insert(ajax, response, status);
  };
}

})(jQuery);
