//
// Created by iZastic on 11/5/2015.
//

#include "ActionMap.hpp"

template<typename T>
void ActionMap<T>::map(const T &key, const Action &action)
{
    _map.emplace(key, action);
}

template<typename T>
const Action &ActionMap<T>::get(const T &key) const
{
    return _map.at(key);
}

template class ActionMap<int>;