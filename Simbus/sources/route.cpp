#include "../headers/route.hpp"

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