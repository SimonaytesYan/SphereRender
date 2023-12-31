#include <SFML/Graphics.hpp>

#include "DynArray/DynArray.h"
#include "Scene/Scene.h"
#include "Screen/Screen.h"
#include "Sphere/Sphere.h"
#include "Vector/Vector.h"

const char kWindowHeader[] = "Sphere";
const int  kWindowSize     = 800;

int main()
{
    sf::RenderWindow window(sf::VideoMode(kWindowSize, kWindowSize), 
                            kWindowHeader);
	Vector camera(0, 0, 0);
	Vector light_src0(0, -400, 150, Color(255, 255, 255));
	Vector light_src1(50, 0, 0, Color(0, 255, 255));
	Vector light_src2(0, 500, 150, Color(255, 0, 255));

	Sphere sphere(Vector(0, 0, 150), 100, Color(128, 128, 128), 20);
	
	Screen screen(Vector(-50, -50, 50), 100, 100, kWindowSize, kWindowSize);

	Scene scene(camera, screen, 0.15);
	scene.AddLLightSrc(light_src0);
	scene.AddLLightSrc(light_src1);
	scene.AddLLightSrc(light_src2);
	scene.AddObject(sphere);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
				}
			}
		}

		scene.Draw(&window);
		window.display();
    }
}
