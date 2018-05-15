#ifndef __DYNAMIQUE_H__
#define __DYNAMIQUE_H__

#include "object.hpp"
#include <vector>

class Dynamique:public Object{
    public:
        Dynamique(int x=0,int y=0,int speed_x=0,int speed_y=0): Object(x,y),speed_(speed_x,speed_y){};
        vec2<float> getSpeed();
        void setSpeed(float speed[2]); 
        void setSpeed(vec2<float> speed);
    private:
        vec2<float> speed_;
        std::vector<vec2<int>> parcours;
};

#endif