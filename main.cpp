#include "Game.hpp"
#include "Configuration.hpp"

int main()
{
    Configuration::initialize();

    Game game;
    game.run();

    return 0;
}