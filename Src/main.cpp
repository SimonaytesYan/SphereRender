#include <SFML/Graphics.hpp>

#include "DynArray/DynArray.h"
#include "Scene/Scene.h"
#include "Screen/Screen.h"
#include "Sphere/Sphere.h"
#include "Vector/Vector.h"

const char kWindowHeader[] = "Sphere";

int main()
{
    sf::RenderWindow window(sf::VideoMode(), 
                            kWindowHeader, sf::Style::Fullscreen);



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

		window.display();
    }
}

void DrawSphere()
{

}