<?php

/**
 * @file
 * Template for Bedrock Hawaiite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Column Left ['column_left']
 *   -- Column Middle ['column_middle']
 *   -- Column Right ['column_right']
 *   -- Content Footer ['content_footer']
 */
?>

<div class="panel-display hawaiite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="hawaiite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="hawaiite-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.hawaiite-content-header -->
    <?php endif; ?>

    <div class="hawaiite-column-container clearfix">

      <div class="hawaiite-column-left hawaiite-column panel-panel">
        <div class="hawaiite-column-left-inner hawaiite-column-inner panel-panel-inner">
          <?php print $content['column_left']; ?>
        </div><!-- /.hawaiite-column-left-inner -->
      </div><!-- /.hawaiite-column-left -->

      <div class="hawaiite-column-middle hawaiite-column panel-panel">
        <div class="hawaiite-column-middle-inner hawaiite-column-inner panel-panel-inner">
          <?php print $content['column_middle']; ?>
        </div><!-- /.hawaiite-column-middle-inner -->
      </div><!-- /.hawaiite-column-middle -->

      <div class="hawaiite-column-right hawaiite-column panel-panel">
        <div class="hawaiite-column-right-inner hawaiite-column-inner panel-panel-inner">
          <?php print $content['column_right']; ?>
        </div><!-- /.hawaiite-column-right-inner -->
      </div><!-- /.hawaiite-column-right -->

    </div><!-- /.hawaiite-column-container -->

    <?php if ($content['content_footer']): ?>
      <div class="hawaiite-content-footer clearfix panel-panel">
          <?php print $content['content_footer']; ?>
      </div><!-- /.hawaiite-content-footer -->
    <?php endif; ?>

  </div><!-- /.hawaiite-content-container -->

</div><!-- /.hawaiite -->
