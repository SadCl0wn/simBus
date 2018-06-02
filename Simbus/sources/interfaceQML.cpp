#include "../headers/interfaceQML.hpp"
#include <QtDebug>
#include <vector>
InterfaceQML::InterfaceQML(QObject *parent) : QObject(parent)
{
}
std::vector<Object> InterfaceQML::objects() const
{
    return _objects;
}
void InterfaceQML::arret(std::vector<std::size_t>,int, int)
{
    _objects.emplace_back(Arret(std::vector<size_t>(), 0, 0));
}
