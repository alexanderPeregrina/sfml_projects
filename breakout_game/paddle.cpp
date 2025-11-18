#include "paddle.h"
#include "constants.h"

Paddle::Paddle(float start_x, float start_y) : MovableEntity() {
    rectangle.setSize({static_cast<float>(constants::paddle_width), 
                       static_cast<float>(constants::paddle_height)});
    rectangle.setFillColor(sf::Color(128, 128, 128));
    rectangle.setOutlineThickness(2.0f);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition({start_x, start_y});
    velocity = {0.0f, 0.0f};
}

void Paddle::update() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        velocity.x = -constants::paddle_speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        velocity.x = constants::paddle_speed;
    } else {
        velocity.x = 0.0f;
    }
    // Update paddle position based on velocity
    rectangle.move(velocity);

    // Keep paddle within window bounds
    auto position = rectangle.getPosition();
    if (position.x < 0)
        rectangle.setPosition({0, position.y});
    else if (position.x + constants::paddle_width > constants::window_width)
        rectangle.setPosition({constants::window_width - constants::paddle_width, position.y});
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}

void Paddle::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}

const sf::Vector2f& Paddle::getVelocity() {
    return velocity;
}

void Paddle::detect_collision(Ball& ball) {
    auto ball_sprite = ball.getSprite();
    if (!ball_sprite) return;

    sf::FloatRect ball_bounds = ball_sprite->getGlobalBounds();
    sf::FloatRect paddle_bounds = rectangle.getGlobalBounds();

    if (ball_bounds.findIntersection(paddle_bounds)) {
        // Simple collision response: invert ball's Y velocity
        auto vel = ball.getVelocity();
        vel.y = -vel.y;
        ball.setVelocity(vel);
    }
}
