<?php

/**
 * @file
 * Template for Bedrock Basalt.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Column Left ['column_left']
 *   -- Column Middle ['column_middle']
 *   -- Column Right ['column_right']
 */
?>

<div class="panel-display basalt clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="basalt-content-container">

    <?php if ($content['content_header']): ?>
      <div class="basalt-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.basalt-content-header -->
    <?php endif; ?>

    <div class="basalt-column-container clearfix">

      <div class="basalt-column-left basalt-column panel-panel">
        <div class="basalt-column-left-inner basalt-column-inner panel-panel-inner">
          <?php print $content['column_left']; ?>
        </div><!-- /.basalt-column-left-inner -->
      </div><!-- /.basalt-column-left -->

      <div class="basalt-column-middle basalt-column panel-panel">
        <div class="basalt-column-middle-inner basalt-column-inner panel-panel-inner">
          <?php print $content['column_middle']; ?>
        </div><!-- /.basalt-column-middle-inner -->
      </div><!-- /.basalt-column-middle -->

      <div class="basalt-column-right basalt-column panel-panel">
        <div class="basalt-column-right-inner basalt-column-inner panel-panel-inner">
          <?php print $content['column_right']; ?>
        </div><!-- /.basalt-column-right-inner -->
      </div><!-- /.basalt-column-right -->

    </div><!-- /.basalt-column-container -->

  </div><!-- /.basalt-content-container -->

</div><!-- /.basalt -->
