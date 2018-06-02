#ifndef __ARRET_H__
#define __ARRET_H__

#include "batiment.hpp"
#include "transportPublique.hpp"

class Transportpublique;

class  Arret:public Batiment{
    public:
        Arret(std::vector<size_t> h,float x=0,float y=0):Batiment(x,y){};
        ~Arret();
        bool popLignes(Transportpublique *transportpublique);
        void pushLignes(Transportpublique *transportpublique);
        std::vector<Transportpublique *> getLignes();
    private:
        std::vector<size_t> horaires;
        std::vector<Transportpublique *> lignes;
};

#endif
