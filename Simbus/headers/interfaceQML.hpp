#ifndef INTERFACE_QML
#define INTERFACE_QML
#include <QObject>

class InterfaceQML:public QObject
{
    Q_OBJECT
public:
    InterfaceQML(QObject* parent=0);

    Q_INVOKABLE void arret();
private:
};

#endif // INTERFACE_QML