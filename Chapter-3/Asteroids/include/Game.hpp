//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_GAME_HPP
#define SFML_GAME_HPP

#include <SFML/Graphics.hpp>
#include "World.hpp"

namespace ztc
{
    class Game
    {
    public:
        /**
         * This c++11 feature lets us delete the copy constructor and operator,
         * which makes this class non-copyable. Only want one game.
         */
        Game(const Game &) = delete;
        Game &operator=(const Game &) = delete;

        Game(unsigned int width = 800, unsigned int height = 600);
        void run(int minFPS = 60);

        void initLevel();

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        void reset();

        sf::RenderWindow _window;
        World _world;

        sf::Time _nextSaucer;
        sf::Text _text;
    };
}

#endif //SFMLTEST_GAME_HPP
