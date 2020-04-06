#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    Weapon testBomb;
    testBomb.name = "ОФАБ 250-270";
    testBomb.count = 30;
    testBomb.HCX = 23;
    testBomb.cost = 7;
    testBomb.HbeforeHCX = 5;
    testBomb.HafterHCX = 10;
    testBomb.date = QDate::fromString("04.04.2005", "dd.MM.yyyy");
    qDebug() << testBomb.remainingDays();
    */
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("awAccaunting.sqlite");

    if(!dataBase.open())
    {
        qDebug() << dataBase.lastError().text();
    }else{
        qDebug() << "All is OK";
        sqlQuery = QSqlQuery(dataBase);

        setHeader();
        fillTableBombs("bombs");
        fillTableMissiles("missiles");

    }
}

void MainWindow::setHeader()
{
    horizontalHeader.append("№ п/п");
    horizontalHeader.append("Наименование");
    horizontalHeader.append("Количество");
    horizontalHeader.append("Дата изготовления");
    horizontalHeader.append("НСХ");
    horizontalHeader.append("Ценность");
    horizontalHeader.append("H до НСХ");
    horizontalHeader.append("H после НСХ");
}

void MainWindow::fillTableBombs(QString tableName)
{
    QSqlQueryModel *model = new QSqlQueryModel;

    sqlQuery.exec("SELECT * FROM " + tableName);
    model->setQuery(sqlQuery);

    for(int i = 0; i < horizontalHeader.size(); ++i)
    {
        model->setHeaderData(i, Qt::Horizontal, horizontalHeader[i]);
    }

    ui->tableBombs->setModel(model);
    ui->tableBombs->resizeColumnsToContents();
}

void MainWindow::fillTableMissiles(QString tableName)
{
    QSqlQueryModel *model = new QSqlQueryModel;

    sqlQuery.exec("SELECT * FROM " + tableName);
    model->setQuery(sqlQuery);

    for(int i = 0; i < horizontalHeader.size(); ++i)
    {
        model->setHeaderData(i, Qt::Horizontal, horizontalHeader[i]);
    }

    ui->tableMissiles->setModel(model);
    ui->tableMissiles->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

