#include "Tetromino.hpp"

Tetromino::Tetromino(Type type) : type(type), x(0), y(0), color(sf::Color::White) {
    initializeBlocks();

    switch (type) {
    case Type::I: color = sf::Color::Cyan; break;
    case Type::O: color = sf::Color::Yellow; break;
    case Type::T: color = sf::Color::Magenta; break;
    case Type::S: color = sf::Color::Green; break;
    case Type::Z: color = sf::Color::Red; break;
    case Type::J: color = sf::Color::Blue; break;
    case Type::L: color = sf::Color(255, 165, 0); break;
    default: break;
    }
}

void Tetromino::initializeBlocks() {
    blocks.clear();
    switch (type) {
    case Type::I: blocks = { {0,0}, {1,0}, {2,0}, {3,0} }; break;
    case Type::O: blocks = { {0,0}, {1,0}, {0,1}, {1,1} }; break;
    case Type::T: blocks = { {0,0}, {1,0}, {2,0}, {1,1} }; break;
    case Type::S: blocks = { {1,0}, {2,0}, {0,1}, {1,1} }; break;
    case Type::Z: blocks = { {0,0}, {1,0}, {1,1}, {2,1} }; break;
    case Type::J: blocks = { {0,0}, {0,1}, {1,1}, {2,1} }; break;
    case Type::L: blocks = { {2,0}, {0,1}, {1,1}, {2,1} }; break;
    default: blocks = { {0,0} };
    }
}

void Tetromino::draw(sf::RenderWindow& window) const {
    sf::RectangleShape block(sf::Vector2f(
        Constants::CELL_SIZE - Constants::GRID_LINE_THICKNESS * 2,
        Constants::CELL_SIZE - Constants::GRID_LINE_THICKNESS * 2
    ));
    block.setFillColor(color);

    for (const auto& pos : blocks) {
        block.setPosition(
            Constants::BOARD_OFFSET_X + (x + pos.x) * Constants::CELL_SIZE + Constants::GRID_LINE_THICKNESS,
            Constants::BOARD_OFFSET_Y + (y + pos.y) * Constants::CELL_SIZE + Constants::GRID_LINE_THICKNESS
        );
        window.draw(block);
    }
}

void Tetromino::rotate(bool clockwise) {
    for (auto& block : blocks) {
        int newX = clockwise ? -block.y : block.y;
        int newY = clockwise ? block.x : -block.x;
        block.x = newX;
        block.y = newY;
    }
}

void Tetromino::move(int dx, int dy) {
    x += dx;
    y += dy;
}

bool Tetromino::isCollision(const std::vector<std::vector<int>>& board) const {
    for (const auto& block : blocks) {
        int boardX = x + block.x;
        int boardY = y + block.y;

        if (boardX < 0 || boardX >= Constants::BOARD_WIDTH ||
            boardY < 0 || boardY >= Constants::BOARD_HEIGHT) {
            return true;
        }

        if (boardY >= 0 && board[boardY][boardX] != 0) {
            return true;
        }
    }
    return false;
}