//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Apple.h"
#include "Board.h"

#include <stdlib.h>
using std::rand;
using std::srand;

#include <time.h>

Apple::Apple() {
    srand(time(NULL));
    this->coor = new Coordinate();
    this->coor->setCoordinates(rand() % (HORIZONTAL_LENGTH-2) + 1, rand() % (VERTICAL_LENGTH-2) + 1)  ;
}

Apple::Apple(const Apple& apple) {
    this->coor = new Coordinate(*apple.coor);
}

Apple::~Apple() {
    delete this->coor;
    this->coor = nullptr;

}

Apple& Apple::operator=(const Apple &apple) {

    if (this == &apple) {
        return *this;
    }

    this->coor = new Coordinate(*apple.coor);

    return *this;
}

ostream& operator<<(ostream& output, const Apple& apple) {
    output << '@';
    return output;
}