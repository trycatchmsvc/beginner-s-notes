/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QPushButton *Clear;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *InputLine;
    QLabel *SelectPath;
    QLabel *OutputLabel;
    QLineEdit *OutputLine;
    QLabel *InputLabel;
    QLabel *Logging;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *SelectMode;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(828, 540);
        MainWindow->setMinimumSize(QSize(828, 540));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 255, 101, 21));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 295, 811, 171));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(740, 465, 80, 24));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 811, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        InputLine = new QLineEdit(gridLayoutWidget);
        InputLine->setObjectName(QString::fromUtf8("InputLine"));

        gridLayout->addWidget(InputLine, 1, 1, 1, 1);

        SelectPath = new QLabel(gridLayoutWidget);
        SelectPath->setObjectName(QString::fromUtf8("SelectPath"));

        gridLayout->addWidget(SelectPath, 0, 0, 1, 2, Qt::AlignHCenter|Qt::AlignVCenter);

        OutputLabel = new QLabel(gridLayoutWidget);
        OutputLabel->setObjectName(QString::fromUtf8("OutputLabel"));

        gridLayout->addWidget(OutputLabel, 2, 0, 1, 1);

        OutputLine = new QLineEdit(gridLayoutWidget);
        OutputLine->setObjectName(QString::fromUtf8("OutputLine"));

        gridLayout->addWidget(OutputLine, 2, 1, 1, 1);

        InputLabel = new QLabel(gridLayoutWidget);
        InputLabel->setObjectName(QString::fromUtf8("InputLabel"));

        gridLayout->addWidget(InputLabel, 1, 0, 1, 1);

        Logging = new QLabel(centralwidget);
        Logging->setObjectName(QString::fromUtf8("Logging"));
        Logging->setGeometry(QRect(20, 270, 131, 21));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(240, 170, 341, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SelectMode = new QLabel(horizontalLayoutWidget);
        SelectMode->setObjectName(QString::fromUtf8("SelectMode"));

        horizontalLayout->addWidget(SelectMode);

        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(horizontalLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 828, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(Clear, SIGNAL(clicked()), textEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        SelectPath->setText(QCoreApplication::translate("MainWindow", "Select Path", nullptr));
        OutputLabel->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        InputLabel->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        Logging->setText(QCoreApplication::translate("MainWindow", "Logging", nullptr));
        SelectMode->setText(QCoreApplication::translate("MainWindow", "Select Mode:", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Mode 1", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Mode 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
