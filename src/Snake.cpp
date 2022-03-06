//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Snake.h"
#include "Apple.h"

Unit::Unit(): coor(new Coordinate()), prev(NULL), next(NULL) {}

Unit::Unit(Coordinate* coor): prev(NULL), next(NULL) {
    this->coor = new Coordinate(*coor);
}

Unit::Unit(const Unit& u): prev(u.prev), next(u.next){
    this->coor = new Coordinate(*u.coor);
}

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
    output << '0';
    return output;
}

Snake::Snake(): head(new Unit()), end(this->head), size(1), speed(1), dir(NONE) {}

Snake::Snake(const Snake& snake): head(snake.head), end(snake.end), size(snake.size), speed(snake.speed), dir(snake.dir) {}

Snake::~Snake() {
    //TODO: Will likely have to delete the tail
    std::cout << "Snake destructor";
    if (this->head == this->end) {
        delete this->head;
        this->head = nullptr;

        this->end = nullptr;
    }
    else {
        delete this->head;
        this->head = nullptr;

        delete this->end;
        this->end = nullptr;
    }

    
}

Snake& Snake::operator=(const Snake &snake) {

    if (this == &snake) {
        return *this;
    }

    //TODO: Will likely have to copy the tail
    this->head = new Unit(*snake.head);


    this->end = new Unit(*snake.end);

    this->size = snake.size;
    this->speed = snake.speed;
    this->dir = snake.dir;

    return *this;
}

ostream& operator<<(ostream& output, const Snake& snake) {
    output << 'X';
    return output;
}

void Snake::move() {

    Unit* temp = this->end;

    while (temp != nullptr && temp != this->head) {
        temp->getCoordinate()->setCoordinates(temp->getNext()->getCoordinate()->getX(), temp->getNext()->getCoordinate()->getY());
        temp = temp->getNext();
    }

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
    this->updateBody();
}

bool Snake::hasCollided() {

    if (this->head->getCoordinate()->getX() < 0 || 
        this->head->getCoordinate()->getX() > (HORIZONTAL_LENGTH-1) ||
        this->head->getCoordinate()->getY() < 1 ||
        this->head->getCoordinate()->getY() > (VERTICAL_LENGTH-2)) {
        return true;
    }

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

void Snake::updateBody() {

    Unit* newEnd = new Unit(this->end->getCoordinate());

    this->end->setPrev(newEnd);
    newEnd->setNext(end);

    this->end = newEnd;
}

void printSnake(Snake& s) {

    Unit* temp = s.getHead();

    std::cout << '[' << *temp->getCoordinate() << "] ";

    temp = temp->getPrev();

    while (temp != nullptr) {
        std::cout << '(' << *temp->getCoordinate() << ") ";

        temp = temp->getPrev();
    }
}
