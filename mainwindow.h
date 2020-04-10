#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMenuBar>
#include <QMenu>
#include <QItemDelegate>

#include "weapon.h"
#include "additem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSqlDatabase dataBase;
    QSqlQuery sqlQuery;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fillTableBombs(QString tableName);
    void fillTableMissiles(QString tableName);
    void setHeader();
    void addDB(Weapon *i, QString tableName);
    QStringList horizontalHeader;
    QVector <Weapon> missiles, bombs;
private slots:
    void on_add_item_triggered();
public slots:
    //Слот для добавления значений в основные векторы
    void addValue(QVector <Weapon> tempMissiles, QVector <Weapon> tempBombs);

private:
    Ui::MainWindow *ui;

};

//Делегат для запрета редактирования столбцов в TableWidget
class NonEditTableColumnDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    NonEditTableColumnDelegate(QObject * parent = 0) : QItemDelegate(parent) {}
    virtual QWidget * createEditor ( QWidget *, const QStyleOptionViewItem &,
                                     const QModelIndex &) const
    {
        return 0;
    }
};
#endif // MAINWINDOW_H
