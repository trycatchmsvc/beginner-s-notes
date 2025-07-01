QT += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

CONFIG += c++17

BUILD_SUBDIR =
win32 {
    CONFIG(release, debug|release):BUILD_SUBDIR = release/
    CONFIG(debug, debug|release):BUILD_SUBDIR = debug/
}
LIBS += -L../../lib/$${BUILD_SUBDIR} -ltoynotelib -L../../testlib/$${BUILD_SUBDIR} -ltestlib

INCLUDEPATH += ../../lib ../../testlib
