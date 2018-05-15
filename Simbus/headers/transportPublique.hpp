#ifndef __TRANSPORTPUBLIQUE_H__
#define __TRANSPORTPUBLIQUE_H__

#include "dynamique.hpp"
#include "arret.hpp"
#include "personne.hpp"

class Arret;

class  Transportpublique:public Dynamique{
    public:
        Transportpublique(float x=0,float y=0,float speed_x=0,float speed_y=0,int nbpmax=0,int nbpmoy=0,int cappacity=40):Dynamique(x,y,speed_x,speed_y){};
        ~Transportpublique();
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
