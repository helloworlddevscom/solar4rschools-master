<?php
/**
 * @file
 * Modified field--fences-ul.tpl.php for use with Foundation's Orbit Slider.
 *
 * @see http://foundation.zurb.com/docs/components/orbit.html
 */
?>
<?php if ($element['#label_display'] == 'inline'): ?>
  <span class="field-label"<?php print $title_attributes; ?>>
    <?php print $label; ?>:
  </span>
<?php elseif ($element['#label_display'] == 'above'): ?>
  <h3 class="field-label"<?php print $title_attributes; ?>>
    <?php print $label; ?>
  </h3>
<?php endif; ?>

<ul class="<?php print $classes; ?>"<?php print $attributes; ?> data-orbit>

  <?php foreach ($items as $delta => $item): ?>
    <li<?php print $item_attributes[$delta]; ?>>
      <?php print render($item); ?>
    </li>
  <?php endforeach; ?>

</ul>
