#include "additem.h"
#include "ui_additem.h"

additem::additem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additem)
{
    ui->setupUi(this);

    ui->tableMissiles->resizeColumnsToContents();
    ui->tableBombs->resizeColumnsToContents();

    ui->tabWidget->setTabText(0, "Авиационные ракеты");
    ui->tabWidget->setTabText(1, "Авиационные бомбы");

    tempMissiles.resize(1);
    tempMissiles.resize(1);

    ui->tableMissiles->setItemDelegateForColumn(0,new NonEditTableColumnDelegate());
    ui->tableBombs->setItemDelegateForColumn(0, new NonEditTableColumnDelegate());
}

additem::~additem()
{
    delete ui;
}

//Изменение количества строк в таблицах
void additem::on_spinBox_valueChanged(int arg1)
{
    ui->tableBombs->setRowCount(arg1);
    ui->tableMissiles->setRowCount(arg1);
    tempMissiles.resize(arg1);
    tempMissiles.resize(arg1);
}

//Сохранение введенных данных ракет во временный вектор
void additem::on_tableMissiles_cellChanged(int row, int column)
{
    switch (column)
    {
        case 0:
            break;
        case 1:
            tempMissiles[row].name = ui->tableMissiles->item(row, column)->text();
            break;
        case 2:
            tempMissiles[row].count = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 3:
            tempMissiles[row].date = QDate::fromString(ui->tableMissiles->item(row, column)->text(),  "dd.MM.yyyy");
            break;
        case 4:
            tempMissiles[row].HCX = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 5:
            tempMissiles[row].cost = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 6:
            tempMissiles[row].HbeforeHCX = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 7:
            tempMissiles[row].name = ui->tableMissiles->item(row, column)->text().toInt();
            break;
    }
}

void additem::on_buttonBox_accepted()
{
    connect(ui->buttonBox, SIGNAL(signalTempVectors(tempMissiles, tempBombs)),this,SLOT(addValue(tempMissiles, tempBombs)));
}
