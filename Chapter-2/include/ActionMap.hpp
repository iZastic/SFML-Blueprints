//
// Created by iZastic on 11/5/2015.
//

#ifndef SFML_BLUEPRINTS_ACTIONMAP_HPP
#define SFML_BLUEPRINTS_ACTIONMAP_HPP

#include <unordered_map>
#include "Action.hpp"

/*
 * This is a template class so that KEY can be any type
 */
template<typename T = int>
class ActionMap
{
public:
    /**
     * This c++11 feature lets us delete the copy constructor and operator,
     * which makes this class non-copyable.
     */
    ActionMap(const ActionMap<T> &) = delete;
    ActionMap<T> &operator=(const ActionMap<T> &) = delete;

    ActionMap() = default;

    // Getters and setters
    void map(const T &key, const Action &action);
    const Action &get(const T &key) const;

private:
    // Unordered maps are faster at runtime
    std::unordered_map<T, Action> _map;
};


#endif //SFML_BLUEPRINTS_ACTIONMAP_HPP
