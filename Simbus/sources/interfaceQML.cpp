#include "../headers/interfaceQML.hpp"
#include <QtDebug>

InterfaceQML::InterfaceQML(QObject *parent) : QObject(parent)
{
}
void InterfaceQML::arret()
{
    qDebug() << "coucou";
}