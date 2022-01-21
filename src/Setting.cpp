#include "Setting.hpp"
#include "Music.hpp"
#include "GamePlay.hpp"
#include "MainMenu.hpp"

int Setting::flagForSetting;

int Setting::flagForBack;

void Setting::setFlagForSetting(int check) {
    flagForSetting = check;
}

int Setting::getFlagForSetting() {
    return flagForSetting;
}

void Setting::setFlagForBack(int check) {
    flagForBack = check;
}

int Setting::getFlagForBack() {
    return flagForBack;
}

void Setting::createMenu() {
    font.loadFromFile("myFont.TTF");
    menu2[0].setFont(font);
    menu2[0].setFillColor(sf::Color::Black);
    menu2[0].setString("Sound");
    menu2[0].setPosition(sf::Vector2f(250, 50));
    menu2[0].setCharacterSize(150);

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("On");
    menu[0].setPosition(sf::Vector2f(197, 200));
    menu[0].setCharacterSize(90);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Black);
    menu[1].setString("Off");
    menu[1].setPosition(sf::Vector2f(480, 200));
    menu[1].setCharacterSize(90);

    menu2[1].setFont(font);
    menu2[1].setFillColor(sf::Color::Black);
    menu2[1].setString("Speed");
    menu2[1].setPosition(sf::Vector2f(250, 300));
    menu2[1].setCharacterSize(150);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::Black);
    menu[2].setString("Slow");
    menu[2].setPosition(sf::Vector2f(180, 450));
    menu[2].setCharacterSize(80);

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::Black);
    menu[3].setString("Fast");
    menu[3].setPosition(sf::Vector2f(470, 450));
    menu[3].setCharacterSize(85);

    menu[4].setFont(font);
    menu[4].setFillColor(sf::Color::Black);
    menu[4].setString("Back");
    menu[4].setPosition(sf::Vector2f(600, 650));
    menu[4].setCharacterSize(80);

    pointer = 0;
    flagForBack = 0;
}

void Setting::drawMenu(sf::RenderWindow &window) {
    for (size_t i = 0; i < 5; i++)
        window.draw(menu[i]);
    for (size_t i = 0; i < 2; i++)
        window.draw(menu2[i]);
    window.draw(sound);
    window.draw(speed);
}

void Setting::openSetting(sf::RenderWindow &window) {
    Setting setting;
    setting.createMenu();
    while (window.isOpen()) {
        setting.controlEvents(window);
        setting.whichOne();
        window.clear(sf::Color::Yellow);
        setting.drawMenu(window);
        window.display();
    }
}

int Setting::getPointer() {
    return pointer;
}

void Setting::moveUp() {
    pointer -= 1;
    if (pointer >= 0) {
        menu[pointer].setFillColor(sf::Color::Red);
        menu[pointer + 1].setFillColor(sf::Color::Black);
    }
}

void Setting::moveDown() {
    pointer += 1;
    if (pointer < 5) {
        menu[pointer].setFillColor(sf::Color::Red);
        menu[pointer - 1].setFillColor(sf::Color::Black);
    }
}

void Setting::whichOne() {
    sound.setSize(sf::Vector2f(80, 80));
    sound.setPosition(sf::Vector2f(60, 670));


    speed.setSize(sf::Vector2f(60, 60));
    textureOfSpeed.loadFromFile("tik.png");
    speed.setTexture(&textureOfSpeed);

    if (GamePlay::getHowFast() == "slow") {
        speed.setPosition(sf::Vector2f(320, 480));
    } else if (GamePlay::getHowFast() == "fast") {
        speed.setPosition(sf::Vector2f(590, 480));
    }
    if (Music::getOffOrOn() == "on") {
        textureOfSound.loadFromFile("soundOn.png");
    }
    if (Music::getOffOrOn() == "off") {
        textureOfSound.loadFromFile("soundOff.png");
    }
    sound.setTexture(&textureOfSound);
}

void Setting::controlEvents(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (getPointer() - 1 >= 0)
                moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (getPointer() + 1 < 5)
                moveDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if ((Setting::getFlagForSetting()) && (getPointer() == 0)) {
                Music::playMusic();
                Music::setOffOrOn("on");
            } else
                Setting::setFlagForSetting(1);
            if (getPointer() == 1) {
                Music::pauseMusic();
                Music::setOffOrOn("off");
            }
            if (getPointer() == 2)
                GamePlay::setHowFast("slow");
            if (getPointer() == 3)
                GamePlay::setHowFast("fast");
            if (getPointer() == 4) {
                setFlagForBack(1);
                MainMenu::openMenu(window);
            }
        }
    }
}