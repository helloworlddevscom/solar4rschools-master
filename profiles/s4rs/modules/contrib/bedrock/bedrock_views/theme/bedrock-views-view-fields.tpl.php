<?php

/**
 * @file
 * A Views hover display.
 *
 * - $view: The view in use.
 * - $exposed_fields: an array of $field objects that should be displayed initially. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 * - $dropdown_fields: an array of $field objects that will only be displayed on hover.
 * - $dropdown_id: The ID to use for the dropdown.
 * - $data_options: The data options to control dropdown behavior.
 *
 * @ingroup views_templates
 */
?>
<div data-dropdown="<?php print $dropdown_id; ?>" data-options="<?php print $data_options; ?>">
  <?php foreach ($exposed_fields as $id => $field): ?>
    <?php if (!empty($field->separator)): ?>
      <?php print $field->separator; ?>
    <?php endif; ?>

    <?php print $field->wrapper_prefix; ?>
      <?php print $field->label_html; ?>
      <?php print $field->content; ?>
    <?php print $field->wrapper_suffix; ?>
  <?php endforeach; ?>
</div>
<?php if (!empty($dropdown_fields)): ?>
<div id="<?php print $dropdown_id; ?>" data-dropdown-content>
  <?php foreach ($dropdown_fields as $id => $field): ?>
    <?php if (!empty($field->separator)): ?>
      <?php print $field->separator; ?>
    <?php endif; ?>

    <?php print $field->wrapper_prefix; ?>
      <?php print $field->label_html; ?>
      <?php print $field->content; ?>
    <?php print $field->wrapper_suffix; ?>
  <?php endforeach; ?>
</div>
<?php endif; ?>
