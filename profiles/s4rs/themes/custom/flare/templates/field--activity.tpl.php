<?php
/**
 * @file
 * Default template for fields on Resource nodes.
 *
 * Overwrite field--field-fences-div.tpl.php
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-div-element
 */
?>

<div class="field-wrapper <?php print $field_name_css;?>">
  <?php if ($element['#label_display'] == 'inline'): ?>
    <span class="field-label label--inline"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php elseif ($element['#label_display'] == 'above'): ?>
    <span class="field-label label--above"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php endif; ?>

  <?php foreach ($items as $delta => $item): ?>
    <div class="<?php print $classes; ?>"<?php print $attributes; ?>><?php print render($item); ?></div>
  <?php endforeach; ?>
  <?php if (isset($update_link)): ?>
    <?php print $update_link; ?>
  <?php endif; ?>
</div>
