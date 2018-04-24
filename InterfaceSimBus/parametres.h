#ifndef PARAMETRES_H
#define PARAMETRES_H
#include <QObject>
#include <QString>
class Parametres:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString adressedepart READ recupadressedepart WRITE setadressedepart)
public:
    Parametres(QObject* parent=0);
    QString recupadressedepart();
    void setadressedepart(QString adressedepart);
    Q_INVOKABLE void save();
private:
    QString adressedepart;

};

#endif // PARAMETRES_H
