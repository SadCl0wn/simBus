#ifndef __DYNAMIQUE_H__
#define __DYNAMIQUE_H__

#include "object.hpp"
#include <vector>

using vectorFloat = std::tuple<float,float>;

class Dynamique:public Object{
    public:
        virtual Dynamique(int x=0,int y=0,int speed_x=0,int speed_y=0): Object(x,y),speed_(speed_x,speed_y){};
        vectorFloat getSpeed();
        void setSpeed(int coordonnees[2]);
        void setSpeed(vectorFloat coord);
    private:
        vectorFloat speed_;
        vector<vectorInt> parcours;
};

#endif