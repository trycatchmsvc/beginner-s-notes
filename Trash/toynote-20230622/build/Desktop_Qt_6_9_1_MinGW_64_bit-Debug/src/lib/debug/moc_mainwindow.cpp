/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/lib/mainwindow.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "notebookFileNameChanged",
        "",
        "name",
        "notebookReady",
        "notebookCreated",
        "notebookOpened",
        "fileName",
        "notebookSaved",
        "notebookClosed",
        "windowClosing",
        "on_actionExit_triggered",
        "displayAbout",
        "newNotebook",
        "saveNotebook",
        "saveNotebookAs",
        "openNotebook",
        "closeNotebook",
        "discardNotebook",
        "newNote",
        "editNote",
        "QModelIndex",
        "idx",
        "deleteNotes",
        "refreshWindowTitle",
        "addNote",
        "Note",
        "note",
        "selectNote",
        "getNote",
        "Notebook::SizeType",
        "setNote",
        "notebookSize",
        "visitWebsite",
        "exit"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'notebookFileNameChanged'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'notebookReady'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'notebookCreated'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'notebookOpened'
        QtMocHelpers::SignalData<void(QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Signal 'notebookSaved'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'notebookClosed'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowClosing'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'on_actionExit_triggered'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'displayAbout'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'newNotebook'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'saveNotebook'
        QtMocHelpers::SlotData<bool()>(14, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'saveNotebookAs'
        QtMocHelpers::SlotData<bool()>(15, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'openNotebook'
        QtMocHelpers::SlotData<bool()>(16, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'closeNotebook'
        QtMocHelpers::SlotData<bool()>(17, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'discardNotebook'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'newNote'
        QtMocHelpers::SlotData<bool()>(19, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'editNote'
        QtMocHelpers::SlotData<bool(const QModelIndex &)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Slot 'deleteNotes'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'refreshWindowTitle'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'addNote'
        QtMocHelpers::SlotData<void(const Note &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Slot 'selectNote'
        QtMocHelpers::SlotData<void(int)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'getNote'
        QtMocHelpers::SlotData<void(Notebook::SizeType) const>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 30, 22 },
        }}),
        // Slot 'setNote'
        QtMocHelpers::SlotData<void(Notebook::SizeType, Note)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 30, 22 }, { 0x80000000 | 26, 27 },
        }}),
        // Slot 'notebookSize'
        QtMocHelpers::SlotData<Notebook::SizeType() const>(32, 2, QMC::AccessPublic, 0x80000000 | 30),
        // Slot 'visitWebsite'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'exit'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->notebookFileNameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->notebookReady(); break;
        case 2: _t->notebookCreated(); break;
        case 3: _t->notebookOpened((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->notebookSaved(); break;
        case 5: _t->notebookClosed(); break;
        case 6: _t->windowClosing(); break;
        case 7: _t->on_actionExit_triggered(); break;
        case 8: _t->displayAbout(); break;
        case 9: _t->newNotebook(); break;
        case 10: { bool _r = _t->saveNotebook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->saveNotebookAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->openNotebook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->closeNotebook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->discardNotebook(); break;
        case 15: { bool _r = _t->newNote();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->editNote((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->deleteNotes(); break;
        case 18: _t->refreshWindowTitle(); break;
        case 19: _t->addNote((*reinterpret_cast< std::add_pointer_t<Note>>(_a[1]))); break;
        case 20: _t->selectNote((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->getNote((*reinterpret_cast< std::add_pointer_t<Notebook::SizeType>>(_a[1]))); break;
        case 22: _t->setNote((*reinterpret_cast< std::add_pointer_t<Notebook::SizeType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Note>>(_a[2]))); break;
        case 23: { Notebook::SizeType _r = _t->notebookSize();
            if (_a[0]) *reinterpret_cast< Notebook::SizeType*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->visitWebsite(); break;
        case 25: _t->exit(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QString )>(_a, &MainWindow::notebookFileNameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::notebookReady, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::notebookCreated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QString )>(_a, &MainWindow::notebookOpened, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::notebookSaved, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::notebookClosed, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::windowClosing, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::on_actionExit_triggered, 7))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::notebookFileNameChanged(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MainWindow::notebookReady()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::notebookCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::notebookOpened(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void MainWindow::notebookSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::notebookClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::windowClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::on_actionExit_triggered()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
