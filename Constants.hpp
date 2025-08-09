// Constants.hpp
#ifndef TETRIS_CONSTANTS_HPP
#define TETRIS_CONSTANTS_HPP

#include <SFML/Graphics.hpp>

namespace Constants {
    // Window settings
    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 700;  // increased height

    // Board settings
    const unsigned int CELL_SIZE = 30;
    const unsigned int BOARD_WIDTH = 10;
    const unsigned int BOARD_HEIGHT = 20;
    const float BOARD_OFFSET_X = 300.0f;
    const float BOARD_OFFSET_Y = 10.0f;  // moved up further

    // Grid settings
    const float GRID_LINE_THICKNESS = 1.0f;
    const sf::Color GRID_LINE_COLOR = sf::Color(50, 50, 50, 100);

    // Game timing
    const float MOVE_DELAY = 0.5f;
    const float FAST_MOVE_DELAY = 0.05f;
}

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 31caca8715998a75f980662684775b7544a0d480
=======
#endif
>>>>>>> 31caca8715998a75f980662684775b7544a0d480
