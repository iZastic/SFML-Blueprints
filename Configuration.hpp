//
// Created by scastner on 11/7/2015.
//

#ifndef SFML_BLUEPRINTS_CONFIGURATION_HPP
#define SFML_BLUEPRINTS_CONFIGURATION_HPP

#include "ResourceManager.hpp"
#include "ActionMap.hpp"

class Configuration
{
public:
    /**
     * This c++11 feature lets us delete the constructor, copy constructor and operator,
     * which makes this class non-copyable.
     */
    Configuration() = delete;
    Configuration(const Configuration &) = delete;
    Configuration &operator=(const Configuration &) = delete;

    enum Textures : int
    {
        Player
    };
    static ResourceManager<sf::Texture, int> textures;

    // Limit number of actions by storing them in an enum
    enum PlayerInputs
    {
        Up,
        Left,
        Right
    };
    static ActionMap<int> playerInputs;

    static void initialize();

private:
    static void initTextures();
    static void initPlayerInputs();
};


#endif //SFML_BLUEPRINTS_CONFIGURATION_HPP
