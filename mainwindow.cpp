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
}

MainWindow::~MainWindow()
{
    delete ui;
}

