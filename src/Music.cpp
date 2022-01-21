#include "Music.hpp"

sf::Music Music::music;
sf::Music Music::gameOverMusic;
sf::Music Music::eatingFoodMusic;
std::string Music::offOrOn;

Music::Music() {
    offOrOn = "on";
    music.openFromFile("Swan-Lake.ogg");
    music.play();
    music.setLoop(true);
    music.setVolume(10.f);
}

void Music::pauseMusic() {
    music.pause();
}

void Music::playMusic() {
    music.play();
    music.setLoop(true);
    music.setVolume(30.f);
}

void Music::playGameOverMusic() {
    gameOverMusic.openFromFile("game-over.wav");
    if (offOrOn == "off") {
        gameOverMusic.pause();
    } else {
        gameOverMusic.play();
        gameOverMusic.setVolume(40.f);
    }
}

void Music::playEatingFoodMusic() {
    eatingFoodMusic.openFromFile("eating-food.ogg");
    if (offOrOn == "off") {
        eatingFoodMusic.pause();
    } else {
        eatingFoodMusic.play();
        eatingFoodMusic.setVolume(40.f);
    }
}

void Music::setOffOrOn(std::string str) {
    offOrOn = str;
}

std::string Music::getOffOrOn() {
    return offOrOn;
}