#ifndef INTERFACE_QML
#define INTERFACE_QML

#include "../headers/arret.hpp"
#include <QObject>
#include <vector>
#include "object.hpp"

class InterfaceQML : public QObject
{
    Q_OBJECT

  public:
    explicit InterfaceQML(QObject *parent = 0);

    Q_INVOKABLE void addArret(int x, int y);
    Q_INVOKABLE std::vector<Object> getArrets();
    
    Q_INVOKABLE void addRoute(int x, int y);
    Q_INVOKABLE std::vector<Object> getRoutes();

  private:
    std::vector<Object> _arrets;
    std::vector<Object> _routes;
};

#endif // INTERFACE_QML
