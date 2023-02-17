(function ($) {

  Drupal.behaviors.generation  = {
      attach: function (context) {
      var summaryCache = {};

      var fetchSummary = function (nid, callback) {
        if (summaryCache[nid] === undefined) {
          // Fetch an instant summary from the server.
          var url = Drupal.settings.basePath + 'generation-instant-summary/' + nid;
          $.ajax({
            url: url,
            success: function (data) {
              summaryCache[nid] = data;
              callback(nid, data);
            },
            dataType: 'json'
          });
        }
        else {
          callback(nid, summaryCache[nid]);
        }
      };

      Drupal.gmap.addHandler('gmap', function (elem) {
        var obj = this;

        obj.bind('clickmarker', function (marker) {

          var matches = marker.text.match(/data-nid="\d+"/);

          if (matches === null || matches.length < 1) {
            return;
          }
          var nid = matches[0].match(/\d+/)[0];

          fetchSummary(nid, function (nid, summary) {
            $('.gmap-popup .generation-placeholder').each(function (index, element) {
              var placeholder = $(element),
                currentNid = placeholder.attr('data-nid'),
                dataType = placeholder.attr('data-type');

              // If the popup no longer contains the nid we fetched data for, do
              // nothing.
              if (currentNid == nid) {
                if (summary[dataType] === undefined) {
                  placeholder.text(Drupal.t('N/A'));
                }
                else {
                  placeholder.text(summary.formatted[dataType]);
                }
              }
            });
          });
        });

      });
    }
  };

})(jQuery);
