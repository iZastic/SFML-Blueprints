//
// Created by iZastic on 11/1/2015.
//
#define _USE_MATH_DEFINES

#include "Player.hpp"
#include "../Chapter-2/Configuration.hpp"

Player::Player() : ActionTarget(Configuration::playerInputs), _isMoving(false), _rotation(0)
{
    Configuration::textures.get(Configuration::Textures::Player).setSmooth(true);
    _ship.setTexture(Configuration::textures.get(Configuration::Textures::Player));
    _ship.setOrigin(49.5, 37.5);
    setPosition(49.5, 37.5);

    bind(Configuration::PlayerInputs::Up, [this](const sf::Event &) {
        _isMoving = true;
    });

    bind(Configuration::PlayerInputs::Left, [this](const sf::Event &) {
        _rotation -= 1;
    });

    bind(Configuration::PlayerInputs::Right, [this](const sf::Event &) {
        _rotation += 1;
    });
}

void Player::processEvents()
{
    _isMoving = false;
    _rotation = 0;
    ActionTarget::processEvents();
}


void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    if (_rotation != 0) {
        float angle = _rotation * 180 * seconds;
        _ship.rotate(angle);
    }
    if (_isMoving) {
        float angle = float(_ship.getRotation() / 180 * M_PI - M_PI_2);
        _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
    }
    _ship.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_ship, states);
}