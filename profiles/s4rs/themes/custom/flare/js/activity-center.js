/**
 * JS for Teacher Activity Center and Resource Library.
 */

(function ($) {

  /**
   * Activity Center node expand/collapse functionality.
   */
  Drupal.behaviors.activityCenterExpanded = {
    attach: function (context) {
      if ($('.node--quick-view').length) {
        var expanded = false;
        $('.node--quick-view .more-details').on('click tap touch', function() {
          if (!expanded) {
            $(this).addClass('expanded');
            $(this).parents('.node__quick-view').next('.node__expanded-view').addClass('expanded');
            expanded = true;
          }
          else {
            $(this).removeClass('expanded');
            $(this).parents('.node__quick-view').next('.node__expanded-view').removeClass('expanded');
            expanded = false;
          }
        });
      }
    }
  };


  /**
   * Creates a custom search button for the Activity Center view exposed form so we can style as a search icon.
   */
  Drupal.behaviors.activityCenterSearchButton = {
    attach: function (context) {
      if ($('.views-widget-filter-search_api_views_fulltext').length) {
        $('.views-widget-filter-search_api_views_fulltext').find('.form-text').after('<div class="submit-button"></div>');
        $('.views-widget-filter-search_api_views_fulltext').find('.submit-button').on('click tap touch', function() {
          $(this).parents('form').submit();
        });
      }
    }
  };


  /**
   * Removes result count from selected options in facet Chosen multiselects provided by ajax_facets module.
   */
  Drupal.behaviors.activityCenterChosenFacetRemoveCount = {
    attach: function (context) {
      removeCount();

      $(document).ajaxSuccess(function() {
        removeCount();
      });

      function removeCount() {
        $('.block--ajax_facets .form-type-multiselect .search-choice').each(function() {
          var $this = $(this);
          var $spanEl = $this.find('span');
          var text = $spanEl.html();
          var splitText = text.split(' ');
          if (splitText[splitText.length - 1].match('\\(([^)]+)\\)')) {
            splitText.pop()
            var newText = splitText.join(' ');
            $spanEl.html(newText);
          }
        });
      }
    }
  };


  /**
   * Resource Library report broken link AJAX functionality.
   * Triggers sending of email to CEBF alerting them of broken link.
   */
  Drupal.behaviors.resourceLibraryReportBrokenLink = {
    attach: function (context) {
      $('#report-btn', context)
        .on('click.reportBroken tap.reportBroken touch.reportBroken', function() {
          var nid = $(this).data('nid');

          $.get('/ajax/resource-library/report-broken/' + nid, function(data) {
            // Render confirmation message.
            $('.messages').remove();
            data = JSON.parse(data);
            $('#main').prepend(data[1].html);
          });

          return false;
        });
    }
  }

})(jQuery);
