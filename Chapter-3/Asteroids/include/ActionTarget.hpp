//
// Created by iZastic on 11/2/2015.
//

#ifndef SFML_BLUEPRINTS_ACTIONTARGET_HPP
#define SFML_BLUEPRINTS_ACTIONTARGET_HPP

#include <SFML/Graphics.hpp>
#include "ActionMap.hpp"
#include <functional>
#include <list>

namespace ztc
{
    template<typename T = int>
    class ActionTarget
    {
    public:
        /**
         * This c++11 feature lets us delete the copy constructor and operator,
         * which makes this class non-copyable.
         */
        ActionTarget(const ActionTarget<T> &) = delete;
        ActionTarget<T> &operator=(const ActionTarget<T> &) = delete;

        /**
         * This c++11 feature, using, defines the type of function that will be managed.
         * "using", is equivalent to typedef but more explicit
         */
        using FuncType = std::function<void(const sf::Event &event)>;

        ActionTarget(const ActionMap<T> &map);

        /**
         * These methods are used to verify the internal events. The first for non real-time
         * events and the second for real-time events.
         */
        bool processEvent(const sf::Event &event) const;
        void processEvents() const;

        // This allows us to store actions and their functions in the appropriate list
        void bind(const T &key, const FuncType &callback);
        void unbind(const T &key);

    private:
        std::list<std::pair<T, FuncType>> _eventsRealTime;
        std::list<std::pair<T, FuncType>> _eventsPoll;

        const ActionMap<T> &_actionMap;
    };
}

#endif //SFML_BLUEPRINTS_ACTIONTARGET_HPP