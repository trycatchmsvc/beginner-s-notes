#include "mainwindow.h"
#include <QtWidgets>

Widget::~Widget()
{
    delete ui;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}
