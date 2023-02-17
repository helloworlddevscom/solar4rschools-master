<?php

/**
 * @file
 * Template for Bedrock Variolite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Sidebar ['sidebar']
 *   -- Content Header ['content_header']
 *   -- Content Main Column ['content_main_column']
 *   -- Content Secondary Column ['content_secondary_column']
 */
?>

<div class="panel-display variolite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <section class="variolite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="variolite-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.variolite-content-header -->
    <?php endif; ?>

    <div class="variolite-content-column-container clearfix <?php if ($content['content_secondary_column']): print 'with-secondary-column'; endif; ?>">

      <article class="variolite-content-main-column variolite-column panel-panel">
        <div class="variolite-content-main-column-inner variolite-column-inner panel-panel-inner">
          <?php print $content['content_main_column']; ?>
        </div><!-- /.variolite-content-main-column-inner -->
      </article><!-- /.variolite-content-main-column -->

      <?php if ($content['content_secondary_column']): ?>
        <aside class="variolite-content-secondary-column variolite-column panel-panel">
          <div class="variolite-content-secondary-column-inner variolite-column-inner panel-panel-inner">
            <?php print $content['content_secondary_column']; ?>
          </div><!-- /.variolite-content-main-column-inner -->
        </aside><!-- /.variolite-content-main-column -->
      <?php endif; ?>

    </div><!-- /.variolite-content-column-container -->

  </section><!-- /.variolite-content-container -->

  <section class="variolite-sidebar panel-panel">
    <div class="variolite-sidebar-inner panel-panel-inner">
      <?php print $content['sidebar']; ?>
    </div><!-- /.variolite-sidebar-inner -->
  </section><!-- /.variolite-sidebar -->

</div><!-- /.variolite -->
