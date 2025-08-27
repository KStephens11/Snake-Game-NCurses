#pragma once
#include <board.hpp>
#include <snake.hpp>
#include <apple.hpp>

class Game {
public:
    Game(int p_h, int p_w);
    void processInput();
    void updateState();
    void redraw();
    bool isOver();
    char getInput();
    void checkCollision();
private:
    Board board;
    Snake snake;
    Apple apple;
    
    chtype input;
    chtype direction;
    int height, width;
    bool gameOver;
};