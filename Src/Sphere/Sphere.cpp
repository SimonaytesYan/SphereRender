#include <math.h>
#include <SFML/Graphics.hpp>

#include "Sphere.h"

int SolveLinEqu(double a, double b, double& x)
{
    if (a == 0)
    {
        if (b == 0)
            return -1;
        return 0;
    }

    x = -b / a;
    return 1;
}

int SolveSqrEqu(double a, double b, double c, double& x1, double& x2)
{
    if (a == 0)
        return SolveLinEqu(b, c, x1);
    
    double D2 = b * b - 2 * a * c;
    if (D2 < 0)
        return 0;
    if (D2 == 0)
    {
        x1 = -b / (2*a);
        return 1;
    }

    x1 = (-b + sqrt(D2)) / (2 * a);
    x2 = (-b - sqrt(D2)) / (2 * a);

    return 2;
}

Vector Sphere::GetIntersectionPoint(Vector v0, Vector ray)
{
    double x = ray.GetX();
    double y = ray.GetY();
    double z = ray.GetZ();

    double c_x = (center - v0).GetX();
    double c_y = (center - v0).GetY();
    double c_z = (center - v0).GetZ();

    double a = x*x + y*y + z*z;
    double b = -2 * (x*c_x + y*c_y + z*c_z);
    double c = c_x*c_x + c_y*c_y + c_z*c_z - r*r;

    double root1       = 0;
    double root2       = 0;
    int    root_number = SolveSqrEqu(a, b, c, root1, root1);

    if (root_number == 0 || root_number == -1)
        return Vector(NAN, NAN, NAN, sf::Color::Black);

    if (root1 > 0)
        return v0 + ray * root1;
    
    if (root_number == 2 && root2 > 0)
        return v0 + ray * root2;

    return Vector(NAN, NAN, NAN, sf::Color::Black);
}
