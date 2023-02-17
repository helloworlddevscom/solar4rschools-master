# Generation Equation

What this module is:

This module allows you to create new widgets that manipulate and display generated
(or configured) data. It does so by creating a new field type `generation_math_equation`.
This new field has several inputs:

### Source

This is the initial number to be displayed (possibly after manipulation). There are three possible sets of data that can be manipulated:

 - _Instant data_: Data gathered instantly through a site provider's queryInstantSummary() method.
See the generation module's includes/provider.inc for the interface for these functions.
 - _Lifetime data_: Data gathered instantly through a site provider's queryInstantSummary() method.
   This might need to be altered in the future to pull instead from queryWindowSummary() with a window of "lifetime".
 - _Constant data_: Fields that are entered manually through the Drupal interface. Two kinds of fields are pulled in:
   - Any fields associated with a `generation_site`. Generation sites are entities defined in the root generation module.
We used eck to add fields to the bundles within each Generation Site entity, and it is these fields that are displayed.
For more information, check out /admin/structure/entity-type/generation_site
   - Any calculated fields associated with a Funder profile.

### Equation

Currently a very simple formula manipulator that expects the calculation source to appear right before it. For example:

```
*3
```

would produce the original number multiplied by three. Leave blank to display the original number unmodified.

Only simple arithmetical operations are permitted (add, subtract, multiply, divide).
Currently equations requiring the source value to be manipulated in a more complicated way, say

```
1/(2+x)
```

are not supported, but this might be a useful option to add in the future.

### Label

The label will be placed after the displayed, calculated number. As a text area,
it can support html characters, and have an appropriate filter.

## Filling fields through entity wrapper manipulation

If you ever need to use entity wrappers set() functions to programmatically create an entry in this field, the format is this:

```

  'field_machine_name' => array(
    0 => array(
      'label' => array(
        'value' => 'kW',
        'format' => 'plain_text',
      ),
      'source' => 'power',
      'equation' => '*3',
    ),
  ),

```