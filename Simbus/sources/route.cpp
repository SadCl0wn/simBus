#include "../headers/route.hpp"
#include <math.h>

std::vector<Route *> Route::AllRoute = {};

Route::Route(float speed,float x1,float y1,float x2,float y2)
{
    this->speed=speed;
    coordDepart = vec2<float>(x1,y2);
    coordArrive = vec2<float>(x2,y2);
    Route::AllRoute.push_back(this);
    distance = sqrt(x1*x2+y1*y2);
}

Route::Route(float coord[4], float speed)
{
    this->speed=speed;
    coordDepart = vec2<float>(coord[0],coord[1]);
    coordArrive = vec2<float>(coord[2],coord[3]);
    Route::AllRoute.push_back(this);
    distance = sqrt(coord[0]*coord[2]+coord[3]*coord[1]);
}

Route::~Route()
{
    for(auto o : connexionArrive)
        o->popArriveConnexion(this);
    for(auto o : connexionDepart)
        o->popDepartConnexion(this);
}

bool Route::pushConnexion(Route *a)
{
    if(a->coordArrive == this->coordDepart || a->coordDepart == this->coordDepart)
    {
        this->connexionDepart.push_back(a);
        return true;
    }
    else if (a->coordArrive == this->coordArrive || a->coordDepart == this->coordArrive)
    {
        this->connexionArrive.push_back(a);
        return true;
    }
    return false;
}

bool   Route::popArriveConnexion(Route *a)
{
    for(unsigned x = 0;x<connexionArrive.size();x++)
    {
        if(connexionArrive[x] == a)
        {
            connexionArrive.erase(connexionArrive.begin()+x);
            return true;
        }
    }
    return false;
}
bool    Route::popDepartConnexion(Route *a)
{
    for(unsigned x = 0;x<connexionDepart.size();x++)
    {
        if(connexionDepart[x] == a)
        {
            connexionDepart.erase(connexionDepart.begin()+x);
            return true;
        }
    }
    return false;
}

bool Route::popConnexion(Route *a)
{
    if(a->coordArrive == this->coordDepart || a->coordDepart == this->coordDepart)
    {
        return this->popDepartConnexion(a);
    }
    else if (a->coordArrive == this->coordArrive || a->coordDepart == this->coordArrive)
    {
        return this->popArriveConnexion(a);
    }
    return false;
}