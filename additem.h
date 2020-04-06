#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
class additem;
}

class additem : public QDialog
{
    Q_OBJECT

public:
    explicit additem(QWidget *parent = nullptr);
    ~additem();

private:
    Ui::additem *ui;
};

#endif // ADDITEM_H
