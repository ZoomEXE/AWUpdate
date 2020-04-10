#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QVector <Weapon> test;
    Weapon testBomb;
    testBomb.name = "ОФАБ 250-270";
    testBomb.count = 30;
    testBomb.HCX = 23;
    testBomb.cost = 7;
    testBomb.HbeforeHCX = 5;
    testBomb.HafterHCX = 10;
    testBomb.date = QDate::fromString("04.04.2005", "dd.MM.yyyy");
    qDebug() << testBomb.remainingDays();
    test.append(testBomb);
    */




    //Открытие базы данных
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("awAccaunting.sqlite");

    ui->tabWidget->setTabText(0, "Авиационные ракеты");
    ui->tabWidget->setTabText(1, "Авиационные бомбы");

    ui->tableBombs->horizontalHeader()->setStretchLastSection(true);
    ui->tableMissiles->horizontalHeader()->setStretchLastSection(true);

    //Загрузка записей из базы данных в TableView
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

//Настройка заголовков таблицы
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

//Заполнение бомб
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

//Заполнение ракет
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

//Открытие окна для добавления элементов
void MainWindow::on_add_item_triggered()
{
    ui->statusbar->showMessage("Добавить новый элемент");
    additem *add = new additem;

    connect(add,
            SIGNAL(signalTempVectors(QVector <Weapon>, QVector <Weapon>)),
            this, SLOT(addValue(QVector <Weapon>, QVector <Weapon>)));
    add->setModal(true);
    add->show();
}

//Добавление записей в БД
void MainWindow::addDB(Weapon *i, QString tableName)
{
    QString str = "INSERT INTO " + tableName +" (name, count, date, HCX, cost, HbeforeHCX, HafterHCX) values('" + i->name +
            "', '" + QString::number(i->count) + "', '" + i->date.toString("dd.MM.yyyy") + "', '" + QString::number(i->HCX) +
            "', '" + QString::number(i->cost) + "', '" + QString::number(i->HbeforeHCX) +
            "', '" + QString::number(i->HafterHCX) + "')";
    bool b = sqlQuery.exec(str);

    qDebug() << b << endl << str;
}
//Добавление записей в векторы и базу данных
void MainWindow::addValue(QVector <Weapon> tempMissiles, QVector <Weapon> tempBombs)
{
    for(auto i = tempMissiles.begin(); i < tempMissiles.end(); ++i)
    {
        missiles.append(*i);
        addDB(i, "missiles");
        fillTableMissiles("missiles");
    }

    for(auto i = tempBombs.begin(); i < tempBombs.end(); ++i)
    {
        bombs.append(*i);
        addDB(i, "bombs");
        fillTableBombs("bombs");
    }

}
