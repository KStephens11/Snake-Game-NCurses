#include <board.hpp>


Board::Board(int p_height, int p_width): height(p_height), width(p_width){
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        board_win = newwin(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2));
        //wtimeout(board_win, 0);
        nodelay(board_win, true);
}

Board::Board(){}

void Board::initialize() {
    clear();
    refresh();
}

void Board::addBorder() {
    box(board_win, 0, 0);
}

void Board::addAt(int y, int x, chtype ch) {
    wmove(board_win, y, x);
    waddch(board_win, ch);
}

chtype Board::getInput() {
    return wgetch(board_win);
}

void Board::clear(){
    wclear(board_win);
    addBorder();
}

void Board::refresh() {
    wrefresh(board_win);
    
}

void Board::writeGameOver() {
    wmove(board_win, height/2, width/2-5);
    wprintw(board_win, "Game Over!");
}