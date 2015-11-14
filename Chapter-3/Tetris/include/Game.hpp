//
// Created by iZastic on 11/14/2015.
//

#ifndef SFML_BLUEPRINTS_GAME_HPP
#define SFML_BLUEPRINTS_GAME_HPP

#include "Board.hpp"
#include "Stats.hpp"

class Game
{
public:
    Game();
    void run(int minFPS = 60);

private:
    sf::RenderWindow _window;
    std::unique_ptr<Piece> _currentPiece;
    Board _board;
    Stats _stats;
    sf::Time _nextFall;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void newPiece();
};

#endif //SFML_BLUEPRINTS_GAME_HPP
