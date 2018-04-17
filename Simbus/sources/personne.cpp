#include "../headers/personne.hpp"

Personne::~Personne(){
    for(auto o : objectifs)
        o->popPersonne(this);
}

bool Personne::popObjectifs(Batiment *objectif)
{
    for(unsigned x = 0;x<objectifs.size();x++)
    {
        if(objectifs[x] == objectif)
        {
            objectifs.erase(objectifs.begin()+x);
            return true;
        }
    }
    return false;
}
void Personne::pushObjectifs(Batiment *personne)
{
    objectifs.push_back(personne);
}

std::vector<Batiment*> Personne::getObjectifs()
{
    return objectifs;
}