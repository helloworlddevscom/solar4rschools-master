#!/usr/bin/env bash

# This file is configured in .lando.yml. Run: lando env-solr-reindex.
# It will reindex Solr on an environment.

echo
echo -e "${RED}WARNING: This will affect a remote Pantheon environment."
echo
echo -e "${ORANGE}Are you sure you want to reindex Solr on a remote Pantheon environment? (y/n):${BLUE}"
echo
read REPLY
if [[ ! "$REPLY" =~ ^[Yy]$ ]]
then
  exit 1
fi

echo
echo -e "${ORANGE}Enter your Pantheon account email. You will need a machine token configured in your Pantheon account for this to work:${BLUE}"
echo
read REPLY_EMAIL
echo

terminus auth:login --email "$REPLY_EMAIL"

echo
echo -e "${ORANGE}Enter the environment to reindex Solr on (dev/test/live):${BLUE}"
echo
read REPLY_ENV
if [ "$REPLY_ENV" = "live" ] || [ "$REPLY_ENV" = "test" ] || [ "$REPLY_ENV" = "dev" ]
then
  if [ "$REPLY_ENV" = "live" ]
  then
    echo
    echo -e "${YELLOW}Are you sure you want to reindex Solr on prod? (y/n):${BLUE}"
    echo
    read REPLY_CONFIRM
    if [[ ! "$REPLY_CONFIRM" =~ ^[Yy]$ ]]
    then
      exit 1
    fi
  fi

  echo
  echo -e "${YELLOW}Reindexing Solr...${NORMAL}"
  echo

  terminus remote:drush solar4schools."$REPLY_ENV" search-api-clear
  terminus remote:drush solar4schools."$REPLY_ENV" search-api-reindex
else
  echo
  echo -e "${RED}Please provide a valid env. Choose between 'dev', 'test', or 'live'.${NORMAL}"
  echo
  exit 1
fi


