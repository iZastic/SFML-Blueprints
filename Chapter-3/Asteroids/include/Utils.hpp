//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_BLUEPRINTS_UTILS_HPP
#define SFML_BLUEPRINTS_UTILS_HPP

#include <cstdlib>
#include <ctime>

namespace ztc
{
    class Utils
    {
    public:
        static void initialize()
        {
            srand((unsigned int) time(NULL));
        }

        static int random(int min, int max)
        {
            return rand() % (max - min + 1) + min;
        }

        static float random(float min, float max)
        {
            return (rand() / float(RAND_MAX)) * (max - min) + min;
        }
    };
}

#endif //SFML_BLUEPRINTS_UTILS_HPP
