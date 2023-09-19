#include "Color.h"

Color operator*(Color color, double coeff)
{
    u_int8_t r = ((double)color.r * coeff > 255) ? 255 : color.r * coeff;
    u_int8_t g = ((double)color.g * coeff > 255) ? 255 : color.g * coeff;
    u_int8_t b = ((double)color.b * coeff > 255) ? 255 : color.b * coeff;
    u_int8_t a = ((double)color.a * coeff > 255) ? 255 : color.a * coeff;

    return Color(r, g, b, a);
}

Color operator+(Color color_a, Color color_b)
{
    short r = ((int)color_a.r + (int)color_b.r > 255) ? 255 : color_a.r + color_b.r;
    short g = ((int)color_a.g + (int)color_b.g > 255) ? 255 : color_a.g + color_b.g;
    short b = ((int)color_a.b + (int)color_b.b > 255) ? 255 : color_a.b + color_b.b;
    short a = ((int)color_a.a + (int)color_b.a > 255) ? 255 : color_a.a + color_b.a;

    return Color(r, g, b, a);
}
