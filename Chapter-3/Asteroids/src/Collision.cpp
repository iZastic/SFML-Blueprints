//
// Created by iZastic on 11/8/2015.
//

#include "Collision.hpp"
#include <cmath>

namespace ztc
{
    bool Collision::circleTest(const sf::Sprite &first, const sf::Sprite &second)
    {
        sf::Vector2f firstRect(first.getTextureRect().width, first.getTextureRect().height);
        firstRect.x *= first.getScale().x;
        firstRect.y *= first.getScale().y;

        sf::Vector2f secondRect(second.getTextureRect().width, second.getTextureRect().height);
        secondRect.x *= second.getScale().x;
        secondRect.y *= second.getScale().y;

        float r1 = (firstRect.x + firstRect.y) / 4;
        float r2 = (secondRect.x + secondRect.y) / 4;
        float xd = first.getPosition().x - second.getPosition().x;
        float yd = first.getPosition().y - second.getPosition().y;

        return std::sqrt(xd * xd + yd * yd) <= r1 + r2;
    }
}