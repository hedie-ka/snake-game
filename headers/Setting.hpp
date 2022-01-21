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

class Setting {
public:
    Setting() {}

    ~Setting() {}

    void createMenu();

    void drawMenu(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    void controlEvents(sf::RenderWindow &window);

    static void openSetting(sf::RenderWindow &window);

    int getPointer();

    void whichOne();

    static void setFlagForSetting(int check);

    static int getFlagForSetting();

    static int getFlagForBack();

    static void setFlagForBack(int check);

private:
    sf::Text menu[5];
    sf::Text menu2[2];
    sf::Font font;
    sf::RectangleShape sound;
    sf::Texture textureOfSound;
    sf::RectangleShape speed;
    sf::Texture textureOfSpeed;
    int pointer;
    static int flagForSetting;
    static int flagForBack;
};