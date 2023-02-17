#!/usr/bin/env bash

# This file is configured in .lando.yml. Run: lando drupal-config-import.
# It will run database updates, revert features and clear caches
# on your local Lando environment.

NORMAL="\033[0m"
RED="\033[31m"
YELLOW="\033[32m"
ORANGE="\033[33m"
PINK="\033[35m"
BLUE="\033[34m"

echo
echo -e "${ORANGE}Are you sure you want to run database updates, revert features and clear caches on your local Lando environment? (y/n):${BLUE}"
echo
read REPLY
if [[ ! "$REPLY" =~ ^[Yy]$ ]]
then
  exit 1
fi

echo
echo -e "${YELLOW}Running database updates, reverting features and clearing caches...${NORMAL}"
echo

drush updb -y

echo
echo -e "${YELLOW}Reverting features...${NORMAL}"
echo

drush fra -y

echo
echo -e "${YELLOW}Clearing caches...${NORMAL}"
echo

drush cc all

echo
echo -e "${YELLOW}Running drush fl and status so you know what's up...${NORMAL}"
echo

drush fl
drush status
