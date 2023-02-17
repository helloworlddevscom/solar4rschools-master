<?php

/**
 * @file
 * Template for Bedrock Granite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Column Left ['column_left']
 *   -- Column Right ['column_right']
 */
?>

<div class="panel-display granite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="granite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="granite-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.granite-content-header -->
    <?php endif; ?>

    <div class="granite-column-container clearfix">

      <div class="granite-column-left granite-column panel-panel">
        <div class="granite-column-left-inner granite-column-inner panel-panel-inner">
          <?php print $content['column_left']; ?>
        </div><!-- /.granite-column-left-inner -->
      </div><!-- /.granite-column-left -->

      <div class="granite-column-right granite-column panel-panel">
        <div class="granite-column-right-inner granite-column-inner panel-panel-inner">
          <?php print $content['column_right']; ?>
        </div><!-- /.granite-column-right-inner -->
      </div><!-- /.granite-column-right -->

    </div><!-- /.granite-column-container -->

  </div><!-- /.granite-content-container -->

</div><!-- /.granite -->
