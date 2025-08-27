#include <snake.hpp>

Snake::Snake(chtype p_dir, int p_y, int p_x){
    dir = p_dir;
    location.first = p_y;
    location.second = p_x;
    //Add head
    body.push_front(std::make_pair(p_y,p_x));
    //Add Body
    body.push_back(std::make_pair(p_y,p_x-1));
    
}

Snake::Snake(){}

void Snake::addLenght() {
    body.push_back(body.back());
}

void Snake::setDirection(chtype p_dir) {
    dir = p_dir;
}

void Snake::moveHead() {
    switch (dir)
    {
    case 'w':
        location.first--;
        break;
    case 's':
        location.first++;
        break;
    case 'a':
        location.second--;
        break;
    case 'd':
        location.second++;
        break;
    }
}

void Snake::moveBody() {
    
    body.push_front(location);
    body.pop_back();
}

int Snake::getY() {
    return location.first;
}

int Snake::getX() {
    return location.second;
}

