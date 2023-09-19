#ifndef SYM_COLOR
#define SYM_COLOR

#include <SFML/Graphics.hpp>

struct Color
{
    u_int8_t r;
    u_int8_t g;
    u_int8_t b;
    u_int8_t a;

    Color() :
    r (0),
    g (0),
    b (0),
    a (255)
    {};
    
    Color(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a = 255) :
    r (r),
    g (g),
    b (b),
    a (a)
    {};

    operator sf::Color() { return sf::Color(r, g, b, a); };
};

Color operator*(Color color, double coeff);
Color operator+(Color color_a, Color color_b);

#endif //SYM_COLOR