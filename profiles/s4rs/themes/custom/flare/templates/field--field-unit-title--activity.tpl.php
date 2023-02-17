<?php
/**
 * @file
 * Template for taxonomy term reference field on Activity node.
 *
 * We need to override this template in order to render a link that points to the
 * Teacher Activity Center view instead of the default taxonomy term page.
 *
 * We are rewriting the [#href] value in solar_activities_preprocess_field(),
 * to include the facetapi args, however when it's rendered by the default
 * field template, those args are being encoded. (e.g. ? is converted to %3).
 *
 * To avoid this we have to manually construct the link in this template.
 *
 * @see solar_activities_preprocess_field().
 */
?>
<div class="field-wrapper <?php print $field_name_css;?>">
  <?php if ($element['#label_display'] == 'inline'): ?>
    <span class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php elseif ($element['#label_display'] == 'above'): ?>
    <span class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php endif; ?>

  <?php foreach ($items as $delta => $item): ?>
    <div class="<?php print $classes; ?>"<?php print $attributes; ?>><a href="<?php print $item['#href']; ?>" typeof="skos:Concept" property="rdfs:label skos:prefLabel" datatype=""><?php print $item['#title']; ?></a></div>
  <?php endforeach; ?>
</div>
