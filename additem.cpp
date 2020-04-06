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
