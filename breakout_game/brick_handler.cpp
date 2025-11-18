#include <algorithm>
#include "brick_handler.h"
#include "constants.h"


BrickHandler::BrickHandler() {
    // Initialize a grid of bricks
    for (int row = 0; row < constants::brick_rows; ++row) {
        for (int col = 0; col < constants::brick_columns; ++col) {
            float x = col * (constants::brick_width) + constants::brick_width; 
            float y = row * (constants::brick_height) + constants::brick_height; 
            bricks.emplace_back(Brick{x, y});
        }
    }
}

void BrickHandler::detect_collision(Ball& ball) {
    auto ball_sprite = ball.getSprite();
    if (!ball_sprite) return;

    sf::FloatRect ball_bounds = ball_sprite->getGlobalBounds();

    for (auto& brick : bricks) {
        // Assuming Brick has a method getRectangle() that returns its rectangle shape
        sf::FloatRect brick_bounds = brick.getRectangle().getGlobalBounds();

        if (ball_bounds.findIntersection(brick_bounds)) {
            // Simple collision response: invert ball's Y velocity
            auto vel = ball.getVelocity();
            vel.y = -vel.y;
            ball.setVelocity(vel);
            brick.hits += 1;
            brick.rectangle.setFillColor(
                sf::Color(0, 255, 0, 255 - (brick.hits * 80))); // Change color based on hits

            // Remove the brick if hit more than constants::brick_strength
            if (brick.hits >= constants::brick_strength)
                delete_brick(brick);
            break; // Exit after first collision
        }
    }
}

void BrickHandler::delete_brick(Brick& brick) {
    auto it = std::find_if(bricks.begin(), bricks.end(),
                           [&brick](const Brick& b) { return &b == &brick; });
    if (it != bricks.end()) {
        bricks.erase(it);
    }
}

void BrickHandler::draw(sf::RenderWindow& window) {
    for (auto& brick : bricks) {
        brick.draw(window);
    }
}