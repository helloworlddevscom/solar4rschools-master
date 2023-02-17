<?php
/**
 * @file
 * Generation Stats site summary block.
 *
 * We're using this block for displaying lifetime carbon equivalents.
 */
?>
<div id="generation-stats-site-summary" class="generation-stats-refreshable clearfix">
  <h2><?php print $title; ?></h2>
  <hr />
  <h3><?php print $subtitle; ?></h3>

  <div class="carbon-equivalent-total">
  <?php foreach ($eq_carbon_digits as $digit):
    ?><div class="carbon-equivalent-digit"><span><?php
      print $digit;
    ?></span></div><?php
        endforeach; ?>
    <span class="legend">lbs CO2</span>
  </div>

  <ul class="carbon-equivalent-equivalents">
  <?php foreach ($eqs as $type => $eq): ?>
    <li class="carbon-equivalent-type-<?php print $type; ?>">
      <?php print $eq; ?>
    </li>
  <?php endforeach; ?>
  </ul>
</div>
