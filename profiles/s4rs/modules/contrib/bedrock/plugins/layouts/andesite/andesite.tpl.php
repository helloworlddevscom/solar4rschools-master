<?php

/**
 * @file
 * Template for Bedrock Andesite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header Left ['content_header_left']
 *   -- Content Header Right ['content_header_right']
 *   -- Column Left ['column_left']
 *   -- Column Middle ['column_middle']
 *   -- Column Right ['column_right']
 */
?>

<div class="panel-display andesite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="andesite-content-container">

    <div class="andesite-content-header-container clearfix">

      <?php if ($content['content_header_left']): ?>
        <div class="andesite-content-header-left andesite-content-header panel-panel">
            <?php print $content['content_header_left']; ?>
        </div><!-- /.andesite-content-header-left -->
      <?php endif; ?>

      <?php if ($content['content_header_right']): ?>
        <div class="andesite-content-header-right andesite-content-header panel-panel">
            <?php print $content['content_header_right']; ?>
        </div><!-- /.andesite-content-header-right -->
      <?php endif; ?>

    </div><!-- /.andesite-content-header-container -->

    <div class="andesite-column-container clearfix">

      <div class="andesite-column-left andesite-column panel-panel">
        <div class="andesite-column-left-inner andesite-column-inner panel-panel-inner">
          <?php print $content['column_left']; ?>
        </div><!-- /.andesite-column-left-inner -->
      </div><!-- /.andesite-column-left -->

      <div class="andesite-column-middle andesite-column panel-panel">
        <div class="andesite-column-middle-inner andesite-column-inner panel-panel-inner">
          <?php print $content['column_middle']; ?>
        </div><!-- /.andesite-column-middle-inner -->
      </div><!-- /.andesite-column-middle -->

      <div class="andesite-column-right andesite-column panel-panel">
        <div class="andesite-column-right-inner andesite-column-inner panel-panel-inner">
          <?php print $content['column_right']; ?>
        </div><!-- /.andesite-column-right-inner -->
      </div><!-- /.andesite-column-right -->

    </div><!-- /.andesite-column-container -->

  </div><!-- /.andesite-content-container -->

</div><!-- /.andesite -->
