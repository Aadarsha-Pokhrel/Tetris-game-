#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include "Board.hpp"
#include "Tetromino.hpp"
#include "Constants.hpp"
#include "StartScreen.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void spawnTetromino();
    void initializeText();

    // New method to handle window resizing view adjustment
    void adjustViewForWindowSize(unsigned int width, unsigned int height);

    sf::RenderWindow window;
    Board board;
    std::unique_ptr<Tetromino> currentTetromino;
    std::unique_ptr<Tetromino> nextTetromino;

    sf::Font font;
    sf::Text scoreText;
    sf::Text levelText;
    sf::Text linesText;
    sf::Text gameOverText;

    float moveDelay;
    float timeSinceLastMove;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;

    bool isPaused;
    bool fastDrop;

    // Start screen stuff
    StartScreen startScreen;
    bool isStartScreenActive;
};

#endif
