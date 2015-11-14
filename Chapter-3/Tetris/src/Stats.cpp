//
// Created by iZastic on 11/14/2015.
//

#include "Stats.hpp"

constexpr int FONT_SIZE = 24;

Stats::Stats() : _rows(0), _score(0), _level(0), _isGameOver(false)
{
    _font.loadFromFile("../../res/fonts/trs-million.ttf");

    _textRows.setFont(_font);
    _textRows.setString("rows : 0");
    _textRows.setCharacterSize(FONT_SIZE);
    _textRows.setPosition(0, 0);

    _textScore.setFont(_font);
    _textScore.setString("score : 0");
    _textScore.setCharacterSize(FONT_SIZE);
    _textScore.setPosition(0, FONT_SIZE + 1);

    _textLevel.setFont(_font);
    _textLevel.setString("level : 0");
    _textLevel.setCharacterSize(FONT_SIZE);
    _textLevel.setPosition(0, (FONT_SIZE + 1) * 2);

    _textGameOver.setFont(_font);
    _textGameOver.setString("Game Over");
    _textGameOver.setCharacterSize(72);
    _textGameOver.setPosition(0, 0);
}

void Stats::addLines(int lines)
{
    if (lines > 0)
    {
        _rows += lines;
        _textRows.setString("rows : " + std::to_string(_rows));
        _textScore.setString("score : " + std::to_string(_score));
        switch (lines)
        {
            case 1:
                _score += 40 * (_level + 1);
                break;
            case 2:
                _score += 100 * (_level + 1);
                break;
            case 3:
                _score += 300 * (_level + 1);
                break;
            case 4:
                _score += 1200 * (_level + 1);
                break;
            default:
                break;
        }
        _level = _rows / 10;
        _textLevel.setString("level : " + std::to_string(_level));
    }
}

unsigned int Stats::getLevel() const
{
    return _level;
}

void Stats::gameOver()
{
    _isGameOver = true;
}

void Stats::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!_isGameOver)
    {
        states.transform *= getTransform();
        target.draw(_textRows, states);
        target.draw(_textScore, states);
        target.draw(_textLevel, states);
    }
    else
        target.draw(_textGameOver, states);
}
