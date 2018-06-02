#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <iostream>

template <typename T>
struct vec2
{
    vec2(T x, T y) : x(x), y(y){};
    vec2(){};
    bool operator==(vec2 &a) { return (a.x == this->x && a.y == this->y); };
    T x;
    T y;
};

class Object
{
  public:
    Object(float x = 0, float y = 0) : coord_(x, y){};
    vec2<float> getCoor();
    void setCoor(float coordonnees[2]);
    void setCoor(vec2<float> coord);

  private:
    vec2<float> coord_;
};

template <typename T>
std::ostream &operator<<(std::ostream os, const vec2<T> &v)
{
    os << "x: " << v.x << ", y: " << v.y;
}

#endif