<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Purpose](#purpose)
- [Project branch strategy](#project-branch-strategy)
- [Recommended versions](#recommended-versions)
- [Codebase](#codebase)
- [Pantheon](#pantheon)
- [External resources](#external-resources)
- [Local dev setup using Lando](#local-dev-setup-using-lando)
  - [(Step 1) Install Lando and Docker Desktop](#step-1-install-lando-and-docker-desktop)
  - [(Step 2) Git clone the repo](#step-2-git-clone-the-repo)
  - [(Step 3) Git config](#step-3-git-config)
  - [(Step 4) Create settings.local.php](#step-4-create-settingslocalphp)
    - [If you are setting up this project via Lando after already having it running via localhost](#if-you-are-setting-up-this-project-via-lando-after-already-having-it-running-via-localhost)
  - [(Step 5) Configure /etc/hosts](#step-5-configure-etchosts)
  - [(Step 6) Lando start](#step-6-lando-start)
  - [(Step 7) Get an account on production](#step-7-get-an-account-on-production)
  - [(Step 8) Get a Pantheon account](#step-8-get-a-pantheon-account)
  - [(Step 9) Configure Pantheon machine token and authorize via Terminus](#step-9-configure-pantheon-machine-token-and-authorize-via-terminus)
  - [(Step 10) Pull and import database from production](#step-10-pull-and-import-database-from-production)
  - [(Step 11) Test your site](#step-11-test-your-site)
  - [(Step 12) Resolve broken images](#step-12-resolve-broken-images)
  - [(Step 13) Reindex Solr](#step-13-reindex-solr)
- [Lando basics](#lando-basics)
- [Lando project specific commands](#lando-project-specific-commands)
  - [lando db-pull](#lando-db-pull)
  - [lando files-pull](#lando-files-pull)
  - [lando drupal-config-import](#lando-drupal-config-import)
  - [lando drupal-solr-reindex](#lando-drupal-solr-reindex)
  - [lando env-deploy](#lando-env-deploy)
  - [lando env-config-import](#lando-env-config-import)
  - [lando env-solr-reindex](#lando-env-solr-reindex)
- [Pushing a new branch](#pushing-a-new-branch)
- [Pull Requests](#pull-requests)
- [Terminus](#terminus)
  - [Using Drush with Terminus](#using-drush-with-terminus)
    - [Check state of Features on Dev environment](#check-state-of-features-on-dev-environment)
    - [Run database updates on Dev environment](#run-database-updates-on-dev-environment)
    - [Revert all Features on Dev environment](#revert-all-features-on-dev-environment)
- [Logging into MySQL on Dev, Test or Prod environments.](#logging-into-mysql-on-dev-test-or-prod-environments)
- [Deployment](#deployment)
  - [Deploy to Dev](#deploy-to-dev)
    - [(Optional) After deploying to Dev:](#optional-after-deploying-to-dev)
  - [Deploy to Test/Staging or Live/Production](#deploy-to-teststaging-or-liveproduction)
    - [(Option 1, recommended) Lando deploy script](#option-1-recommended-lando-deploy-script)
    - [(Option 2) Pantheon dashboard](#option-2-pantheon-dashboard)
      - [Test](#test)
      - [Live/Prod](#liveprod)
- [Updating Drupal Core](#updating-drupal-core)
- [Updating contrib modules](#updating-contrib-modules)
- [Location of contrib modules](#location-of-contrib-modules)
- [Location of custom modules and Features](#location-of-custom-modules-and-features)
  - [Custom modules:](#custom-modules)
  - [Features:](#features)
- [Theme](#theme)
  - [Location of Drupal theme directory](#location-of-drupal-theme-directory)
  - [Compiling SASS/.scss](#compiling-sassscss)
    - [To compile:](#to-compile)
    - [To watch for changes and compile:](#to-watch-for-changes-and-compile)
  - [Media queries](#media-queries)
- [Locus Energy API](#locus-energy-api)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->


# Purpose

Drupal 7 website for CEBF (Clean Energy Bright Futures) (http://www.cebrightfutures.org/).


# Project branch strategy

    master                            :: Push automatically deploys to Dev env.
    CEBF-ticket-number-description    :: Feature branch corresponding to a Jira ticket. Branch off of master and create a PR to merge back in.


# Recommended versions

    PHP         :: 7.4 (installed automatically by Lando)
    Node        :: 11.0.0 (installed automatically by Lando)
    Drush       :: 8.x (installed automatically by Lando)


# Codebase

Although the site is hosted on Pantheon, we have a fork of the Pantheon repo on GitHub (which you're probably looking at now).
Please clone this instead of the Pantheon repo, although both should work.
https://github.com/HelloWorldDevs/solar4rschools

Pantheon has it's own Git repo. You can get a link to clone it here:
https://dashboard.pantheon.io/sites/727f67e7-eb02-409e-bae8-83c38874da94#dev/code


# Pantheon

This site is hosted on Pantheon. Pantheon provides a Dashboard from which you can manage deploys, create database backups etc.

Pantheon Dashboard:
https://dashboard.pantheon.io/sites/727f67e7-eb02-409e-bae8-83c38874da94#dev/code


# External resources

* Environments:
  * Dev: http://dev-solar4schools.pantheonsite.io/
  * Test: http://test-solar4schools.pantheonsite.io/
  * Prod/Live: https://www.cebrightfutures.org
* Pantheon dashboard: https://dashboard.pantheon.io/sites/727f67e7-eb02-409e-bae8-83c38874da94#dev/code


# Local dev setup using Lando


## (Step 1) Install Lando and Docker Desktop

Follow the recommended instructions for installing Lando if you haven't already. Docker Desktop will be installed as well.

https://docs.lando.dev/basics/installation.html#macos


## (Step 2) Git clone the repo

`git clone` the Github repo into whichever directory you prefer.

`cd` into the repo/project root.


## (Step 3) Git config

Modify your `.git/config` to match the following, replacing any existing remotes or `master` branch. This is an attempt to keep the Pantheon and Github repos in sync.

```
[checkout]
	defaultRemote = github
[remote "github"]
	url = git@github.com:HelloWorldDevs/solar4rschools.git
	fetch = +refs/heads/*:refs/remotes/github/*
	pushurl = ssh://codeserver.dev.727f67e7-eb02-409e-bae8-83c38874da94@codeserver.dev.727f67e7-eb02-409e-bae8-83c38874da94.drush.in:2222/~/repository.git
	pushurl = git@github.com:HelloWorldDevs/solar4rschools.git
[remote "pantheon"]
	url = ssh://codeserver.dev.727f67e7-eb02-409e-bae8-83c38874da94@codeserver.dev.727f67e7-eb02-409e-bae8-83c38874da94.drush.in:2222/~/repository.git
	fetch = +refs/heads/*:refs/remotes/pantheon/*
	pushurl = git@github.com:HelloWorldDevs/solar4rschools.git
	pushurl = ssh://codeserver.dev.727f67e7-eb02-409e-bae8-83c38874da94@codeserver.dev.727f67e7-eb02-409e-bae8-83c38874da94.drush.in:2222/~/repository.git
[branch "master"]
	remote = github
	merge = refs/heads/master
	rebase = true
```


## (Step 4) Create settings.local.php

Run:

```
cp docroot/sites/default/default.settings.local.php docroot/sites/default/settings.local.php
```

### If you are setting up this project via Lando after already having it running via localhost

If you are setting up this project via Lando after already having it running via localhost
Make note of your localhost database creds in `local_settings.php` and copy them to `settings.local.php`. Now delete `local_settings.php`. Your localhost setup should continue to work. I’m trying to deprecate `local_settings.php` in favor of `settings.local.php` to make the naming of this file consistent across projects.


## (Step 5) Configure /etc/hosts

Edit `/etc/hosts` on your local machine. Add this line:

```
127.0.0.1				cebf.lando
```

Normally Lando will create site URLs in the format *.lndo.site. Because of the proxy settings we have in `.lando.yml`, those won’t be created. Instead we’ll have this nicer URL, but the trade off is we have to add it to our `/etc/hosts` file.


## (Step 6) Lando start

Run:

```
lando start
```

The first time you run this it will take a while. Eventually you’ll be given some URLs to access the site, however they will not work yet because we haven’t pulled the database yet. Lando attempts to create URLs based on the available ports on your machine. The URLs that will be most reliable/consistent will be https://cebf.lando or http://cebf.lando, however you may find that they are instead https://cebf.lando:444/ or http://cebf.lando:8000/. Make note of whatever URLs you’re given so we can try them later.


## (Step 7) Get an account on production

Ask another developer on this project to create you an account on production. This way when you pull the production database you’ll be able to login.

## (Step 8) Get a Pantheon account

Ask another developer to invite you to the Pantheon team.

## (Step 9) Configure Pantheon machine token and authorize via Terminus

**Note:** This step is necessary because we are using the `drupal7` Lando recipe instead of `pantheon`. See `.lando.yml` for more info.

Configure a machine token in your Pantheon account following this documentation. It would make sense to name the token "CEBF - Lando".

https://pantheon.io/docs/machine-tokens

After creating the machine token, copy it and run:

```
lando ssh
terminus auth:login --machine-token=YOUR_MACHINE_TOKEN
exit
```

This will allow you to use `lando db-pull`.

You'll likely need to do this step again if you ever run `lando destroy`.


## (Step 10) Pull and import database from production

To pull and import the database from production, run:

```
lando db-pull
```

Choose `live`.

## (Step 11) Run database updates, revert features and clear caches

To run database updates, revert features and clear caches, run:

```
cd web
```

```
lando drupal-config-import
```

This is a wrapper around `drush updb -y; drush fra -y; drush cc all`. You could call these directly instead.

_Always run one of these commands after pulling the database from a remote environment._

## (Step 11) Test your site

Go to one of the URLs Lando gave you in Step 6. If using Chrome you may have to use the “Advanced” option to bypass the SSL warning. For some reason Chrome does not like the way Lando signs SSL certificates. You will only have to do this the first time you visit the site after running lando start.

The site should load, however most images will be broken. Lets fix that.


## (Step 12) Resolve broken images

In order to conserve space on your machine, it is not recommended to pull the `sites/default/files` directory. (However, you can do it with `lando files-pull`.)

Instead, we highly recommend you proxy images from production using the [Resource Override Chrome plugin](https://helloworlddevs.atlassian.net/wiki/spaces/HWD/pages/1208877057/Developer+Tools#Resource-Override).

After installing, configuring and enabling Resource Override, refresh your site. You should see images.


## (Step 13) Reindex Solr

To reindex Solr run:

```
lando drupal-solr-reindex
```

# Lando basics

https://helloworlddevs.atlassian.net/wiki/spaces/HWD/pages/1635418113/Lando+basics


# Lando project specific commands

Run `lando` for a full list of commands.

## lando db-pull
```
lando db-pull
```
Pulls and imports the database from a remote Pantheon environment.

## lando files-pull
```
lando files-pull
```
Pulls files directory from a remote Pantheon environment.

## lando drupal-config-import
```
lando drupal-config-import
```
Runs database updates, reverts features and clears caches on your local Lando environment.

## lando drupal-solr-reindex
```
lando drupal-solr-reindex
```
Reindexes Solr on your local Lando environment.

## lando env-deploy
```
lando env-deploy
```
Deploys to Test or Live Pantheon environment (deploys code, updates database, reverts features and clears caches).

## lando env-config-import
```
lando env-config-import
```
Runs database updates, reverts features and clears caches on a remote Pantheon environment.

## lando env-solr-reindex
```
lando env-solr-reindex
```
Reindexes Solr on a remote Pantheon environment.


# Drush

_NOTE: In order to run a Drush command, you must be in `web`._

Drush is a CLI tool for Drupal. Lando installs it automatically and you can use it by running:

```
lando drush COMMAND
```

## Useful Drush commands

### Clear caches

```
lando drush cc all
```

### Run database updates

```
lando drush updb -y
```

### Revert features

```
lando drush fra -y
```

### Update features

```
lando drush fu -y
```

### List installed modules

```
lando drush pm-list
```


# Pushing a new branch

To push a new branch, follow this format:

```
git push -u github CEBF-428-resource-library
```

# Pull Requests

We have in the past worked in a PR workflow but not recently. A PR workflow should be compatible with the changes to `.git/config`,
however some extra work will be necessary after merging the PR:

Pull the `master` branch and then push it. This will pull the merged commits from `github` remote and push them to `pantheon` remote.


# Terminus

Terminus is a CLI tool for Pantheon. We install it into the main Lando container during the build process.

It's likely you'll never have to use Terminus directly. You'll hopefully find that you can accomplish what you need by running `lando` and choosing a command from the list.

To use it, run:

```
lando ssh
```

```
terminus
```

## Using Drush with Terminus

You can use Terminus to run Drush commands on different Pantheon environments. The possible environments are dev, test and live.

### Check state of Features on Dev environment

```
terminus drush solar4schools.dev -- fd
```

### Run database updates on Dev environment

```
terminus drush solar4schools.dev -- updb -y
```

### Revert all Features on Dev environment

```
terminus drush solar4schools.dev -- fra all
```

# Logging into MySQL on Dev, Test or Prod environments.

You can login to MySQL by copying and running a login command found in the Pantheon Dashboard.
When in an environment tab, click the "Connection Info" button at the top right and copy the "Command Line" command.


# Deployment

## Deploy to Dev

Deployment to the Dev environment occurs automatically whenever the Pantheon ```master``` branch is pushed to.
Running ```git push``` while on the ```master``` branch should push to Pantheon and deploy to Dev.

There shouldn’t be anything else that you need to do. Database updates, features revert and cache clear will be run automatically. This is accomplished via a QuickSilver script at `web/private/scripts/quicksilver/drush_update_import.sh` and configured in `pantheon.yml` to hook into Pantheon workflows.

### (Optional) After deploying to Dev:

If it seems that the QuickSilver script did not revert a feature, you can run these commands manually:

```
lando ssh
```

```
terminus drush solar4schools.dev -- updb -y; terminus drush solar4schools.dev -- fra -y; terminus drush solar4schools.dev -- cc all
```

Please check whether features have been properly reverted by running:

```
terminus drush solar4schools.dev -- fl
```

## Deploy to Test/Staging or Live/Production

### (Option 1, recommended) Lando deploy script

The easiest way to deploy to Test or Live is to use the script we’ve configured in `.lando.yml`.

Run this from anywhere inside your project directory:

```
lando env-deploy
```

You’ll be asked which environment you want to deploy to. Enter either test and live.

The script is a wrapper for Terminus commands and will deploy, run database updates, revert features and clear caches for you. There shouldn’t be anything else you need to do.

### (Option 2) Pantheon dashboard

You could also deploy to Test or Live using the Pantheon Dashboard. However you will need to run Terminus Drush commands afterward to import config, because Pantheon does not provide an option to do this through the Dashboard.

#### Test

Go to https://dashboard.pantheon.io/sites/727f67e7-eb02-409e-bae8-83c38874da94#test/deploys

If there are commits to deploy, you should see an option to run the deploy there. Feel free to check the options to run database updates and clear caches, however you will also do this via Terminus Drush just to  be safe.

**After the deploy finishes, run these Terminus Drush commands:**

```
lando ssh
```

```
terminus drush solar4schools.test -- updb -y; terminus drush solar4schools.test -- fra -y; terminus drush solar4schools.test -- cc all
```

Please check whether Features have been properly reverted by running:

```
terminus drush solar4schools.test -- fl
```

#### Live/Prod

Go to https://dashboard.pantheon.io/sites/727f67e7-eb02-409e-bae8-83c38874da94#live/deploys

If there are commits to deploy, you should see an option to run the deploy there. Feel free to check the options to run database updates and clear caches, however you will also do this via Terminus Drush just to  be safe.

**After the deploy finishes, run these Terminus Drush commands:**

```
lando ssh
```

```
terminus drush solar4schools.live -- updb -y; terminus drush solar4schools.live -- fra -y; terminus drush solar4schools.live -- cc all;
```

Please check whether Features have been properly reverted by running:

```
terminus drush solar4schools.live -- fl
```


# Updating Drupal Core

Because we are using Pantheon, updating Drupal Core is extra complicated. Pantheon has their own modified version of core that we need to use.
The best way to update core seems to be to download Pantheon's repo as a zip and then copy and paste files/directories to overwrite our current ones:

https://github.com/pantheon-systems/drops-7

In Github, pay attention to the last time the file/directory was updated.
Assuming we've kept up with regular updates, you may only need to copy and paste the files/directories that have changed recently.

_DO NOT_ overwrite the `/profiles` directory, because it contains the custom theme and modules.

In theory we _should_ be able to update Drupal Core from the Pantheon dashboard, but something appears to be preventing that option.

After replacing the files/directories, run `lando drush updb -y` to run database updates.

Run `lando drush status` to check the version of core reported is what you expect.

Poke around the site locally. If all looks fine, you should be ok to commit and deploy.


# Updating Drupal contrib modules

## Download update using Drush

To update a module, run:

`drush pm-update MODULE_NAME`

## Reapply module patches

Patches to various contrib modules can be found in the `patches` directory.
After updating a module, be sure to reapply any patches by running from project root:

`patch -p1 < patches/PATCH_NAME.patch`

# Location of contrib modules

You can find contrib modules in multiple places. This is most likely a mistake, but so it goes.

```profiles/s4rs/modules/contrib```

```sites/all/modules/contrib```


# Location of custom modules and Features

You can find custom modules and Features in multiple places. This is most likely a mistake, but so it goes.

## Custom modules:

```profiles/s4rs/modules/custom```

```sites/all/modules/custom```

## Features:

```profiles/s4rs/modules/features```

```sites/all/modules/features```

# Theme

The CSS for this site is a mess. In 2019 Ben began slowly moving chunks of CSS from the massive `style.css` file
and into separate .scss files located inside the `scss` directory inside the theme directory. There is still a ton of work to be done.

## Location of Drupal theme directory

The location of the theme directory is different than most Drupal 7 projects. It is located inside of a profile:

```profiles/s4rs/themes/flare```

## Compiling SASS/.scss

### To compile:

`lando gulp build`

### To watch for changes and compile:

`lando gulp watch`

## Media queries

If working inside of a .scss file, please use the `breakpoint()` mixin to create a media query like so:

```
@include breakpoint($bp--medium) {

}
```

Inside of `_variables.scss` are all the possible breakpoint variables that can be used.


# Locus Energy API

Kiosk sites that use the Locus Energy API function differently than other kiosks after the refactor that occurred in May 2018.
Instead of calling the API whenever a kiosk graph is loaded, the API is only called by a cron job which stores the data in the ```locus_api_data``` table. This was done to reduce API calls.

The cron will not run locally unless you manually override it with this line in your ```local_settings.php```:

```
$conf['locus_energy_cron_force_run'] = TRUE;
```

To enable the cron a Pantheon environment:

```
lando ssh
```

```
terminus drush 'vset locus_energy_cron_force_run TRUE' --site=solar4schools --env=test
```

To disable the cron a Pantheon environment:

```
lando ssh
```


```
terminus drush 'vset locus_energy_cron_force_run FALSE' --site=solar4schools --env=test
```

When done testing, ALWAYS set this variable to FALSE to avoid unnecessary API calls.

