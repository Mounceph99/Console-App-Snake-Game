//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_SNAKE_H
#define CONSOLE_APP_SNAKE_GAME_SNAKE_H

#include "Board.h"
#include <iostream>
using std::ostream;



enum Direction {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

class Unit {
private:
    Coordinate* coor;
    Unit* prev;
    Unit* next;

public:
    Unit();
    Unit(Coordinate* coor);
    Unit(const Unit& unit);
    ~Unit();

    Unit& operator=(const Unit& unit);
    friend ostream& operator<<(ostream& output, const Unit& unit);

    Coordinate* getCoordinate() {return coor;};

};

class Snake {
    private:
        Unit* head;
        int size;
        int speed;
        Direction dir;

    public:
        Snake();
        Snake(const Snake& snake);
        ~Snake();

        Snake& operator=(const Snake& snake);
        friend ostream& operator<<(ostream& output, const Snake& snake);

        void setDirection(Direction dir) {this->dir = dir;};
        void move();
};


#endif //CONSOLE_APP_SNAKE_GAME_SNAKE_H
