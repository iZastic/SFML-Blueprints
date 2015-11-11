//
// Created by iZastic on 11/8/2015.
//

#include <cmath>
#include "Collision.hpp"
#include "Shoot.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Saucer.hpp"
#include "Meteor.hpp"
#include "Utils.hpp"

namespace ztc
{
    bool Saucer::isCollide(const Entity &other) const
    {
        return dynamic_cast<const ShootSaucer *>(&other) == nullptr && Collision::circleTest(_sprite, other._sprite);
    }

    void Saucer::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();
        Entity *near = nullptr;
        float near_distance = 300;
        for (Entity *entityPtr : _world.getEntities())
        {
            if (entityPtr != this && (dynamic_cast<const Meteor *>(entityPtr) ||
                                      dynamic_cast<const ShootPlayer *>(entityPtr)))
            {
                float x = getPosition().x - entityPtr->getPosition().x;
                float y = getPosition().y - entityPtr->getPosition().y;
                float dist = std::sqrt(x * x + y * y);
                if (dist < near_distance)
                {
                    near_distance = dist;
                    near = entityPtr;
                }
            }
        }
        if (near != nullptr)
        {
            sf::Vector2f pos = near->getPosition() - getPosition();
            float angle_rad = std::atan2(pos.y, pos.x);
            _impulse -= sf::Vector2f(std::cos(angle_rad), std::sin(angle_rad)) * 300.f * seconds;
        }
        else
        {
            sf::Vector2f pos = Configuration::player->getPosition() - getPosition();
            float angle_rad = std::atan2(pos.y, pos.x);
            _impulse += sf::Vector2f(std::cos(angle_rad), std::sin(angle_rad)) * 100.f * seconds;
        }
        _sprite.move(seconds * _impulse);
    }

    void Saucer::onDestroy()
    {
        Enemy::onDestroy();
        _world.add(Configuration::Sounds::Boom2);
    }

    void Saucer::newSaucer(World &world)
    {
        Saucer *res = nullptr;
        if (Utils::random(0.f, 1.f) > Configuration::getScore() / 40000.f)
            res = new BigSaucer(world);
        else
            res = new SmallSaucer(world);
        res->setPosition(Utils::random(0, 1) * world.getWidth(),
                         Utils::random(0.f, (float) world.getHeight()));
        world.add(res);
    }

/**********  BIG SAUCER  **********/
    BigSaucer::BigSaucer(World &world) : Saucer(Configuration::Textures::BigSaucer, world)
    {
        _world.add(Configuration::Sounds::SaucerSpawn1);
        _impulse *= 300.f;
    }

    int BigSaucer::getPoints() const
    {
        return 50;
    }

/********** SMALL SAUCER **********/
    SmallSaucer::SmallSaucer(World &world) : Saucer(Configuration::Textures::SmallSaucer, world)
    {
        _timeSinceLastShoot = sf::Time::Zero;
        _world.add(Configuration::Sounds::SaucerSpawn2);
        _impulse *= 400.f;
    }

    int SmallSaucer::getPoints() const
    {
        return 200;
    }

    void SmallSaucer::update(sf::Time deltaTime)
    {
        Saucer::update(deltaTime);
        _timeSinceLastShoot += deltaTime;
        if (_timeSinceLastShoot > sf::seconds(1.5))
        {
            if (Configuration::player != nullptr)
                _world.add(new ShootSaucer(*this));
            _timeSinceLastShoot = sf::Time::Zero;
        }
    }
}