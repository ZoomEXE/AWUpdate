#include "additem.h"
#include "ui_additem.h"

additem::additem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additem)
{
    ui->setupUi(this);

    ui->tableMissiles->resizeColumnsToContents();
    ui->tableBombs->resizeColumnsToContents();

    ui->tableBombs->horizontalHeader()->setStretchLastSection(true);
    ui->tableMissiles->horizontalHeader()->setStretchLastSection(true);

    ui->tabWidget->setTabText(0, "Авиационные ракеты");
    ui->tabWidget->setTabText(1, "Авиационные бомбы");

    tempMissiles.resize(1);
    tempBombs.resize(1);

    //ui->tableMissiles->setItemDelegateForColumn(0,new NonEditTableColumnDelegate());
    //ui->tableBombs->setItemDelegateForColumn(0, new NonEditTableColumnDelegate());
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
            tempMissiles[row].name = ui->tableMissiles->item(row, column)->text();
            break;
        case 1:
            tempMissiles[row].count = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 2:
            tempMissiles[row].date = QDate::fromString(ui->tableMissiles->item(row, column)->text(),  "dd.MM.yyyy");
            break;
        case 3:
            tempMissiles[row].HCX = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 4:
            tempMissiles[row].cost = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 5:
            tempMissiles[row].HbeforeHCX = ui->tableMissiles->item(row, column)->text().toInt();
            break;
        case 6:
            tempMissiles[row].HafterHCX = ui->tableMissiles->item(row, column)->text().toInt();
            break;
    }
}

void additem::on_buttonBox_accepted()
{
   emit signalTempVectors(tempMissiles, tempBombs);
}

void additem::on_tableBombs_cellChanged(int row, int column)
{
    switch (column)
    {
        case 0:
            tempBombs[row].name = ui->tableBombs->item(row, column)->text();
            break;
        case 1:
            tempBombs[row].count = ui->tableBombs->item(row, column)->text().toInt();
            break;
        case 2:
            tempBombs[row].date = QDate::fromString(ui->tableBombs->item(row, column)->text(),  "dd.MM.yyyy");
            break;
        case 3:
            tempBombs[row].HCX = ui->tableBombs->item(row, column)->text().toInt();
            break;
        case 4:
            tempBombs[row].cost = ui->tableBombs->item(row, column)->text().toInt();
            break;
        case 5:
            tempBombs[row].HbeforeHCX = ui->tableBombs->item(row, column)->text().toInt();
            break;
        case 6:
            tempBombs[row].HafterHCX = ui->tableBombs->item(row, column)->text().toInt();
            break;
    }
}
