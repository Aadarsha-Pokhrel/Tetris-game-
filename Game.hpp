#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include "Board.hpp"
#include "Tetromino.hpp"
#include "Constants.hpp"
<<<<<<< HEAD
#include "StartScreen.hpp"
#include <SFML/Audio.hpp>  // add this include at the top of Game.hpp

// inside class Game private section

=======
>>>>>>> 31caca8715998a75f980662684775b7544a0d480

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void spawnTetromino();
<<<<<<< HEAD
   
    void initializeText();

    // New method to handle window resizing view adjustment
    void adjustViewForWindowSize(unsigned int width, unsigned int height);

    sf::Music backgroundMusic;
    sf::SoundBuffer gameOverBuffer;
    sf::Sound gameOverSound;
    bool gameOverSoundPlayed;
  
=======
    void initializeText();
    void updateUIText();
    void drawNextPiecePreview();
    void drawPauseScreen();

>>>>>>> 31caca8715998a75f980662684775b7544a0d480
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
<<<<<<< HEAD

    // Start screen stuff
    StartScreen startScreen;
    bool isStartScreenActive;
=======
>>>>>>> 31caca8715998a75f980662684775b7544a0d480
};

#endif