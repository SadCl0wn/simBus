#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "object.hpp"
#include <vector>

class Route{
    public:
        static std::vector<Route *> AllRoute;
        Route(float speed = 30,float x1=0,float y1=0,float x2=0,float y2=0);
        Route(float speed = 30,float coord[4]);
        ~Route();
        float getSpeed(){return speed;};
        float getDistance(){return distance;};
        vec2<float> getCoordDepart(){return coordDepart;};
        vec2<float> getCoordArrive(){return coordArrive;};
        bool pushConnexion(Route *a);
        bool popConnexion(Route *a);
        bool popArriveConnexion(Route *a);
        bool popDepartConnexion(Route *a);
    private:
        float speed;
        float distance;
        vec2<float> coordDepart;
        vec2<float> coordArrive;
        
        std::vector<Route *> connexionArrive;
        std::vector<Route *> connexionDepart;
};

#endif