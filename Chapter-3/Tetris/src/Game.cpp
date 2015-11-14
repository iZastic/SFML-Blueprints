//
// Created by iZastic on 11/14/2015.
//

#include "Game.hpp"
#include "Random.hpp"

Game::Game() : _window(sf::VideoMode(800, 600), "SFML Tetris"), _board()
{
    Random::init();
    _board.setPosition(10, 10);
    _stats.setPosition(300, 10);
    newPiece();
}

void Game::run(int minFPS)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time fixedStep = sf::seconds(1.f / minFPS);

    while (_window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > fixedStep)
        {
            timeSinceLastUpdate -= fixedStep;
            update(fixedStep);
        }
        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                _window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        _window.close();
                        break;
                    case sf::Keyboard::Down:
                        _board.move(*_currentPiece, 0, 1);
                        break;
                    case sf::Keyboard::Left:
                        _board.move(*_currentPiece, -1, 0);
                        break;
                    case sf::Keyboard::Right:
                        _board.move(*_currentPiece, 1, 0);
                        break;
                    case sf::Keyboard::Space:
                        _board.drop(*_currentPiece);
                        newPiece();
                        break;
                    case sf::Keyboard::S:
                        _board.rotateRight(*_currentPiece);
                        break;
                    case sf::Keyboard::D:
                        _board.rotateLeft(*_currentPiece);
                        break;
                }
                break;
            default: break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    if (!_board.isGameOver())
    {
        _stats.addLines(_board.clearLines(*_currentPiece));
        _nextFall += deltaTime;
        if (!_board.isFallen(*_currentPiece) && _currentPiece->getTimeSinceLastMove() > sf::seconds(1.f))
            newPiece();
        sf::Time max_time = sf::seconds((float) std::max(0.1, 0.6 - 0.05 * _stats.getLevel()));
        while (_nextFall > max_time)
        {
            _nextFall -= max_time;
            _board.move(*_currentPiece, 0, 1);
        }
    }
    else
        _stats.gameOver();
}

void Game::render()
{
    _window.clear();
    if (!_board.isGameOver())
        _window.draw(_board);
    _window.draw(_stats);
    _window.display();
}

void Game::newPiece()
{
    _currentPiece.reset(new Piece((Piece::TetriminoTypes) Random::random(0, Piece::TetriminoTypes::SIZE - 1), 0));
    _board.spawn(*_currentPiece);
}