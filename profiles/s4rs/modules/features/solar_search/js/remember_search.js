(function ($) {

/**
 * Adds successful search to user cookie.
 */

/**
 * Handle array values.
 * @see http://drupal.org/node/1149078
 */
  Drupal.behaviors.rememberSearch = {
    attach: function (context, settings) {
      var recentSearches = new Array;
      var list = $('.pane-user-recent-search .pane-content ul');
      var latestSearch = settings.hasOwnProperty('successfulSearch') ? settings.successfulSearch : false;
      var newList = new Array;

      if ($.cookie("recentSearches")) {
        recentSearches = JSON.parse($.cookie("recentSearches"));
        list.empty();
        for(var i=0; i < recentSearches.length && i < 4; i++) {
          if (latestSearch && recentSearches[i].path != latestSearch.path) {
            newList.push(recentSearches[i]);
          }
          if (recentSearches[i].title != '') {
            list.append("<li><a href='"+recentSearches[i].path + "'>" + recentSearches[i].title + "</li>");
          }
        }
      }

      // Display successful searches
      if (latestSearch) {
        // Add successful search to cookie.
        newList.unshift(latestSearch);
        $.cookie("recentSearches", JSON.stringify(newList), {json:true});
      }
    }
  };
}(jQuery));

