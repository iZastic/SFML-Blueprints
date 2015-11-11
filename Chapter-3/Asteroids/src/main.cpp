#include "Game.hpp"

int main()
{
    ztc::Configuration::initialize();

    ztc::Game game(1280, 800);
    game.run();

    return 0;
}