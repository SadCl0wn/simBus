#ifndef __TRANSPORTPUBLIQUE_H__
#define __TRANSPORTPUBLIQUE_H__

#include "dynamique.hpp"
#include "arret.hpp"
#include "personne.hpp"

class Arret;

class Transportpublique : public Dynamique
{
  public:
    Transportpublique(float x = 0, float y = 0, float speed_max = 80, int nbpmax = 0, int nbpmoy = 0, int cappacity = 40) : Dynamique(x, y, speed_max){};
    ~Transportpublique();

    bool popArrets(Arret *arret);
    void pushArrets(Arret *arret);
    std::vector<Arret *> getArrets();

    bool popPersonne(Personne *personne);
    void pushPersonne(Personne *personne);
    std::vector<Personne *> getPersonnes();
    Arret *Check_Arret();
    void Actualiser_bus();
    void getpassagers(Arret *a);
    void descendre(Arret *a);

  private:
    std::vector<Arret *> arrets;
    std::vector<Personne *> personnes;
};

#endif
