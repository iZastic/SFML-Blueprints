//
// Created by iZastic on 11/8/2015.
//

#include "Game.hpp"

Game::Game()
        : _width(800), _height(600),
          _window(sf::VideoMode(_width, _height), "SFML-Blueprints Chapter-3"),
          _running(true)
{
    _player.setPosition(_width / 2, _height / 2);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time lastStep;
    sf::Time fixedStep = sf::seconds(1.f / 60);

    // Implements the "Minimum time step" model
    // Game runs as fast as it can, passing last delta to update()
    while (_running) {
        processEvents();
        lastStep = clock.restart();
        while (lastStep > fixedStep) {
            lastStep -= fixedStep;
            update(fixedStep);
        }
        update(lastStep);
        render();
    }
    _window.close();
}

void Game::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _running = false;
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    _running = false;
                }
        }
    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime)
{
    _player.update(deltaTime);

    sf::Vector2f playerPosition = _player.getPosition();
    if (playerPosition.x < 0) {
        playerPosition.x = _width;
        playerPosition.y = _height - playerPosition.y;
    }
    else if (playerPosition.x > _width) {
        playerPosition.x = 0;
        playerPosition.y = _height - playerPosition.y;
    }

    if (playerPosition.y < 0) {
        playerPosition.y = _height;
    }
    else if (playerPosition.y > _height) {
        playerPosition.y = 0;
    }

    _player.setPosition(playerPosition);
}

void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.display();
}
