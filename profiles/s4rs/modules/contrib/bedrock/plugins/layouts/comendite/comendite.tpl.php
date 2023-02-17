<?php

/**
 * @file
 * Template for Bedrock Comendite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Content Main Column ['content_main_column']
 *   -- Content Secondary Column ['content_secondary_column']
 */
?>

<div class="panel-display comendite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <section class="comendite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="comendite-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.comendite-content-header -->
    <?php endif; ?>

    <div class="comendite-content-column-container clearfix <?php if ($content['content_secondary_column']): print 'with-secondary-column'; endif; ?>">

      <article class="comendite-content-main-column comendite-column panel-panel">
        <div class="comendite-content-main-column-inner comendite-column-inner panel-panel-inner">
          <?php print $content['content_main_column']; ?>
        </div><!-- /.comendite-content-main-column-inner -->
      </article><!-- /.comendite-content-main-column -->

      <?php if ($content['content_secondary_column']): ?>
        <aside class="comendite-content-secondary-column comendite-column panel-panel">
          <div class="comendite-content-secondary-column-inner comendite-column-inner panel-panel-inner">
            <?php print $content['content_secondary_column']; ?>
          </div><!-- /.comendite-content-secondary-column-inner -->
        </aside><!-- /.comendite-content-secondary-column -->
      <?php endif; ?>

    </div><!-- /.comendite-content-column-container -->

  </section><!-- /.comendite-content-container -->

</div><!-- /.comendite -->
