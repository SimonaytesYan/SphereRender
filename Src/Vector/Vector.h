#ifndef SYM_GEOM_VECTOR
#define SYM_GEOM_VECTOR

#include <math.h>
#include <SFML/Graphics.hpp>

#include "../Color/Color.h"

class Vector
{
    protected :
    double x;
    double y;
    double z;

    Color color;

    public : 
    Vector(double x, double y, double z, Color color = Color(255, 255, 255));
    ~Vector();
    
    double GetX()     {return x;};
    double GetY()     {return y;};
    double GetZ()     {return z;};
    Color  GetColor() {return color;};

    inline double Length() const { return sqrt(x*x + y*y + z*z); };

    void Dump();

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a);
    friend Vector operator+=(Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, double b);
    friend Vector operator/(const Vector& a, double b);
    friend double operator,(const Vector& a, const Vector& b);  
    friend Vector operator!(const Vector& a);
    friend double operator^(const Vector& a, const Vector& b);
};

Vector operator-(const Vector& a);
Vector operator-(const Vector& a, const Vector& b);
Vector operator+=(Vector& a, const Vector& b);
Vector operator*(const Vector& a, double b);
Vector operator/(const Vector& a, double b);
double operator,(const Vector& a, const Vector& b);		//scalar product
Vector operator!(const Vector& a);						//return normalized vector
Vector operator+(const Vector& a);						//return normal to vector
double operator^(const Vector& a, const Vector& b);     //return cos between vectors

#endif //SYM_GEOM_VECTOR
