//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_BLUEPRINTS_ENTITY_HPP
#define SFML_BLUEPRINTS_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "Configuration.hpp"

namespace ztc
{
    class World;
    class Entity : public sf::Drawable
    {
    public:
        /**
         * This c++11 feature lets us delete the copy constructor and operator,
         * which makes this class non-copyable.
         */
        Entity(const Entity &) = delete;
        Entity &operator=(const Entity &) = delete;

        Entity(Configuration::Textures textureID, World &world);
        virtual ~Entity() {}

        virtual bool isAlive() const;
        virtual bool isCollide(const Entity &other) const = 0;

        const sf::Vector2f &getPosition() const;
        template<typename ... Args>
        void setPosition(Args &&... args)
        {
            _sprite.setPosition(std::forward<Args>(args) ...);
        }

        virtual void update(sf::Time deltaTime) = 0;
        virtual void onDestroy();

    protected:
        friend class Saucer;
        friend class Meteor;
        friend class Player;
        friend class ShootPlayer;
        friend class ShootSaucer;

        sf::Sprite _sprite;
        sf::Vector2f _impulse;
        World &_world;
        bool _alive;

    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };
}

#endif //SFML_BLUEPRINTS_ENTITY_HPP
