#include "Game.hpp"

int main() {
    Player::setDefaultInputs();

    Game game;
    game.run();

    return 0;
}