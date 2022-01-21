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

class Music {
public:
    Music();

    static void pauseMusic();

    static void playMusic();

    static void playGameOverMusic();

    static void playEatingFoodMusic();

    static void setOffOrOn(std::string str);

    static std::string getOffOrOn();

private:
    static sf::Music music;
    static sf::Music gameOverMusic;
    static sf::Music eatingFoodMusic;
    static std::string offOrOn;
};
