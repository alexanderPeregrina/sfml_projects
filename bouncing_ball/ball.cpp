#include "ball.h"
#include "constants.h"

void generate_random_direction(float& velocity) {
    int direction = rand() % 2;
    
    switch (direction) {
        case 0: // no moving in this direction
            velocity = constants::ball_speed;;
            break;
        case 1: // move in positive direction
            velocity = -constants::ball_speed;
            break;

    }
}

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
    generate_random_direction(velocity.x);
    generate_random_direction(velocity.y);
    velocity.y *= 2.0f; // make vertical speed different
}

void Ball::update() {
    // Update ball position based on velocity
    getSprite()->move(velocity);

    // Bounce off the window edges
    auto position = getSprite()->getPosition();
    if (position.x <= 0 || position.x + constants::ball_size >= constants::window_width )
    {
        // change direction of movement
        velocity.x *= -1.0;
    }
    if( position.y <= 0 || position.y + constants::ball_size >= constants::window_height) {

        // change direction of movement
        velocity.y *= -1.0;
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(*getSprite());
}

/*void Ball::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}*/

