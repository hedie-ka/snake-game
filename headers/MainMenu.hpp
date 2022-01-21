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

class MainMenu {
public:
    MainMenu() {}

    void createMenu();

    void drawMenu(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    void controlEvents(sf::RenderWindow &window);

    static void openMenu(sf::RenderWindow &window);

    int getPointer();

private:
    sf::Text menu[3];
    sf::Font font;
    sf::Texture texture;
    sf::Sprite logo;
    int pointer;
};