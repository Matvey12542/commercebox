(function($) {
  /*
   * Open colorpicker on click
   */
  Drupal.behaviors.otherColorButton = {
    attach: function (context, settings) {
      var $picker_default = $('.form-item-bg-color-button, #color-picker-default');
      $picker_default.hide();

      $('.form-item-bg-default input[type="radio"]').click(function() {
        var $picker_default = $('.form-item-bg-color-button, #color-picker-default');
        $picker_default.hide();
        if($(this).val() == 'other') {
          hideotherpicker();
          $picker_default.toggle();

        }
      });
      // PAGE ELEM
      var $picker_default = $('.form-item-page-style-color-page, #color-picker-page-style');
      $picker_default.hide();
      $('.form-item-bg-default-page input[type="radio"]').click(function() {
        $picker_default.hide();
        if($(this).val() == 'other') {
          hideotherpicker();
          $picker_default.toggle();
        }
      });

      var $colorpicker = $('.form-button-settings .form-item-bg-color, .form-button-settings #color-picker');
      $colorpicker.hide();
      $('.form-item-bg-rounded input[type="radio"]').click(function() {
        $colorpicker.hide();
        if ($(this).val() == 'other') {
          hideotherpicker();
          $colorpicker.toggle();
        }
      });

      var $picker_pager = $('.form-item-pager-other-style, #color-picker-pager');
      $picker_pager.hide();
      $('.form-item-pager-style input[type="radio"]').click(function() {
        $picker_pager.hide();
        if($(this).val() == 'other') {
          hideotherpicker();
          $picker_pager.toggle();
        }
      });
    }
  }

  Drupal.behaviors.colorElements = {
    attach: function (context, settings) {
      var $bg_color = $('.form-item-page-style-color input');
      var $colorpicker = $('.form-item-page-style-color, #color-picker-page-style');
      $('#edit-preview-image img').css('background',$bg_color.val());
      $colorpicker.hide();

      $('.page-admin-ui-elements-page-style #edit-bg-default input[type="radio"]').click(function() {
        $colorpicker.hide();
        if ($(this).val() == 'other') {
          $bg_color = $('.form-item-page-style-color input');
          $colorpicker.toggle();
          $('#edit-preview-image img').css('background',$bg_color.val());
          $('#color-picker-page-style').hover(function() {
            $(this).mousemove(function(){
              $('#edit-preview-image img').css('background',$bg_color.val());
            });
          });
        }
        else {
          $bg_color = $(this).val();
          if ($(this).val() == 'default') {
            $bg_color = '9ee7ff';
          }
          $('#edit-preview-image img').css('background','#' + $bg_color);
        }
      });
    }
  }
  // for buttons page
  Drupal.behaviors.buttonsElements = {
    attach: function (context, settings) {
      // Add blok area for pafer element
      $('.page-admin-ui-elements-button #edit-preview-image').append('<div class="pager" id="pager"><div class="pager-round" id="round1">1</div><div class="pager-round" id="round2">2</div><div class="pager-round" id="round3">3</div></div>');

      //Add 6 div to image
      for(var i=0; i<6; i++) {
        $('.page-admin-ui-elements-button #edit-preview-image').append('<div class="image-button" id="id-button'+i+'">Add to cart</div>');
      }
      //Default bacground
      var $defbacg =  $('input.form-submit').attr( "color" );
      var $radius = $('input.form-submit').attr( "round" ) + 'px';
      var $pager_color = $('input.form-submit').attr( "pagercolor" );
      var $background = $('input.form-submit').attr( "pageelemcolor" );

      if ($radius == '') {
        $radius = 'none';
      }
      var $imgbacg = $('#ui-elements-button-form input[name="default_pager_style"]').val();
      $('#edit-preview-image img').css('background',$imgbacg);
      // Set default elements
      $('.image-button').css({'background': $defbacg, 'border-radius': $radius}); // set default buttons

      $('#pager .pager-round').css('background',$pager_color); // pager
      $('#edit-preview-image img').css('background',$background); //background



      $('#edit-bg-default input[type="radio"]').click(function() {
        var $background = $(this).next().css('background');
        if($(this).val() == 'other') {
          $background = $('.form-item-bg-color-button input').val();
        }
        $('.image-button').css({'background': $background, 'border-radius': '0' });
        $('#color-picker-default').hover(function() {
          $(this).mousemove(function(){
            $bg_color = $('.form-item-bg-color-button input').val();
            $('.image-button').css({'background': $bg_color});
          });
        });
      });


      // Clic to Rounded Buttons
      $('#edit-bg-rounded input[type="radio"]').click(function() {
        var $background = $(this).next().css('background');
        if($(this).val() == 'other') {
          $background = $('.form-item-bg-color input').val();
        }
        $('.image-button').css({'background': $background, 'border-radius': '30px'});
        $('#color-picker').hover(function() {
          $(this).mousemove(function(){
            $bg_color = $('.form-item-bg-color input').val();
            $('.image-button').css({'background': $bg_color, 'border-radius': '30px'});
          });
        });
      });
      // Clic to Page elem
      $('.form-item-bg-default-page input[type="radio"]').click(function() {
        var $background = $(this).next().css('background');
        if($(this).val() == 'other') {
          $background = $('.form-item-page-style-color-page input').val();
        }
        $('#edit-preview-image img').css('background',$background);
        $('#color-picker-page-style').hover(function() {
          $(this).mousemove(function(){
            $bg_color = $('.form-item-page-style-color-page input').val();
            $('#edit-preview-image img').css({'background': $bg_color});
            console.log($bg_color);
          });
        });
      });

      // pager click
      $('.form-item-pager-style input[type="radio"]').click(function() {
        var $background = $(this).next().css('background');
        if($(this).val() == 'other') {
          $background = $('#edit-pager-other-style').val();
        }
        $('#pager .pager-round').css('background',$background);
//
        $('#color-picker-pager').hover(function() {
          $(this).mousemove(function(){
            $bg_color = $('#edit-pager-other-style').css('background');

            $('#pager .pager-round').css('background',$bg_color);

          });
        });
      });
    }
  }

  Drupal.behaviors.selectRadioButton = {
    attach: function (context, settings) {
      $('#ui-elements-button-form .form-item-bg-default .form-type-radio > label').click(function() {
        if ($('.form-type-radios .form-item-bg-default input[type="radio"]').val() != 'none') {
          $('.form-type-radios .form-item-bg-rounded input[value="none"]').attr('checked',true);
        }
      });
      $('#ui-elements-button-form .form-item-bg-rounded .form-type-radio > label').click(function() {
        if ($('.form-type-radios .form-item-bg-rounded input[type="radio"]').val() != 'none') {
          $('.form-type-radios.form-item-bg-default input[value="none"]').attr('checked',true);
        }
      });
    }
  };

  Drupal.behaviors.bacgroundPage = {
    attach: function (context, settings) {

      var $href = $('#ui-elements-bg-form .form-managed-file a');
      if ($href.length == 0) {
        var $bg_color = $('#ui-elements-bg-form .form-item-bg-color input').val();
        $('#edit-preview-image img').css('background',$bg_color);
      }

        $('#ui-elements-bg-form #color-picker').hover(function() {
          $(this).mousemove(function(){
            if($('#ui-elements-bg-form .form-managed-file a').length == 0) {
            var $bg_color = $('#ui-elements-bg-form .form-item-bg-color input').val();
            $('#edit-preview-image img').css('background',$bg_color);
            }
          });
        });

      if($('#ui-elements-bg-form .form-managed-file a').length != 0) {
        $href = $('#ui-elements-bg-form .form-managed-file a').attr('href');
        $image = "url('"+$href+"')";
        $('#edit-preview-image img').css('background-image', $image);
      }
      updateimage();

      $("#edit-bg-repeat-x").click(function() {
        updateimage();
      });

      $("#edit-bg-repeat-y").click(function() {
       updateimage();
      });
      $("#edit-bg-repeat").click(function() {
        updateimage();
      });
      $('#edit-bg-image-remove-button').live('click', function(e) {
        $('#edit-preview-image img').css('background-image', 'none');
        updateimage();
      });

    }
  };

  function updateimage() {

    if($("#edit-bg-repeat-y").is(":checked") && $("#edit-bg-repeat-x").is(":checked"))
    {
      $('#edit-preview-image img').css('background-repeat', 'repeat');
    }else if($("#edit-bg-repeat-y").is(":checked") && !$("#edit-bg-repeat-x").is(":checked")) {
      $('#edit-preview-image img').css('background-repeat', 'repeat-y');
    }else if(!$("#edit-bg-repeat-y").is(":checked") && $("#edit-bg-repeat-x").is(":checked")) {
      $('#edit-preview-image img').css('background-repeat', 'repeat-x');
    }
    else{
      $('#edit-preview-image img').css('background-repeat', 'repeat');
    }
    if(!$("#edit-bg-repeat").is(":checked"))
    {
      $('#edit-preview-image img').css('background-repeat', 'no-repeat');
    }
  }

  function hideotherpicker() {
    $('#color-picker-default, .form-item-bg-color-button').hide();
    $('#color-picker, .form-item-bg-color').hide();
    $('#color-picker-pager, .form-item-pager-other-style').hide();
    $('#color-picker-page-style, .form-item-page-style-color-page').hide();

  }
})(jQuery);