#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "background.h"
#include "constants.h"
#include "ball.h"

// To compile: g++ -std=c++17 -O2 random_walk.cpp background.cpp ball.cpp -o random_walk -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

using namespace std::literals;

void generate_random_direction(float& velocity) {
    int direction = rand() % 3;
    
    switch (direction) {
        case 0: // no moving in this direction
            velocity = 0.0f;
            break;
        case 1: // move in positive direction
            velocity = constants::ball_speed;
            break;
        case 2: // move in negative direction
            velocity = -constants::ball_speed;
            break;
    }
}

int main() 
{

    sf::RenderWindow window{ sf::VideoMode{ sf::Vector2u{ constants::window_width,
                                                               constants::window_height } },
                                 "Random Walk Simulation"s };

    sf::Music music{"moonlight_drive.ogg"};

    window.setFramerateLimit(60);

    Background background(0.0f, 0.0f);
    Ball ball(constants::window_width / 2.0f, constants::window_height / 2.0f);
    float vel_x, vel_y;

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

        generate_random_direction(vel_x);
        generate_random_direction(vel_y);
        ball.setVelocity({vel_x, vel_y});
        ball.update();

        window.clear();
        background.draw(window);
        ball.draw(window);
        window.display();
    }

    return 0;
}
