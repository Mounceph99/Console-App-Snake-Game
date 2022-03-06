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
        c->readInput(b->snake);
        b->snake->move();

        if (b->snake->hasCollided()) {
            gameOver = true;
        }

        if (b->snake->isEating(*b->apple->getCoordinate())) {
            b->apple->generateNewFood();
            b->snake->grow();
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });


        Sleep(50);
    }

    return 0;
}
