#ifndef GRAPHIC_WALL_H
#define GRAPHIC_WALL_H

#include <SFML/Graphics.hpp>

class Wall : public sf::Drawable, public sf::Transformable {
public:
    bool load(sf::Vector2u newPosition, unsigned int width, unsigned int height);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::VertexArray m_vertices;
    sf::Texture texture;
};

#endif