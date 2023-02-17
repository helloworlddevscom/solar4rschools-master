<?php

/**
 * This file is configured in pantheon.yml. It is run whenever
 * the Pantheon sync_code, deploy and clone_database workflows occur.
 * It will automatically run database updates, revert features and clear caches
 * on any environment where the triggering workflow occurs.
 */

// Run database updates.
echo "Running database updates..\n";
passthru('drush updb -y');
echo "Database updates complete.";

// Import all config changes.
echo "Reverting features...\n";
passthru('drush fra -y');
echo "Features revert complete.\n";

// Clear all caches.
echo "Rebuilding cache.\n";
passthru('drush cc all');
echo "Rebuilding cache complete.\n";
