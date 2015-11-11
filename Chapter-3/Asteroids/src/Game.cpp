//
// Created by iZastic on 11/8/2015.
//

#include "Game.hpp"
#include "Meteor.hpp"
#include "Saucer.hpp"
#include "Player.hpp"
#include "Utils.hpp"

namespace ztc
{
    Game::Game(unsigned int width, unsigned int height)
            : _window(sf::VideoMode(width, height), "SFML-Blueprints Chapter-3"), _world(width, height)
    {
        _text.setFont(Configuration::fonts.get(Configuration::Fonts::Trs_Million));
        _text.setCharacterSize(70);
        _text.setString("Press any Key to start");

        sf::FloatRect size = _text.getGlobalBounds();
        _text.setOrigin(size.width / 2, size.height / 2);
        _text.setPosition(width / 2, height / 2);
    }

    void Game::run(int minFPS)
    {
        sf::Clock clock;
        sf::Time lastStep;
        sf::Time fixedStep = sf::seconds(1.f / minFPS);

        // Implements the "Minimum time step" model
        // Game runs as fast as it can, passing last delta to update()
        while (_window.isOpen())
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
    }

    void Game::initLevel()
    {
        int meteors;
        switch (Configuration::level)
        {
            case 1:
                meteors = 4;
                break;
            case 2:
                meteors = 5;
                break;
            case 3:
                meteors = 7;
                break;
            case 4:
                meteors = 9;
                break;
            default:
                meteors = 11;
                break;
        }
        for (int i = 0; i < meteors; ++i)
        {
            Meteor *meteor = new BigMeteor(_world);
            do
            {
                meteor->setPosition(Utils::random(0.f, (float) _world.getWidth()),
                                    Utils::random(0.f, (float) _world.getHeight()));
            } while (_world.isCollide(*meteor));
            _world.add(meteor);
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
                    if (event.key.code == sf::Keyboard::Escape)
                        _window.close();
                    if (Configuration::isGameOver())
                        reset();
                default:
                    break;
            }
            if (!Configuration::isGameOver() && Configuration::player != nullptr)
                Configuration::player->processEvent(event);
        }
        if (!Configuration::isGameOver() && Configuration::player != nullptr)
            Configuration::player->processEvents();
    }

    void Game::update(sf::Time deltaTime)
    {
        if (!Configuration::isGameOver())
        {
            _world.update(deltaTime);

            if (Configuration::player == nullptr)
            {
                Configuration::player = new Player(_world);
                Configuration::player->setPosition(_world.getWidth() / 2, _world.getHeight() / 2);
                _world.add(Configuration::player);
            }
            _nextSaucer -= deltaTime;

            if (_nextSaucer < sf::Time::Zero)
            {
                Saucer::newSaucer(_world);
                _nextSaucer = sf::seconds(Utils::random(10.f, 60.f - Configuration::level * 2));
            }

            if (_world.size() <= 1)
            {
                ++Configuration::level;
                initLevel();
            }
        }
    }

    void Game::render()
    {
        _window.clear();

        if (Configuration::isGameOver())
            _window.draw(_text);
        else
        {
            _window.draw(_world);
            Configuration::draw(_window);
        }

        _window.display();
    }

    void Game::reset()
    {
        _nextSaucer = sf::seconds(Utils::random(5.f, 6.f - Configuration::level * 2));
        _world.clear();
        Configuration::player = nullptr;
        Configuration::reset();
        initLevel();
    }
}