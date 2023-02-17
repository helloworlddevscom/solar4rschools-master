<?php
/**
 * @file
 * Global generation data summary.
 */
?>
<div id="<?php print $css_id; ?>" class="generation-stats--summary-global generation-stats-refreshable">
  <div class="generation-stats-current-power">
    <?php print $current_power; ?>
  </div>
  <div class="generation-stats-total-energy">
    <?php print $total_energy; ?>
  </div>
  <div class="generation-stats-carbon-offset">
    <?php print $carbon; ?>
  </div>
</div>
