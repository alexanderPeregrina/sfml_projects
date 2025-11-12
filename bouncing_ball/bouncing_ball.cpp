#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "background.h"
#include "constants.h"
#include "ball.h"

// To compile: g++ -std=c++17 -O2 bouncing_ball.cpp background.cpp ball.cpp -o bouncing_ball -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

using namespace std::literals;

int main() 
{

    sf::RenderWindow window{ sf::VideoMode{ sf::Vector2u{ constants::window_width,
                                                          constants::window_height } },
                                 "Bouncing Ball Simulation"s };

    sf::Music music{"moonlight_drive.ogg"};

    window.setFramerateLimit(60);

    Background background(0.0f, 0.0f);
    Ball ball(constants::window_width / 2.0f, constants::window_height / 2.0f);

    music.setLooping(true);
    music.play();

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        while (auto mayEvent = window.pollEvent()) {
            if (mayEvent->is<sf::Event::Closed>())
                window.close();
        }

        // keep the Escape key check using global keyboard state
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        ball.update();

        window.clear();
        background.draw(window);
        ball.draw(window);
        window.display();
    }

    return 0;
}
