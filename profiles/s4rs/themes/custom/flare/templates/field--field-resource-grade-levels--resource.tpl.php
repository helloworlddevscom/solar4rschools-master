<?php
/**
 * @file
 * Template for field_resource_grade_levels when used on Resource node.
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

  <?php $i = 1; ?>
  <?php $items_count = count($items); ?>
  <?php foreach ($items as $delta => $item): ?>
    <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
      <?php print render($item); ?><?php if ($i != $items_count): ?>,<?php endif; ?>
      <?php $i++; ?>
    </div>
  <?php endforeach; ?>
</div>
