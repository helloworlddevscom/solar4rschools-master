<?php
/**
 * @file
 * Global generation data summary.
 */
?>
<div id="<?php print $css_id; ?>" class="generation-stats--carbon-equivalents-global generation-stats-refreshable">
  <div class="carbon-equivalent-summary">
    <?php print $summary; ?>
  </div>
  <ul class="carbon-equivalent-equivalents">
  <?php foreach ($eqs as $type => $eq): ?>
    <li class="carbon-equivalent-type-<?php print $type; ?>">
      <?php print $eq; ?>
    </li>
  <?php endforeach; ?>
  </ul>
</div>
