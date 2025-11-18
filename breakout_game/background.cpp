#include "background.h"
#include "constants.h"

// Initialize static members
sf::Texture Background::texture;

Background::Background(float start_x, float start_y) : Entity()
{
    // Load a texture for the background
    (void)texture.loadFromFile("background_breakout.jpg");
    setTexture(texture);
    if(getSprite())
    {
        getSprite()->setPosition({start_x, start_y});
        getSprite()->setScale({
            static_cast<float>(constants::window_width) / texture.getSize().x,
            static_cast<float>(constants::window_height) / texture.getSize().y});
    }
}

void Background::update() {
    // Background might not need to update anything for a static image
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(*getSprite());
}