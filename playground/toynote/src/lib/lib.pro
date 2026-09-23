QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

TARGET = toynotelib

SOURCES += \
    mainwindow.cpp \
    notebook.cpp \
    note.cpp \
    editnotedialog.cpp

HEADERS  += \
    mainwindow.hpp \
    notebook.hpp \
    note.hpp \
    config.hpp \
    editnotedialog.hpp \
    toynote_global.hpp

FORMS    += \
    mainwindow.ui \
    editnotedialog.ui

RESOURCES += \
    resources.qrc

CONFIG += c++17

TRANSLATIONS += toynote_ru_RU.ts \
                toynote_en_US.ts

DEFINES += TOYNOTELIB_LIBRARY
