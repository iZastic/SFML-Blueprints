//
// Created by scastner on 11/7/2015.
//

#include "Configuration.hpp"

ResourceManager<sf::Texture, int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;

void Configuration::initialize()
{
    initTextures();
    initPlayerInputs();
}

void Configuration::initTextures()
{
    textures.load(Textures::Player, "../../res/images/player/Ship.png");
}

void Configuration::initPlayerInputs()
{
    playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
    playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
    playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
}