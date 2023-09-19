#ifndef SYM_SPHERE
#define SYM_SPHERE

#include <SFML/Graphics.hpp>

#include "../Color/Color.h"
#include "../Vector/Vector.h"

class Sphere
{
    Vector center;
    double r;
    Color  color;
    double shininess_factor;

    public :
    Sphere(Vector _center, double _r, Color _color, double _shininess_factor = 10) :
    center (_center),
    r (_r),
    color (_color),
    shininess_factor(_shininess_factor)
    {};

    double GetShininessFact() { return shininess_factor; };
    Color GetColor() { return color; };
    Vector GetCenter() { return center; };
                                                            //v0 - point from which ray is emitted
                                                            // return white vector with coords intersection point 
                                                            // if ray and sphere intersect. 
    Vector GetIntersectionPoint(Vector v0, Vector ray);     // return black vector with NAN coords otherwise
};

#endif //SYM_SPHERE