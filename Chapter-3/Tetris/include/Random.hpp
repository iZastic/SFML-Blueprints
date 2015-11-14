//
// Created by iZastic on 11/14/2015.
//

#ifndef SFML_BLUEPRINTS_RANDOM_HPP
#define SFML_BLUEPRINTS_RANDOM_HPP

#include <cstdlib>
#include <ctime>

class Random
{
public:
    static void init()
    {
        srand(time(NULL));
    }

    static float random(float min, float max)
    {
        return (rand() / float(RAND_MAX)) * (max - min) + min;
    }

    static int random(int min, int max)
    {
        return rand() % (max - min + 1) + min;
    }
};

#endif //SFML_BLUEPRINTS_RANDOM_HPP
