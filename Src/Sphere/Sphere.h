#ifndef SYM_SPHERE
#define SYM_SPHERE

#include <SFML/Graphics.hpp>

#include "../Vector/Vector.h"

class Sphere
{
    Vector center;
    double r;
    sf::Color color;
};

#endif //SYM_SPHERE