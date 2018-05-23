#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "object.hpp"
#include <vector>

class Route{
    public:
        Route(float x1=0,float y1=0,float x2=0,float y2=0):coordDepart(x1,y2),coordArrive(x2,y2){};
        Route(float coord[4]):coordDepart(coord[0],coord[1]),coordArrive(coord[2],coord[3]){};
        ~Route();
        bool pushConnexion(Route *a);
        bool popConnexion(Route *a);
        bool popArriveConnexion(Route *a);
        bool popDepartConnexion(Route *a);
    private:
        vec2<float> coordDepart;
        vec2<float> coordArrive;
        
        std::vector<Route *> connexionArrive;
        std::vector<Route *> connexionDepart;
};

#endif