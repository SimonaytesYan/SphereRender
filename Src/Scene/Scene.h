#ifndef SYM_SCENE
#define SYM_SCENE

#include "../DynArray/DynArray.h"
#include "../Screen/Screen.h"
#include "../Sphere/Sphere.h"
#include "../Vector/Vector.h"

class Scene
{
    Vector camera;
    Screen screen;
    
    DynArray<Vector> light_src = DynArray<Vector>(0);
    DynArray<Sphere> objects        = DynArray<Sphere>(0);

    double background_light;

    public :
    Scene(Vector _camera, Screen _screen, double _background_light = 0.15) :
    camera (_camera),
    screen (_screen),
    background_light (_background_light)
    {
        light_src = DynArray<Vector>(0);
        objects   = DynArray<Sphere>(0); 
    };

    void AddLLightSrc(Vector new_light_source) { light_src.PushBack(new_light_source); };
    void AddObject(Sphere new_object) { objects.PushBack(new_object); };

    void Draw(sf::RenderWindow* window);
};

#endif //SYM_SCENE