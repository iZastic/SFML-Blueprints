//
// Created by iZastic on 11/9/2015.
//

#include "Collision.hpp"
#include "Meteor.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Utils.hpp"

namespace ztc
{
    bool Meteor::isCollide(const Entity &other) const
    {
        const Player *player = dynamic_cast<const Player *>(&other);
        return (player == nullptr ? dynamic_cast<const Meteor *>(&other) == nullptr : !player->isShielded()) && Collision::circleTest(_sprite, other._sprite);
    }

    void Meteor::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();
        _sprite.move(seconds * _impulse);
        _sprite.rotate(_rotation);
    }

    BigMeteor::BigMeteor(World &world) :
            Meteor((Configuration::Textures) Utils::random(Configuration::Textures::BigMeteor1,
                                                           Configuration::Textures::BigMeteor4), world)
    {
        _impulse *= 100.f;
        _rotation = Utils::random(0.025f, 0.05f);
    }

    int BigMeteor::getPoints() const
    {
        return 20;
    }

    void BigMeteor::onDestroy()
    {
        Meteor::onDestroy();
        int nb = Utils::random(2, 3);
        for (int i = 0; i < nb; i++)
        {
            MediumMeteor *meteor = new MediumMeteor(_world);
            meteor->setPosition(getPosition());
            _world.add(meteor);
        }
        _world.add(Configuration::Sounds::Explosion1);
    }

    MediumMeteor::MediumMeteor(World &world) :
            Meteor((Configuration::Textures) Utils::random(Configuration::Textures::MediumMeteor1,
                                                           Configuration::Textures::MediumMeteor2), world)
    {
        _impulse *= 200.f;
        _rotation = Utils::random(0.05f, 0.075f);
    }

    int MediumMeteor::getPoints() const
    {
        return 60;
    }

    void MediumMeteor::onDestroy()
    {
        Meteor::onDestroy();
        int nb = Utils::random(2, 3);
        for (int i = 0; i < nb; i++)
        {
            SmallMeteor *meteor = new SmallMeteor(_world);
            meteor->setPosition(getPosition());
            _world.add(meteor);
        }
        _world.add(Configuration::Sounds::Explosion2);
    }

    SmallMeteor::SmallMeteor(World &world) :
            Meteor((Configuration::Textures) Utils::random(Configuration::Textures::SmallMeteor1,
                                                           Configuration::Textures::SmallMeteor4), world)
    {
        _impulse *= 300.f;
        _rotation = Utils::random(0.075f, 0.1f);
    }

    int SmallMeteor::getPoints() const
    {
        return 100;
    }

    void SmallMeteor::onDestroy()
    {
        Meteor::onDestroy();
        _world.add(Configuration::Sounds::Explosion3);
    }
}