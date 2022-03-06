//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_SNAKE_H
#define CONSOLE_APP_SNAKE_GAME_SNAKE_H

#include <iostream>
using std::ostream;

class Unit;

class Snake {
    private:
        Unit* head;

    public:
        Snake();
        Snake(const Snake& snake);
        ~Snake();

        Snake& operator=(const Snake& snake);
        friend ostream& operator<<(ostream& output, const Snake& snake);
};

class Unit {
    private:
        int x_pos;
        int y_pos;
        Unit* prev;
        Unit* next;

    public:
        Unit();
        Unit(const Unit& unit);
        ~Unit();

        Unit& operator=(const Unit& unit);
        friend ostream& operator<<(ostream& output, const Unit& unit);

};


#endif //CONSOLE_APP_SNAKE_GAME_SNAKE_H
