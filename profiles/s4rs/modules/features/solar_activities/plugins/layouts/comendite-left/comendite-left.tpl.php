<?php

/**
 * @file
 * Template for Page Manager layout comendite-left.
 * This is based on the Comendite layout provided by the Bedrock module,
 * but the sidebar is on the left as needed for the Teacher Activity Center.
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

<div class="panel-display comendite-left clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <section class="comendite-left-content-container">

    <?php if ($content['content_header']): ?>
      <div class="comendite-left-content-header clearfix panel-panel">
        <?php print $content['content_header']; ?>
      </div><!-- /.comendite-left-content-header -->
    <?php endif; ?>

    <div class="comendite-left-content-column-container clearfix <?php if ($content['content_secondary_column']): print 'with-secondary-column'; endif; ?>">

      <?php if ($content['content_secondary_column']): ?>
      <aside class="comendite-left-content-secondary-column comendite-left-column panel-panel">
        <div class="comendite-left-content-secondary-column-inner comendite-left-column-inner panel-panel-inner">
          <?php print $content['content_secondary_column']; ?>
        </div><!-- /.comendite-left-content-secondary-column-inner -->
      </aside><!-- /.comendite-left-content-secondary-column -->
      <?php endif; ?>

        <article class="comendite-left-content-main-column comendite-left-column panel-panel">
        <div class="comendite-left-content-main-column-inner comendite-left-column-inner panel-panel-inner">
          <?php print $content['content_main_column']; ?>
        </div><!-- /.comendite-left-content-main-column-inner -->
      </article><!-- /.comendite-left-content-main-column -->

    </div><!-- /.comendite-left-content-column-container -->

  </section><!-- /.comendite-left-content-container -->

</div><!-- /.comendite-left -->
