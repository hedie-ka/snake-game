#include "GameOverMenu.hpp"
#include "GamePlay.hpp"

void GameOverMenu::drawMenu(sf::RenderWindow &window) {
    for (size_t i = 0; i < 3; i++)
        window.draw(menu[i]);
}

void GameOverMenu::createMenu() {
    gameOverFont.loadFromFile("Acero y Sangre.otf");
    menu[0].setFont(gameOverFont);
    menu[0].setFillColor(sf::Color::Black);
    menu[0].setString("GameOver!");
    menu[0].setPosition(sf::Vector2f(125, 50));
    menu[0].setCharacterSize(100);

    otherFont.loadFromFile("myFont.TTF");
    menu[1].setFont(otherFont);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Restart");
    menu[1].setPosition(sf::Vector2f(280, 400));
    menu[1].setCharacterSize(100);

    menu[2].setFont(otherFont);
    menu[2].setFillColor(sf::Color::Black);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(335, 550));
    menu[2].setCharacterSize(100);

}

int GameOverMenu::getPointer() {
    return pointer;
}

void GameOverMenu::moveUp() {
    pointer -= 1;
    if (pointer >= 1) {
        menu[pointer].setFillColor(sf::Color::White);
        menu[pointer + 1].setFillColor(sf::Color::Black);
    }
}

void GameOverMenu::moveDown() {
    pointer += 1;
    if (pointer < 3) {
        menu[pointer].setFillColor(sf::Color::White);
        menu[pointer - 1].setFillColor(sf::Color::Black);
    }
}

void GameOverMenu::controlEvents(sf::RenderWindow &window) {
    GameOverMenu instance;
    instance.createMenu();
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (instance.getPointer() - 1 >= 1)
                    instance.moveUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (instance.getPointer() + 1 < 3)
                    instance.moveDown();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                if (instance.getPointer() == 1)
                    GamePlay::play(window);
                if (instance.getPointer() == 2)
                    window.close();
            }
        }
        window.clear(sf::Color::Red);
        instance.drawMenu(window);
        window.display();
    }
}