#ifndef __PERSONNE_H__
#define __PERSONNE_H__

#include "dynamique.hpp"
#include "batiment.hpp"

class Batiment;

class  Personne:public Dynamique{
    public:
        Personne(float x=0,float y=0,float speed_x=0,float speed_y=0):Dynamique(x,y,speed_x,speed_y){};
        ~Personne();
        bool popObjectifs(Batiment *batiment);
        void pushObjectifs(Batiment *batiment);
        std::vector<Batiment *> getObjectifs();
    private:
        std::vector<size_t> heureDeplacement;
        std::vector<Batiment *> objectifs;
};

#endif