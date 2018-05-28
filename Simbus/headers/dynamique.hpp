#ifndef __DYNAMIQUE_H__
#define __DYNAMIQUE_H__

#include "object.hpp"
#include "route.hpp"
#include <vector>

class Dynamique:public Object{
    public:
        Dynamique(float x=0,float y=0,float speed_max=0): Object(x,y),speed_(0,0),max_speed(speed_max){};
        vec2<float> getSpeed();
        void setSpeed(float speed[2]); 
        void setSpeed(vec2<float> speed);
        void pathfinding(vec2<float> objectif);
    private:
        vec2<float> speed_;
        float   max_speed;
        std::vector<vec2<float>> parcours;
};

#endif