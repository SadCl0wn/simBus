#ifndef __TRANSPORTPUBLIQUE_H__
#define __TRANSPORTPUBLIQUE_H__

#include "dynamique.hpp"
#include "arret.hpp"
#include "personne.hpp"

class  Transportpublique:public Dynamique{
    public:
        Transportpublique(int nbpmax=0,int nbpmoy=0,int[1] c):Dynamique(x,y,speed_x,speed_y){};
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
