//
// Created by iZastic on 11/14/2015.
//

#ifndef SFML_BLUEPRINTS_PIECE_HPP
#define SFML_BLUEPRINTS_PIECE_HPP

#include <SFML/Graphics.hpp>

class Piece
{
public:
    static const unsigned short int ROTATIONS = 4;
    static const unsigned short int MATRIX_SIZE = 4;
    static const unsigned int PIVOT_Y = 1;
    static const unsigned int PIVOT_X = 2;

    enum TetriminoTypes
    {
        O = 0, I, S, Z, L, J, T, SIZE
    };

    static const sf::Color TetriminoColors[TetriminoTypes::SIZE];
    static const char TetriminoShapes[TetriminoTypes::SIZE][ROTATIONS][MATRIX_SIZE][MATRIX_SIZE];

    Piece(const Piece &) = delete;
    Piece &operator=(const Piece &) = delete;

    Piece(TetriminoTypes type, short int rotation);
    TetriminoTypes getType() const;

    void setRotation(short int rotation);
    short int getRotation() const;

    void setPosition(int x, int y);
    int getPosX() const;
    int getPosY() const;

    sf::Time getTimeSinceLastMove() const;

private:
    const TetriminoTypes _type;
    short int _rotation;
    int _posX;
    int _posY;
    sf::Clock _timeSinceLastMove;
};


#endif //SFML_BLUEPRINTS_PIECE_HPP
