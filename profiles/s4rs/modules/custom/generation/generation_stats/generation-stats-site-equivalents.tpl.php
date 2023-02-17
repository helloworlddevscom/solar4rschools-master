<?php
/**
 * @file
 * Generation site carbon equivalents.
 */
?>
<div id="<?php print $css_id; ?>" class="generation-chart-header generation-stats-refreshable clearfix">
  <span class="date"><?php print $as_of; ?></span>
  <h1><?php print $title; ?></h1>
  <dl class="stats">
    <dt><?php print $current_power_label; ?></dt>
    <dd><?php print $current_power; ?></dd>
    <dt><?php print $period_label; ?>:</dt>
    <dd><?php print $period_energy; ?></dd>
  </dl>
</div>
