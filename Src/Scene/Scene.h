#ifndef SYM_SCENE
#define SYM_SCENE

#include "../DynArray/DynArray.h"
#include "../Screen/Screen.h"
#include "../Sphere/Sphere.h"
#include "../Vector/Vector.h"

class Scene
{
    Vector camera = Vector(0, 0, 0);
    Screen screen;
    
    DynArray<Vector> lights_sources = DynArray<Vector>(0);
    DynArray<Sphere> objects        = DynArray<Sphere>(0);

    public :
    Scene(Vector _camera, Screen _screen)
    {
        camera = _camera;
        screen = _screen;

        lights_sources = DynArray<Vector>(0);
        objects        = DynArray<Sphere>(0);
    };

    void AddLightPoint(Vector new_light_source) { lights_sources.PushBack(new_light_source); };
    void AddObject(Sphere new_object) { objects.PushBack(new_object); };

    void Draw(sf::RenderWindow* window);
};

#endif //SYM_SCENE