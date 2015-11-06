//
// Created by iZastic on 11/1/2015.
//

#include "Game.hpp"

Game::Game()
        : _window(sf::VideoMode(800, 600), "SFML-Blueprints"),
          _running(true)
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time lastStep;
    sf::Time fixedStep = sf::seconds(1.f / 60);

    // Implements the "Minimum time step" model
    // Game runs as fast as it can, passing last delta to update()
    while (_running)
    {
        processEvents();
        lastStep = clock.restart();
        while (lastStep > fixedStep)
        {
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
    while (_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                _running = false;
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    _running = false;
        }
    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime)
{
    _player.update(deltaTime);
}

void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.display();
}
