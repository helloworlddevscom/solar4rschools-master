<?php

/**
 * @file
 * Template for Bedrock Obsidian.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Column Left ['column_left']
 *   -- Column Middle ['column_middle']
 *   -- Column Right ['column_right']
 */
?>

<div class="panel-display obsidian clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="obsidian-column-container clearfix">

    <div class="obsidian-column-left obsidian-column panel-panel">
      <div class="obsidian-column-left-inner obsidian-column-inner panel-panel-inner">
        <?php print $content['column_left']; ?>
      </div><!-- /.obsidian-column-left-inner -->
    </div><!-- /.obsidian-column-left -->

    <div class="obsidian-column-middle obsidian-column panel-panel">
      <div class="obsidian-column-middle-inner obsidian-column-inner panel-panel-inner">
        <?php print $content['column_middle']; ?>
      </div><!-- /.obsidian-column-middle-inner -->
    </div><!-- /.obsidian-column-middle -->

    <div class="obsidian-column-right obsidian-column panel-panel">
      <div class="obsidian-column-right-inner obsidian-column-inner panel-panel-inner">
        <?php print $content['column_right']; ?>
      </div><!-- /.obsidian-column-right-inner -->
    </div><!-- /.obsidian-column-right -->

  </div><!-- /.obsidian-column-container -->

</div><!-- /.obsidian -->
