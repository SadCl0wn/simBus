#include "../headers/transportPublique.hpp"
#include <math.h>
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

Arret *Transportpublique::Check_Arret()
{
    vec2<float> c = getCoor();
    c.x;
    c.y;

    for (auto i : arrets)
    {
        vec2<float> a = i->getCoor();

        float d = sqrt(c.x * a.x + c.y * a.y);
        if (d < 15)
        {
            return i;
        }
    }
    return nullptr;
}

void Transportpublique::Actualiser_bus()
{
    Arret *arret = Check_Arret();

    if (arret == nullptr)
    {
        return;
    }
    descendre(arret);
    getpassagers(arret);
}

void Transportpublique::getpassagers(Arret *a)
{
    std::vector<Personne *> g = a->getPersonnes();
    for (auto p : g)
    {
        personnes.push_back(p);
        a->popPersonne(p);
    }
}

void Transportpublique::descendre(Arret *a)
{
    for (auto p : personnes)
    {
        std::vector<Batiment *> o = p->getObjectifs();
        if (o[0] == a)
        {
            popPersonne(p);
            a->pushPersonne(p);
        }
    }
}

bool Transportpublique::popPersonne(Personne* personne){
    for (unsigned x = 0; x < personnes.size(); x++)
    {
        if (personnes[x] == personne)
        {
            personnes.erase(personnes.begin() + x);
            return true;
        }
    }
    return false;
}
