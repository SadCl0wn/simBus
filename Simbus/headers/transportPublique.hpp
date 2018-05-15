#ifndef __TRANSPORTPUBLIQUE_H__
#define __TRANSPORTPUBLIQUE_H__

#include "dynamique.hpp"
#include "arret.hpp"
#include "personne.hpp"

class Arret;

class  Transportpublique:public Dynamique{
    public:
        Transportpublique(int x=0,int y=0,int speed_x=0,int speed_y=0,int nbpmax=0,int nbpmoy=0,int cappacity=40):Dynamique(x,y,speed_x,speed_y){};
        ~Transportpublique();                        //COMPLETER *Batiment delink
        bool popArrets(Arret *arret);
        void pushArrets(Arret *arret);
        std::vector<Arret *> getArrets();

        bool popPersonnes(Personne *personne);
          void pushPersonnes(Personne *personne);
          std::vector<Personne *> getPersonnes();
    private:
        std::vector<Arret *> arrets;
        std::vector<Personne *> personnes;

};

#endif
