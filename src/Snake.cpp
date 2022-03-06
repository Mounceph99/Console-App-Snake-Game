//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Snake.h"

Snake::Snake() {
}

Snake::Snake(const Snake& snake) {
}

Snake::~Snake() {
}

Snake& Snake::operator=(const Snake &snake) {

    if (this == &snake) {
        return *this;
    }

    return *this;
}

ostream& operator<<(ostream& output, const Snake& snake) {
    return output;
}


Unit::Unit() {
}

Unit::Unit(const Unit& u) {
}

Unit::~Unit() {
}

Unit& Unit::operator=(const Unit &u) {

    if (this == &u) {
        return *this;
    }

    return *this;
}

ostream& operator<<(ostream& output, const Unit& u) {
    return output;
}
