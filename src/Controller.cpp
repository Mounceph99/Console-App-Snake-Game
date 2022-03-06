//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Controller.h"
#include "Snake.h"
#include "Board.h"

#include <conio.h>

Controller::Controller() {}

Controller::Controller(const Controller& controller) {}

Controller::~Controller() {}

Controller& Controller::operator=(const Controller &controller) {
    
    if (this == &controller) {
        return *this;
    }

    return *this;
}

ostream& operator<<(ostream& output, const Controller& controller) {
    return output;
}

void Controller::readInput(Board* board) {
    if (kbhit()) {
        switch (getch()) {
            case 'w': board->getSnake()->setDirection(UP); break;
            case 's': board->getSnake()->setDirection(DOWN); break;
            case 'a': board->getSnake()->setDirection(LEFT); break;
            case 'd': board->getSnake()->setDirection(RIGHT); break;
        }
    }
}