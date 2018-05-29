#ifndef __BATIMENT_H__
#define __BATIMENT_H__

#include "object.hpp"
#include "personne.hpp"

class Personne;

class Batiment:public Object{
    public:
        Batiment(int x=0,int y=0): Object(x,y){};
        ~Batiment(); //COMPLETER *Batiment delink
        
        /**
        * @returns vect2.x = nbPersonneParJour
        * vect2.y = nbPersonneMax
        */
        void addPersonne(Personne* Personne)
        vec2<unsigned> getStats();
        bool popPersonne(Personne *personne);
        void pushPersonnes(Personne *personne);
        std::vector<Personne *> getPersonnes();
        unsigned getnbPersonneMax(); 
    private:
        std::vector<Personne *> personnes;
        unsigned nbPersonneParJour;
        unsigned nbPersonneMax;
};

#endif