<?php
/**
 * @file
 * Power-One data types and units.
 */

/**
 * Get a list of fields and their corresponding Power-One data type.
 */
function _power_one_field_data_types() {
  static $types = array();
  if (empty($types)) {
    $types = array(
      '1PhaseCurrent' => 'Current',
      '1PhaseVoltage' => 'Voltage',
      '3PhaseCurrent' => 'Current',
      '3PhaseLineNeutralVoltage' => 'Voltage',
      '3PhaseVoltage' => 'Voltage',
      'AmbientTemp' => 'Temperature',
      'AmpHours' => 'Amp Hours',
      'BarometricPressure' => 'Pressure',
      'BatteryTemp' => 'Temperature',
      'CellTemp' => 'Temperature',
      'CumIrradiance' => 'Cumulative Irradiance',
      'Current' => 'Current',
      'CurrentA' => 'Current',
      'CurrentB' => 'Current',
      'CurrentC' => 'Current',
      'CurrentL1' => 'Current',
      'CurrentL2' => 'Current',
      'DCAmpHours' => 'Amp Hours',
      'DCCurrent' => 'Current',
      'DCGenerationEnergy' => 'Energy',
      'DCGenerationPower' => 'Power',
      'DCPVEnergy' => 'Energy',
      'DCPVPower' => 'Power',
      'DCRenewableEnergy' => 'Energy',
      'DCRenewablePower' => 'Power',
      'DCStorageInCurrent' => 'Current',
      'DCStorageInEnergy' => 'Energy',
      'DCStorageInPower' => 'Power',
      'DCStorageOutCurrent' => 'Current',
      'DCStorageOutEnergy' => 'Energy',
      'DCStorageOutPower' => 'Power',
      'DCStorageVoltage' => 'Voltage',
      'DCVoltage' => 'Voltage',
      'DCWindEnergy' => 'Energy',
      'DCWindPower' => 'Power',
      'DeviceTemp' => 'Temperature',
      'EarliestCommunicationTime' => 'Date',
      'EarliestDate' => 'Date',
      'EarliestDataReceiptTime' => 'Date',
      'EarliestSampleTime' => 'Date',
      'ExpectedPVEnergy' => 'Energy',
      'ExpectedPVPower' => 'Power',
      'FlowDiffTemp' => 'Temperature',
      'FlowRate' => 'Flow',
      'FlowReturnTemp' => 'Temperature',
      'FlowTemp' => 'Temperature',
      'FlowVolume' => 'Volume',
      'GenerationEnergy' => 'Energy',
      'GenerationPower' => 'Power',
      'GrossDemandEnergy' => 'Energy',
      'GrossDemandPower' => 'Power',
      'GrossUsageEnergy' => 'Energy',
      'GrossUsagePower' => 'Power',
      'InstalledCapacity' => 'Power',
      'InverterDirectEnergy' => 'Energy',
      'InverterDirectPower' => 'Power',
      'Irradiance' => 'Irradiance',
      'LatestCommunicationTime' => 'Date',
      'LatestDataReceiptTime' => 'Date',
      'LatestDataUpdateTime' => 'Date',
      'LatestDate' => 'Date',
      'LatestSampleTime' => 'Date',
      'LineFrequency' => 'Frequency',
      'LineInEnergy' => 'Energy',
      'LineInPower' => 'Power',
      'LineOutEnergy' => 'Energy',
      'LineOutPower' => 'Power',
      'NetUsageEnergy' => 'Energy',
      'NetUsagePower' => 'Power',
      'Precipitation' => 'Length',
      'PVEnergy' => 'Energy',
      'PVEnergyPI' => 'Energy', // TODO: Is this correct?
      'PVEnergyPR' => 'Percent',
      'PVPower' => 'Power',
      'PVPowerPI' => 'Power', // TODO: Is this correct?
      'PVPowerPR' => 'Percent',
      'RatedCapacity' => 'Energy',
      'RelativeHumidity' => 'Percent',
      'RenewableEnergy' => 'Energy',
      'RenewablePower' => 'Power',
      'RGGenerationEnergy' => 'Energy',
      'RGGenerationPower' => 'Power',
      'RGGrossUsageEnergy' => 'Energy',
      'RGGrossUsagePower' => 'Power',
      'RGNetUsageEnergy' => 'Energy',
      'RGNetUsagePower' => 'Power',
      'RGPVEnergy' => 'Energy',
      'RGPVPower' => 'Power',
      'RGRenewableEnergy' => 'Energy',
      'RGRenewablePower' => 'Power',
      'RGSolarThermalEnergy' => 'Energy',
      'RGSolarThermalPower' => 'Power',
      'SolarThermalEnergy' => 'Energy',
      'SolarThermalPower' => 'Power',
      'StorageInCurrent' => 'Current',
      'StorageInEnergy' => 'Energy',
      'StorageInPower' => 'Power',
      'StorageOutCurrent' => 'Current',
      'StorageOutEnergy' => 'Energy',
      'StorageOutPower' => 'Power',
      'Voltage' => 'Voltage',
      'VoltageAB' => 'Voltage',
      'VoltageAN' => 'Voltage',
      'VoltageBC' => 'Voltage',
      'VoltageBN' => 'Voltage',
      'VoltageCA' => 'Voltage',
      'VoltageCN' => 'Voltage',
      'VoltageL1' => 'Voltage',
      'VoltageL2' => 'Voltage',
      'WindDirection' => 'Direction',
      'WindEnergy' => 'Energy',
      'WindPower' => 'Power',
      'WindSpeed' => 'Velocity',
    );
  }
  return $types;
}

/**
 * Returns a list of all possible units that the API understands.
 */
function _power_one_variable_units($variable = NULL) {
  return array(
    'amp-hours' => array(
      'label' => 'Ah',
    ),
    'amps' => array(
      'label' => 'A',
    ),
    'british-thermal-units' => array(
      'label' => 'Btu',
    ),
    'celsius' => array(
      'label' => '°C',
    ),
    'centimeters' => array(
      'label' => 'cm',
    ),
    'cubic-feet' => array(
      'label' => 'ft³',
    ),
    'cubic-feet-per-hr' => array(
      'label' => 'ft³/h',
    ),
    'cubic-feet-per-min' => array(
      'label' => 'ft³/min',
    ),
    'cubic-meters' => array(
      'label' => 'm³',
    ),
    'cubic-meters-per-hr' => array(
      'label' => 'm³/h',
    ),
    'cubic-meters-per-min' => array(
      'label' => 'm³/min',
    ),
    'degrees-north' => array(
      'label' => '°N',
    ),
    'fahrenheit' => array(
      'label' => '°F',
    ),
    'feet' => array(
      'label' => 'ft',
    ),
    'feet-per-second' => array(
      'label' => 'ft/s',
    ),
    'gallons' => array(
      'label' => 'g',
    ),
    'gallons-per-hr' => array(
      'label' => 'g/h',
    ),
    'gallons-per-min' => array(
      'label' => 'g/min',
    ),
    'gigajoules' => array(
      'label' => 'GJ',
    ),
    'hertz' => array(
      'label' => 'Hz',
    ),
    'inches' => array(
      'label' => 'in',
    ),
    'inches-hg' => array(
      'label' => 'inHg',
    ),
    'kilo-amp-hours' => array(
      'label' => 'kAh',
    ),
    'kilometers' => array(
      'label' => 'km',
    ),
    'kilometers-per-hour' => array(
      'label' => 'km/h',
    ),
    'kiloohms' => array(
      'label' => 'kΩ',
    ),
    'kilowatt-hours' => array(
      'label' => 'kWh',
    ),
    'kilowatt-hours-per-meter-sq' => array(
      'label' => 'kWh/m²',
    ),
    'kilowatts' => array(
      'label' => 'kW',
    ),
    'kilowatts-per-meter-sq' => array(
      'label' => 'kW/m²',
    ),
    'liters' => array(
      'label' => 'L',
    ),
    'liters-per-hr' => array(
      'label' => 'L/h',
    ),
    'liters-per-min' => array(
      'label' => 'L/min',
    ),
    'megajoules' => array(
      'label' => 'MJ',
    ),
    'megaohms' => array(
      'label' => 'MΩ',
    ),
    'megawatt-hours' => array(
      'label' => 'MWh',
    ),
    'megawatts' => array(
      'label' => 'MW',
    ),
    'meters' => array(
      'label' => 'm',
    ),
    'meters-per-second' => array(
      'label' => 'm/s',
    ),
    'miles' => array(
      'label' => 'mi',
    ),
    'miles-per-hour' => array(
      'label' => 'mi/h',
    ),
    'milliamps' => array(
      'label' => 'mA',
    ),
    'millibars' => array(
      'label' => 'mbar',
    ),
    'millimeters' => array(
      'label' => 'mm',
    ),
    'millimeters-h2o' => array(
      'label' => 'mmH2O',
    ),
    'millimeters-hg' => array(
      'label' => 'mmHg',
    ),
    'millivolts' => array(
      'label' => 'mV',
    ),
    'milliwatts' => array(
      'label' => 'mW',
    ),
    'numeric-percent' => array(
      'label' => '',
    ),
    'ohms' => array(
      'label' => 'Ω',
    ),
    'power-factor' => array(
      'label' => 'PF',
    ),
    'revolutions-per-minute' => array(
      'label' => 'r/min',
    ),
    'torr' => array(
      'label' => 'Torr',
    ),
    'volts' => array(
      'label' => 'V',
    ),
    'watt-hours' => array(
      'label' => 'Wh',
    ),
    'watt-hours-per-meter-sq' => array(
      'label' => 'Wh/m²',
    ),
    'watts' => array(
      'label' => 'W',
    ),
    'watts-per-meter-sq' => array(
      'label' => 'W/m²',
    ),
    'whole-percent' => array(
      'label' => '%',
    ),
  );
}

/**
 * Get a list of Power-One data types and their corresponding units.
 */
function _power_one_data_type_units() {
  static $units = array();
  if (empty($units)) {
    $units = array(
      'Amp Hours' => 'kilo-amp-hours',
      'Cumulative Irradiance' => 'kilowatt-hours-per-meter-sq',
      'Current' => 'amps',
      'Date' => 'None',
      'Direction' => 'degrees-north',
      'Energy' => 'watt-hours',
      'Flow' => 'liters-per-min',
      'Frequency' => 'hertz',
      'Irradiance' => 'watts-per-meter-sq',
      'Length' => 'meters',
      'Percent' => 'whole-percent',
      'Power' => 'watts',
      'Power Factor' => 'power-factor',
      'Pressure' => 'millibars',
      'Temperature' => variable_get('power_one_unit_temperature', 'fahrenheit'),
      'Velocity' => variable_get('power_one_unit_velocity', 'miles-per-hour'),
      'Voltage' => 'volts',
      'Volume' => 'liters',
    );
  }
  return $units;
}
