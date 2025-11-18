#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Ball : public MovableEntity {
  private:
    static sf::Texture texture;
    bool ball_below_window;
  public:
    Ball(float start_x, float start_y);

    // Impeletmentation of pure virtual functions from Entity
    void update() override;
    void draw(sf::RenderWindow& window) override;
    void setVelocity(const sf::Vector2f& vel) override;
    const sf::Vector2f& getVelocity() override;
    // Helper function to check if ball is below window
    bool is_ball_below_window();
    void reset_ball_below_window();

};

#endif // BALL_H