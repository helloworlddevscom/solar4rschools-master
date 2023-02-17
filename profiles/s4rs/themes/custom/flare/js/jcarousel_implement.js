(function ($) {
  Drupal.behaviors.jcarousel  = {
      attach: function (context) {
        var jcarousel = $('.carousel-ul').parent();
        $('.carousel-ul').parent()
          .on('jcarousel:reload jcarousel:create', function () {
              var width = jcarousel.innerWidth();
              var maxToShow = jcarousel.jcarousel('items').length > 5 ? 5 : jcarousel.jcarousel('items').length;

              if (width >= 600) {
                  width = width / maxToShow;
              } else if (width >= 350) {
                  width = width / 2;
              }

              jcarousel.jcarousel('items').css('width', width + 'px');
          })
          .jcarousel({
              wrap: 'circular'
          });
        jcarousel.append('<a class="jcarousel-control-next" href="#">›</a>');
        $('.jcarousel-control-next')
            .jcarouselControl({
                target: '+=1'
            });

        $('.jcarousel-pagination')
            .on('jcarouselpagination:active', 'a', function() {
                $(this).addClass('active');
            })
            .on('jcarouselpagination:inactive', 'a', function() {
                $(this).removeClass('active');
            })
            .on('click', function(e) {
                e.preventDefault();
            })
            .jcarouselPagination({
                perPage: 1,
                item: function(page) {
                    return '<a href="#' + page + '">' + page + '</a>';
                }
            });

    }
  };

})(jQuery);
