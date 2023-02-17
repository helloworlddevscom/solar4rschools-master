<?php
/**
 * @file
 * Overwrite field--field-fences-div.tpl.php
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-div-element
 */
?>
<?php if ($element['#field_name'] === 'field_grade_levels'): ?>
<div class="field-wrapper">
  <span class="field-label">
    <?php print t('Author'); ?>
  </span>
  <div class="field field-author inline">
    <?php print $element['#object']->name; ?>
  </div>
</div>
<?php endif; ?>
<div class="field-wrapper <?php print $field_name_css;?>">
  <?php if ($element['#label_display'] == 'inline'): ?>
    <span class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php elseif ($element['#label_display'] == 'above'): ?>
    <h3 class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>
    </h3>
  <?php endif; ?>

  <?php foreach ($items as $delta => $item): ?>
    <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
      <?php print render($item); ?>
    </div>
  <?php endforeach; ?>
  <?php if (isset($update_link)): ?>
    <?php print $update_link; ?>
  <?php endif; ?>
</div>
