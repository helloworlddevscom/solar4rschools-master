<?php

/**
 * @file
 * Custom theme implementation for entities of type tour_video.
 *
 * @see entity.tpl.php
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page): ?>
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      print render($content);
    ?>
  </div>
</div>
