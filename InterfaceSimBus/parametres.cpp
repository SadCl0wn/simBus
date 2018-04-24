#include "parametres.h"
#include <QFile>
#include <QTextStream>

Parametres::Parametres(QObject* parent):QObject(parent)
{

}
QString Parametres::recupadressedepart(){
    return adressedepart;

}
void Parametres::setadressedepart(QString AdreDep){
    adressedepart=AdreDep;

}
 void Parametres::save(){
     QString filename="Data.txt"; // initialiser nom fichier
     QFile file( filename ); //creation fichier
     if ( file.open(QIODevice::ReadWrite) ) //on l ouvre en lecture/ecrire
     {
         QTextStream stream( &file ); //creation flux
         stream << adressedepart << endl;// transfert adresse depart via le flux
     }
     file.close();

}
