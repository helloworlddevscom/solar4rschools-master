<?php

/**
 * @file
 * Template for S4RS Kiosks.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Content Header ['content_header']
 *   -- Main Content ['main_content']
 *   -- Content Footer ['content_footer']
 */
?>

<div class="panel-display kiosk-layout clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <?php if ($content['content_header']): ?>
    <div class="kiosk-layout-content-header clearfix panel-panel">
       <?php print $content['content_header']; ?>
    </div><!-- /.kiosk-layout-content-header -->
  <?php endif; ?>

  <div class="kiosk-layout-content-container">

    <?php if ($content['content_prefix']): ?>
      <div class="kiosk-layout-content-prefix clearfix panel-panel">
          <?php print $content['content_prefix']; ?>
      </div><!-- /.kiosk-layout-content-prefix -->
    <?php endif; ?>

    <div class="kiosk-layout-main-content-container clearfix">

      <div class="kiosk-layout-main-content panel-panel">
        <div class="kiosk-layout-main-content-inner panel-panel-inner">
          <?php print $content['main_content']; ?>
        </div><!-- /.kiosk-layout-main-content-inner -->
      </div><!-- /.kiosk-layout-main-content -->

    </div><!-- /.kiosk-layout-main-content-container -->

  </div><!-- /.kiosk-layout-content-container -->

  <div class="kiosk-layout-content-suffix clearfix panel-panel">
    <?php print $content['content_suffix']; ?>
  </div><!-- /.kiosk-layout-content-suffix -->

  <?php if ($content['content_footer']): ?>
    <div class="kiosk-layout-content-footer clearfix panel-panel">
        <?php print $content['content_footer']; ?>
    </div><!-- /.kiosk-layout-content-footer -->
  <?php endif; ?>

</div><!-- /.kiosk-layout -->
