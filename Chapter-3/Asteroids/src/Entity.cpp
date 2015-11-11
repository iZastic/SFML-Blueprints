//
// Created by iZastic on 11/8/2015.
//

#include "Entity.hpp"
#include "World.hpp"

namespace ztc
{
    Entity::Entity(Configuration::Textures textureID, World &world) : _world(world), _alive(true)
    {
        sf::Texture &texture = Configuration::textures.get(textureID);
        texture.isSmooth();
        _sprite.setTexture(texture);
        _sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    }

    bool Entity::isAlive() const
    {
        return _alive;
    }

    const sf::Vector2f &Entity::getPosition() const
    {
        return _sprite.getPosition();
    }

    void Entity::onDestroy()
    {
        _alive = false;
    }

    void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);
    }
}