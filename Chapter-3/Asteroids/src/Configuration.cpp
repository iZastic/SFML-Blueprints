//
// Created by iZastic on 11/7/2015.
//

#include "Configuration.hpp"
#include "Utils.hpp"
#include "Player.hpp"

namespace ztc
{
    ResourceManager<sf::Font, int> Configuration::fonts;
    ResourceManager<sf::Texture, int> Configuration::textures;
    ResourceManager<sf::SoundBuffer, int> Configuration::sounds;
    ResourceManager<sf::Music, int> Configuration::music;

    ActionMap<int> Configuration::playerInputs;
    int Configuration::level;
    int Configuration::lives;

    Player *Configuration::player = nullptr;

    int Configuration::_score;
    sf::Text Configuration::_scoreText;
    sf::Sprite Configuration::_lifeSprite;

    void Configuration::initialize()
    {
        Utils::initialize();

        initFonts();
        initTextures();
        initSounds();
        initMusic();

        initPlayerInputs();

        _scoreText.setFont(fonts.get(Fonts::Trs_Million));
        _scoreText.setCharacterSize(24);

        _lifeSprite.setTexture(textures.get(Textures::PlayerLife));

        music.get(Music::Theme).setLoop(true);
        music.get(Music::Theme).play();

        lives = level = _score = -1;
    }

    void Configuration::reset()
    {
        level = 1;
        lives = 3;
        _score = 0;
        _scoreText.setString("0");
    }

    bool Configuration::isGameOver()
    {
        return lives < 0;
    }

    void Configuration::addScore(int s)
    {
        int old = _score;
        _score += s * level;
        lives += _score / 10000 - old / 10000;
        _scoreText.setString(std::to_string(_score));
    }

    int Configuration::getScore()
    {
        return _score;
    }

    void Configuration::draw(sf::RenderTarget &target)
    {
        target.draw(_scoreText);
        for (int i = 0; i < lives; ++i)
        {
            _lifeSprite.setPosition(40 * i, 40);
            target.draw(_lifeSprite);
        }
    }

    void Configuration::initFonts()
    {
        fonts.load(Fonts::Trs_Million, "../../res/fonts/trs-million.ttf");
    }

    void Configuration::initTextures()
    {
        textures.load(Textures::Player, "../../res/images/player/Ship.png");
        textures.load(Textures::PlayerLife, "../../res/images/player/life.png");
        textures.load(Textures::ShootPlayer, "../../res/images/shoot/Player.png");

        textures.load(Textures::BigSaucer, "../../res/images/saucer/Big.png");
        textures.load(Textures::SmallSaucer, "../../res/images/saucer/Small.png");
        textures.load(Textures::ShootSaucer, "../../res/images/shoot/Saucer.png");

        textures.load(Textures::BigMeteor1, "../../res/images/meteor/Big1.png");
        textures.load(Textures::BigMeteor2, "../../res/images/meteor/Big2.png");
        textures.load(Textures::BigMeteor3, "../../res/images/meteor/Big3.png");
        textures.load(Textures::BigMeteor4, "../../res/images/meteor/Big4.png");

        textures.load(Textures::MediumMeteor1, "../../res/images/meteor/Medium1.png");
        textures.load(Textures::MediumMeteor2, "../../res/images/meteor/Medium2.png");

        textures.load(Textures::SmallMeteor1, "../../res/images/meteor/Small1.png");
        textures.load(Textures::SmallMeteor2, "../../res/images/meteor/Small2.png");
        textures.load(Textures::SmallMeteor3, "../../res/images/meteor/Small3.png");
        textures.load(Textures::SmallMeteor4, "../../res/images/meteor/Small4.png");
    }

    void Configuration::initSounds()
    {
        sounds.load(Sounds::Jump, "../../res/sounds/hyperspace.flac");

        sounds.load(Sounds::Boom, "../../res/sounds/boom.flac");
        sounds.load(Sounds::Boom2, "../../res/sounds/boom2.flac");

        sounds.load(Sounds::SaucerSpawn1, "../../res/sounds/spawn1.flac");
        sounds.load(Sounds::SaucerSpawn2, "../../res/sounds/spawn2.flac");

        sounds.load(Sounds::Explosion1, "../../res/sounds/explosion1.flac");
        sounds.load(Sounds::Explosion2, "../../res/sounds/explosion2.flac");
        sounds.load(Sounds::Explosion3, "../../res/sounds/explosion3.flac");

        sounds.load(Sounds::LaserPlayer, "../../res/sounds/laser1.ogg");
        sounds.load(Sounds::LaserEnemy, "../../res/sounds/laser2.ogg");
    }

    void Configuration::initMusic()
    {
        music.load(Music::Theme, "../../res/music/theme.ogg");
    }

    void Configuration::initPlayerInputs()
    {
        playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
        playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
        playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
        playerInputs.map(PlayerInputs::Shoot, Action(sf::Keyboard::Space));
        playerInputs.map(PlayerInputs::Hyperspace, Action(sf::Keyboard::Down, Action::Type::Released));
    }
}