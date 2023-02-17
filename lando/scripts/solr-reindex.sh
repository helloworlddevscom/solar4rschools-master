#!/usr/bin/env bash

# This file is configured in .lando.yml. Run: lando drupal-solr-reindex.
# It will reindex Solr on your local Lando env.

NORMAL="\033[0m"
RED="\033[31m"
YELLOW="\033[32m"
ORANGE="\033[33m"
PINK="\033[35m"
BLUE="\033[34m"

echo
echo -e "${ORANGE}Are you sure you want to reindex Solr on your local Lando environment? (y/n):${BLUE}"
echo
read REPLY
if [[ ! "$REPLY" =~ ^[Yy]$ ]]
then
  exit 1
fi

echo
echo -e "${YELLOW}Reindexing Solr...${NORMAL}"
echo

drush search-api-reindex

echo
echo -e "${YELLOW}Clearing caches...${NORMAL}"
echo

drush cc all
