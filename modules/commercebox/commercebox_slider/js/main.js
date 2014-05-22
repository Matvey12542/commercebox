(function ($) {


  Drupal.behaviors.openPopup = {
    attach: function (context, settings) {
//      if ($('body').find('#remove').length == 0) {
//        console.log($('#remove'))
//        $('#block-system-main').once().append('<div class="remove"> </div>');
//      }
//      $('#block-system-main').append('<div class="remove">1 </div>');
//      console.log($('#remove'));
      $('.view-commercebox-slider a.edit-slide, a.new-slide').click(function (e) {
        e.preventDefault();
//        if ($('.black-space').length == 0) {
//          $('body').append("<div class='black-space'> </div>");
//        }
//        $('#remove').remove();

      });

      $('#remove a.close').click(function (e) {      // remove black area
        e.preventDefault();
        $(".black-space").remove();
      });

//      if ($('#remove').length == 0) {               // remove black area
//        $(".black-space").remove();
//      }

      $('.view-commercebox-slider .delete-slide', $(context)).click(function () {
        var $del = $(this).parent().parent().parent();
        $del.remove();
      });
      $(".block-system .content").append("<span id='process'>save </span>");

//      $('.form-submit').bind('click',function() {
////        $.ajax({
////          type: 'GET',
////          url: '/data/remove/nojs',
////          dataType: 'json',
////          success: function () {
////            $('#remove').remove();
////          },
////          error: function (xmlhttp) {
////            alert(Drupal.ajaxError(xmlhttp, db.uri));
////          }
////        });
////        $('#remove').remove();
//        alert('buuu');
//      });

// Drag and Drop Slider
      $('.view-commercebox-slider .view-content').sortable({
          stop: function (event, ui) {
            $("#process").show('slow');
            setTimeout(function() { $("#process").hide('slow'); }, 2000);
            var $newobj = new Object();
            var $arr = new Array();

            $('.view-commercebox-slider .view-content .views-row').each(function (i) {
              var obj = {};
              var $nid = $('.settings', this).attr('id');
              var $pos = $('.settings', this).attr('pos');

              obj['nid'] = $nid;
              obj['pos'] = $pos;
              $arr.push(obj);
            });

            $newobj.slides = $arr;
            $('.view-commercebox-slider .view-content .views-row').each(function (i) {
              $('.settings', this).attr('pos', i + 1);
            });

            var $href = "/commercebox_slider_resort";
            var post = "slides=" + JSON.stringify($newobj);
            $.ajax({
              url: $href,
              type: "POST",
              dataType: 'json',
              data: post,
              success: function (data) {
//                alert('success');
              }
            });
          }
        }
      );
    }
  };

})(jQuery);
