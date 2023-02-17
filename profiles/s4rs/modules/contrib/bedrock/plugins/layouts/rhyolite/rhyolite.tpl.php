<?php

/**
 * @file
 * Template for Bedrock Rhyolite.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   -- Content Header ['content_header']
 *   -- Content Main Column ['content_main_column']
 *   -- Content Secondary Column ['content_secondary_column']
 *   -- Content Tertiary Column ['content_tertiary_column']
 */
?>

<div class="panel-display rhyolite clearfix <?php if (!empty($class)): print $class; endif; ?>" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <section class="rhyolite-content-container">

    <?php if ($content['content_header']): ?>
      <div class="rhyolite-content-header clearfix panel-panel">
          <?php print $content['content_header']; ?>
      </div><!-- /.rhyolite-content-header -->
    <?php endif; ?>

    <div class="rhyolite-content-column-container clearfix <?php if ($content['content_secondary_column']): print 'with-secondary-column'; endif; ?>">

      <article class="rhyolite-content-main-column rhyolite-column panel-panel">
        <div class="rhyolite-content-main-column-inner rhyolite-column-inner panel-panel-inner">
          <?php print $content['content_main_column']; ?>
        </div><!-- /.rhyolite-content-main-column-inner -->
      </article><!-- /.rhyolite-content-main-column -->

      <?php if ($content['content_secondary_column']): ?>
        <aside class="rhyolite-content-secondary-column rhyolite-column panel-panel">
          <div class="rhyolite-content-secondary-column-inner rhyolite-column-inner panel-panel-inner">
            <?php print $content['content_secondary_column']; ?>
          </div><!-- /.rhyolite-content-secondary-column-inner -->
        </aside><!-- /.rhyolite-content-secondary-column -->
      <?php endif; ?>

      <?php if ($content['content_tertiary_column']): ?>
        <aside class="rhyolite-content-tertiary-column rhyolite-column panel-panel">
          <div class="rhyolite-content-tertiary-column-inner rhyolite-column-inner panel-panel-inner">
            <?php print $content['content_tertiary_column']; ?>
          </div><!-- /.rhyolite-content-tertiary-column-inner -->
        </aside><!-- /.rhyolite-content-tertiary-column -->
      <?php endif; ?>

    </div><!-- /.rhyolite-content-column-container -->

  </section><!-- /.rhyolite-content-container -->

</div><!-- /.rhyolite -->
