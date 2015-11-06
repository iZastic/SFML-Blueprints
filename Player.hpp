//
// Created by iZastic on 11/1/2015.
//

#ifndef SFML_BLUEPRINTS_PLAYER_HPP
#define SFML_BLUEPRINTS_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "ActionTarget.hpp"

class Player : public sf::Drawable, public ActionTarget<int>
{
public:
    /**
     * This c++11 feature lets us delete the copy constructor and operator,
     * which makes this class non-copyable. Only want one player.
     */
    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;

    Player();

    /**
     * This c++11 feature, variadic template, simple forwards any arguments to the
     * parent class without knowing them. This makes it possible to use both functions.
     */
    template<typename ... Args>
    void setPosition(Args &&... args)
    {
        _shape.setPosition(std::forward<Args>(args) ...);
    }

    void processEvents();
    void update(sf::Time deltaTime);

    enum PlayerInputs {
        Up,
        Left,
        Right
    };
    static void setDefaultInputs();

private:
    // Follow with, override, to make sure the function is overridden
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::RectangleShape _shape;
    sf::Vector2f _velocity;
    bool _isMoving;
    int _rotation;

    static ActionMap<int> _playerInputs;
};


#endif //SFML_BLUEPRINTS_PLAYER_HPP
