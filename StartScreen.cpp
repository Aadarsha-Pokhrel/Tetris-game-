#include "StartScreen.hpp"
#include "Constants.hpp"
#include <iostream>

StartScreen::StartScreen(sf::Font& font) : fontRef(font) {
    title.setFont(fontRef);
    title.setString("TETRIS GAME");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);

    author1.setFont(fontRef);
    author1.setString("Aadarsha");
    author1.setCharacterSize(28);
    author1.setFillColor(sf::Color::Cyan);

    author2.setFont(fontRef);
    author2.setString("Aanat");
    author2.setCharacterSize(28);
    author2.setFillColor(sf::Color::Magenta);

    author3.setFont(fontRef);
    author3.setString("Aashish");
    author3.setCharacterSize(28);
    author3.setFillColor(sf::Color::Yellow);

    startButton.setSize(sf::Vector2f(220.f, 64.f));
    startButton.setFillColor(sf::Color(70, 130, 180));
    startButton.setOutlineThickness(2.f);
    startButton.setOutlineColor(sf::Color::White);

    startText.setFont(fontRef);
    startText.setString("START");
    startText.setCharacterSize(32);
    startText.setFillColor(sf::Color::White);
}

void StartScreen::layout(sf::RenderWindow& window) {
    sf::Vector2f size = window.getView().getSize();
    float W = size.x;
    float H = size.y;

    // title centered near top
    sf::FloatRect tb = title.getLocalBounds();
    title.setOrigin(tb.left + tb.width / 2.f, tb.top + tb.height / 2.f);
    title.setPosition(W / 2.f, H * 0.14f);

    // authors stacked, centered
    author1.setPosition(W / 2.f - author1.getLocalBounds().width / 2.f, H * 0.30f);
    author2.setPosition(W / 2.f - author2.getLocalBounds().width / 2.f, H * 0.38f);
    author3.setPosition(W / 2.f - author3.getLocalBounds().width / 2.f, H * 0.46f);

    // button centered
    startButton.setPosition(W / 2.f - startButton.getSize().x / 2.f, H * 0.60f);
    sf::FloatRect btb = startText.getLocalBounds();
    startText.setOrigin(btb.left + btb.width / 2.f, btb.top + btb.height / 2.f);
    startText.setPosition(startButton.getPosition().x + startButton.getSize().x / 2.f,
        startButton.getPosition().y + startButton.getSize().y / 2.f);
}

bool StartScreen::handleEvent(const sf::Event& e, sf::RenderWindow& window) {
    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i pix(e.mouseButton.x, e.mouseButton.y);
        sf::Vector2f world = window.mapPixelToCoords(pix);
        if (startButton.getGlobalBounds().contains(world))
            return true;
    }

    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
        return true;
    }

    return false;
}

void StartScreen::draw(sf::RenderWindow& window) {
    // Save the original view
    sf::View originalView = window.getView();

    // Reset to default view for proper UI rendering
    window.setView(window.getDefaultView());

    // Always layout before drawing
    layout(window);

    window.draw(title);
    window.draw(author1);
    window.draw(author2);
    window.draw(author3);
    window.draw(startButton);
    window.draw(startText);

    // Restore the original view
    window.setView(originalView);
}
