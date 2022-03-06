//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_BOARD_H
#define CONSOLE_APP_SNAKE_GAME_BOARD_H

#include <iostream>
using std::ostream;

class Snake;
class Apple;

const int HORIZONTAL_LENGTH = 50;
const int VERTICAL_LENGTH = 15;

const int IGNORE_INT = -976321;


class Board {

    public:

    Snake* snake;
    Apple* apple;

        Board();
        Board(const Board& board);
        ~Board();

        Board& operator=(const Board& board);
        friend ostream& operator<<(ostream& output, const Board& board);

};

class Coordinate {
private:
    int x_pos;
    int y_pos;

public:
    Coordinate();
    Coordinate(int x, int y);
    Coordinate(const Coordinate& coor);
    ~Coordinate();

    Coordinate& operator=(const Coordinate& coor);
    friend ostream& operator<<(ostream& output, const Coordinate& coor);

    int getX() {return this->x_pos;};
    int getY() {return this->y_pos;};

    void setCoordinates(int x, int y) {

        if (x != IGNORE_INT) {
            this->x_pos = x;
        }

        if (y != IGNORE_INT) {
            this->y_pos = y;
        }

    };
};




#endif //CONSOLE_APP_SNAKE_GAME_BOARD_H
