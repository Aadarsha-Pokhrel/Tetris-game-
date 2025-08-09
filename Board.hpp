#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tetromino.hpp"
#include "Constants.hpp"

class Board {
public:
    Board();
    void draw(sf::RenderWindow& window) const;
    bool isGameOver() const { return gameOver; }
    int getScore() const { return score; }
    int getLevel() const { return level; }
    int getLinesCleared() const { return linesCleared; }
    const std::vector<std::vector<int>>& getGrid() const { return grid; }

    bool moveTetromino(Tetromino& tetromino, int dx, int dy);
    bool rotateTetromino(Tetromino& tetromino);
    bool placeTetromino(Tetromino& tetromino);
    void dropTetromino(Tetromino& tetromino);
    void reset();
    void setGameOver(bool status) { gameOver = status; }

private:
    std::vector<std::vector<int>> grid;
    bool gameOver;
    int score;
    int level;
    int linesCleared;

    void clearLines();
};

#endif