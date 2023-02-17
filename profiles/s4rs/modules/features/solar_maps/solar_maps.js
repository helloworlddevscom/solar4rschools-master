/**
 * @file
 * Override for leaflet bounding script to incorporate markercluster.
 */
(function ($) {

  // Add a timeout for onMapZoom logic in order to
  // reduce xhr request flood and fire only 500ms (or whatever timeout is set to)
  // after the last zoom tick.
  var timeout = 500,
      timeoutID;

  // Gets collection of data points represented in the
  // visible region of the map and updates map as well
  // as the list below the map.
  var onMapZoom = function(map, info, layer_key) {
    // Grab the handle of the companion list pane.
    var listPaneSelector = '.ajax-response-map-companion-list';

    // Get the url of the map data GeoJSON feed.
    var url = (typeof info.url !== 'undefined') ? info.url : Drupal.settings.leafletBBox[layer_key].url;

    // Define the bounding argument key.
    var bbox_arg_id = ('bbox_arg_id' in Drupal.settings.leafletBBox[layer_key]) ? Drupal.settings.leafletBBox[layer_key].bbox_arg_id : 'bbox';

    // Add bbox and zoom parameters as get params.
    url += "?" + bbox_arg_id +"=" + map.getBounds().toBBoxString();
    url += "&zoom=" + map.getZoom();

    // Append any existing query string (respect exposed filters).
    if (window.location.search.substring(1) !== '') {
      url += "&" + window.location.search.substring(1);
    }

    // Attempt to fetch JSON.
    var $jqXHR = $.getJSON(url).fail(function (){
      if (console && console.log) {
        console.log('Failed to get JSON.');
      }
    });

    // Upon succesful fetch, rebuild the layers and update the companion list.
    $jqXHR.done(function(data) {
      // Keep track of nids seen and clean up duplicates.
      var nids = [];
      var nidString;

      // This is an attempt to speed up the initial loading of this page. When we pass one hundred or
      // so nids as an argument to a view it results in an very complicated query. On initial page load,
      // what we actually want is to show all nodes. So we try to detect initial load and if so
      // pass 'all' to the view. This will display all results using a hopefully faster query.
      if (map._initialCenter == null
        || map._initialCenter.lat == map.getCenter().lat
        && map._initialCenter.lng == map.getCenter().lng && map._zoom == 4) {
        nidString = 'all';
      }
      else {
        data.features = $.grep(data.features, function (feature) {
          // Learn more about ~ here: http://www.metaltoad.com/blog/javascript-understanding-objects-vs-arrays-and-when-use-them
          var duplicate = ~nids.indexOf(feature.properties.nid);
          if (!duplicate) {
            nids.push(feature.properties.nid);
          }

          return !duplicate;
        });

        // Update the companion list.
        // The node ID is contained in each feature; we need a
        // string of comma-separated NIDs to feed into the view.
        nidString = nids.length ? nids.join() : 'none';
      }

      // Define the json layer as a markercluster group to
      // enable client-side clustering.
      var markerGroup = new L.MarkerClusterGroup();
      var geojsonLayer = new L.GeoJSON(data, Drupal.leafletBBox.geoJSONOptions);
      markerGroup.addLayer(geojsonLayer);

      // Re-assign the fresh data to the layers.
      Drupal.leafletBBox.markerGroup[layer_key].clearLayers();
      Drupal.leafletBBox.markerGroup[layer_key].addLayer(markerGroup);

      // Connect the layer control to the new data.
      Drupal.leafletBBox.overlays[info.layer_title] = Drupal.leafletBBox.markerGroup[layer_key];

      if (Drupal.settings.hasOwnProperty('solar_maps')) {
        // Trim off the final comma, and prepare the view URI.
        var viewName = Drupal.settings.solar_maps.view_attributes.view_name;
        var viewDisplayID = Drupal.settings.solar_maps.view_attributes.view_display_id;
        var listURI = '/solar-maps/location-list/' + viewName + '/' + viewDisplayID + '/' + nidString + '/' + window.location.search;

        // Get the updated view content.
        $('.loadspinner.companion-list').animateSprite('stop').fadeOut();
        $(listPaneSelector + ' .pane-content').load(listURI, function (response, status, xhr) {
          if (status == 'error') {
            if (console && console.log) {
              console.log('Failed to load location list.');
            }
          }
          else {
            // Get the current page's path without the leading slash.
            var path = window.location.pathname;
            if (path.charAt(0) == '/') {
              path = path.substr(1);
            }

            // In the companion list, the flag links use the listURI as the
            // ?destination return path. We want to use the panel path, but
            // "use panel path" in the view configuration has no effect the
            // flag link URI.
            var $flagLinks = $('.ajax-response-map-companion-list .links .flag-wrapper a');
            $flagLinks.each(function (idx, el) {
              var pathParts = $(el).attr('href').split('?');
              var queryParts = pathParts[1].split('token=');
              var newPath
                = pathParts[0] + '?destination=' + path + '&token=' + queryParts[1];
              $(el).attr('href', newPath);
            });

            // Similarly, for pager links on the companion list, the URL is
            // pointing to the map feed URI instead of the panel path.
            var $pagerLinks = $('.ajax-response-map-companion-list .pager a');
            $pagerLinks.each(function (idx, el){
              var pathParts = $(el).attr('href').split('?');
              var newPath = path + '?' + pathParts[1];
              $(el).attr('href', newPath);
            });
          }

          $('.loadspinner.companion-list').animateSprite('stop').fadeOut();
        });
      }
    });
  };

  // Override map load from leaflet.bbox.js so
  // we can register our needed event handlers.
  Drupal.leafletBBox.onMapLoad = function(map) {
    Drupal.leafletBBox.map = map;
    Drupal.leafletBBox.markerGroup = [];

    // Intialize empty layers and associated controls.
    var layer_count = 0;
    $.each(Drupal.settings.leafletBBox, function(key, value) {
      if (typeof value.url !== 'undefined') {
        // Add empty layers.
        Drupal.leafletBBox.markerGroup[key] = new L.LayerGroup();
        Drupal.leafletBBox.markerGroup[key].addTo(map);

        // Connect layer controls to layer data.
        Drupal.leafletBBox.overlays[value.layer_title] = Drupal.leafletBBox.markerGroup[key];

        layer_count++;
      }
    });

    // If we have more than one data layer, add the control.
    if (layer_count > 1) {
      L.control.layers(null, Drupal.leafletBBox.overlays).addTo(map);
    }

    // Loading a map is the same as moving/zooming.
    map.on('moveend', Drupal.leafletBBox.moveEnd);
    Drupal.leafletBBox.moveEnd();

    // Attach the loadspinner markup.
    var $popupLoadspinner = $('<div>', {
      'class': 'loadspinner popupLoadspinner'
    });
    $('body').append($popupLoadspinner);

    // Configure the animation for the popup loadspinners.
    var spinnerAnimation = {
      columns: 12,
      fps: 12,
      loop: true,
      animations: {
        spin: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
      }
    };

    // Don't let popup loadspinners start yet.
    $('.popupLoadspinner')
      .animateSprite(spinnerAnimation)
      .animateSprite('stop');

    // Start the companion listing load spinner.
    $('.loadspinner.companion-list').animateSprite(spinnerAnimation);

    // Hook into popup open so we can center the map display on the pin/popup.
    map.on('popupopen', Drupal.leafletBBox.popupOpen);
  };

  // Override how we create layers to enable
  // client-side clustering with Leaflet.markerCluster.
  Drupal.leafletBBox.makeGeoJSONLayer = function(map, info, layer_key) {
    if (timeoutID) {
      clearTimeout(timeoutID);
    }

    timeoutID = setTimeout(function() {
      onMapZoom(map, info, layer_key);
    }, timeout);
  };

  // Override leaflet.bbox.js.
  Drupal.leafletBBox.geoJSONOptions = {

    onEachFeature: function(feature, layer) {
      layer.on('click', function (event) {
        var map = Drupal.leafletBBox.map;
        var $popupContent = $('<div>', {class: 'leaflet-popup-content'});

        // Set up the loading spinner position.
        var spinnerTop = event.originalEvent.pageY - $('.loadspinner').height();
        var spinnerLeft = event.originalEvent.pageX - $('.loadspinner').width();

        // Animate the spinner sprite, position it, then show it.
        $('.popupLoadspinner')
          .animateSprite('restart')
          .css({
            top:  spinnerTop + 'px',
            left: spinnerLeft + 'px'
          })
          .show();

        // Map bubble content parameters.
        var nid = feature.properties.nid;
        var view_mode = 'map_bubble_teaser';
        var nodeURI = '/node/load/ajax/' + nid + '/' + view_mode;

        // Perform content load via AJAX.
        $popupContent.load(nodeURI, function() {
          layer.bindPopup($popupContent.html());

          // On the first click on a feature after page load, the popup
          // doesn't always open, so force it if it didn't open.
          if (!map._popup) {
            layer.openPopup();
          }
        });

        // Stop the loading spinner animation and hide.
        $('.popupLoadspinner').animateSprite('stop').fadeOut();
      });
    }
  };

  Drupal.leafletBBox.popupOpen = function(e) {
    // Center map on open pin/popup.
    var px = Drupal.leafletBBox.map.project(e.popup._latlng);
    px.y -= e.popup._container.clientHeight/2;
    Drupal.leafletBBox.map.panTo(
      Drupal.leafletBBox.map.unproject(px), {animate: true}
    );
  };

  Drupal.behaviors.solar_maps = {
    attach: function (context, settings) {
      var map_expanded = false;
      $('.map-expand').click( function(e) {
        if (map_expanded === false) {
          $(this).addClass('open');
          $('body').addClass('expanded-map');
          map_expanded = true;
        }
        else {
          $('body').removeClass('expanded-map');
          $(this).removeClass('open');
          map_expanded = false;
        }
        Drupal.leafletBBox.map.invalidateSize(true);
      });

      // On page load with an empty browser cache, a slower connection means
      // the map was positioned before the containers were modified. Adding
      // a short delay here and invalidaing size without animation.
      setTimeout( function () {
        Drupal.leafletBBox.map.invalidateSize(false);
      }, 250);
    }
  };

})(jQuery);
