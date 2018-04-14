#ifndef QMLCPP_H
#define QMLCPP_H
#include <QtQml/qqml.h>

class qmlcpp:public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool run READ running WRITE setRun NOTIFY runChanged)
public:
    explicit qmlcpp(QObject * parent=0);
    bool running();
    void setRun(bool running);
private:
    bool run;
signals:
    void runChanged();


};
QML_DECLARE_TYPE(qmlcpp)
/*
 *creation class qmlcpp
 * creation attribut run qui suivant  son état va emettre un signal runChanged pour lier le qml et le cpp
 *
*/
#endif // QMLCPP_H
