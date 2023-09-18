#include <cmath>

#include "Vector.h"

Vector::Vector(double x, double y, double z, sf::Color color) :
x (x),
y (y),
z (z),
color (color)
{}

Vector::~Vector()
{
    this->x = NAN;
    this->y = NAN;
    this->z = NAN;
}

Vector operator+(const Vector& a, const Vector& b)
{
    sf::Color new_color((a.color.r + b.color.r)/2, 
                        (a.color.g + b.color.g)/2,
                        (a.color.b + b.color.b)/2);

    Vector res = Vector(a.x + b.x, a.y + b.y, a.z + b.z,  new_color);
    return res;
}

Vector operator-(const Vector& a)
{
    sf::Color new_color(255 - a.color.r, 
                        255 - a.color.g, 
                        255 - a.color.b);
    return Vector(-a.x, -a.y, -a.z, new_color);
}

Vector operator-(const Vector& a, const Vector& b)
{
    return a + (-b);
}

Vector operator*(const Vector& a, double b)
{
    return Vector(a.x * b, a.y * b, a.z * b, a.color);
}

Vector operator/(const Vector& a, double b)
{
    return Vector(a.x / b, a.y / b, a.z / b, a.color);
}

double operator,(const Vector& a, const Vector& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector operator!(const Vector& a)
{
    double a_len = a.Length();
    return Vector(a.x / a_len, a.y / a_len, a.z / a_len);
}

inline double Vector::Length() const
{ 
	return sqrt(x*x + y*y + z*z);
}
