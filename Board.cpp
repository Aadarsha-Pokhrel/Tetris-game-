#include "Board.hpp"
#include <algorithm>

Board::Board() : gameOver(false), score(0), level(1), linesCleared(0) {
    grid.resize(Constants::BOARD_HEIGHT, std::vector<int>(Constants::BOARD_WIDTH, 0));
}

void Board::draw(sf::RenderWindow& window) const {
    // Draw board background
    sf::RectangleShape boardBg(sf::Vector2f(
        Constants::BOARD_WIDTH * Constants::CELL_SIZE,
        Constants::BOARD_HEIGHT * Constants::CELL_SIZE
    ));
    boardBg.setPosition(Constants::BOARD_OFFSET_X, Constants::BOARD_OFFSET_Y);
    boardBg.setFillColor(sf::Color(30, 30, 30));
    window.draw(boardBg);

    // Draw grid lines
    for (unsigned int x = 0; x <= Constants::BOARD_WIDTH; x++) {
        sf::RectangleShape line(sf::Vector2f(Constants::GRID_LINE_THICKNESS,
            Constants::BOARD_HEIGHT * Constants::CELL_SIZE));
        line.setPosition(Constants::BOARD_OFFSET_X + x * Constants::CELL_SIZE, Constants::BOARD_OFFSET_Y);
        line.setFillColor(Constants::GRID_LINE_COLOR);
        window.draw(line);
    }

    for (unsigned int y = 0; y <= Constants::BOARD_HEIGHT; y++) {
        sf::RectangleShape line(sf::Vector2f(Constants::BOARD_WIDTH * Constants::CELL_SIZE,
            Constants::GRID_LINE_THICKNESS));
        line.setPosition(Constants::BOARD_OFFSET_X, Constants::BOARD_OFFSET_Y + y * Constants::CELL_SIZE);
        line.setFillColor(Constants::GRID_LINE_COLOR);
        window.draw(line);
    }

    // Draw blocks
    sf::RectangleShape block(sf::Vector2f(
        Constants::CELL_SIZE - Constants::GRID_LINE_THICKNESS * 2,
        Constants::CELL_SIZE - Constants::GRID_LINE_THICKNESS * 2
    ));

    for (unsigned int y = 0; y < Constants::BOARD_HEIGHT; y++) {
        for (unsigned int x = 0; x < Constants::BOARD_WIDTH; x++) {
            if (grid[y][x] != 0) {
                block.setPosition(
                    Constants::BOARD_OFFSET_X + x * Constants::CELL_SIZE + Constants::GRID_LINE_THICKNESS,
                    Constants::BOARD_OFFSET_Y + y * Constants::CELL_SIZE + Constants::GRID_LINE_THICKNESS
                );
                block.setFillColor(sf::Color(grid[y][x]));
                window.draw(block);
            }
        }
    }
}

bool Board::moveTetromino(Tetromino& tetromino, int dx, int dy) {
    tetromino.move(dx, dy);
    if (tetromino.isCollision(grid)) {
        tetromino.move(-dx, -dy);
        return false;
    }
    return true;
}

bool Board::rotateTetromino(Tetromino& tetromino) {
    tetromino.rotate();
    if (tetromino.isCollision(grid)) {
        tetromino.rotate(false);
        return false;
    }
    return true;
}

bool Board::placeTetromino(Tetromino& tetromino) {
    if (tetromino.isCollision(grid)) {
        return false;
    }

    const auto& blocks = tetromino.getBlocks();
    for (const auto& block : blocks) {
        int x = tetromino.getX() + block.x;
        int y = tetromino.getY() + block.y;

        // ** Fix: Clamp coordinates to grid bounds before writing **
        if (y >= 0 && y < static_cast<int>(Constants::BOARD_HEIGHT) &&
            x >= 0 && x < static_cast<int>(Constants::BOARD_WIDTH)) {
            grid[y][x] = static_cast<int>(tetromino.getColor().toInteger());
        }
    }

    clearLines();
    return true;
}

void Board::dropTetromino(Tetromino& tetromino) {
    while (!tetromino.isCollision(grid)) {
        tetromino.move(0, 1);
    }
    tetromino.move(0, -1);
}

void Board::clearLines() {
    int linesToClear = 0;
    for (int y = Constants::BOARD_HEIGHT - 1; y >= 0; y--) {
        bool lineComplete = true;
        for (int x = 0; x < Constants::BOARD_WIDTH; x++) {
            if (grid[y][x] == 0) {
                lineComplete = false;
                break;
            }
        }

        if (lineComplete) {
            grid.erase(grid.begin() + y);
            grid.insert(grid.begin(), std::vector<int>(Constants::BOARD_WIDTH, 0));
            y++;
            linesToClear++;
        }
    }

    if (linesToClear > 0) {
        linesCleared += linesToClear;
        switch (linesToClear) {
        case 1: score += 100 * level; break;
        case 2: score += 300 * level; break;
        case 3: score += 500 * level; break;
        case 4: score += 800 * level; break;
        }
        level = 1 + linesCleared / 10;
    }
}

void Board::reset() {
    grid.clear();
    grid.resize(Constants::BOARD_HEIGHT, std::vector<int>(Constants::BOARD_WIDTH, 0));
    gameOver = false;
    score = 0;
    level = 1;
    linesCleared = 0;
}
