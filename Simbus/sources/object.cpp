#include "../headers/object.hpp"

Object(int x,int y)
{
    coord_.x=x;
    coord_.y=y;
}

vectorInt Object::getCoor(){
    return coord_;
}

void Object::setCoor(int coordonnees[2]){
    coord_ = std::make_tuple(coordonnees[0],coordonnees[1]);
}
void Object::setCoor(vectorInt coord){
        coord_ = coord;
}