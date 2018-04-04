#ifndef __PERSONNE_H__
#define __PERSONNE_H__

#include "dynamique.hpp"

using vectorFloat = std::tuple<float,float>;

class  Personne:public Dynamique{
    public:
        Personne (int x=0,int y=0,int speed_x=0,int speed_y=0):Dynamique(x,y,speed_x,speed_y){};
    private:
        uint32_t 
};

#endif