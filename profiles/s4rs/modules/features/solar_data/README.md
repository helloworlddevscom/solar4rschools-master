## How to create a new equivalency category

A widget category groups widgets into things like "Real-time data," or "This funder's reach."

1. Add a term to the "Widget types" taxonomy at `admin/structure/taxonomy/widget_types`
2. Modify the 'field_show_realtime' field to pull information from the new widget
at `admin/structure/types/manage/project/fields/field_show_realtime` by adding the term's
id to the Entity Selection -> View arguments field.
3. Modify the Project node page panel at `admin/structure/pages/nojs/operation/node_view/handlers/node_view_panel_context_2/content`
by adding a pane linked to the "Widget selects: A project's widgets"
view. Give it a style of "collapsible" and a css class of "widget" if you want it to look
like the other widgets on the page.
4. Assign this term to an existing Equivalency/Statistic entity, or create a new one at
`admin/structure/entity-type/equivalencies_statistics/equivalencies_statistics`
