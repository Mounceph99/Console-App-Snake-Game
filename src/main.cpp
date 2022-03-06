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
#include <conio.h>



int main() {
    Controller* c = new Controller();
    Board* b = new Board();
    bool gameOver = false;


    while (!gameOver) {
        cout << *b;
        c->readInput(b->snake);
        b->snake->move();

        if (b->snake->isEating(*b->apple->getCoordinate())) {
            b->apple->generateNewFood();
            b->snake->grow();
        }

        if (b->snake->hasCollided()) {
            gameOver = true;
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
        Sleep(100);
    }

    system("CLS");
    std::cout << "Thanks for playing :)))" << std::endl;


    return 0;
}
