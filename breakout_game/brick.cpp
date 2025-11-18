#include "brick.h"
#include "constants.h"  
 

// Initialize static members

Brick::Brick(float start_x, float start_y) : Entity() {
   //setTexture(texture);
   rectangle.setSize({static_cast<float>(constants::brick_width), 
                      static_cast<float>(constants::brick_height)});
   rectangle.setFillColor(sf::Color::Green);
   rectangle.setOutlineThickness(2.0f);
   rectangle.setOutlineColor(sf::Color::Black);
   rectangle.setPosition({start_x, start_y});
   hits = 0;
}

void Brick::update() {
    // Bricks might not need to update anything for a static entity
}

void Brick::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}

const sf::RectangleShape& Brick::getRectangle() {
    return rectangle;
}