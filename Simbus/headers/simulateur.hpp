#ifndef __SIMULATEUR_H__
#define __SIMULATEUR_H__

#include "object.hpp"
#include <vector>

class Simulateur
{
    public:
        Simulateur(){}
    private:
        std::vector<Object> objects;
};

#endif