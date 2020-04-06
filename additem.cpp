#include "additem.h"
#include "ui_additem.h"

additem::additem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additem)
{
    ui->setupUi(this);
}

additem::~additem()
{
    delete ui;
}

void additem::on_spinBox_valueChanged(int arg1)
{
    ui->tableBombs->setRowCount(arg1);
    ui->tableMissiles->setRowCount(arg1);
}
