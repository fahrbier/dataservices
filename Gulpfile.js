var gulp = require('gulp');
var concat = require('gulp-concat');
var insert = require('gulp-insert');


gulp.task('default', function() {

    return gulp.src([
        './data/data*.inc',
        './services/*service.inc',
    ]).pipe(insert.wrap('<%', '%>')).pipe(concat('/services.inc')).pipe(gulp.dest('./dist/'));

});
