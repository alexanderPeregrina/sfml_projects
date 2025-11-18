#ifndef BRICK_HANDLER_H
#define BRICK_HANDLER_H
#include <SFML/Graphics.hpp>
#include "brick.h"
#include "ball.h"
#include <vector>

class BrickHandler {
  private:
    std::vector<Brick> bricks;
  public:
    BrickHandler();

    void detect_collision(Ball& ball); 
    void delete_brick(Brick& brick);
    void draw(sf::RenderWindow& window);

    size_t getNumBricks() { return bricks.size(); }
};

#endif // BRICK_HANDLER_H