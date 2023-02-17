<?php

/**
 * @file
 * Template for Solar Weather block.
 *
 * Variables:
 * $data - The entire data array returned by solar! Weather API.
 */
?>
<div class="solar-weather-block">
  <div class="solar-weather-current">

    <div class="solar-weather-current-conditions-image solar-weather-code">
      <?php print $current_icon; ?>
    </div>

    <div class="solar-weather-current-temperature">
    <?php print $current_temperature; ?>
    </div>

    <div class="solar-weather-current-condition">
    <?php print $current_condition; ?>
    </div>

    <div class="solar-weather-current-wind-direction">
    <?php print $current_wind_direction; ?>
    </div>

    <div class="solar-weather-current-wind-speed">
    <?php print $current_wind_speed; ?>
    </div>
  </div>

  <?php print $source; ?>
</div>
