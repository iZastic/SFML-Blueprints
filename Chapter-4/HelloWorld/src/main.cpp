//
// Created by iZastic on 11/15/2015.
//

#include <list>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Converter.hpp"

b2Body *createBox(b2World &world, int x, int y, int width, int height, sf::Texture *texture = nullptr,
                  b2BodyType type = b2_dynamicBody);
void displayWorld(std::list<b2Body *> bodies, b2World &world, sf::RenderWindow &window);

int main(int argc, char **argv)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chapter-4 HelloWorld", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // Create world
    b2Vec2 gravity(0.f, 9.8f);
    b2World world(gravity);

    // Create body storage and add ground
    std::list<b2Body *> bodies;
    bodies.emplace_back(createBox(world, 400, 590, 800, 20, nullptr, b2_staticBody));

    sf::Texture texture;
    texture.loadFromFile("../../res/images/crate.jpg");
    texture.setSmooth(true);

    sf::Clock clock;
    // Minimalist game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                bodies.emplace_back(
                        createBox(world, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 32, 32,
                                  &texture));
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            bodies.emplace_back(
                    createBox(world, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 32, 32,
                              &texture));

        window.setTitle("Chapter-4 HelloWorld | Bodies: " + std::to_string(world.GetBodyCount()) + " | FPS: " +
                        std::to_string(1.f / clock.restart().asSeconds()));

        displayWorld(bodies, world, window);
    }

    // Clean up
    for (b2Body *body : bodies)
    {
        delete static_cast<sf::RectangleShape *>(body->GetUserData());
        world.DestroyBody(body);
    }

    return 0;
}


b2Body *createBox(b2World &world, int x, int y, int width, int height, sf::Texture *texture, b2BodyType type)
{
    // Object definition
    b2BodyDef bodyDef;
    bodyDef.position.Set(converter::pixelsToMeters<float>(x), converter::pixelsToMeters<float>(y));
    bodyDef.type = type;

    // Object shape
    b2PolygonShape b2shape;
    b2shape.SetAsBox(converter::pixelsToMeters<float>(width / 2.f), converter::pixelsToMeters<float>(height / 2.f));

    // Object physical characteristics
    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.0;
    fixtureDef.friction = 0.4;
    fixtureDef.restitution = 0.5;
    fixtureDef.shape = &b2shape;

    // Create the object in the world
    b2Body *res = world.CreateBody(&bodyDef);
    res->CreateFixture(&fixtureDef);

    // Create the visible shape
    sf::Shape *shape = new sf::RectangleShape(sf::Vector2f(width, height));
    shape->setOrigin(width / 2.f, height / 2.f);
    shape->setPosition(sf::Vector2f(x, y));
    if (texture != nullptr)
    {
        shape->setTexture(texture);
    }
    else
    {
        if (type == b2_dynamicBody)
            shape->setFillColor(sf::Color::Blue);
        else
            shape->setFillColor(sf::Color::White);
    }

    // Use Box2D's user data to hold the SFML shape
    res->SetUserData(shape);

    return res;
}

void displayWorld(std::list<b2Body *> bodies, b2World &world, sf::RenderWindow &window)
{
    // Update the physical world
    world.Step(1.f / 60, 8, 3);

    window.clear();

    // Draw each shape with updated position and rotation
    for (b2Body *body = world.GetBodyList(); body != nullptr; body = body->GetNext())
    {
        sf::Shape *shape = static_cast<sf::Shape *>(body->GetUserData());
        shape->setPosition(converter::metersToPixels(body->GetPosition().x),
                           converter::metersToPixels(body->GetPosition().y));
        shape->setRotation(converter::radToDeg<float>(body->GetAngle()));
        window.draw(*shape);
    }

    window.display();
}












