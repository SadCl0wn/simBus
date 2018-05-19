#include "../headers/object.hpp"

vec2<float> Object::getCoor(){
    return coord_;
}

void Object::setCoor(float coordonnees[2]){
    coord_ = vec2<float>(coordonnees[0],coordonnees[1]);
}
void Object::setCoor(vec2<float> coord){
        coord_ = coord;
}