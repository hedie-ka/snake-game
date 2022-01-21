#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <Wall.hpp>
#include <Food.hpp>
#include <Snake.hpp>
#include <GameOverMenu.hpp>
#include <GamePlay.hpp>
#include <MainMenu.hpp>
#include <Music.hpp>
#include <Setting.hpp>

int main(int, char**) {
    static sf::RenderWindow window(sf::VideoMode(800, 800), "~Snake Game~");
    window.setPosition(sf::Vector2i(300, 20));
    window.setFramerateLimit(20);
    GamePlay::setHowFast("slow");
    MainMenu menu;
    menu.createMenu();
    Music music;
    while (window.isOpen())
    {
        menu.controlEvents(window);
        window.clear(sf::Color::Yellow);
        menu.drawMenu(window);
        window.display();
    }
    return 0;
}
