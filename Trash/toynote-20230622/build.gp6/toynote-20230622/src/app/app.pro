QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET = toynote

SOURCES = main.cpp

BUILD_SUBDIR =
win32 {
    CONFIG(release, debug|release):BUILD_SUBDIR = release/
    CONFIG(debug, debug|release):BUILD_SUBDIR = debug/
}
LIBS += -L../lib/$${BUILD_SUBDIR} -ltoynotelib

INCLUDEPATH = ../lib

CONFIG += c++17
