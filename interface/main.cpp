#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QGeoRoute>
#include "qmlcpp.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<qmlcpp>("Local" , 1, 0,"qmlcpp");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
