#include "../headers/object.hpp"

vec2<int> Object::getCoor(){
    return coord_;
}

void Object::setCoor(int coordonnees[2]){
    coord_ = vec2<int>(coordonnees[0],coordonnees[1]);
}
void Object::setCoor(vec2<int> coord){
        coord_ = coord;
}