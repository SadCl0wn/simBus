#ifndef __PERSONNE_H__
#define __PERSONNE_H__

#include "dynamique.hpp"
#include "batiment.hpp"

class Batiment;

class  Personne:public Dynamique{
    public:
        Personne(int x=0,int y=0,int speed_x=0,int speed_y=0):Dynamique(x,y,speed_x,speed_y){};
        ~Personne();                        //COMPLETER *Batiment delink
        bool popObjectifs(Batiment *batiment);
        void pushObjectifs(Batiment *batiment);
        std::vector<Batiment *> getObjectifs();
    private:
        std::vector<uint32_t> heureDeplacement;
        std::vector<Batiment *> objectifs;
};

#endif