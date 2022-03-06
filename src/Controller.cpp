//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Controller.h"

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