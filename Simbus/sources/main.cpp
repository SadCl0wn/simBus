#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "../headers/parametres.hpp"
#include "../headers/interfaceQML.hpp"
#include "../headers/markermodel.hpp"

int main(int argc, char *argv[])
{
    MarkerModel markermodel;
    markermodel.setAddAction(true);
    MarkerModel markermodel2;
    markermodel2.setAddAction(false);

    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    qmlRegisterType<Parametres>("Parametres", 1,0, "Parametres");
    qmlRegisterType<InterfaceQML>("InterfaceQml", 1,0, "InterfaceQml");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("markermodel", &markermodel);
    engine.rootContext()->setContextProperty("markermodel2", &markermodel2);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
