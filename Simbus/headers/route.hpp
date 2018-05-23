#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "object.hpp"

class Route{
    public:
        Route(float x1=0,float y1=0,float x2=0,float y2=0):coord_Depart(x1,y2),coord_Arrive(x2,y2){};
        Route(float coord[4]):coord_Depart(coord[0],coord[1]),coord_Arrive(coord[2],coord[3]){};
    private:
        vec2<float> coord_Depart;
        vec2<float> coord_Arrive;

};

#endif