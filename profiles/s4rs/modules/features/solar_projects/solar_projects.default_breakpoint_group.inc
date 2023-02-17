<?php
/**
 * @file
 * solar_projects.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function solar_projects_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.flare.xlarge';
  $breakpoints[] = 'breakpoints.theme.flare.large';
  $breakpoints[] = 'breakpoints.theme.flare.medium';
  $breakpoints[] = 'breakpoints.theme.flare.small';
  $breakpoints[] = 'breakpoints.theme.flare.default';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'project_large';
  $breakpoint_group->name = 'Project large';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['project_large'] = $breakpoint_group;

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.flare.xlarge';
  $breakpoints[] = 'breakpoints.theme.flare.large';
  $breakpoints[] = 'breakpoints.theme.flare.medium';
  $breakpoints[] = 'breakpoints.theme.flare.small';
  $breakpoints[] = 'breakpoints.theme.flare.default';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'project_small';
  $breakpoint_group->name = 'Project small';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['project_small'] = $breakpoint_group;

  return $export;
}
