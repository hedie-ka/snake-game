#ifndef GRAPHIC_SNAKE_H
#define GRAPHIC_SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <random>
#include <math.h>
#include <list>

class Snake : public sf::Drawable, public sf::Transformable {
public:
    Snake() {}

    ~Snake();

    void createSnake(sf::Vector2f headPosition, sf::Vector2f bodyPosition);

    void grow(sf::Vector2f &direction);

    void moveSnake(sf::Vector2f direction);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Vector2f getHeadPosition();

    sf::Vector2f getTailPosition();

    sf::Vector2f getPositionOfPlaceBeforeHead();

    void newMove(sf::Vector2f headPosition);

    bool defeatSnake();

    bool accidentOfTwoSnakes(sf::Vector2f &headOfOtherSnake);

    bool ifFoodUnderSnake(sf::Vector2f &foodPosition);

private:
    std::list<sf::RectangleShape> snake;
    sf::Texture texture;
    sf::Texture headTexture;
};

#endif

