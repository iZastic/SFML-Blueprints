//
// Created by iZastic on 11/8/2015.
//
#define _USE_MATH_DEFINES

#include "Enemy.hpp"
#include "Utils.hpp"
#include <cmath>

namespace ztc
{
    Enemy::Enemy(Configuration::Textures textureID, World &world) : Entity(textureID, world)
    {
        float angle = Utils::random(0.f, 2.f * M_PI);
        _impulse = sf::Vector2f(std::cos(angle), std::sin(angle));
    }

    void Enemy::onDestroy()
    {
        Entity::onDestroy();
        Configuration::addScore(getPoints());
    }
}