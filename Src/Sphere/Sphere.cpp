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
    
    double D = b * b - 4 * a * c;
    if (D < 0)
        return 0;
    if (D == 0)
    {
        x1 = -b / (2 * a);
        return 1;
    }

    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);

    return 2;
}

double min(double a, double b)
{
    return (a < b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

Vector Sphere::GetIntersectionPoint(Vector v0, Vector ray)
{
    Vector center1 = (center - v0);

    double a = (ray, ray);
    double b = -2 * (ray, center1);
    double c = (center1, center1) - r * r;

    double root1       = 0;
    double root2       = 0;
    int    root_number = SolveSqrEqu(a, b, c, root1, root2);

    if (root_number == 0 || root_number == -1)
        return Vector(NAN, NAN, NAN, Color(0, 0, 0));
    
    if (root_number == 2)
        return v0 + ray * min(root2, root1);

    return v0 + ray * root1;
}
