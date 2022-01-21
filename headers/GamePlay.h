#ifndef GRAPHIC_GAMEPLAY_H
#define GRAPHIC_GAMEPLAY_H

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
#include "TileMap.h"
#include "Wall.h"
#include "Food.h"
#include "Snake.h"
#include "Music.h"

class GamePlay {
public:
    void loading();

    void controlEvents(sf::RenderWindow &window);

    void myDraw(sf::RenderWindow &window);

    void separateWalls(int whichOne);

    sf::Vector2f ifIsOn(int where);

    void growSnakes(sf::Vector2f &lastPositionOfTail1, sf::Vector2f &lastPositionOfTail2);

    void speed();

    void defeat(sf::RenderWindow &window);

    static void play(sf::RenderWindow &window);

    static void setHowFast(std::string speed);

    static std::string getHowFast();

private:
    TileMap map;
    Wall firstWall;
    Wall secondWall;
    Food firstFood;
    Food secondFood;
    Snake firstSnake;
    Snake secondSnake;
    sf::Vector2f directionForFirstSnake = {40, 0};
    sf::Vector2f directionForSecondSnake = {0, 40};
    sf::Clock clock;
    static std::string howFast;
};

#endif