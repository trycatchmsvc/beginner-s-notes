/********************************************************************************
** Form generated from reading UI file 'editnotedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITNOTEDIALOG_H
#define UI_EDITNOTEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditNoteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *titleEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditNoteDialog)
    {
        if (EditNoteDialog->objectName().isEmpty())
            EditNoteDialog->setObjectName("EditNoteDialog");
        EditNoteDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(EditNoteDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(EditNoteDialog);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label);

        titleEdit = new QLineEdit(EditNoteDialog);
        titleEdit->setObjectName("titleEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, titleEdit);


        verticalLayout->addLayout(formLayout);

        label_2 = new QLabel(EditNoteDialog);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(EditNoteDialog);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        buttonBox = new QDialogButtonBox(EditNoteDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(plainTextEdit);
        label_2->setBuddy(titleEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(EditNoteDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditNoteDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditNoteDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditNoteDialog);
    } // setupUi

    void retranslateUi(QDialog *EditNoteDialog)
    {
        EditNoteDialog->setWindowTitle(QCoreApplication::translate("EditNoteDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditNoteDialog", "&Title:", nullptr));
        label_2->setText(QCoreApplication::translate("EditNoteDialog", "T&ext:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditNoteDialog: public Ui_EditNoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITNOTEDIALOG_H
