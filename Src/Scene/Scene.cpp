#include <SFML/Graphics.hpp>

#include "Scene.h"

void Scene::Draw(sf::RenderWindow* window)
{
    Vector iterator = screen.v0;
    Vector delta_x(screen.width / screen.x_pixel_n, 0, 0);
    Vector delta_y(0, screen.height / screen.y_pixel_n, 0);
    
    sf::Image result;
    result.create(screen.x_pixel_n, screen.y_pixel_n, sf::Color::Black);

    for (int y = 0; y < screen.y_pixel_n; y++, iterator += delta_y)
    {
        for (int x = 0; x < screen.x_pixel_n; x++, iterator += delta_x)
        {
            Vector ray = iterator - camera;
            
            for (int obj_i = 0; obj_i < objects.GetLength(); obj_i++)
            {
                Vector int_point = objects[obj_i].GetIntersectionPoint(camera, ray);

                if (int_point.GetColor() == sf::Color::Black)
                    continue;

                Color color(0, 0, 0);
                Vector normal = int_point - objects[obj_i].GetCenter();

                for (int l_i = 0; l_i < light_src.GetLength(); l_i++)
                {
                    Vector light_ray     =  light_src[l_i] - int_point;
                    Vector reflected_ray = -light_ray - (normal * 2 * (normal ^ (-light_ray)));

                    double spec_coeff = (camera - int_point) ^ reflected_ray;
                    double diff_coeff = normal ^ light_ray; 

                    if (spec_coeff > 0)
                        color = color + light_src[l_i].GetColor() * pow(spec_coeff, objects[obj_i].GetShininessFact());
                    if (diff_coeff > 0)
                        color = color + (light_src[l_i].GetColor() * objects[obj_i].GetColor()) * diff_coeff;
                }
                result.setPixel(x, y, color + objects[obj_i].GetColor() * background_light);
            }
        }

        iterator += -Vector(screen.width, 0, 0);
    }

    sf::Texture texture;
    texture.loadFromImage(result);
    sf::Sprite sprite(texture);

    window->draw(sprite);
}
