(function ($) {

/**
 * Theme function for a multipage control.
 *
 * @param settings
 *   An object with the following keys:
 *   - title: The name of the tab.
 * @return
 *   This function has to return an object with at least these keys:
 *   - item: The root tab jQuery element
 *   - nextLink: The anchor tag that acts as the clickable area of the control
 *   - nextTitle: The jQuery element that contains the group title
 *   - previousLink: The anchor tag that acts as the clickable area of the control
 *   - previousTitle: The jQuery element that contains the group title
 */
Drupal.theme.multipage = function (settings) {

  var controls = {};
  controls.item = $('<span class="multipage-button"></span>');

  controls.previousLink = $('<input type="button" class="multipage-link multipage-link-previous" value="" />');
  controls.previousTitle = Drupal.t('<< Back');
  controls.item.append(controls.previousLink.val(controls.previousTitle));

  controls.nextLink = $('<input type="button" class="multipage-link multipage-link-next" value="" />');
  controls.nextTitle = Drupal.t('Next >>');
  controls.item.append(controls.nextLink.val(controls.nextTitle));

  if (!settings.has_next) {
    controls.nextLink.hide();
  }
  if (!settings.has_previous) {
    controls.previousLink.hide();
  }

  $('#edit-save').click(function(e) {
    $('input[name="current_page"]').val($('.multipage-pane:visible').next().prop('id'));
  });

  return controls;
};

})(jQuery);
