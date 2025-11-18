#ifndef PADDLE_H
#define PADDLE_H    
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "Ball.h"

class Paddle : public MovableEntity {
  private:
    sf::RectangleShape rectangle;
  public:
    Paddle(float start_x, float start_y);

    // Delete copy constructor and assignment
    Paddle(const Paddle&) = delete;
    Paddle& operator=(const Paddle&) = delete;

    // Define move constructor and assignment
    Paddle(Paddle&& other) noexcept = default;
    Paddle& operator=(Paddle&& other) noexcept = default;

    // Impeletmentation of pure virtual functions from Entity
    void update() override;
    void draw(sf::RenderWindow& window) override;
    void setVelocity(const sf::Vector2f& vel) override;
    const sf::Vector2f& getVelocity() override;

    // Helper function for collision detection
    void detect_collision(Ball& ball);
};
#endif // PADDLE_H