//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_BLUEPRINTS_WORLD_HPP
#define SFML_BLUEPRINTS_WORLD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Configuration.hpp"
#include <memory>
#include <list>

namespace ztc
{
    class Entity;
    class World : public sf::Drawable
    {
    public:
        /**
         * This c++11 feature lets us delete the copy constructor and operator,
         * which makes this class non-copyable.
         */
        World(const World &) = delete;
        World &operator=(const World &) = delete;

        World(int width, int height);
        ~World();

        void add(Entity *entity);
        void add(Configuration::Sounds soundID);
        void clear();

        bool isCollide(const Entity &other);
        int size();

        const std::list<Entity *> getEntities() const;
        int getWidth() const;
        int getHeight() const;

        void update(sf::Time deltaTime);

    private:
        std::list<Entity *> _entities;
        std::list<Entity *> _entitiesTemp;

        std::list<std::unique_ptr<sf::Sound>> _sounds;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates) const override;

        const int _width, _height;
    };
}

#endif //SFML_BLUEPRINTS_WORLD_HPP
