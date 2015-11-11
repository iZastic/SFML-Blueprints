//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_BLUEPRINTS_SAUCER_HPP
#define SFML_BLUEPRINTS_SAUCER_HPP

#include "Enemy.hpp"

namespace ztc
{
    class Saucer : public Enemy
    {
    public:
        Saucer(const Saucer &) = delete;
        Saucer &operator=(const Saucer &) = delete;

        using Enemy::Enemy;

        virtual bool isCollide(const Entity &other) const;
        virtual void update(sf::Time deltaTime);
        virtual void onDestroy();

        static void newSaucer(World &world);
    };

    class BigSaucer : public Saucer
    {
    public:
        BigSaucer(World &world);
        virtual int getPoints() const;
    };

    class SmallSaucer : public Saucer
    {
    public:
        SmallSaucer(World &world);
        virtual int getPoints() const;
        virtual void update(sf::Time deltaTime);
    private:
        sf::Time _timeSinceLastShoot;
    };
}

#endif //SFML_BLUEPRINTS_SAUCER_HPP
