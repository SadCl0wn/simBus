#include "../headers/arret.hpp"

Arret::~Arret(){
    for(auto o : lignes)
        o->popArrets(this);
}

bool Arret::popLignes(Transportpublique *ligne)
{
    for(unsigned x = 0;x<lignes.size();x++)
    {
        if(lignes[x] == ligne)
        {
            lignes.erase(lignes.begin()+x);
            return true;
        }
    }
    return false;
}
void Arret::pushLignes(Transportpublique *ligne)
{
    lignes.push_back(ligne);
}

std::vector<Transportpublique *> Arret::getLignes()
{
    return lignes;
}
