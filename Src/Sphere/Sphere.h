#ifndef SYM_SPHERE
#define SYM_SPHERE

#include <SFML/Graphics.hpp>

#include "../Vector/Vector.h"

class Sphere
{
    Vector center;
    double r;
    sf::Color color;

    public :
    Sphere(Vector _center, double _r, sf::Color _color) :
    center (_center),
    r (_r),
    color (_color)
    {};

    sf::Color GetColor() { return color; };
    Vector GetCenter() { return center; };
                                                            //v0 - point from which ray is emitted
                                                            // return white vector with coords intersection point 
                                                            // if ray and sphere intersect. 
    Vector GetIntersectionPoint(Vector v0, Vector ray);     // return black vector with NAN coords otherwise
};

#endif //SYM_SPHERE