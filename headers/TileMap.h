#ifndef GRAPHIC_TILEMAP_H
#define GRAPHIC_TILEMAP_H

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(sf::Vector2u tileSize, unsigned int width, unsigned int height);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::VertexArray m_vertices;
    sf::Texture texture;
};

#endif
