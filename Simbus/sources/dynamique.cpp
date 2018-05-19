#include "../headers/dynamique.hpp"

vec2<float> Dynamique::getSpeed()
{
    return speed_;
}
void Dynamique::setSpeed(float speed[2])
{
    speed_ = vec2<float>(speed[0],speed[1]);
}
void Dynamique::setSpeed(vec2<float> speed)
{
    speed_ = speed;
}