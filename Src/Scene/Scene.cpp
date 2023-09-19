#include <SFML/Graphics.hpp>

#include "Scene.h"

void Scene::Draw(sf::RenderWindow* window)
{
    Vector iterator = screen.v0;
    Vector delta_x(screen.weight / screen.x_pixel_n, 0, 0);
    Vector delta_y(0, screen.height / screen.y_pixel_n, 0);
    
    sf::Image result;
    result.create(screen.x_pixel_n, screen.y_pixel_n, sf::Color::Black);

    for (int y = 0; y < screen.y_pixel_n; y++, iterator += delta_x)
    {
        for (int x = 0; x < screen.x_pixel_n; x++, iterator += delta_y)
        {
            Vector ray = iterator - camera;
            
            for (int obj_i = 0; obj_i < objects.GetLength(); obj_i++)
            {
                Vector int_point = objects[obj_i].GetIntersectionPoint(iterator, ray);

                if (int_point.GetColor() == sf::Color::Black)
                    result.setPixel(x, y, sf::Color::Black);
                else
                {
                    sf::Color new_pixel(0, 0, 0);
                    Vector normal = int_point - objects[obj_i].GetCenter();
                    
                    for (int l_i = 0; l_i < light_src.GetLength(); l_i++)
                    {
                        double diff_coeff = (normal, light_src[l_i]) / 
                                            (normal.Length() * light_src[l_i].Length());

                        new_pixel.r += diff_coeff * objects[obj_i].GetColor().r;
                        new_pixel.g += diff_coeff * objects[obj_i].GetColor().g;
                        new_pixel.b += diff_coeff * objects[obj_i].GetColor().b;
                    }

                    result.setPixel(x, y, new_pixel);
                }
            }
        }
    }

    sf::Texture texture;
    texture.loadFromImage(result);
    sf::Sprite sprite(texture);

    window->draw(sprite);
}
