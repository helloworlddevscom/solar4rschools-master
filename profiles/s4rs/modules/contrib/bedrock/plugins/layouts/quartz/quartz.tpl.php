<?php

/**
 * @file
 * Template for Bedrock Quartz.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header Left ['content_header_left']
 *   -- Content Header Right ['content_header_right']
 *   -- Content Main ['content_main']
 */
?>

<div class="panel-display quartz clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="quartz-content-container">

    <div class="quartz-content-header-container clearfix">

      <?php if ($content['content_header_left']): ?>
        <div class="quartz-content-header-left quartz-content-header panel-panel">
            <?php print $content['content_header_left']; ?>
        </div><!-- /.quartz-content-header-left -->
      <?php endif; ?>

      <?php if ($content['content_header_right']): ?>
        <div class="quartz-content-header-right quartz-content-header panel-panel">
            <?php print $content['content_header_right']; ?>
        </div><!-- /.quartz-content-header-right -->
      <?php endif; ?>

    </div><!-- /.quartz-content-header-container -->

    <section class="quartz-content-main panel-panel">
      <div class="quartz-content-main-inner panel-panel-inner">
        <?php print $content['content_main']; ?>
      </div><!-- /.quartz-content-main-inner -->
    </section><!-- /.quartz-content-main -->

  </div><!-- /.quartz-content-container -->

</div><!-- /.quartz -->
