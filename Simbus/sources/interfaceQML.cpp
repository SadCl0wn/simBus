#include "../headers/interfaceQML.hpp"
#include <QtDebug>

InterfaceQML::InterfaceQML(QObject *parent) : QObject(parent)
{
}

void InterfaceQML::addArret(int x, int y)
{
    _arrets.emplace_back(Arret(std::vector<size_t>(), x, y));
}
