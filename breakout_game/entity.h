#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>

// Abstract base class to represent any graphical entity on the screen
class Entity {
  protected:
    // Use a pointer so Entity can be default-constructed before a texture exists
    std::unique_ptr<sf::Sprite> sprite;

  public: 
    Entity() = default;

    // Delete copy constructor and assignment
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;


    // Define move constructor and assignment
    Entity(Entity&& other) noexcept = default;
    Entity& operator=(Entity&& other) noexcept = default;

    // Pure virtual functions to be implemented by derived classes
    virtual void update() = 0; // Pure virtual function to update entity state
    virtual void draw(sf::RenderWindow& window) = 0;
    
    // helper functions
    // Create/replace the sprite using a loaded texture
    void setTexture(const sf::Texture& tex) {
      sprite = std::make_unique<sf::Sprite>(tex);
    }
    // Access helpers 9*8/
    sf::Sprite* getSprite() { return  sprite.get(); }
    const sf::Sprite* getSprite() const { return sprite.get(); }

    virtual ~Entity() = default; // Virtual destructor
};

// Abstract class for movable entities
class MovableEntity : public Entity {
  protected:
    sf::Vector2f velocity; // Velocity vector for movement

  public:
    virtual void setVelocity(const sf::Vector2f& vel)= 0;
    virtual const sf::Vector2f& getVelocity()= 0;
    virtual void update() = 0;
};

#endif // ENTITY_H