//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Snake.h"
#include "Apple.h"

Unit::Unit(): coor(new Coordinate()), prev(NULL), next(NULL) {}

Unit::Unit(Coordinate* coor): coor(coor), prev(NULL), next(NULL) {}

Unit::Unit(const Unit& u): coor(u.coor), prev(u.prev), next(u.next){}

Unit::~Unit() {
    delete this->coor;
    delete this->prev;
    delete this->next;

    this->coor = nullptr;
    this->prev = nullptr;
    this->next = nullptr;
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
    return output;
}

Snake::Snake(): head(new Unit()), size(1), speed(1), dir(NONE) {}

Snake::Snake(const Snake& snake): head(snake.head), size(snake.size), speed(snake.speed), dir(snake.dir) {}

Snake::~Snake() {
    //TODO: Will likely have to delete the tail
    delete this->head;
    this->head = nullptr;
}

Snake& Snake::operator=(const Snake &snake) {

    if (this == &snake) {
        return *this;
    }

    //TODO: Will likely have to copy the tail
    this->head = new Unit(*snake.head);

    this->size = snake.size;
    this->speed = snake.speed;
    this->dir = snake.dir;

    return *this;
}

ostream& operator<<(ostream& output, const Snake& snake) {
    output << '*';
    return output;
}

void Snake::move() {  
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
    
    if (this->head->getCoordinate()->getX() == food.getX() &&
        this->head->getCoordinate()->getY() == food.getY()) {
        return true;
    }

    return false;
}

void Snake::grow() {
    this->size++;
}

bool Snake::hasCollided() {

    if (this->head->getCoordinate()->getX() < 0 || 
        this->head->getCoordinate()->getX() > (HORIZONTAL_LENGTH-1) ||
        this->head->getCoordinate()->getY() < 1 ||
        this->head->getCoordinate()->getY() > (VERTICAL_LENGTH-2)) {
        return true;
    }

    return false;
}
