#include "../headers/transportPublique.hpp"

Transportpublique::~Transportpublique()
{
    for (auto a : arrets)
        a->popLignes(this);
}

bool Transportpublique::popArrets(Arret *arret)
{
    for (unsigned x = 0; x < arrets.size(); x++)
    {
        if (arrets[x] == arret)
        {
            arrets.erase(arrets.begin() + x);
            return true;
        }
    }
    return false;
}
void Transportpublique::pushArrets(Arret *transportpublique)
{
    arrets.push_back(transportpublique);
}

std::vector<Arret *> Transportpublique::getArrets()
{
    return arrets;
}
