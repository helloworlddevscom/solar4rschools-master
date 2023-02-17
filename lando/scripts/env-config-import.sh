#!/usr/bin/env bash

# This file is configured in .lando.yml. Run: lando env-config-import.
# It will run database updates, reverts features and clear caches
# on the chosen environment. This is useful if importing config did not succeed
# for whatever reason during the deploy process.

NORMAL="\033[0m"
RED="\033[31m"
YELLOW="\033[32m"
ORANGE="\033[33m"
PINK="\033[35m"
BLUE="\033[34m"

echo
echo -e "${RED}WARNING: This will affect a remote Pantheon environment."
echo
echo -e "${ORANGE}Are you sure you want to run database updates, revert features and clear caches on a remote Pantheon environment? (y/n):${BLUE}"
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
echo -e "${ORANGE}Enter the environment to import on (dev/test/live):${BLUE}"
echo
read REPLY_ENV
if [ "$REPLY_ENV" = "live" ] || [ "$REPLY_ENV" = "test" ] || [ "$REPLY_ENV" = "dev" ]
then
  if [ "$REPLY_ENV" = "live" ]
  then
    echo
    echo -e "${YELLOW}Are you sure you want to run databse updates, revert features and clear caches on prod? This will wipe out any config changes that are currently on prod. (y/n):${BLUE}"
    echo
    read REPLY_CONFIRM
    if [[ ! "$REPLY_CONFIRM" =~ ^[Yy]$ ]]
    then
      exit 1
    fi
  fi

  echo
  echo -e "${YELLOW}Running database updates, reverting features and clearing caches on $REPLY_ENV environment...${NORMAL}"
  echo

  terminus remote:drush solar4schools."$REPLY_ENV" -- updb -y

  echo
  echo -e "${YELLOW}Reverting features...${NORMAL}"
  echo

  terminus remote:drush solar4schools."$REPLY_ENV" -- fra -y

  echo
  echo -e "${YELLOW}Clearing caches...${NORMAL}"
  echo

  terminus remote:drush solar4schools."$REPLY_ENV" cc all

  echo
  echo -e "${YELLOW}Running drush fl and status so you know what's up...${NORMAL}"
  echo

  terminus remote:drush solar4schools."$REPLY_ENV" fl
  terminus remote:drush solar4schools."$REPLY_ENV" status
else
  echo
  echo -e "${RED}Please provide a valid env. Choose between 'dev', 'test', or 'live'.${NORMAL}"
  echo
  exit 1
fi
