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

void InterfaceQML::addRoute(int x1, int x2, int y1 int y2, float speed)
{
    float[4] pos = {x1, x2, y1, y2};
    _routes.emplace_back(Route(pos, speed));
}

std::vector<Object> InterfaceQML::getRoutes()
{
    return _routes;
}