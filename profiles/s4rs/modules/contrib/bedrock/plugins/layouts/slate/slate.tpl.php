<?php

/**
 * @file
 * Template for Bedrock Slate.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Main Content ['main_content']
 */
?>

<div class="panel-display slate clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="slate-main-content panel-panel clearfix">
    <div class="slate-main-content-inner panel-panel-inner">
      <?php print $content['main_content']; ?>
    </div><!-- /.slate-main-content-inner -->
  </div><!-- /.slate-main-content -->

</div><!-- /.slate -->
