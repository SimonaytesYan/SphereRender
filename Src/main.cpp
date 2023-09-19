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

	Sphere sphere(Vector(0, 0, 15), 5, sf::Color::Green);
	Vector light_src(10, 10, 10, sf::Color::White);
	Screen screen(Vector(-10, 10, 5), 20, 20, kWindowSize, kWindowSize);
	Vector camera(0, 0, 0);

	Scene scene(camera, screen);
	scene.AddLLightSrc(light_src);
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
