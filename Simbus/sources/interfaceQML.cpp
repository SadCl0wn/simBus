#include "../headers/interfaceQML.hpp"
#include <QtDebug>
#include <vector>
InterfaceQML::InterfaceQML(QObject *parent) : QObject(parent)
{
}

void InterfaceQML::addArret(int x, int y)
{
    _arrets.emplace_back(Arret(std::vector<size_t>(), x, y));
}

std::vector<Object> InterfaceQML::getArrets()
{
    return _arrets;
}