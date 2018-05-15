#include "parametres.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Parametres::Parametres(QObject* parent):QObject(parent)
{
    isValidParam=false;
}
QString Parametres::recupadressedepart(){
    return adressedepart;


}
void Parametres::setadressedepart(QString adressedep){
    adressedepart=adressedep;
    isValidParam=false;

}
QString Parametres::recupadressearrivee(){
    return adressearrivee;

}
void Parametres::setadressearrivee(QString adressearr){
    adressearrivee=adressearr;
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
         stream <<"adresse_de_depart ="<< recupadressedepart() << "\n";// transfert adresse depart via le flux
         stream <<"adresse_d_arrivee ="<<recupadressearrivee() << endl;// transfert adresse arrivee via le flux
        // stream <<recupheure() << endl;// transfert heure via le flux
        //stream <<recupminute() << endl;// transfert minute via le flux
         stream <<"horaire ="<<textvalue(recupheure()) << ":"<<textvalue(recupminute()) << endl;


     }
     file.close();
     isValidParam=true;


}
 void Parametres::ajoutArret(const QString &new_pos){
     coordonnees.append(new_pos);
     qDebug() << coordonnees ;//afficher le contenu du tableau
     isValidParam=false;

 }
 void Parametres::modificationArret(QString before_pos,QString new_pos){
     int index= coordonnees.indexOf(before_pos);   // recuperer l'index de l'ancienne position
     if (index> -1){    // si index > -1 , c est qu on a trouvé l'ancienne coordonnée dans le tableau
         coordonnees.removeAt(index); //on supprime la coordonnée de l ancienne coordonnée
         coordonnees.insert(index,new_pos); // on ajoute la nouvelle coordonnée dans le tableau sur la meme ligne
    }
    qDebug() << coordonnees;//afficher le contenu du tableau
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
