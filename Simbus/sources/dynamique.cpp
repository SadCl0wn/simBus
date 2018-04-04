#include "../headers/dynamique.hpp"

vectorFloat Dynamique::getSpeed()
{
    return speed_;
}
void Dynamique::setSpeed(int coordonnees[2])
{
    speed_ = std::make_tuple(coordonnees[0],coordonnees[1]);
}
void Dynamique::setSpeed(vectorFloat coord)
{
    speed_ = coord;
}