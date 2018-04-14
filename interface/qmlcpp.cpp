#include "qmlcpp.h"
#include <QDebug>

qmlcpp::qmlcpp(QObject * parent)
{
    run=false;


}

bool qmlcpp::running(){
    qDebug() << run;
    return run;
}

void qmlcpp::setRun(bool running){
    run=running;
    qDebug() << "setRun " <<run;
}
