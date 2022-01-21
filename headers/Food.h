#ifndef GRAPHIC_FOOD_H
#define GRAPHIC_FOOD_H

#include <SFML/Graphics.hpp>

class Food : public sf::Drawable, public sf::Transformable {
public:
    Food();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::VertexArray food;
    sf::Texture texture;
};

#endif
