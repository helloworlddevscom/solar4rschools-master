<?php

/**
 * @file
 * Template for Bedrock Jadeite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Column Left Top ['column_left_top']
 *   -- Column Middle Top ['column_middle_top']
 *   -- Column Right Top ['column_right_top']
 *   -- Column Left Bottom ['column_left_bottom']
 *   -- Column Middle Bottom ['column_middle_bottom']
 *   -- Column Right Bottom ['column_right_bottom']
 */
?>

<div class="panel-display jadeite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="jadeite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="jadeite-content-header clearfix panel-panel">
        <?php print $content['content_header']; ?>
      </div><!-- /.jadeite-content-header -->
    <?php endif; ?>
    <div class="jadeite-column-container-top jadeite-column-container clearfix">

      <div class="jadeite-column-left-top jadeite-column-left jadeite-column panel-panel">
        <div class="jadeite-column-left-top-inner jadeite-column-left-inner jadeite-column-inner panel-panel-inner">
          <?php print $content['column_left_top']; ?>
        </div><!-- /.jadeite-column-left-top-inner -->
      </div><!-- /.jadeite-column-left-top -->

      <div class="jadeite-column-middle-top jadeite-column-middle jadeite-column panel-panel">
        <div class="jadeite-column-middle-top-inner jadeite-column-middle-inner jadeite-column-inner panel-panel-inner">
          <?php print $content['column_middle_top']; ?>
        </div><!-- /.jadeite-column-middle-top-inner -->
      </div><!-- /.jadeite-column-middle-top -->

      <div class="jadeite-column-right-top jadeite-column-right jadeite-column panel-panel">
        <div class="jadeite-column-right-top-inner jadeite-column-right-inner jadeite-column-inner panel-panel-inner">
          <?php print $content['column_right_top']; ?>
        </div><!-- /.jadeite-column-right-top-inner -->
      </div><!-- /.jadeite-column-right-top -->

    </div><!-- /.jadeite-column-container-top -->

    <div class="jadeite-column-container-bottom jadeite-column-container clearfix">

      <div class="jadeite-column-left-bottom jadeite-column-left jadeite-column panel-panel">
        <div class="jadeite-column-left-bottom-inner jadeite-column-left-inner jadeite-column-inner panel-panel-inner">
          <?php print $content['column_left_bottom']; ?>
        </div><!-- /.jadeite-column-left-bottom-inner -->
      </div><!-- /.jadeite-column-left-bottom -->

      <div class="jadeite-column-middle-bottom jadeite-column-middle jadeite-column panel-panel">
        <div class="jadeite-column-middle-bottom-inner jadeite-column-middle-inner jadeite-column-inner panel-panel-inner">
          <?php print $content['column_middle_bottom']; ?>
        </div><!-- /.jadeite-column-middle-bottom-inner -->
      </div><!-- /.jadeite-column-middle-bottom -->

      <div class="jadeite-column-right-bottom jadeite-column-right jadeite-column panel-panel">
        <div class="jadeite-column-right-bottom-inner jadeite-column-right-inner jadeite-column-inner panel-panel-inner">
          <?php print $content['column_right_bottom']; ?>
        </div><!-- /.jadeite-column-right-bottom-inner -->
      </div><!-- /.jadeite-column-right-bottom -->

    </div><!-- /.jadeite-column-container-bottom -->

  </div><!-- /.jadeite-content-container -->

</div><!-- /.jadeite -->
