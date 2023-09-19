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
                    result.setPixel(x, y, sf::Color::Black);
                else
                {
                    int r = 0;
                    int g = 0;
                    int b = 0;
                    double diff_coeff = 0;
                    double spec_coeff = 0;

                    Vector normal = int_point - objects[obj_i].GetCenter();

                    for (int l_i = 0; l_i < light_src.GetLength(); l_i++)
                    {
                        Vector light_ray     = light_src[l_i] - int_point;
                        Vector reflected_ray = light_ray - normal * 2 * (normal ^ light_ray);

                        double spec_coeff_i = (camera - int_point) ^ reflected_ray;
                        double diff_coeff_i = normal ^ light_ray; 

                        //if (spec_coeff_i > 0)
                        //    spec
                        if (diff_coeff_i > 0)
                        {
                            diff_coeff += diff_coeff_i;
                        }
                    }

                    r = (int)(diff_coeff * objects[obj_i].GetColor().r);
                    g = (int)(diff_coeff * objects[obj_i].GetColor().g);
                    b = (int)(diff_coeff * objects[obj_i].GetColor().b);
                    
                    r = (r > 255) ? 255 : r;
                    g = (g > 255) ? 255 : g;
                    b = (b > 255) ? 255 : b;

                    result.setPixel(x, y, sf::Color(r, g, b));
                }
            }
        }

        iterator += -Vector(screen.width, 0, 0);
    }

    sf::Texture texture;
    texture.loadFromImage(result);
    sf::Sprite sprite(texture);

    window->draw(sprite);
}
