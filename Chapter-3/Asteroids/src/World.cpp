//
// Created by iZastic on 11/8/2015.
//

#include "World.hpp"
#include "Entity.hpp"

namespace ztc
{
    World::World(int width, int height) : _width(width), _height(height)
    {
    }

    World::~World()
    {
        clear();
    }

    void World::add(Entity *entity)
    {
        _entitiesTemp.push_back(entity);
    }

    void World::add(Configuration::Sounds soundID)
    {
        std::unique_ptr<sf::Sound> sound(new sf::Sound(Configuration::sounds.get(soundID)));
        sound->setAttenuation(0);
        sound->play();
        _sounds.emplace_back(std::move(sound));
    }

    void World::clear()
    {
        for (Entity *entity : _entities)
            delete entity;
        _entities.clear();

        for (Entity *entity : _entitiesTemp)
            delete entity;
        _entitiesTemp.clear();

        _sounds.clear();
    }

    bool World::isCollide(const Entity &other)
    {
        for (Entity *entityPtr : _entities)
            if (other.isCollide(*entityPtr))
                return true;
        return false;
    }

    int World::size()
    {
        return _entities.size() + _entitiesTemp.size();
    }

    const std::list<Entity *> World::getEntities() const
    {
        return _entities;
    }

    int World::getWidth() const
    {
        return _width;
    }

    int World::getHeight() const
    {
        return _height;
    }

    void World::update(sf::Time deltaTime)
    {
        if (_entitiesTemp.size() > 0)
            _entities.merge(_entitiesTemp);

        for (Entity *entityPtr : _entities)
        {
            Entity &entity = *entityPtr;
            entity.update(deltaTime);

            sf::Vector2f pos = entity.getPosition();
            if (pos.x < 0)
            {
                pos.x = _width;
                pos.y = _height - pos.y;
            }
            else if (pos.x > _width)
            {
                pos.x = 0;
                pos.y = _height - pos.y;
            }
            if (pos.y < 0)
            {
                pos.y = _height;
            }
            else if (pos.y > _height)
            {
                pos.y = 0;
            }
            entity.setPosition(pos);
        }

        const auto end = _entities.end();
        for (auto it_i = _entities.begin(); it_i != end; ++it_i)
        {
            Entity &entity_i = **it_i;
            auto it_j = it_i;
            it_j++;
            for (; it_j != end; ++it_j)
            {
                Entity &entity_j = **it_j;

                if (entity_i.isAlive() && entity_i.isCollide(entity_j))
                    entity_i.onDestroy();

                if (entity_j.isAlive() && entity_j.isCollide(entity_i))
                    entity_j.onDestroy();
            }
        }

        for (auto it = _entities.begin(); it != _entities.end();)
        {
            if (!(*it)->isAlive())
            {
                delete *it;
                it = _entities.erase(it);
            }
            else
            {
                ++it;
            }
        }

        _sounds.remove_if([](const std::unique_ptr<sf::Sound> &sound) -> bool {
            return sound->getStatus() != sf::SoundSource::Status::Playing;
        });
    }

    void World::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        for (Entity *entity : _entities)
            target.draw(*entity, states);
    }
}