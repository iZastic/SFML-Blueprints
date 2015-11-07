//
// Created by scastner on 11/7/2015.
//

#ifndef SFML_BLUEPRINTS_RESOURCEMANAGER_HPP
#define SFML_BLUEPRINTS_RESOURCEMANAGER_HPP

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <memory>

template<typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager
{
public:
    /**
     * This c++11 feature lets us delete the copy constructor and operator,
     * which makes this class non-copyable.
     */
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;

    ResourceManager() = default;

    /**
     * This c++11 feature, variadic template, simply forwards any arguments to the
     * parent class without knowing them. This method uses it because not all SFML
     * resource classes use the same parameters.
     */
    template<typename ... Args>
    void load(const IDENTIFIER &id, Args &&... args)
    {
        std::unique_ptr<RESOURCE> ptr(new RESOURCE);
        if (!ptr->loadFromFile(std::forward<Args>(args)...))
            throw std::runtime_error("Impossible to load file");
        _map.emplace(id, std::move(ptr));
    }

    RESOURCE &get(const IDENTIFIER &id) const
    {
        return *_map.at(id);
    }

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> _map;
};

template<typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER>
{
public:
    /**
     * This c++11 feature lets us delete the copy constructor and operator,
     * which makes this class non-copyable.
     */
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;

    ResourceManager() = default;

    /**
     * This c++11 feature, variadic template, simply forwards any arguments to the
     * parent class without knowing them. This method uses it because not all SFML
     * resource classes use the same parameters.
     */
    template<typename ... Args>
    void load(const IDENTIFIER &id, Args &&... args)
    {
        std::unique_ptr<sf::Music> ptr(new sf::Music);
        if (!ptr->openFromFile(std::forward<Args>(args)...))
            throw std::runtime_error("Impossible to load file");
        _map.emplace(id, std::move(ptr));
    }

    sf::Music &get(const IDENTIFIER &id) const
    {
        return *_map.at(id);
    }

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> _map;
};

#endif //SFML_BLUEPRINTS_RESOURCEMANAGER_HPP