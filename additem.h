#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include "weapon.h"
#include "mainwindow.h"
#include <vector>

namespace Ui {
class additem;
}

class additem : public QDialog
{
    Q_OBJECT

public:
    explicit additem(QWidget *parent = nullptr);
    ~additem();
    QVector <Weapon> tempMissiles, tempBombs;

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_buttonBox_accepted();
    
    void on_tableMissiles_cellChanged(int row, int column);

    void on_tableBombs_cellChanged(int row, int column);

private:
    Ui::additem *ui;

signals:
    void signalTempVectors(QVector <Weapon> tempMissiles, QVector <Weapon> tempBombs);
};

#endif // ADDITEM_H
