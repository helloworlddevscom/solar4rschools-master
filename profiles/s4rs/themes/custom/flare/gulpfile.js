/**
 * Gulp File
 *
 * To compile SCSS: gulp build-css
 * // To minify JS: gulp build-js (No JS task yet)
 * To compile/minify all: gulp build
 * To compile/minify and watch SCSS and JS: gulp watch
 * To run sass-lint on SCSS: gulp lint-scss
 */

'use strict';
// Include gulp.
const gulp = require('gulp');

const sass = require('gulp-sass');
const shell = require('gulp-shell');
const plumber = require('gulp-plumber');
const notify = require('gulp-notify');
const autoprefix = require('gulp-autoprefixer');
const glob = require('gulp-sass-glob');
const minifycss = require('gulp-clean-css');
// const minifyjs = require('gulp-minify');
// const uglify = require('gulp-uglify');
// const concat = require('gulp-concat');
const rename = require('gulp-rename');
const sassLint = require('gulp-sass-lint');
const sourcemaps = require('gulp-sourcemaps');
const watch = require('gulp-watch');
const addsrc = require('gulp-add-src');

// Task: Compile CSS.
gulp.task('compile-css', function() {
  return gulp
    .src('./scss/style.scss')
    .pipe(
      plumber({
        errorHandler: function(error) {
          notify.onError({
            title: 'Gulp',
            subtitle: 'Failure!',
            message: 'Error: <%= error.message %>',
            sound: 'Beep'
          })(error);
          this.emit('end');
        },
      })
    )
    .pipe(sourcemaps.init())
    .pipe(glob())
    .pipe(
      sass({
        includePaths: ['node_modules/breakpoint-sass/stylesheets'],
        errLogToConsole: true,
      })
    )
    .pipe(
      autoprefix({
        Browserslist: ['last 25 versions'],
      })
    )
    .pipe(minifycss())
    .pipe(rename({ suffix: '.min' }))
    .pipe(sourcemaps.write('.'))
    .pipe(gulp.dest('./build/css'));
});

// Task: Lint SCSS files using sass-lint.
gulp.task('lint-scss', function() {
  return gulp
    .src(['./scss/**/*.scss'])
    .pipe(sassLint({
      options: {
        configFile: './.sass-lint.yml',
        formatter: 'stylish'
      },
    }))
    .pipe(sassLint.format())
    .pipe(sassLint.failOnError())
});

// Task: Build CSS and run sass-lint to notify of any errors (but not fix them).
gulp.task('build-css', gulp.series('compile-css', 'lint-scss'));

// JS
// gulp.task('build-js', function() {
//   gulp.src(['./js/global.js'])
//     .pipe(concat('global.js'))
//     .pipe(minifyjs())
//     .pipe(uglify())
//     .pipe(rename({suffix: '.min'}))
//     .pipe(gulp.dest('./build/js'));
// });

// Task: Build both CSS and JS. (No JS task yet).
gulp.task('build', gulp.series('build-css'));

// Task: Run drush to clear the theme registry.
gulp.task('drush', shell.task(['drush cache-clear theme-registry']));

// Task: Watch both CSS and JS.
gulp.task('watch', function() {
  gulp.watch('./scss/**/*.scss', gulp.series('build-css'));
});

// Task: Default task.
gulp.task('default', gulp.series('build-css', 'watch'));
