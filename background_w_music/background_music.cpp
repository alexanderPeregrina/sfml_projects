#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "constants.h"

// To compile: g++ -std=c++17 -O2 background_music.cpp -o background_music -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

using namespace std::literals;

int main() {
    sf::RenderWindow game_window{ sf::VideoMode{ sf::Vector2u{ constants::window_width,
                                                               constants::window_height } },
                                 "Background image with music"s };

    // load a sprite to display
    sf::Texture texture("the_doors.jpg");
    sf::Sprite sprite(texture);

    // load a music to play
    sf::Music music("When_the_Musics_Over.ogg");
    music.setLooping(true);
    music.play();   

    // resize image to fit window
    auto windows_size = game_window.getSize();
    sprite.setScale({
        float(windows_size.x) / texture.getSize().x,
        float(windows_size.y) / texture.getSize().y});

    game_window.setFramerateLimit(60);

    while (game_window.isOpen()) {
        game_window.clear(sf::Color::Black);

        // pollEvent in SFML 3
        while (auto maybeEvent = game_window.pollEvent()) {

            // Close window: exit
            if (maybeEvent->is<sf::Event::Closed>())
                game_window.close();
        }

        // keep the Escape key check using global keyboard state
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            game_window.close();

        game_window.draw(sprite);
        game_window.display();
    }
    return 0;
}