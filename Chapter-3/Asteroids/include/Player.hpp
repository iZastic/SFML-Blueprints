//
// Created by iZastic on 11/1/2015.
//

#ifndef SFML_BLUEPRINTS_PLAYER_HPP
#define SFML_BLUEPRINTS_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "ActionTarget.hpp"
#include "Entity.hpp"
#include "World.hpp"

namespace ztc
{
    class Player : public Entity, public ActionTarget<int>
    {
    public:
        /**
         * This c++11 feature lets us delete the copy constructor and operator,
         * which makes this class non-copyable. Only want one player.
         */
        Player(const Player &) = delete;
        Player &operator=(const Player &) = delete;

        Player(World &world);

        virtual bool isCollide(const Entity &other) const;
        virtual void update(sf::Time deltaTime);
        virtual void onDestroy();

        void processEvents();
        void shoot();
        void goToHyperspace();

        bool isShielded() const;

    private:
        bool _isMoving;
        int _rotation;
        sf::Time _shield;
        sf::Time _timeSinceLastShoot;
        sf::CircleShape _shieldShape;

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };
}

#endif //SFML_BLUEPRINTS_PLAYER_HPP
