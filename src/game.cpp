#include <game.hpp>

#define SNAKE_CHAR '@'

Game::Game(int p_h, int p_w): height(p_h), width(p_w), gameOver(false){
    board = Board(height, width);
    snake = Snake('d', 2, 2);
    apple = Apple(height, width);
    board.initialize();
}
    

void Game::processInput(){
    input = board.getInput();
    if (input == 's' || input == 'w' || input == 'a' || input == 'd') {
        snake.setDirection(input);
    }
    if (input == 'r') {
        snake.addLenght();
    } 
}

void Game::checkCollision() {
    if(snake.getY() == 0 || snake.getX() == 0 || snake.getY() == height-1 || snake.getX() == width-1) {
        gameOver = true;
    }
    if(snake.getY() == apple.getY() && snake.getX() == apple.getX()) {
        snake.addLenght();
        apple.genApple();
    }
    //for(const auto & pos: snake.body) {
    // This is to make sure that it doesnt check the head against the head
    for(auto pos = std::next(snake.body.begin()); pos != snake.body.end(); ++pos){
        if (snake.getY() == pos->first && snake.getX() == pos->second) {
        //if (snake.getY() == pos.first && snake.getX() == pos.second) {
            gameOver = true;
        }
    }
}

void Game::updateState(){
    snake.moveHead();
    snake.moveBody();
    checkCollision();
    
    
    
}

void Game::redraw(){
    board.clear();

    board.addAt(apple.getY(), apple.getX(), '*');
    
    for(const auto & pos: snake.body) {
        board.addAt(pos.first, pos.second, SNAKE_CHAR);
    }

    

    if (gameOver == true) {
        board.writeGameOver();
    }

    board.refresh();
}

bool Game::isOver(){
    return gameOver;
}

