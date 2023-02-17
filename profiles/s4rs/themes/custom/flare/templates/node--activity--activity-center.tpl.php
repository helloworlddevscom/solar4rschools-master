<?php

/**
 * @file
 * Activity node - Activity Center view mode.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */

$has_image = true;
if (empty($content['field_thumbnail_image'])) {
  $has_image = false;
}

?>
<div id="node-<?php print $node->nid; ?>"
     class="<?php print $classes; ?> node--quick-view clearfix"<?php print $attributes; ?>>
    <div class="node__quick-view <?php if ($has_image): ?>has-image<?php endif; ?> clearfix">
      <?php if ($has_image): ?>
          <div class="quick-view__image">
            <?php print render($content['field_thumbnail_image']); ?>
          </div>
      <?php endif; ?>

        <div class="quick-view__text">

          <?php print render($title_prefix); ?>
            <h2<?php print $title_attributes; ?>>
                <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
            </h2>
          <?php print render($title_suffix); ?>

          <?php print render($content['field_grade_levels']); ?>
          <?php print render($content['field_unit_title']); ?>
          <?php print render($content['field_lesson_number']); ?>
          <?php print render($content['body']); ?>
          <?php print render($content['field_activity_energy_content']); ?>

            <div class="more-details">
                <div class="more-details__icon">
                    <div class="icon__closed">+</div>
                    <div class="icon__open">-</div>
                </div>
                <dev class="more-details__text">
                    <span class="text__closed"><?php print t('More Details'); ?></span>
                    <span class="text__open"><?php print t('Less Details'); ?></span>
                </dev>
            </div>
        </div>
    </div>

    <div class="node__expanded-view">
      <?php print render($content['field_learning_goals_met']); ?>
      <?php print render($content['field_activity_education_science']); ?>
      <?php print render($content['field_activity_ngss_science']); ?>
      <?php
        $author = user_load($node->uid);
        $author_name = $author->realname;
      ?>
      <div class="field-wrapper field-author">
          <span class="field-label"><?php print t('Author'); ?>:</span>
          <div class="field field-name-author inline">
            <?php print render($author_name); ?>
          </div>
      </div>
      <?php print render($content['field_next_generation_science_st']); ?>
      <?php print render($content['field_activity_other_subjects']); ?>
      <?php print render($content['field_activity_length2']); ?>
    </div>
</div>
