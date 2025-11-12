#include "ball.h"
#include "constants.h"

//Initialize static members 
sf::Texture Ball::texture;

Ball::Ball(float start_x, float start_y) : MovableEntity() {
    // Load a texture for the ball
    (void)texture.loadFromFile("ball.png");
    setTexture(texture);
    if(getSprite())
    {
        getSprite()->setPosition({start_x, start_y});
        getSprite()->setScale({
            static_cast<float>(constants::ball_size) / texture.getSize().x,
            static_cast<float>(constants::ball_size) / texture.getSize().y});
    }

    // Initialize velocity for random walk
    velocity = {constants::ball_speed, constants::ball_speed};
}

void Ball::update() {
    // Update ball position based on velocity
    getSprite()->move(velocity);

    // Bounce off the window edges
    auto position = getSprite()->getPosition();
    if (position.x <= 0 || position.x + constants::ball_size >= constants::window_width 
       || position.y <= 0 || position.y + constants::ball_size >= constants::window_height) {
        getSprite()->setPosition({constants::window_width/2.0f, constants::window_height/2.0f}); // Move back to origin
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(*getSprite());
}

void Ball::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}
