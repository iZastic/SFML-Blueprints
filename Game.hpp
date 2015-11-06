//
// Created by iZastic on 11/1/2015.
//

#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Game
{
public:
    /**
     * This c++11 feature lets us delete the copy constructor and operator,
     * which makes this class non-copyable. Only want one game.
     */
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);

    void render();

    sf::RenderWindow _window;
    Player _player;
    bool _running;
};


#endif //SFMLTEST_GAME_HPP
