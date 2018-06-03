#include "../headers/interfaceQML.hpp"
#include "../headers/route.hpp"
#include <QtDebug>
#include <vector>

InterfaceQML::InterfaceQML(QObject *parent) : QObject(parent)
{
}

void InterfaceQML::addArret(float x, float y)
{
    _arrets.emplace_back(Arret(std::vector<size_t>(), x, y));
}

std::vector<Arret> InterfaceQML::getArrets()
{
    return _arrets;
}

void InterfaceQML::addRoute(float x1, float x2, float y1, float y2, float speed)
{
   _routes.emplace_back(Route(speed, x1, x2, y1, y2));
}

std::vector<Route> InterfaceQML::getRoutes()
{
    return _routes;
}
