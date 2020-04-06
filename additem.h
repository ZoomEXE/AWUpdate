#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include "weapon.h"

namespace Ui {
class additem;
}

class additem : public QDialog
{
    Q_OBJECT

public:
    explicit additem(QWidget *parent = nullptr);
    ~additem();

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::additem *ui;
};

#endif // ADDITEM_H
