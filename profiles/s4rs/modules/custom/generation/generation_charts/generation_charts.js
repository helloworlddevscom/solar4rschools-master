(function ($) {
  Drupal.GenerationCharts = Drupal.GenerationCharts || {};
  Drupal.GenerationCharts.ajaxRequests = Drupal.GenerationCharts.ajaxRequests || {};
  Drupal.GenerationCharts.ajaxRequests.loadChart = Drupal.GenerationCharts.ajaxRequests.loadChart || null;

  /**
   * Fetches and caches data for a chart using Ajax, and builds the chart.
   */
  Drupal.GenerationCharts.loadChart = function (dataUrl) {
    Drupal.GenerationCharts.cache = Drupal.GenerationCharts.cache || {};

    // Check to see if we have the data cached already.
    if (Drupal.GenerationCharts.cache[dataUrl]) {
      Drupal.GenerationCharts.buildChart(Drupal.GenerationCharts.cache[dataUrl]);
      return;
    }

    Drupal.GenerationCharts.ajaxRequests.loadChart = $.ajax({
      url: dataUrl,
      dataType: 'json',
      beforeSend: function () {
        var prevRequest = Drupal.GenerationCharts.ajaxRequests.loadChart;
        if (prevRequest != null) {
          // Remove error-contacting-server messages, if any.
          $('.generation-charts-error').remove();
          $('.generation-charts-ajax-spinner').remove();
          // Cancel the previous request
          prevRequest.abort();
        }
        // Create a spinner to indicate the chart is loading.
        var $spinner = $('.generation-charts-ajax-spinner');
        if ($spinner.length < 1) {
          var $chartContainer = $('#generation-chart-wrapper');

          $chartContainer.css('position', 'relative')
            .css({
              height: Drupal.settings.generationCharts.css.height,
              width: Drupal.settings.generationCharts.css.width
            });
          $spinner = $('<div></div>')
            .addClass('generation-charts-ajax-spinner')
            .appendTo($chartContainer);
        }
        $spinner.fadeIn(125);
      },
      success: function (chartData, textStatus, jqXHR) {
        // Remove error-contacting-server messages, if any.
        $('.generation-charts-error').fadeOut();

        $('.generation-charts-ajax-spinner').fadeOut();

        Drupal.GenerationCharts.cache[dataUrl] = chartData;
        Drupal.GenerationCharts.buildChart(chartData);
      },
      error: function (jqXHR, textStatus, errorThrown) {
        // Add an error message explaining why the chart isn't appearing.
        // Warning: Theme-specific selector for div.messages container.
        if (textStatus != 'abort') {
          var message = Drupal.settings.generationCharts.messages.error;
          $('#content-header').append('<div class="messages error generation-charts-error">' + message + '</div>');

          $('.generation-charts-ajax-spinner').fadeOut();
        }
      },
    });
  };

  /**
   * Builds the chart using the given data structure.
   */
  Drupal.GenerationCharts.buildChart = function (chartData) {
    // Filter out series with less than two data points.
    var test = $.grep(chartData.series, function (series, i) {
      return (typeof series.data !== 'undefined') &&
        (series.data !== null) &&
        (series.data.length >= 2);
    });

    // First, destroy the current chart, if there is one.
    if (Drupal.GenerationCharts.chart) {
      Drupal.GenerationCharts.chart.destroy();
      Drupal.GenerationCharts.chart = null;
    }
    else {
      // Some options can only be set through Highcharts.setOptions(), such as
      // the 'global' and 'lang' options. So we must call it before building
      // our first chart.
      Highcharts.setOptions(Drupal.settings.generationCharts.chart);
    }

    if (test.length >= 1) {
      // Combine the data and the options we received on initial page load,
      // then create the chart.
      var chartOptions = $.extend(/* deep: */ true, {}, chartData, Drupal.settings.generationCharts.chart);

      Drupal.GenerationCharts.chart = new Highcharts.StockChart(chartOptions);
    }
    else {
      // If we don't have any data to graph, we don't want to try to invoke
      // Highstock, as it will fall into an infinite loop.
      if ($('.generation-charts-no-data').length < 1) {
        var message = Drupal.settings.generationCharts.messages.noData;
        $(Drupal.settings.generationCharts.selector).append('<p class="generation-charts-no-data">' + message + '</p>');
      }
    }
  };

  /**
   * Attach JavaScript to period selector links. When a new period is selected,
   * we reload the chart with data for that period and trigger a hook, allowing
   * other code to react to the selection.
   */
  Drupal.GenerationCharts.attachPeriodSelector = function (context) {
    var first = true;

    $('a[href^="#period-"]', context).click(function (e) {
      e.preventDefault();

      // Activate the link clicked on.
      var $active = $(this).parent();
      $active.siblings().removeClass('active');
      $active.addClass('active');

      // Determine period from link hash and reload the chart.
      var period = this.hash.split('#period-')[1],
        dataUrl = Drupal.settings.generationCharts.periodSelector.dataUrls[period];

      if (typeof dataUrl === 'string') {
        Drupal.GenerationCharts.loadChart(dataUrl);

        // Allow other scripts to act on this event. New chart is likely not
        // fully loaded yet, but other code should get notified right away, to
        // allow (for instance) other async requests to be fired off.
        Drupal.GenerationCharts.period = period;
        var hook = first ? 'generation-charts.period-attached' : 'generation-charts.period-changed';
        $(window).trigger(hook, period);
        first = false;

        // Log click in database table generation_charts_log.
        var siteID = Drupal.settings.generationCharts.site_id;
        var logUrl = 'generation-charts-log/'+siteID+'/'+period;
        Drupal.GenerationCharts.logClick(logUrl);
      }
      else {
        // @todo: refactor error handling code
        var message = Drupal.t('The @period chart is not yet configured for this page. Please contact an administrator.', {'@period': period});
        $('#content-header').append('<div class="messages error generation-charts-error">' + message + '</div>');
      }
    });
  };

  /**
   * Initialize the chart on the page.
   */
  Drupal.behaviors.GenerationCharts = {
    attach: function (context) {
      var settings = Drupal.settings.generationCharts;
      $(settings.selector, context).css(settings.css);
      // Are we displaying a custom time period?
      if (settings.period) {
        Drupal.GenerationCharts.attachPeriodSelector(context);
        $('a[href="#period-' + settings.period + '"]', context).click();
      }
      else {
        // Custom time
        Drupal.GenerationCharts.loadChart(settings.dataUrl);
      }
    }
  };

  /**
   * Themes the legend trigger icon.
   */
  Drupal.theme.prototype.generationChartsLegendTrigger = function () {
    var imageUrl = Drupal.settings.generationCharts.triggerImageUrl;
    var image = $('<img src="' + imageUrl + '" id="generation-charts-legend-trigger">');
    return image.wrap('<div id="generation-charts-legend-trigger-wrapper" />').parent();
  };

  /**
   * Themes the legend popup.
   */
  Drupal.theme.prototype.generationChartsLegendPopup = function (chartData) {
    var legendPopupContent = $.map(chartData.series, function (series) {
      var description;
      description = series.generationCharts.description || Drupal.t('Description coming soon.');
      return [
        '<p class="series-index-' + series.yAxis + '">',
        '<span class="series-name" style="color: ' + series.color + ';">',
        Drupal.checkPlain(series.name),
        '</span> <span class="series-description">' + description + '</span></p>'
      ].join('');
    }).join('');

    var legendPopup = $('<div></div>')
      .addClass('generation-charts-legend clearfix')
      .addClass('series-count-' + (chartData.series.length > 1 ? 'multiple' : 'single'));

    legendPopup.append(legendPopupContent);

    return legendPopup;
  };

  /**
   * Logs click of period link in generation_charts_log database table.
   */
  Drupal.GenerationCharts.logClick = function (logUrl) {
    Drupal.GenerationCharts.ajaxRequests.logClick = $.ajax({
      url: logUrl,
      dataType: 'json',
      success: function (logData, textStatus, jqXHR) {
      },
      error: function (jqXHR, textStatus, errorThrown) {
      },
    });
  };

})(jQuery);
