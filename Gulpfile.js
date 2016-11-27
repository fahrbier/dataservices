var gulp = require('gulp');
var concat = require('gulp-concat');
var insert = require('gulp-insert');
var mustache = require("gulp-mustache");
var rename = require("gulp-rename");

gulp.task('default', function() {

    return gulp.src([
        './data/data*.inc',
        './services/*service.inc',
    ]).pipe(concat('/services.inc')).pipe(insert.wrap('<%', '%>')).pipe(gulp.dest('./dist/'));

});

var dateNow = new Date();
 
gulp.task('writedataclasses', function() {
    
    nameClass = "Person";    
    gulp.src("data/template/dataClass.inc")
        .pipe( mustache( 
                         { 
                             "todaysDate" : dateNow.getFullYear() + '-' + (dateNow.getMonth()+1) + '-' + dateNow.getDate(), 
                             "name" : nameClass, 
                             "properties" : [ 
                                 {"name": "id",       "ccname": "Id",       "type": "string",  "last":false}, 
                                 {"name": "forename", "ccname": "Forename", "type": "string",  "last":false}, 
                                 {"name": "surname",  "ccname": "Surname",  "type": "string",  "last":false}, 
                                 {"name": "age",      "ccname": "Age",      "type": "integer", "last":true} 
                             ]
                         } 
        ))
        .pipe(rename('data'+ nameClass +'.inc'))
        .pipe( gulp.dest('data') );        

    nameClass = "Landmark";            
    gulp.src("data/template/dataClass.inc")
        .pipe( mustache( 
                         { 
                             "todaysDate" : dateNow.getFullYear() + '-' + (dateNow.getMonth()+1) + '-' + dateNow.getDate(), 
                             "name" : nameClass, 
                             "properties" : [ 
                                 {"name": "id",        "ccname": "Id",        "type": "string",  "last":false}, 
                                 {"name": "name",      "ccname": "Name",      "type": "real",    "last":false}, 
                                 {"name": "longitude", "ccname": "Longitude", "type": "real",    "last":false}, 
                                 {"name": "latitude",  "ccname": "Latitude",  "type": "integer", "last":true} 
                             ]
                         } 
        ))
        .pipe(rename('data'+ nameClass +'.inc'))
        .pipe( gulp.dest('data') );    

    nameClass = "News";            
    gulp.src("data/template/dataClass.inc")
        .pipe( mustache( 
                         { 
                             "todaysDate" : dateNow.getFullYear() + '-' + (dateNow.getMonth()+1) + '-' + dateNow.getDate(), 
                             "name" : nameClass, 
                             "properties" : [ 
                                 {"name": "id",          "ccname": "Id",          "type": "string", "last":false}, 
                                 {"name": "dateNews",    "ccname": "DateNews",    "type": "date",   "last":false}, 
                                 {"name": "headline",    "ccname": "Headline",    "type": "string", "last":false}, 
                                 {"name": "idSupplier",  "ccname": "IdSupplier",  "type": "string", "last":false},
                                 {"name": "dateCreated", "ccname": "DateCreated", "type": "date",   "last":true}
                             ]
                         } 
        ))
        .pipe(rename('data'+ nameClass +'.inc'))
        .pipe( gulp.dest('data') );    

        
});