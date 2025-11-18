#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "background.h"
#include "constants.h"
#include "ball.h"
#include "brick_handler.h"
#include "paddle.h"

// To compile: g++ -std=c++17 -O2 breakout_game.cpp background.cpp ball.cpp brick.cpp brick_handler.cpp paddle.cpp -o breakout_game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

using namespace std::literals;

int lifes = 3;

void reset_game(Ball& ball, BrickHandler& brick_handler)
{
    
    // Reset ball position to center
    ball.getSprite()->setPosition({
        constants::window_width / 2.0f,
        constants::window_height / 2.0f});
    // Reset ball velocity
    ball.setVelocity({constants::ball_speed, constants::ball_speed});

    ball.reset_ball_below_window();

    // Reinitialize bricks
    brick_handler = BrickHandler{};
}

int main() 
{

    sf::RenderWindow window{ sf::VideoMode{ sf::Vector2u{ constants::window_width,
                                                          constants::window_height } },
                                 "Breakout Game"s };

    sf::Music music{"moonlight_drive.ogg"};

    window.setFramerateLimit(60);

    Background background(0.0f, 0.0f);
    Ball ball(constants::window_width / 2.0f, constants::window_height / 2.0f);
    float vel_x, vel_y;

    BrickHandler brick_handler{};

    Paddle paddle((constants::window_width - constants::paddle_width) / 2.0f,
                  constants::window_height - (2.0f * constants::paddle_height));


    music.setLooping(true);
    music.play();

    sf::Font mtf_font{"MTF Toast.ttf"};
    sf::Text lifes_text{mtf_font};
    lifes_text.setCharacterSize(30);
    lifes_text.setFillColor(sf::Color::White);
    lifes_text.setPosition({10.0f, 10.0f});
    
    while (window.isOpen() && lifes > 0 && brick_handler.getNumBricks() > 0) {
        window.clear(sf::Color::Black);
        while (auto mayEvent = window.pollEvent()) {
            if (mayEvent->is<sf::Event::Closed>())
                window.close();
        }

        // keep the Escape key check using global keyboard state
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
            reset_game(ball, brick_handler);
            lifes = 3;
        }

        window.clear();
        ball.update();
        if (ball.is_ball_below_window()) {
            --lifes;
            // Reset game
            reset_game(ball, brick_handler);
        }
        lifes_text.setString("Lifes: "s + std::to_string(lifes));
        paddle.update();
        brick_handler.detect_collision(ball);
        paddle.detect_collision(ball);
        background.draw(window);
        ball.draw(window);
        paddle.draw(window);
        brick_handler.draw(window);
        window.draw(lifes_text);
        window.display();
    }
    window.clear(sf::Color::Black);
    sf::Font font("MTF Toast.ttf");
    sf::Text text{font};
    // set the string to display
    if (brick_handler.getNumBricks() == 0)
    {
      text.setString("You Win!"s);
      text.setFillColor(sf::Color::Green);
    }
    else
    {
      text.setString("Game Over"s);
      text.setFillColor(sf::Color::Red);
    }
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition({constants::window_width / 2.0f - 50.0f,
                     constants::window_height / 2.0f - 20.0f});
    window.draw(text);
    window.display();

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
    }
    return 0;
}
