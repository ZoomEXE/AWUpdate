/*
 * Класс неуправляеммого вооружения для базы данных
 * Файл создан 04.04.2020
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QVector>

class Weapon : public QObject
{
    Q_OBJECT
public:
    explicit Weapon(QObject *parent = nullptr);

    int count, cost, HCX, HbeforeHCX, HafterHCX;
    QString name;
    QDate date;

    Weapon(const Weapon &other):
            QObject(other.parent()),
            count(other.count),
            cost(other.cost),
            HCX(other.HCX),
            HbeforeHCX(other.HbeforeHCX),
            HafterHCX(other.HafterHCX),
            name(other.name),
            date(other.date)
        {}
    Weapon& operator=(const Weapon &other){
        count = other.count;
        cost = other.cost;
        HCX = other.HCX;
        HbeforeHCX = other.HbeforeHCX;
        HafterHCX = other.HafterHCX;
        name = other.name;
        date = other.date;
        return *this;
    }

    int remainingDays(); //Количество дней до конца НСХ

signals:

};

#endif // WEAPON_H
