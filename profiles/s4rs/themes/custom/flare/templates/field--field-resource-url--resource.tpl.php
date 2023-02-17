<?php
/**
 * @file
 * Template for Resource URL(s) field on Resource node.
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

  <ul class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <li><?php print render($item); ?></li>
    <?php endforeach; ?>
  </ul>
  <div class="report-btn-wrapper">
    <a id="report-btn" data-nid="<?php print $element['#object']->nid; ?>">
      <small>Report Broken Link</small>
    </a>
  </div>
</div>
