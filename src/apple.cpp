#include <apple.hpp>

Apple::Apple(int p_height, int p_width): height(p_height), width(p_width){
    genApple();
}

Apple::Apple(){}

int Apple::genNumber(int num1, int num2) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(num1, num2);
    return distr(gen);
}

void Apple::genApple() {
    x  = genNumber(1, width-2);
    y = genNumber(1, height-2);
}

int Apple::getY(){
    return y;
}

int Apple::getX(){
    return x;
}