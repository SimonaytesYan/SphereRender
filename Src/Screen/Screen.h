#ifndef SYM_SCREEN
#define SYM_SCREEN

#include "../Vector/Vector.h"
#include "../Scene/Scene.h"

class Screen        //plane parallel with XOY
{
    public : 
    Vector v0;      //left bottom kernel
    double height;  //size of the screen
    double width;  //size of the screen

    unsigned int x_pixel_n;   //screen resolution
    unsigned int y_pixel_n;   //screen resolution

    Screen(Vector _v0, double _height, double _width, 
           unsigned int _x_pixel_n, unsigned int _y_pixel_n) :
    v0 (_v0),
    height (_height),
    width (_width),
    x_pixel_n (_x_pixel_n),
    y_pixel_n (_y_pixel_n)
    {};

    //friend void Scene::Draw(sf::RenderWindow* window);
};

#endif //SYM_SCREEN