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

class Weapon : public QObject
{
    Q_OBJECT
public:
    explicit Weapon(QObject *parent = nullptr);

    int count, cost, HCX, HbeforeHCX, HafterHCX;
    QString name;
    QDate date;

    int remainingDays(); //Количество дней до конца НСХ

signals:

};

#endif // WEAPON_H
