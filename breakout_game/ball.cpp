#include "ball.h"
#include "constants.h"

//Initialize static members 
sf::Texture Ball::texture;

Ball::Ball(float start_x, float start_y) : MovableEntity() {
    // Load a texture for the ball
    (void)texture.loadFromFile("red_ball.png");
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

    ball_below_window = false;
}

void Ball::update() {
    // Update ball position based on velocity
    getSprite()->move(velocity);

    // Bounce off the window edges
    auto position = getSprite()->getPosition();
    if (position.x <= 0 || position.x + constants::ball_size >= constants::window_width )
        velocity.x = -velocity.x;

    if (position.y <= 0 )
        velocity.y = -velocity.y;

    // Check if ball goes below the window (missed by paddle)
    if (position.y + constants::ball_size >= constants::window_height ) {
        // Reset ball position to center
        getSprite()->setPosition({
            constants::window_width / 2.0f,
            constants::window_height / 2.0f});
        // Reset velocity
        velocity = {constants::ball_speed, constants::ball_speed};
        // Decrease life count
        ball_below_window = true;
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(*getSprite());
}

void Ball::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}

const sf::Vector2f& Ball::getVelocity() {
    return velocity;
}

bool Ball::is_ball_below_window(){
    return ball_below_window;

}

void Ball::reset_ball_below_window(){
    ball_below_window = false;
}
