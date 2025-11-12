#ifndef BACKGROUND_H
#define BACKGROUND_H    

#include <SFML/Graphics.hpp>
#include "entity.h"

class Background : public Entity 
{
  private:
    static sf::Texture texture;
  public:
    Background(float start_x, float start_y);
  // implement pure virtual 
    void update() override;
    void draw(sf::RenderWindow& window) override;

};
#endif // BACKGROUND_H