#ifndef __ARRET_H__
#define __ARRET_H__

#include "batiment.hpp"
#include "transportPublique.hpp"

class  Transportpublique;

class  Arret:public Batiment{
    public:
        Arret(std::vector<time_t> h,int x=0,int y=0, int tmp=0, time_t tma=0, int nbpj=0,int nbpm=0):Batiment(x,y){};
        ~Arret();                        //COMPLETER *Batiment delink
        bool popLignes(Transportpublique *transportpublique);
        void pushLignes(Transportpublique *transportpublique);
        std::vector<Transportpublique *> getLignes();
    private:
        std::vector<uint32_t> horaires;
        std::vector<Transportpublique *> lignes;

};

#endif
