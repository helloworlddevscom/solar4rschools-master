<?php

/**
 * @file
 * Template for Bedrock Adakite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Column Left ['column_left']
 *   -- Column Middle ['column_middle']
 *   -- Column Right ['column_right']
 *   -- Content Footer Left ['content_footer_left']
 *   -- Content Footer Right ['content_footer_right']
 */
?>

<div class="panel-display adakite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="adakite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="adakite-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.adakite-content-header -->
    <?php endif; ?>

    <div class="adakite-column-container clearfix">

      <div class="adakite-column-left adakite-column panel-panel">
        <div class="adakite-column-left-inner adakite-column-inner panel-panel-inner">
          <?php print $content['column_left']; ?>
        </div><!-- /.adakite-column-left-inner -->
      </div><!-- /.adakite-column-left -->

      <div class="adakite-column-middle adakite-column panel-panel">
        <div class="adakite-column-middle-inner adakite-column-inner panel-panel-inner">
          <?php print $content['column_middle']; ?>
        </div><!-- /.adakite-column-middle-inner -->
      </div><!-- /.adakite-column-middle -->

      <div class="adakite-column-right adakite-column panel-panel">
        <div class="adakite-column-right-inner adakite-column-inner panel-panel-inner">
          <?php print $content['column_right']; ?>
        </div><!-- /.adakite-column-right-inner -->
      </div><!-- /.adakite-column-right -->

    </div><!-- /.adakite-column-container -->

    <div class="adakite-content-footer-container clearfix">

      <?php if ($content['content_footer_left']): ?>
        <div class="adakite-content-footer-left adakite-content-footer panel-panel">
            <?php print $content['content_footer_left']; ?>
        </div><!-- /.adakite-content-footer-left -->
      <?php endif; ?>

      <?php if ($content['content_footer_right']): ?>
        <div class="adakite-content-footer-right adakite-content-footer panel-panel">
            <?php print $content['content_footer_right']; ?>
        </div><!-- /.adakite-content-footer-right -->
      <?php endif; ?>

    </div><!-- /.adakite-content-footer-container -->

  </div><!-- /.adakite-content-container -->

</div><!-- /.adakite -->
