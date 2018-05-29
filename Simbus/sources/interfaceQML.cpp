#include "../headers/interfaceQML.hpp"
#include <QtDebug>

InterfaceQML::InterfaceQML(QObject *parent) : QObject(parent)
{
}
std::vector<Object> InterfaceQML::objects() const
{
    return _objects;
}
void InterfaceQML::arret()
{
    _objects.emplace_back(Arret(std::vector<size_t>(), 0, 0));
}
