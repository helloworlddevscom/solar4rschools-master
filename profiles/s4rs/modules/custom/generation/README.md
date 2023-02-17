## About the Generation API module
__Briefly__: Provides an API to query energy generation devices using multiple data providers.

More detail:
This module is intended to create a series of entities based on the input of various data providers.

In previous versions of the module, related data was saved on a per-node basis.
Since we're creating entities, related tabs will show up on the entity level.
Entities will then be related to nodes as an entity reference.

### Configuration
Configuration takes place from Administration » Configuration » Generation API `admin/config/generation`.
There are two configuration pages:

__Variables__:
Administration » Configuration » Generation API » All variables or `admin/config/generation/variables`
lists all variables returned by any module implementing the GenerationProvider class.
The method called to get these variables is getVariables();
Variables are what can be graphed for each data collection site. As these all come from the
listed providers, it's not intended that users be able to add or edit these items.
 - These could be refactored as Entities in the future.

__Variable presets__:
Administration » Configuration » Generation API » All presets or `admin/config/generation/variable-presets/list`
lists all variable preset overrides manually created by the administrator on a global level.
Note, any new variable added through getVariables also creates a preset that can be edited by the user.
 - These could also be refactored as Entities in the future.

### Extension
Any modules wishing to extend the GenerationProvider class should do so by including a file
named as such: `my_module.generation.inc`. This file should contain a class structured as such:
`class MyModuleGenerationProvider implements GenerationProvider {}`

### Submodules
The Generation module contains three submodules:
 * Generation Statistics - Provides panes with generation statistics.
 * Generation Charts - Provides charts of generation data.
 * Generation Equations - Provides a custom field to arithmetically manipulate generation data. See it's README for more information.

### Deeper dive into the GenerationProvider interface.

The purpose of this section is to inform external providers who are creating APIs of what
functionality is available in this site. This is a high-level view. Specific information
about each object detailed can be provided if requested.

#### General information:

- We prefer restful services that return a json object, but returned XML is also acceptable.

#### Features requested:

__Our structure__:

The way we've organized data on the BEF website, we have the following objects from providers:

- Generation site: a specific information collection area (a set of solar panels, for example). A generation site
has a unique identifier, a location, and a system size. It may choose to supply other information,
which may or may not be passed on to the BEF website.

- Generation site device: each generation site might contain several generation site devices (several solar panels,
a car charging station, etc.) If it is possible or desired to display site information on a per-device level, this should be
made available through the API.

- Generation variable: Each generation site will have a series of variables it tracked. This is
generally up to the provider, but the most important is obviously power or energy. Other useful information
include things like temperature or wind speed, depending on the device type.

- Generation variable unit: This information helps us determine labels to show for each generation
variable.

__Authentication__:

Authentication can be accomplished however you feel is best via web services. Previous
providers have requested an API key, or have implemented a token that can be passed
in subsequent queries.

__Global requests__:

On various places on the site, BEF displays a summation of generation information for all
its providers. The following calls are requested to speed such summations.

1. __Required__: The ability to ask for a list of all generation sites owned by BEF.
2. _Requested_: The ability to ask for an instant summary of all sites owned by BEF.
3. _Requested_: The ability to ask for a list of all variables supplied by any generation site.

On a per-site basis, BEF displays information about generation over time. The following
are requested to create such queries:

1. __Required__: The ability to ask for lifetime generation information about a given site.
2. __Required__: The ability to ask for generation information about a specific generation site
over a specific amount of time (like a week, a day, a year).
3. __Required__: The ability to ask for generation information about a specific generation site
over a specific amount of time PER a supplied time unit, or "bins" (hours, days, weeks).
