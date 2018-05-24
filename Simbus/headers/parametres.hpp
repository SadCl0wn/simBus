#ifndef PARAMETRES_H
#define PARAMETRES_H
#include <QObject>
#include <QString>
#include <QStringList>
class Parametres:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString adressedepart READ recupadressedepart WRITE setadressedepart)
    Q_PROPERTY(QString adressearrivee READ recupadressearrivee WRITE setadressearrivee)
    Q_PROPERTY(int heure READ recupheure WRITE setheure)
    Q_PROPERTY(int minute READ recupminute WRITE setminute)
public:
    Parametres(QObject* parent=0);
    QString recupadressedepart();
    void setadressedepart(QString adressedep);
    QString recupadressearrivee();
    void setadressearrivee(QString adressearr);
    int recupminute();
    int recupheure();
    void setheure(int h);
    void setminute(int min);

    Q_INVOKABLE void ajoutArret(const QString &new_pos); //dialogue bouton pour ajouter arret
    Q_INVOKABLE void modificationArret(QString before_pos,QString new_pos);
    Q_INVOKABLE void supprimerArret(QString pos);
    Q_INVOKABLE void simuler();



    Q_INVOKABLE void save();
private:
    QString adressedepart;
    QString adressearrivee;
    int heure;
    int minute;
    QString textvalue(int value);
    QStringList coordonnees;
    bool isValidParam;


};

#endif // PARAMETRES_H
