//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_BLUEPRINTS_COLLISION_HPP
#define SFML_BLUEPRINTS_COLLISION_HPP

#include <SFML/Graphics.hpp>

namespace ztc
{
    class Collision
    {
    public:
        Collision() = delete;
        Collision(const Collision &) = delete;
        Collision &operator=(const Collision &) = delete;

        static bool circleTest(const sf::Sprite &first, const sf::Sprite &seconds);
    };
}

#endif //SFML_BLUEPRINTS_COLLISION_HPP
