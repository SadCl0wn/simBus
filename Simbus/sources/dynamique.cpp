#include "../headers/dynamique.hpp"
#include <limits.h>
#include <algorithm>
#include <math.h>

struct RoutePath
{
    bool addAccessible(std::vector<RoutePath> &accessible, float speed_object);
    Route *r;
    unsigned int temps;
    vec2<float> precedent;
};

bool RoutePath::addAccessible(std::vector<RoutePath> &accessible, std::vector<RoutePath> &parcourue, float speed_object)
{
    RoutePath routeP;
    for (auto route : this->r->getConnexionDepart())
    {
        if (route == this->r)
            continue;
        routeP.r = route;
        routeP.temps = this->temps;
        routeP.precedent = this->r->getCoordDepart();
        bool aHit = false;
        std::for_each(accessible.beging(), accessible.end(), [routeP, &aHit](RoutePath &a) {
            if (a.r == routeP.r)
            {
                aHit = true;
                if (a.temps > routeP.temps)
                {
                    a.precedent = route.precedent;
                    a.temps = routeP.temps;
                }
            }
        });
        std::for_each(parcourue.beging(), parcourue.end(), [routeP, &aHit](RoutePath &a) {if(a.r == routeP.r)aHit = true; });
        if (!aHit)
            accessible.push_back(routeP);
    }
    for (auto route : this->r->getConnexionArrive())
    {
        if (route == this->r)
            continue;
        routeP.r = route;
        float routeSpeed = route->getSpeed();
        routeP.temps = this->temps + this->r->getDistance() / ((routeSpeed < speed_object) ? routeSpeed : speed_object);
        routeP.precedent = this->r->getCoordDepart();
        std::for_each(accessible.beging(), accessible.end(), [routeP, &aHit](RoutePath &a) {
            if (a.r == routeP.r)
            {
                aHit = true;
                if (a.temps > routeP.temps)
                {
                    a.precedent = route.precedent;
                    a.temps = routeP.temps;
                }
            }
        });
        std::for_each(parcourue.beging(), parcourue.end(), [routeP, &aHit](RoutePath &a) {if(a.r == routeP.r)aHit = true; });
        if (!aHit)
            accessible.push_back(routeP);
    }
}

void Dynamique::pathfinding(vec2<float> objectif)
{
    std::vector<RoutePath> accessible;
    std::vector<RoutePath> parcourue;
    vec2<float> coord_actuel = this->getCoor();
    vec2<float> a;
    RoutePath plusProche{nullptr, UINT_MAX, coord_actuel};
    unsigned int t = 0;
    for (auto route : Route::AllRoute)
    {
        a = route->getCoordDepart();
        t = sqrt(a.x * coord_actuel.x + a.y * coord_actuel.y) / route->getSpeed();
        if (t < plusProche.temps)
        {
            plusProche.r = route;
            plusProche.temps = t;
        }
    }
    this->parcours.push_back(plusProche.r->getCoordDepart());
    plusProche.addAccessible(accessible, this->max_speed);
    parcourue.push_back(plusProche);
    while (accessible.size() > 0)
    {
        accessible.front().addAccessible(accessible, this->max_speed);
        parcourue.push_back(accessible[0]);
        accessible.erase(0);
    }
}

vec2<float> Dynamique::getSpeed()
{
    return speed_;
}
void Dynamique::setSpeed(float speed[2])
{
    speed_ = vec2<float>(speed[0], speed[1]);
}
void Dynamique::setSpeed(vec2<float> speed)
{
    speed_ = speed;
}
