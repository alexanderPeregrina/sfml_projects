#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Ball : public MovableEntity {
  private:
    static sf::Texture texture;
  public:
    Ball(float start_x, float start_y);

    // Impeletmentation of pure virtual functions from Entity
    void update() override;
    void draw(sf::RenderWindow& window) override;
    void setVelocity(const sf::Vector2f& vel) override;
};

#endif // BALL_H