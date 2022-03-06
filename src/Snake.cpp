//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Snake.h"
#include "Apple.h"

Unit::Unit(): coor(new Coordinate()), prev(NULL), next(NULL) {}

Unit::Unit(Coordinate* coor): prev(NULL), next(NULL) {
    this->coor = new Coordinate(*coor);
}

Unit::Unit(const Unit& u) {
    this->coor = new Coordinate(*u.coor);

    if (u.prev != nullptr) {
        this->prev = new Unit(u.prev->getCoordinate());
    }
    else {
        this->prev = nullptr;
    }

    if (u.next != nullptr) {
        this->next = new Unit(u.next->getCoordinate());
    }
    else {
        this->next = nullptr;
    }
}

Unit::~Unit() {

    //Will call destructors recursively
    if (this->prev != nullptr) {
        delete this->next;
    }

    if (this->next != nullptr) {
        delete this->prev;
    }

    delete this->coor;

    this->coor = nullptr;
    this->prev = this->next = nullptr;
}

Unit& Unit::operator=(const Unit &u) {

    if (this == &u) {
        return *this;
    }

    this->coor = new Coordinate(*u.coor);
    this->prev = new Unit(*u.prev);
    this->next = new Unit(*u.next);

    return *this;
}

ostream& operator<<(ostream& output, const Unit& u) {
    output << 'o';
    return output;
}

Snake::Snake(): head(new Unit()), end(this->head), size(1), speed(1), dir(NONE) {}

Snake::Snake(const Snake& snake): size(snake.size), speed(snake.speed), dir(snake.dir) {
    this->head = new Unit(*snake.head);
    this->end = new Unit(*snake.end);
}

Snake::~Snake() {

    delete this->head;
    delete this->end;

    this->head = this->end = nullptr;
}

Snake& Snake::operator=(const Snake &snake) {

    if (this == &snake) {
        return *this;
    }

    this->head = new Unit(*snake.head);

    if (snake.size == 1) {
        this->end = this->head;
    }
    else {
        Unit* temp = this->head;

        while (temp != nullptr && temp->getPrev() != nullptr) {
            temp = temp->getPrev();
        }

        this->end = temp;
    }
    

    this->size = snake.size;
    this->speed = snake.speed;
    this->dir = snake.dir;

    return *this;
}

ostream& operator<<(ostream& output, const Snake& snake) {
    //This is the head of the snake.
    output << 'O';
    return output;
}

void Snake::move() {

    //Move every unit other than head. Each unit should move to where the next unit is located.
    Unit* temp = this->end;
    while (temp != nullptr && temp != this->head) {
        temp->getCoordinate()->setCoordinates(temp->getNext()->getCoordinate()->getX(), temp->getNext()->getCoordinate()->getY());
        temp = temp->getNext();
    }

    //Move the head
    switch(dir) {
        case UP:
            this->head->getCoordinate()->setCoordinates(IGNORE_INT, this->head->getCoordinate()->getY()-speed);
            break;
        case DOWN:
            this->head->getCoordinate()->setCoordinates(IGNORE_INT, this->head->getCoordinate()->getY()+speed);
            break;
        case LEFT:
            this->head->getCoordinate()->setCoordinates(this->head->getCoordinate()->getX()-speed, IGNORE_INT);
            break;
        case RIGHT:
            this->head->getCoordinate()->setCoordinates(this->head->getCoordinate()->getX()+speed, IGNORE_INT);
            break;
    }
}

bool Snake::isEating(Coordinate& food) {
    return this->head->getCoordinate()->getX() == food.getX() &&
           this->head->getCoordinate()->getY() == food.getY();
}

void Snake::grow() {
    this->size++;
    this->addUnitToBody();
}

bool Snake::hasCollided() {

    //Wall collsions
    if (this->head->getCoordinate()->getX() < 0 || 
        this->head->getCoordinate()->getX() > (HORIZONTAL_LENGTH-1) ||
        this->head->getCoordinate()->getY() < 1 ||
        this->head->getCoordinate()->getY() > (VERTICAL_LENGTH-2)) {
        return true;
    }


    //Check collision on the snake's body
    Unit* temp = this->head->getPrev();

    while (temp != nullptr) {
        if (this->head->getCoordinate()->getX() == temp->getCoordinate()->getX() &&
            this->head->getCoordinate()->getY() == temp->getCoordinate()->getY()) {
            return true;
        }

        temp = temp->getPrev();
    }

    return false;
}

void Snake::addUnitToBody() {
    Unit* newEnd = new Unit(this->end->getCoordinate());
    this->end->setPrev(newEnd);
    newEnd->setNext(end);
    this->end = newEnd;
}
