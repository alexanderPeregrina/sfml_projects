#ifndef BRICKS_H
#define BRICKS_H  
#include <SFML/Graphics.hpp>
#include"brick.h"
#include "entity.h" 

class Brick : public Entity {
  private:
    //static sf::Texture texture;
    sf::RectangleShape rectangle;
    int hits;
  public:
    Brick(float start_x, float start_y);

    // Delete copy constructor and assignment
    Brick(const Brick&) = delete;
    Brick& operator=(const Brick&) = delete;

    // Define move constructor and assignment
    Brick(Brick&& other) noexcept = default;
    Brick& operator=(Brick&& other) noexcept = default;


    // Impeletmentation of pure virtual functions from Entity
    void update() override;
    void draw(sf::RenderWindow& window) override;

    // Helper to access rectangle shape for collision detection
    const sf::RectangleShape& getRectangle();

    // Make BrickHandler a friend class to access private members
    friend class BrickHandler; 
};

#endif // BRICKS_H