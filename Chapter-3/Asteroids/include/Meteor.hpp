//
// Created by iZastic on 11/9/2015.
//

#ifndef SFML_BLUEPRINTS_METEOR_HPP
#define SFML_BLUEPRINTS_METEOR_HPP

#include "Enemy.hpp"

namespace ztc
{
    class Meteor : public Enemy
    {
    public:
        Meteor(const Meteor &) = delete;
        Meteor &operator=(const Meteor &) = delete;

        using Enemy::Enemy;

        virtual bool isCollide(const Entity &other) const;
        virtual void update(sf::Time deltaTime);
    protected:
        float _rotation;
    };

    class BigMeteor : public Meteor
    {
    public :
        BigMeteor(World &world);
        virtual int getPoints() const;
        virtual void onDestroy();
    };

    class MediumMeteor : public Meteor
    {
    public :
        MediumMeteor(World &world);
        virtual int getPoints() const;
        virtual void onDestroy();
    };

    class SmallMeteor : public Meteor
    {
    public :
        SmallMeteor(World &world);
        virtual int getPoints() const;
        virtual void onDestroy();
    };
}

#endif //SFML_BLUEPRINTS_METEOR_HPP
