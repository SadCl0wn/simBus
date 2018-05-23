#ifndef __OBJECT_H__
#define __OBJECT_H__

template <typename T>
struct vec2{
    vec2(T x,T y):x(x),y(y){};
    T x;
    T y;
};

class Object{
    public:
        Object(float x=0,float y=0):coord_(x,y){};
        vec2<float> getCoor();
        void setCoor(float coordonnees[2]);
        void setCoor(vec2<float> coord);
    private:
        vec2<float> coord_;
};

#endif