#include "weapon.h"

Weapon::Weapon(QObject *parent) : QObject(parent)
{

}

int Weapon::remainingDays()
{
    QDate endOfHCX = date.addYears(HCX);
    return QDate::currentDate().daysTo(endOfHCX);
}
