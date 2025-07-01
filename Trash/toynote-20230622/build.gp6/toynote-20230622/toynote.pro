TEMPLATE = subdirs
SUBDIRS = \
    testlib \
    tests \
    lib \
    app
testlib.subdir = src/testlib
tests.subdir = src/tests
tests.depends = lib testlib
lib.subdir = src/lib
app.subdir = src/app
app.depends = lib
