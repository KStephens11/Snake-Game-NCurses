#pragma once
#include <ncurses.h>

class Board {
public:
    Board(int p_height, int p_width);
    Board();
public:
    void refresh();
    void clear();
    void addBorder();
    void initialize();
    void addAt(int y, int x, chtype ch);
    chtype getInput();
    void writeGameOver();
private:
    chtype input;
    WINDOW* board_win;
    int height, width;
};



