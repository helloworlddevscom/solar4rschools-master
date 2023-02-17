<?php

/**
 * @file
 * Wrap all field values in a ul element.
 */
?>
<ul>
<li class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <span class="field-label"<?php print $title_attributes; ?>>
    <?php print $label; ?>:
  </span>
  <?php foreach ($items as $delta => $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
</li>
</ul>
