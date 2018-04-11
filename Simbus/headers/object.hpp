#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <tuple>

template <typename T>
struct vec2{
    T x;
    T y;
}

class Object{
    public:
        Object(int x=0,int y=0):coord_(x,y){};
        vec2<int> getCoor();
        void setCoor(int coordonnees[2]);
        void setCoor(vec2<int> coord);
    private:
        vec2<int> coord_;
};

#endif