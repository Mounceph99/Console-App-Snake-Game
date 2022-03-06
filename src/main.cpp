//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Board.h"
#include "Apple.h"
#include "Controller.h"
#include "Snake.h"

#include "iostream"
using std::cout;

#include "Windows.h"

int main() {
    Controller* c = new Controller();
    Board* b = new Board();
    bool gameOver = false;


    while (!gameOver) {
        cout << *b;
        c->readInput(b);
        b->getSnake()->move();

        if (b->getSnake()->hasCollided()) {
            gameOver = true;
        }

        if (b->getSnake()->isEating(*b->getApple()->getCoordinate())) {
            b->getApple()->generateNewFood();
            b->getSnake()->grow();
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });


        Sleep(50);
    }

    return 0;
}
