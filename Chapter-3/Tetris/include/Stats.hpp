//
// Created by iZastic on 11/14/2015.
//

#ifndef SFML_BLUEPRINTS_STATS_HPP
#define SFML_BLUEPRINTS_STATS_HPP

#include <SFML/Graphics.hpp>

class Stats : public sf::Transformable, public sf::Drawable
{
public:
    Stats();
    void addLines(int lines);
    unsigned int getLevel() const;
    void gameOver();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;
    unsigned int _rows;
    unsigned int _score;
    unsigned int _level;
    bool _isGameOver;

    sf::Font _font;
    sf::Text _textRows;
    sf::Text _textScore;
    sf::Text _textLevel;
    sf::Text _textGameOver;
};

#endif //SFML_BLUEPRINTS_STATS_HPP
