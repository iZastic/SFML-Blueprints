#include "Game.hpp"
#include "../Chapter-2/Configuration.hpp"

int main()
{
    Configuration::initialize();

    Game game;
    game.run();

    return 0;
}