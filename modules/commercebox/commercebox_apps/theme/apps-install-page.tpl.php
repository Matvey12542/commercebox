<?php if (isset($content['featured_app']) && is_array($content['featured_app'])) { print drupal_render($content['featured_app']); }?>
<?php if (isset($content['apps'])) : ?>
<div id="apps-list" class="clearfix">
  This is install page tpl
  <form>
    <?php
      if (!empty($content['apps']['cb_theme'])) {
        print '<input type="radio" name="theme" value="default">';
      }
      print drupal_render($content['apps']);
    ?>
  </form>
</div>
<?php endif; ?>
