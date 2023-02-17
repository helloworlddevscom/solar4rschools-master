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
 *   -- Column Inner Left ['column_inner_left']
 *   -- Column Inner Right ['column_inner_right']
 *   -- Column Right ['column_right']
 *   -- Column Full Width ['content_full_width']
 */
?>

<div class="panel-display jerusalem_marble clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <div class="jerusalem_marble-content-container">

    <?php if ($content['content_header']): ?>
      <div class="jerusalem_marble-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.jerusalem_marble-content-header -->
    <?php endif; ?>

    <div class="jerusalem_marble-column-container clearfix">

      <div class="jerusalem_marble-column-left jerusalem_marble-column panel-panel">
        <div class="jerusalem_marble-column-left-inner jerusalem_marble-column-inner panel-panel-inner">
          <?php print $content['column_left']; ?>
        </div><!-- /.jerusalem_marble-column-left-inner -->
      </div><!-- /.jerusalem_marble-column-left -->
      <div class="jerusalem_marble-column-inner-left jerusalem_marble-column panel-panel">
        <div class="jerusalem_marble-column-left-inner jerusalem_marble-column-inner panel-panel-inner">
          <?php print $content['column_inner_left']; ?>
        </div><!-- /.jerusalem_marble-column-left-inner -->
      </div><!-- /.jerusalem_marble-column-left -->
      <div class="jerusalem_marble-column-inner-right jerusalem_marble-column panel-panel">
        <div class="jerusalem_marble-column-inner-right-inner jerusalem_marble-column-inner panel-panel-inner">
          <?php print $content['column_inner_right']; ?>
        </div><!-- /.jerusalem_marble-column-inner-right-inner -->
      </div><!-- /.jerusalem_marble-column-inner-right -->

      <div class="jerusalem_marble-column-right jerusalem_marble-column panel-panel">
        <div class="jerusalem_marble-column-right-inner jerusalem_marble-column-inner panel-panel-inner">
          <?php print $content['column_right']; ?>
        </div><!-- /.jerusalem_marble-column-right-inner -->
      </div><!-- /.jerusalem_marble-column-right -->
    </div><!-- /.jerusalem_marble-column-container -->
    <?php if ($content['content_full_width']): ?>
      <div class="jerusalem_marble-content-full-width clearfix panel-panel">
          <?php print $content['content_full_width']; ?>
      </div><!-- /.jerusalem_marble-content-full-width -->
    <?php endif; ?>

  </div><!-- /.jerusalem_marble-content-container -->

</div><!-- /.jerusalem_marble -->
