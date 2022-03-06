//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Controller.h"
#include "Snake.h"

#include <conio.h>

Controller::Controller() {
}

Controller::Controller(const Controller& controller) {
}

Controller::~Controller() {
}

Controller& Controller::operator=(const Controller &controller) {

    if (this == &controller) {
        return *this;
    }

    return *this;
}

ostream& operator<<(ostream& output, const Controller& controller) {
    return output;
}

void Controller::readInput(Snake* snake) {
    if (kbhit()) {
        switch (getch()) {
            case 'w': snake->setDirection(UP); break;
           case 's': snake->setDirection(DOWN); break;
            case 'a': snake->setDirection(LEFT); break;
            case 'd': snake->setDirection(RIGHT); break;
        }
    }
}