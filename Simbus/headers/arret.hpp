#ifndef __PERSONNE_H__
#define __PERSONNE_H__

#include "Batiment.hpp"
#include "Transportpublique.hpp"

class  Arret:public Batiment{
    public:
        Arret(date[*] h, int tmp=0, date tma=0, int nbpj=0,int nbpm=0):Dynamique(){};
        ~Arret();                        //COMPLETER *Batiment delink
        bool popLignes(Transportpublique *transportpublique);
        void pushLignes(Transportpublique *transportpublique);
        std::vector<Transportpublique *> getLignes();
    private:
        std::vector<uint32_t> horaires;
        std::vector<Transportpublique *> lignes;

};

#endif
