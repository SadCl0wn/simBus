#ifndef PARAMETRES_H
#define PARAMETRES_H
#include <QObject>
#include <QString>
#include <QStringList>
class Parametres:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString longitudeHG READ recuplongitudeHG WRITE setlongitudeHG)
    Q_PROPERTY(QString latitudeHG READ recuplatitudeHG WRITE setlatitudeHG)
    Q_PROPERTY(QString longitudeBD READ recuplongitudeBD WRITE setlongitudeBD)
    Q_PROPERTY(QString latitudeBD READ recuplatitudeBD WRITE setlatitudeBD)
    Q_PROPERTY(int heure READ recupheure WRITE setheure)
    Q_PROPERTY(int minute READ recupminute WRITE setminute)
public:
    Parametres(QObject* parent=0);
    QString recuplongitudeHG();

    void setlongitudeHG(QString longHG);

    QString recuplatitudeHG();

    void setlatitudeHG(QString latHG);

    QString recuplatitudeBD();

    void setlatitudeBD(QString latBD);

    QString recuplongitudeBD();

    void setlongitudeBD(QString longBD);
    int recupminute();
    int recupheure();
    void setheure(int h);
    void setminute(int min);

    Q_INVOKABLE void ajoutArret(const QString &new_pos); //dialogue bouton pour ajouter arret

    Q_INVOKABLE void supprimerArret(QString pos);
    Q_INVOKABLE void simuler();

    Q_INVOKABLE void supprimerTousLesArrets() ;

    Q_INVOKABLE void save();
private:
    QString longitudeHG;
    QString latitudeHG;
    QString longitudeBD;
    QString latitudeBD;
    int heure;
    int minute;
    QString textvalue(int value);
    QStringList coordonnees;
    bool isValidParam;


};

#endif // PARAMETRES_H
