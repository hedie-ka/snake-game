#include "Food.h"

Food::Food() {
    texture.loadFromFile("food.png");
    food.setPrimitiveType(sf::Quads);
    food.resize(4);
    food[0].position = sf::Vector2f(0, 40);
    food[1].position = sf::Vector2f(0, 0);
    food[2].position = sf::Vector2f(40, 0);
    food[3].position = sf::Vector2f(40, 40);
    food[0].texCoords = sf::Vector2f(0, 40);
    food[1].texCoords = sf::Vector2f(0, 0);
    food[2].texCoords = sf::Vector2f(40, 0);
    food[3].texCoords = sf::Vector2f(40, 40);
}

void Food::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &this->texture;
    target.draw(food, states);
}