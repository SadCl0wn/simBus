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

    std::vector<Object> objects() const;

    Q_INVOKABLE void arret();

  private:
    std::vector<Object> _objects;
};

#endif // INTERFACE_QML