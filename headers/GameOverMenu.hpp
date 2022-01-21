#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <random>
#include <math.h>
#include <list>

class GameOverMenu {
public:
    GameOverMenu() { pointer = 1; }

    void createMenu();

    void drawMenu(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    int getPointer();

    static void controlEvents(sf::RenderWindow &window);

private:
    sf::Text menu[3];
    sf::Font gameOverFont;
    sf::Font otherFont;
    int pointer;
};