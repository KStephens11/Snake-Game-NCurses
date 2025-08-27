#pragma once
#include <ncurses.h>
#include <list>
#include <utility>

class Snake{
public:
    Snake(chtype p_dir, int p_y, int p_x);
    Snake();
    int getLenght();
    void addLenght();
    void setDirection(chtype p_dir);
    void moveHead();
    void moveBody();
    int getY();
    int getX();
    

public:
    std::list<std::pair<int, int>> body;

private:
    chtype dir;
    std::pair<int, int> location;
    
};