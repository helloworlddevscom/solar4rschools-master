<?php

/**
 * @file
 * Template for Bedrock Flint.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Sidebar ['sidebar']
 *   -- Content Main ['content_main']
 */
?>

<div class="panel-display flint clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <section class="flint-content-main panel-panel">
    <div class="flint-content-main-inner panel-panel-inner">
      <?php print $content['content_main']; ?>
    </div><!-- /.flint-content-main-inner -->
  </section><!-- /.flint-content-main -->

  <section class="flint-sidebar panel-panel">
    <div class="flint-sidebar-inner panel-panel-inner">
      <?php print $content['sidebar']; ?>
    </div><!-- /.flint-sidebar-inner -->
  </section><!-- /.flint-sidebar -->

</div><!-- /.flint -->
