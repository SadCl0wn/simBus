#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <tuple>

using vectorInt = std::tuple<int,int>;

class Object{
    public:
        Object(int x=0,int y=0):coord_(x,y){};
        vectorInt getCoor();
        void setCoor(int coordonnees[2]);
        void setCoor(vectorInt coord);
    private:
        vectorInt coord_;
};

#endif