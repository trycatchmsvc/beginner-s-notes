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

TRANSLATIONS += translations/toynote_ru_RU.ts \
                translations/toynote_en_US.ts
