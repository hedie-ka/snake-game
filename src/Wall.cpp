#include "Wall.h"

bool Wall::load(sf::Vector2u newPosition, unsigned int width, unsigned int height) {
    texture.loadFromFile("wall.png");
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j) {
            sf::Vertex *quad = &m_vertices[(i + j * width) * 4];
            quad[0].position = sf::Vector2f(i * newPosition.x, j * newPosition.y);
            quad[0].texCoords = sf::Vector2f(0, 40);
            quad[1].position = sf::Vector2f((i + 1) * newPosition.x, j * newPosition.y);
            quad[1].texCoords = sf::Vector2f(0, 0);
            quad[2].position = sf::Vector2f((i + 1) * newPosition.x, (j + 1) * newPosition.y);
            quad[2].texCoords = sf::Vector2f(40, 0);
            quad[3].position = sf::Vector2f(i * newPosition.x, (j + 1) * newPosition.y);
            quad[3].texCoords = sf::Vector2f(40, 40);
        }
    return true;
}

void Wall::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &this->texture;
    target.draw(m_vertices, states);
}
