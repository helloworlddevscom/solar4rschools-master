                                           ;''
                                         ''';:
                                        ''
                                       ''
       ,':      `',     ,'.      ,;`   ''   ;'''`      ;;.     ;;.              ,;  .;;     `;:       '
     `@@@@@, @@#@@@@  `@@@@@  @@@@@@+ ;',   ''''';   +@@@@@  '@@@@@  @@   @@ @@@@@ @@@@@'  @@@@@` @@'@@ @@   @@
     @@: `@@ @@@  @@# @@` '@@ @@' '@@ '''    ''''',  @@  ;@# @@  +@@ @@   @@ @@@;;@@#  @@ @@' `@@ @@@+; @@, ,@@
    `@@   @@:@@,   @@.@@...@@ @@   @@ '''      ''''  @@@'   +@#   @@ @@   @@ @@   @@   .. @@...@@ @@'   ,@@ @@`
    ,@@   +@+@@    @@;@@@@@@@ @@   @@ .''':     `''`  @@@@@.@@;   @@ @@   @@ @@   @@      @@@@@@@.@@     @@ @@
    `@@   @@,@@,   @@.@@      @@   @@  ''''':    `',     #@@'@#   @@ @@   @@ @@   @@   @@ @@      @@     @@;@+
     @@' ,@@ @@@  @@# @@. :@@ @@   @@  ,''''''    ', @@  .@@ @@` #@@ @@' @@@ @@   @@# .@@ @@+ `@@ @@      @@@
      @@@@@. @@+@@@@  `@@@@@  @@   @@   ;'''''    '` '@@@@@` ,@@@@@  #@@@@@@ @@    @@@@@.  @@@@@. @@      @@@
        .`   @@. .`     `.                ''''    '    ..      ..      .             ..      ..           @@,
             @@.                                 ';                                                     @@@@
             @@.                                ''                                                      @@@`
                                           :'''';

# Bedrock

## A helper module for OpenSourcery's theme system

### Description

Bedrock was initially developed as a base theme for Drupal. The idea to make it a helper module came from the desire to inherit and benefit from an existing theme foundation built on Aurora and the Singularity grid system. By taking advantage of Aurora's sub-theme structure, Bedrock has grown to become a robust set of helper tools for a theme system including:

* Responsive Panel Layouts
* Fieldable Panel Panes
* @TODO Entity View Modes

### Requirements

1. [Sass](http://github.com/Snugug/training-glossary/wiki/Sass#head)
2. [Compass](http://github.com/Snugug/training-glossary/wiki/Compass#head)
3. [Breakpoint](http://github.com/team-sass/breakpoint) - Media Query Handling
4. [Singularity](http://github.com/Team-Sass/Singularity) - Fluid grid framework
5. [Toolkit](http://github.com/Team-Sass/toolkit) - Modern Web Development tools
6. [Panels](http://drupal.org/project/panels) - Panels Drupal module

#### Suggested Drupal Base Theme

Additionally, we suggest the use of [Aurora](http://drupal.org/project/aurora) as a base theme. You can use whatever theme you want, but we use the Aurora stack and as such that is what we have tested these tools with.

### Directions

1. [Download](http://ftp.drupal.org/files/projects/bedrock-7.x-1.0-alpha1.tar.gz) or [clone](https://drupal.org/project/bedrock/git-instructions) the Bedrock repository and place the module in one of the [suggested locations](http://drupal.org/documentation/install/modules-themes) best suited to your Drupal setup.
2. Enable the module and configure a panel page to use one of the Bedrock layouts.
3. Copy and import the Sass partials to your theme's SMACSS-based layout. For example, if you're using the Basalt panel layout, copy plugins/layouts/basalt/sass/partials/_basalt.scss to your theme's Sass structure and include in your layout partial using `@import 'basalt'`. We recommend structuring your partials, so you may want to place them in named subdirectories, resulting in `@import 'basalt/basalt'`.
4. Ensure your theme declares the required variables listed at the top of the Sass layout partial you've included in your theme. For example, if you're using the Basalt panel layout, the following variables are required: `$small, $medium, $large, $xlarge (global breakpoints)`, `$grids`, and `$gutters`. Please see the [Singularity documentation](http://github.com/Team-Sass/Singularity/wiki) for `$grids` and `$gutters` usage.
5. @TODO Finish directions.

### Resources

* [Scalable and Modular Architecture for CSS](http://smacss.com)
