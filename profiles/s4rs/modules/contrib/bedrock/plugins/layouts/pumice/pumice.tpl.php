<?php

/**
 * @file
 * Template for Bedrock Pumice.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Column Left ['column_left']
 *   -- Column Right ['column_right']
 */
?>

<div class="panel-display pumice clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="pumice-column-container clearfix">

    <div class="pumice-column-left pumice-column panel-panel">
      <div class="pumice-column-left-inner pumice-column-inner panel-panel-inner">
        <?php print $content['column_left']; ?>
      </div><!-- /.pumice-column-left-inner -->
    </div><!-- /.pumice-column-left -->

    <div class="pumice-column-right pumice-column panel-panel">
      <div class="pumice-column-right-inner pumice-column-inner panel-panel-inner">
        <?php print $content['column_right']; ?>
      </div><!-- /.pumice-column-right-inner -->
    </div><!-- /.pumice-column-right -->

  </div><!-- /.pumice-column-container -->

</div><!-- /.pumice -->
