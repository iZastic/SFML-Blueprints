//
// Created by iZastic on 11/7/2015.
//

#ifndef SFML_BLUEPRINTS_CONFIGURATION_HPP
#define SFML_BLUEPRINTS_CONFIGURATION_HPP

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "ActionMap.hpp"

namespace ztc
{
    class Player;
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

        enum Fonts : int
        {
            Trs_Million
        };
        static ResourceManager<sf::Font, int> fonts;

        enum Textures : int
        {
            Player,
            PlayerLife,
            ShootPlayer,
            BigSaucer,
            SmallSaucer,
            ShootSaucer,
            BigMeteor1,
            BigMeteor2,
            BigMeteor3,
            BigMeteor4,
            MediumMeteor1,
            MediumMeteor2,
            SmallMeteor1,
            SmallMeteor2,
            SmallMeteor3,
            SmallMeteor4,
        };
        static ResourceManager<sf::Texture, int> textures;

        enum Sounds : int
        {
            Jump,
            Boom,
            Boom2,
            SaucerSpawn1,
            SaucerSpawn2,
            Explosion1,
            Explosion2,
            Explosion3,
            LaserPlayer,
            LaserEnemy
        };
        static ResourceManager<sf::SoundBuffer, int> sounds;

        enum Music : int
        {
            Theme
        };
        static ResourceManager<sf::Music, int> music;

        // Limit number of actions by storing them in an enum
        enum PlayerInputs : int
        {
            Up,
            Left,
            Right,
            Shoot,
            Hyperspace
        };
        static ActionMap<int> playerInputs;

        static ztc::Player *player;
        static int level;
        static int lives;

        static void initialize();
        static void reset();

        static bool isGameOver();
        static void addScore(int s);
        static int getScore();

        static void draw(sf::RenderTarget &target);

    private:
        static int _score;
        static sf::Text _scoreText;
        static sf::Sprite _lifeSprite;

        static void initFonts();
        static void initTextures();
        static void initSounds();
        static void initMusic();

        static void initPlayerInputs();
    };
}

#endif //SFML_BLUEPRINTS_CONFIGURATION_HPP
