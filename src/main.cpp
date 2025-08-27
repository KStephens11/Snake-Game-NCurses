//#include <iostream>
#include <ncurses.h>
#include <board.hpp>
#include <game.hpp>
#include <unistd.h>
#include <iostream>
#include <apple.hpp>

#define BOARD_ROWS 17
#define BOARD_COLS 42

// TODO
// BUG: APPLE STICKS TO SNAKE (MIGHT BE FIXED LOOK OUT FOR IT)
// OPTIMIZATION: STOP CHECKING FOR APPLE COORDINATES EVERY FRAME, GET IT AT THE START AND WHEN THE APPLE IS EATEN AND REGENERATED
// MAYBE PUT A CHECK TO FIND ANOTHER LOCATION IF THE GENERATED LOCATION IS ON THE SNAKE
// IMPLEMENT WIN CONDITION (DONT KNOW HOW YET)

int main() {

    initscr();
    refresh();
    //halfdelay(1);
    curs_set(0);
    noecho();
    //timeout(1000);
    
    Game game = Game(BOARD_ROWS, BOARD_COLS);
    while(!game.isOver()) {

        game.processInput();

        game.updateState();

        game.redraw();
        usleep(135000);

    }

    //mvprintw(20, 20, "Game Over");
    usleep(650000);
    //getch();
    endwin();
}