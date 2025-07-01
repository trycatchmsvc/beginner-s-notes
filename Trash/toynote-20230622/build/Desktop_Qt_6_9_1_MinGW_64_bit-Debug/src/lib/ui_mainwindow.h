/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Notebook;
    QAction *actionNew_Note;
    QAction *actionDelete_Notes;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionOpen_Notebook;
    QAction *actionClose_Notebook;
    QAction *actionSave_As;
    QAction *actionVisit_Website;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *notesView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        actionNew_Notebook = new QAction(MainWindow);
        actionNew_Notebook->setObjectName("actionNew_Notebook");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Notebook-new.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew_Notebook->setIcon(icon);
        actionNew_Note = new QAction(MainWindow);
        actionNew_Note->setObjectName("actionNew_Note");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Note-add.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew_Note->setIcon(icon1);
        actionDelete_Notes = new QAction(MainWindow);
        actionDelete_Notes->setObjectName("actionDelete_Notes");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/Note-remove.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDelete_Notes->setIcon(icon2);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/Notebook-save.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon3);
        actionOpen_Notebook = new QAction(MainWindow);
        actionOpen_Notebook->setObjectName("actionOpen_Notebook");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/Notebook-open.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen_Notebook->setIcon(icon4);
        actionClose_Notebook = new QAction(MainWindow);
        actionClose_Notebook->setObjectName("actionClose_Notebook");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/Notebook-save-as.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave_As->setIcon(icon5);
        actionVisit_Website = new QAction(MainWindow);
        actionVisit_Website->setObjectName("actionVisit_Website");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        notesView = new QTableView(centralWidget);
        notesView->setObjectName("notesView");
        notesView->setMinimumSize(QSize(382, 0));
        notesView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        gridLayout->addWidget(notesView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew_Notebook);
        menuFile->addAction(actionOpen_Notebook);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionClose_Notebook);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionVisit_Website);
        mainToolBar->addAction(actionNew_Notebook);
        mainToolBar->addAction(actionOpen_Notebook);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNew_Note);
        mainToolBar->addAction(actionDelete_Notes);

        retranslateUi(MainWindow);
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(displayAbout()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(saveNotebook()));
        QObject::connect(actionOpen_Notebook, SIGNAL(triggered()), MainWindow, SLOT(openNotebook()));
        QObject::connect(actionClose_Notebook, SIGNAL(triggered()), MainWindow, SLOT(closeNotebook()));
        QObject::connect(actionNew_Notebook, SIGNAL(triggered()), MainWindow, SLOT(newNotebook()));
        QObject::connect(actionSave_As, SIGNAL(triggered()), MainWindow, SLOT(saveNotebookAs()));
        QObject::connect(actionNew_Note, SIGNAL(triggered()), MainWindow, SLOT(newNote()));
        QObject::connect(actionDelete_Notes, SIGNAL(triggered()), MainWindow, SLOT(deleteNotes()));
        QObject::connect(notesView, SIGNAL(activated(QModelIndex)), MainWindow, SLOT(editNote(QModelIndex)));
        QObject::connect(actionVisit_Website, SIGNAL(triggered()), MainWindow, SLOT(visitWebsite()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Toynote", nullptr));
        actionNew_Notebook->setText(QCoreApplication::translate("MainWindow", "New Notebook", nullptr));
#if QT_CONFIG(tooltip)
        actionNew_Notebook->setToolTip(QCoreApplication::translate("MainWindow", "Create a new notebook", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew_Notebook->setShortcut(QCoreApplication::translate("MainWindow", "Alt+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Note->setText(QCoreApplication::translate("MainWindow", "New Note", nullptr));
#if QT_CONFIG(tooltip)
        actionNew_Note->setToolTip(QCoreApplication::translate("MainWindow", "Add a new note", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew_Note->setShortcut(QCoreApplication::translate("MainWindow", "Alt+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_Notes->setText(QCoreApplication::translate("MainWindow", "Delete Notes", nullptr));
#if QT_CONFIG(tooltip)
        actionDelete_Notes->setToolTip(QCoreApplication::translate("MainWindow", "Delete the selected note(s)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDelete_Notes->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About Toynote", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Save the notebook", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Notebook->setText(QCoreApplication::translate("MainWindow", "&Open Notebook", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen_Notebook->setToolTip(QCoreApplication::translate("MainWindow", "Open a notebook", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen_Notebook->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose_Notebook->setText(QCoreApplication::translate("MainWindow", "&Close", nullptr));
#if QT_CONFIG(tooltip)
        actionClose_Notebook->setToolTip(QCoreApplication::translate("MainWindow", "Close the notebook", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClose_Notebook->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Sa&ve As", nullptr));
#if QT_CONFIG(tooltip)
        actionSave_As->setToolTip(QCoreApplication::translate("MainWindow", "Save the notebook to a chosen file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionVisit_Website->setText(QCoreApplication::translate("MainWindow", "Visit Website", nullptr));
#if QT_CONFIG(shortcut)
        actionVisit_Website->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
