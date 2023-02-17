(function ($) {

  Drupal.generationStats = Drupal.generationStats || {};
  Drupal.generationStats.ajaxRequests = Drupal.generationStats.ajaxRequests || {};

  Drupal.behaviors.generationStats = {
    attach: function (context) {
      if ($('#generation-stats-site-equivalents', context).length > 0) {
        $(window).bind('generation-charts.period-changed', function (event, period) {
          var settings = Drupal.settings.generationStats.blocks['generation-stats-site-equivalents'];
          Drupal.generationStats.ajaxRequests['generation-stats-site-equivalents'] = Drupal.generationStats.ajaxRequests['generation-stats-site-equivalents'] || null;
          Drupal.generationStats.ajaxRequests['generation-stats-site-equivalents'] = $.ajax({
            url: settings.refreshUrl[period],
            dataType: 'json',
            beforeSend: function () {
              var prevRequest = Drupal.generationStats.ajaxRequests['generation-stats-site-equivalents'];
              if (prevRequest != null) {
                // Remove old spinners or errors
                $('#generation-stats-site-equivalents .generation-stats-placeholder').remove();
                $('#generation-stats-site-equivalents .generation-stats-error').remove();
                // Cancel the previous request
                prevRequest.abort();
              }
              // Add new spinner
              $('#generation-stats-site-equivalents').append('<span class="generation-stats-placeholder"></span>');
            },
            success: function (data) {
              $('#generation-stats-site-equivalents').replaceWith(data.content);
            },
            error: function (jqXHR, textStatus, errorThrown) {
              $('#generation-stats-site-equivalents .generation-stats-placeholder').remove();
              if (textStatus != 'abort') {
                $('#generation-stats-site-equivalents').append('<span class="generation-stats-error" title="' + errorThrown + '"></span>');
              }
            }
          });
        });
      }

      var $blocks = $('.generation-stats-refreshable', context);
      if ($blocks.length > 0) {
        var interval = Drupal.settings.generationStats.blockRefreshInterval;

        $blocks.each(function (index, block) {
          var $block = $(block)
            , blockId = $block.attr('id')
            , settings = Drupal.settings.generationStats.blocks[blockId];
          Drupal.generationStats.ajaxRequests[blockId] = Drupal.generationStats.ajaxRequests[blockId] || null;

          // Create a new function with this block's blockId and settings within
          // closure.
          var refresher = function () {
            var url;

            if (blockId === 'generation-stats-site-equivalents') {
              // When page is initially loading, Drupal.GenerationCharts.period is
              // empty, so we need to fallback to generation_chart's settings.
              var period = Drupal.GenerationCharts.period || Drupal.settings.generationCharts.period;
              url = settings.refreshUrl[period];
            }
            else {
              url = settings.refreshUrl;
            }

            Drupal.generationStats.ajaxRequests[blockId] = $.ajax({
              url: url,
              dataType: 'json',
              beforeSend: function () {
                var prevRequest = Drupal.generationStats.ajaxRequests[blockId];
                if (prevRequest != null) {
                  // Remove old spinners or errors
                  $('#' + blockId + ' .generation-stats-placeholder').remove();
                  $('#' + blockId + ' .generation-stats-error').remove();
                  // Cancel the previous request
                  prevRequest.abort();
                }
                // Add new spinner
                $('#' + blockId).append('<span class="generation-stats-placeholder"></span>');
              },
              success: function (data) {
                $('#' + blockId).replaceWith(data.content);

                // Run myself again!
                setTimeout(refresher, interval);
              },
              error: function (jqXHR, textStatus, errorThrown) {
                $('#' + blockId + ' .generation-stats-placeholder').remove();
                if (textStatus != 'abort') {
                  $('#' + blockId).append('<span class="generation-stats-error" title="' + errorThrown + '"></span>');
                }
              }
            });
          };

          // Do first refresh call for this block. We want to refresh immediately
          // because the block might either be showing placeholders (no data) or
          // old data.
          refresher();
        });
      }
    }
  };
})(jQuery);
