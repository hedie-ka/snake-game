#include "MainMenu.hpp"
#include "GamePlay.hpp"
#include "Setting.hpp"

void MainMenu::drawMenu(sf::RenderWindow &window) {
    window.draw(logo);
    for (size_t i = 0; i < 3; i++)
        window.draw(menu[i]);
}

void MainMenu::createMenu() {
    texture.loadFromFile("logo.png");
    logo.setPosition(sf::Vector2f(100, 500));
    logo.setTexture(texture);

    font.loadFromFile("myFont.TTF");
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("play");
    menu[0].setPosition(sf::Vector2f(250, 10));
    menu[0].setCharacterSize(250);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Black);
    menu[1].setString("setting");
    menu[1].setPosition(sf::Vector2f(260, 300));
    menu[1].setCharacterSize(130);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::Black);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(325, 450));
    menu[2].setCharacterSize(130);
    pointer = 0;
}

int MainMenu::getPointer() {
    return pointer;
}

void MainMenu::moveUp() {
    pointer -= 1;
    if (pointer >= 0) {
        menu[pointer].setFillColor(sf::Color::Red);
        menu[pointer + 1].setFillColor(sf::Color::Black);
    }
}

void MainMenu::moveDown() {
    pointer += 1;
    if (pointer < 3) {
        menu[pointer].setFillColor(sf::Color::Red);
        menu[pointer - 1].setFillColor(sf::Color::Black);
    }
}

void MainMenu::openMenu(sf::RenderWindow &window) {
    MainMenu menu;
    menu.createMenu();
    while (window.isOpen()) {
        menu.controlEvents(window);
        window.clear(sf::Color::Yellow);
        menu.drawMenu(window);
        window.display();
    }
}

void MainMenu::controlEvents(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (getPointer() - 1 >= 0)
                moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (getPointer() + 1 < 3)
                moveDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (getPointer() == 0 && Setting::getFlagForBack() == 0)
                GamePlay::play(window);
            else
                Setting::setFlagForBack(0);
            if (getPointer() == 1) {
                Setting::setFlagForSetting(0);
                Setting::openSetting(window);
            }
            if (getPointer() == 2)
                window.close();
        }
    }
}