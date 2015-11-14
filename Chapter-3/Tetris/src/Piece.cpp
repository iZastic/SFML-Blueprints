//
// Created by iZastic on 11/14/2015.
//

#include <assert.h>
#include "Piece.hpp"

const sf::Color Piece::TetriminoColors[Piece::TetriminoTypes::SIZE] = {
        sf::Color::Blue,
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Cyan,
        sf::Color::Magenta,
        sf::Color::White,
        sf::Color(195, 132, 58)
};

const char Piece::TetriminoShapes[Piece::TetriminoTypes::SIZE][Piece::ROTATIONS][Piece::MATRIX_SIZE][Piece::MATRIX_SIZE] = {
        { // O
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                }
        },
        {//I
                {
                        {0, 0, 0, 0},
                        {1, 1, 2, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 0},
                        {0, 0, 1, 0},
                        {0, 0, 1, 0}
                },
                {
                        {0, 0, 0, 0},
                        {1, 1, 2, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 0},
                        {0, 0, 1, 0},
                        {0, 0, 1, 0}
                }
        },
        {//S
                {
                        {0, 0, 0, 0},
                        {0, 0, 2, 1},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0},
                        {0, 0, 2, 1},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                }
        },
        {//Z
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 1},
                        {0, 0, 2, 1},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 1},
                        {0, 0, 2, 1},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                }
        },
        {//L
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 1},
                        {0, 1, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 1},
                        {0, 1, 2, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 1, 1, 0},
                        {0, 0, 2, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                }
        },
        {//J
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 1},
                        {0, 0, 2, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 1, 0, 0},
                        {0, 1, 2, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                }
        },
        {//T
                {
                        {0, 0, 0, 0},
                        {0, 1, 2, 1},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 0, 2, 1},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 1, 2, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0},
                        {0, 1, 2, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                }
        }
};

Piece::Piece(Piece::TetriminoTypes type, short int rotation) : _type(type), _rotation(rotation), _posX(0), _posY(0)
{
    assert(rotation >= 0 && rotation < ROTATIONS);
}

Piece::TetriminoTypes Piece::getType() const
{
    return _type;
}

void Piece::setRotation(short int rotation)
{
    assert(rotation >= 0 && rotation < ROTATIONS);
    _rotation = rotation;
    _timeSinceLastMove.restart();
}

short int Piece::getRotation() const
{
    return _rotation;
}

void Piece::setPosition(int x, int y)
{
    _posX = x;
    _posY = y;
    _timeSinceLastMove.restart();
}

int Piece::getPosX() const
{
    return _posX;
}

int Piece::getPosY() const
{
    return _posY;
}

sf::Time Piece::getTimeSinceLastMove() const
{
    return _timeSinceLastMove.getElapsedTime();
}
