<?php
/**
 * @file
 * Basic cart shopping cart block
 */
?>

<?php if (empty($cart)): ?>
  <p><?php print t('No materials selected.'); ?></p>
<?php else: ?>
  <div class="basic-cart-grid basic-cart-block">
    <?php if(is_array($cart) && count($cart) >= 1): ?>
      <?php foreach($cart as $nid => $node): ?>
        <div class="basic-cart-cart-contents row">
          <div class="basic-cart-cart-node-title cell"><?php print $node->title . ' (' . $node->basic_cart_quantity . ')'; ?></div>
          <div class="basic-cart-delete-image cell">
            <a href="/cart/remove/<?php print $nid; ?>"><img class="basic-cart-delete-image-image" title="<?php print t('Remove from Cart');?>" alt="<?php print t('Remove from cart'); ?>" src="<?php print base_path() . drupal_get_path('module', 'basic_cart') . '/images/delete2.png'; ?>" /></a>
          </div>
          <?php if ($node->basic_cart_unit_price > 0): ?>
          <div class="basic-cart-cart-x cell">Points-per-unit:</div>
          <div class="basic-cart-cart-unit-price cell">
            <?php print str_replace('.00 points', '', basic_cart_price_format($node->basic_cart_unit_price)); ?>
          </div>
          <?php endif; ?>

        </div>
      <?php endforeach; ?>
      <div class="basic-cart-cart-total-price-contents row">
        <?php if ($price > 0): ?>
        <div class="basic-cart-total-price cell">
          <?php print t('Total points'); ?>: <?php print str_replace('.00 points', '', $price); ?>
        </div>
        <?php endif; ?>
      </div>
      <?php if (!empty ($vat)): ?>
        <div class="basic-cart-block-total-vat-contents row">
          <div class="basic-cart-total-vat cell"><?php print t('Total VAT'); ?>: <strong><?php print $vat; ?></strong></div>
        </div>
      <?php endif; ?>
      <div class="basic-cart-cart-view-button basic-cart-cart-button-block row">
        <?php print l(t('Manage my materials list'), 'cart', array('attributes' => array('class' => array('button')))); ?>
      </div>
      <div class="basic-cart-cart-checkout-button basic-cart-cart-button-block row">
        <?php print l(t('Submit my materials list for review and approval'), 'checkout', array('attributes' => array('class' => array('button')))); ?>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
