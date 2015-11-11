//
// Created by iZastic on 11/1/2015.
//
#define _USE_MATH_DEFINES

#include "Player.hpp"
#include "Collision.hpp"
#include "Shoot.hpp"
#include "Utils.hpp"
#include <cmath>

namespace ztc
{
    Player::Player(World &world) : Entity(Configuration::Textures::Player, world),
                                   ActionTarget(Configuration::playerInputs),
                                   _isMoving(false), _rotation(0)
    {
        bind(Configuration::PlayerInputs::Up, (const FuncType &) [this](const sf::Event &) {
            _isMoving = true;
        });

        bind(Configuration::PlayerInputs::Left, (const FuncType &) [this](const sf::Event &) {
            _rotation -= 1;
        });

        bind(Configuration::PlayerInputs::Right, (const FuncType &) [this](const sf::Event &) {
            _rotation += 1;
        });

        bind(Configuration::PlayerInputs::Shoot, (const FuncType &) [this](const sf::Event &) {
            shoot();
        });
        bind(Configuration::PlayerInputs::Hyperspace, (const FuncType &) [this](const sf::Event &) {
            goToHyperspace();
        });
        sf::Vector2u size = _sprite.getTexture()->getSize();
        _shieldShape = sf::CircleShape(std::sqrt(size.x * size.x + size.y * size.y) / 2);
        _shieldShape.setFillColor(sf::Color(255, 255, 0, 64));
        _shieldShape.setOrigin(_shieldShape.getRadius(), _shieldShape.getRadius());
    }

    bool Player::isCollide(const Entity &other) const
    {
        return _shield == sf::Time::Zero && dynamic_cast<const ShootPlayer *>(&other) == nullptr && Collision::circleTest(_sprite, other._sprite);
    }

    void Player::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
        ActionTarget::processEvents();
    }

    void Player::shoot()
    {
        if (_timeSinceLastShoot > sf::seconds(0.3) && _shield <= sf::Time::Zero)
        {
            _world.add(new ShootPlayer(*this));
            _timeSinceLastShoot = sf::Time::Zero;
        }
    }

    void Player::goToHyperspace()
    {
        _world.add(Configuration::Sounds::Jump);
        setPosition(Utils::random(0, _world.getWidth()), Utils::random(0, _world.getHeight()));
        _shield = sf::seconds(0.5f);
    }

    void Player::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();
        _timeSinceLastShoot += deltaTime;

        if (_rotation != 0)
        {
            float angle = _rotation * 250 * seconds;
            _sprite.rotate(angle);
        }

        if (_isMoving)
        {
            float angle = _sprite.getRotation() / 180 * M_PI - M_PI_2;
            _impulse += sf::Vector2f(std::cos(angle), std::sin(angle)) * 300.f * seconds;
        }

        if (_shield > sf::Time::Zero)
        {
            _shield -= deltaTime;
            _shieldShape.setPosition(getPosition());
        }
        else
            _shield = sf::Time::Zero;

        _sprite.move(seconds * _impulse);
    }

    void Player::onDestroy()
    {
        Entity::onDestroy();
        Configuration::lives--;
        Configuration::player = nullptr;
        _world.add(Configuration::Sounds::Boom);
        _shield = sf::Time::Zero;
    }

    bool Player::isShielded() const
    {
        return _shield != sf::Time::Zero;
    }

    void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        Entity::draw(target, states);
        if (_shield > sf::Time::Zero)
            target.draw(_shieldShape, states);
    }
}