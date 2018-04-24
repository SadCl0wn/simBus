#include "../headers/Arret.hpp"

Arret::~Arret(){
    for(auto o : arrets)
        o->popArret(this);
}

bool Arret::popArrets(Transportpublique *ligne)
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
void Arret::pushArrets(transportpublique *arret)
{
    lignes.push_back(arret);
}

std::vector<Arret*> Personne::getArrets()
{
    return lignes;
}
