<?php

/**
 * @file
 * Template for Bedrock Coal.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Column Left ['column_left']
 *   -- Column Right ['column_right']
 */
?>

<div class="panel-display coal clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="coal-column-container clearfix">

    <div class="coal-column-left coal-column panel-panel">
      <div class="coal-column-left-inner coal-column-inner panel-panel-inner">
        <?php print $content['column_left']; ?>
      </div><!-- /.coal-column-left-inner -->
    </div><!-- /.coal-column-left -->

    <div class="coal-column-right coal-column panel-panel">
      <div class="coal-column-right-inner coal-column-inner panel-panel-inner">
        <?php print $content['column_right']; ?>
      </div><!-- /.coal-column-right-inner -->
    </div><!-- /.coal-column-right -->

  </div><!-- /.coal-column-container -->

</div><!-- /.coal -->
