//
// Created by iZastic on 11/8/2015.
//

#ifndef SFML_BLUEPRINTS_ENEMY_HPP
#define SFML_BLUEPRINTS_ENEMY_HPP

#include "Entity.hpp"

namespace ztc
{
    class Enemy : public Entity
    {
    public:
        /**
         * This c++11 feature lets us delete the copy constructor and operator,
         * which makes this class non-copyable.
         */
        Enemy(const Enemy &) = delete;
        Enemy &operator=(const Enemy &) = delete;

        Enemy(Configuration::Textures textureID, World &world);

        virtual int getPoints() const = 0;
        virtual void onDestroy();
    };
}

#endif //SFML_BLUEPRINTS_ENEMY_HPP
