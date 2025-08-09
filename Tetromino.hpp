#ifndef TETRIS_TETROMINO_HPP
#define TETRIS_TETROMINO_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.hpp"

class Tetromino {
public:
    enum class Type { I, O, T, S, Z, J, L, COUNT };

    Tetromino(Type type);
    void draw(sf::RenderWindow& window) const;
    void rotate(bool clockwise = true);
    void move(int dx, int dy);
    bool isCollision(const std::vector<std::vector<int>>& board) const;

    const std::vector<sf::Vector2i>& getBlocks() const { return blocks; }
    Type getType() const { return type; }
    sf::Color getColor() const { return color; }
    int getX() const { return x; }
    int getY() const { return y; }

private:
    Type type;
    std::vector<sf::Vector2i> blocks;
    sf::Color color;
    int x = 0;
    int y = 0;

    void initializeBlocks();
};

#endif