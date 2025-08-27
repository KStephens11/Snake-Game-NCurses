#pragma once
#include <random>
#include <iostream>

class Apple{
public:
    Apple(int height, int width);
    Apple();
    void genApple();
    int getY();
    int getX();
private:
    int genNumber(int num1, int num2);
private:
    int y, x, height, width;
};