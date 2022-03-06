//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Board.h"
#include "Apple.h"
#include "iostream"
using std::cout;

int main() {
    Board* b = new Board();

    while (true) {
        cout << *b;
        b->apple->getCoordinate()->setCoordinates(b->apple->getCoordinate()->getX()+1, b->apple->getCoordinate()->getY());
        //Cant clear screen in CLION
        system("CLS");
    }


    return 0;
}
