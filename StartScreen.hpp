#ifndef TETRIS_STARTSCREEN_HPP
#define TETRIS_STARTSCREEN_HPP

#include <SFML/Graphics.hpp>

class StartScreen {
public:
    explicit StartScreen(sf::Font& font);
    bool handleEvent(const sf::Event& e, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::Font& fontRef;
    sf::Text title;
    sf::Text author1;
    sf::Text author2;
    sf::Text author3;
    sf::RectangleShape startButton;
    sf::Text startText;

    void layout(sf::RenderWindow& window);
};

#endif