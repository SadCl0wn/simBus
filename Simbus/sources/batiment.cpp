#include "../headers/batiment.hpp"

Batiment::~Batiment()
{
    for(auto o : personnes)
        o->popObjectifs(this);
}

vec2<unsigned> Batiment::getStats(){
    vec2<unsigned> stats(nbPersonneParJour,nbPersonneMax);
    return stats;
}

bool Batiment::popPersonne(Personne *personne)
{
    for(unsigned x = 0;x<personnes.size();x++)
    {
        if(personnes[x] == personne)
        {
            personnes.erase(personnes.begin()+x);
            return true;
        }
    }
    return false;
}
void Batiment::pushPersonne(Personne *personne)
{
    std::vector<Personne *> n=this->getPersonnes();
    if (n.size() < this->getnbPersonneMax())
        personnes.push_back(personne);
}

std::vector<Personne*> Batiment::getPersonnes()
{
    return personnes;
}

unsigned Batiment::getnbPersonneMax(){
    return nbPersonneMax;
}
