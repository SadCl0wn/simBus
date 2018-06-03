#include "../headers/parametres.hpp"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Parametres::Parametres(QObject* parent):QObject(parent)
{
    isValidParam=false;
}
QString Parametres::recuplatitudeHG(){
    return latitudeHG;


}
void Parametres::setlatitudeHG(QString latHG){
    latitudeHG=latHG;
    isValidParam=false;

}
QString Parametres::recuplongitudeHG(){
    return longitudeHG;

}
void Parametres::setlongitudeHG(QString longHG){
    longitudeHG=longHG;
    isValidParam=false;

}
QString Parametres::recuplatitudeBD(){
    return latitudeBD;


}
void Parametres::setlatitudeBD(QString latBD){
    latitudeBD=latBD;
    isValidParam=false;

}
QString Parametres::recuplongitudeBD(){
    return longitudeBD;

}
void Parametres::setlongitudeBD(QString longBD){
    longitudeBD=longBD;
    isValidParam=false;

}

int Parametres::recupheure(){
    return heure;

}
void Parametres::setheure(int h){
    heure=h;
    isValidParam=false;

}

int Parametres::recupminute(){
    return minute;

}
void Parametres::setminute(int min){
    minute=min;
    isValidParam=false;

}
QString Parametres::textvalue(int value){
    QString res="";
    if (value<10){
        res+="0";

    }
    res+=QString::number(value);
    return res;

}

 void Parametres::save(){
     QString filename="Data.txt"; // initialiser nom fichier
     QFile file( filename ); //creation fichier
     if ( file.open(QIODevice::WriteOnly|QIODevice::Text) ) //on l ouvre en lecture/ecrire
     {
         QTextStream stream( &file ); //creation flux
         stream <<"latitudeHG ="<< recuplatitudeHG() << "\n";// transfert adresse depart via le flux
         stream <<"longitudeHG ="<<recuplongitudeHG() << endl;// transfert adresse arrivee via le flux
         stream <<"latitudeBD ="<<  recuplatitudeBD()<< "\n";// transfert adresse depart via le flux
         stream <<"longitudeBD ="<<recuplongitudeBD() << endl;
        // stream <<recupheure() << endl;// transfert heure via le flux
        //stream <<recupminute() << endl;// transfert minute via le flux
         //stream <<"horaire ="<<textvalue(recupheure()) << ":"<<textvalue(recupminute()) << endl;
         for (QString arret: coordonnees){
             stream<<arret<<endl;
         }


     }
     file.close();
     isValidParam=true;


}
 void Parametres::ajoutArret(const QString &new_pos){
     coordonnees.append(new_pos);
     qDebug() << coordonnees ;//afficher le contenu du tableau
     isValidParam=false;

 }

 void Parametres::supprimerArret(QString pos){
     int index= coordonnees.indexOf(pos);   // recuperer l'index de l'ancienne position
     if (index> -1){    // si index > -1 , c est qu on a trouvé l'ancienne coordonnée dans le tableau
         coordonnees.removeAt(index); //on supprime la coordonnée de l ancienne coordonnée


 }
 qDebug() << coordonnees;//afficher le contenu du tableau
 isValidParam=false;
 }

 void Parametres::simuler(){
     if(isValidParam==false){
         save();
     }
    //appel fonction simulation
 }
 void Parametres::supprimerTousLesArrets() {
     coordonnees.clear();
 }
