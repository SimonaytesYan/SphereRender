#ifndef SYM_GEOM_VECTOR
#define SYM_GEOM_VECTOR

#include <SFML/Graphics.hpp>

class Vector
{
    protected :
    double x;
    double y;
    double z;

    sf::Color color;

    public : 
    Vector(double x, double y, double z, sf::Color color = sf::Color::White);
    ~Vector();
    
    double    GetX()     {return x;};
    double    GetY()     {return y;};
    double    GetZ()     {return z;};
    sf::Color GetColor() {return color;};

    inline double Length() const;

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, double b);
    friend Vector operator/(const Vector& a, double b);
    friend double operator,(const Vector& a, const Vector& b);  
    friend Vector operator!(const Vector& a);
};

Vector operator-(const Vector& a);
Vector operator-(const Vector& a, const Vector& b);
Vector operator*(const Vector& a, double b);
Vector operator/(const Vector& a, double b);
double operator,(const Vector& a, const Vector& b);		//scalar product
Vector operator!(const Vector& a);						//return normalized vector
Vector operator+(const Vector& a);						//return normal to vector

#endif //SYM_GEOM_VECTOR