#include "../headers/dynamique.hpp"
#include <limits.h>
#include <math.h>

struct routePath{
    Route *r;
    unsigned int temps;
};

void Dynamique::pathfinding(vec2<float> objectif)
{
    std::vector<routePath> accesible;
    routePath plusProche{nullptr,UINT_MAX};
    vec2<float> coord_actuel = this->getCoor();
    vec2<float> a;
    unsigned int t;
    for(auto route : Route::AllRoute)
    {
        a = route->getCoordDepart();
        t = sqrt(a.x*coord_actuel.x+a.y*coord_actuel.y)/route->getSpeed();
        if(t < plusProche.temps)
        {
            plusProche.r = route;
            plusProche.temps = t;
        }
    }
    this->parcours.push_back(plusProche.r->getCoordDepart());
    routePath routeP;
    for(auto route : plusProche.r->getConnexionDepart())
    {
        routeP.r = route;
        routeP.temps = t;
        accesible.push_back(routeP);
    }
    for(auto route : plusProche.r->getConnexionArrive())
    {
        routeP.r = route;
        routeP.t = t+plusProche.r->getDistance()/route->getSpeed();
        accesible.push_back(routeP);
        accesible.push_back(routeP);
    }
}

vec2<float> Dynamique::getSpeed()
{
    return speed_;
}
void Dynamique::setSpeed(float speed[2])
{
    speed_ = vec2<float>(speed[0],speed[1]);
}
void Dynamique::setSpeed(vec2<float> speed)
{
    speed_ = speed;
}