#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "journal.h"
#include <QtWidgets>
#include <QPushButton>
#include <QString>
#include <QRadioButton>
#include <QButtonGroup>
#include <QIODevice>
#include <QTextStream>
#include <fstream>
#include <vector>
#include <sstream>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    modeButtonGroup = new QButtonGroup(this);
    modeButtonGroup->addButton(ui->radioButton, 2);
    modeButtonGroup->addButton(ui->radioButton_2, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString input_line = ui -> InputLine -> text();
    QString output_line = ui -> OutputLine -> text();
    std::fstream ist; //Поток чтения обычного файла
    std::fstream ost_f; // Поток чтения и записи бинарного файла

    QString input_line_path = input_line.replace( "\\", "\\\\" );
    QString output_line_path = output_line.replace( "\\", "\\\\" );
    ist.open(input_line_path.toStdString(), std::ios_base::in|std::ios_base::out);
    ost_f.open(output_line_path.toStdString(), std::ios_base::binary|std::ios_base::in|std::ios_base::out);

    QString out_text;
    QTextStream ost(&out_text, QIODevice::WriteOnly);
    QMessageBox::information(this, tr("Нажата кнопка выполнения"), tr("Выбран режим %1").arg(modeButtonGroup->checkedId() ));

    std::vector<journal> array = {};



    if (!ui->radioButton->isChecked()) {

        ost << tr("Текстовый файл: ") << ui->InputLine->text() << "\n"
            << tr("Двоичный файл: ") << ui->OutputLine->text() << "\n"
            << tr("Режим: ") << modeButtonGroup->checkedId() << "\n\n";

        std::ostringstream oss;


        load_txt(array, ist);
        sort_array(array);
        print_table(array, oss);
        save_bin(array, ost_f);
        ost << QString::fromStdString(oss.str());
        ui->textEdit->setPlainText(out_text);

    }

    if (!ui ->radioButton_2 -> isChecked()){
        ost << tr("Текстовый файл: ") << ui->InputLine->text() << "\n"
            << tr("Двоичный файл: ") << ui->OutputLine->text() << "\n"
            << tr("Режим: ") << modeButtonGroup->checkedId() << "\n\n";

        load_bin(array, ost_f);
        sort_array(array);
        std::ostringstream oss;
        print_table(array, oss);
        ost << QString::fromStdString(oss.str());
        ui->textEdit->setPlainText(out_text);
    }
}




