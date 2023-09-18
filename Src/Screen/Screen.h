#ifndef SYM_SCREEN
#define SYM_SCREEN

class Screen        //plane parallel to the  at a distance z from camera
{
    double z;       //distance from camera
    double height;  //size of the screen
    double weight;  //size of the screen

    double x_pixel_n;   //screen resolution
    double y_pixel_n;   //screen resolution
};

#endif //SYM_SCREEN