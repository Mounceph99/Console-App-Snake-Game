//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Board.h"
#include "Snake.h"
#include "Apple.h"

#include "iostream"
using std::endl;

Board::Board() {
    this->snake = new Snake();
    this->apple = new Apple();
}

Board::Board(const Board& board) {
    this->snake = new Snake(*board.snake);
    this->apple = new Apple(*board.apple);
}

Board::~Board() {
    delete this->snake;
    delete this->apple;

    this->snake = nullptr;
    this->apple = nullptr;
}

Board& Board::operator=(const Board &board) {

    if (this == &board) {
        return *this;
    }

    this->snake = new Snake(*board.snake);
    this->apple = new Apple(*board.apple);

    return *this;
}

ostream& operator<<(ostream& output, const Board& board) {

    for (int row = 0; row < VERTICAL_LENGTH; row++) {

        //Prints the leftmost side of board
        output << "\t\t\t|";

        for (int column = 0; column < HORIZONTAL_LENGTH; column++) {

            //Print upper and lower bound of board
            if (row == 0 || row == VERTICAL_LENGTH-1) {
                output << '-';
            } else if (column == board.apple->getCoordinate()->getX() && row == board.apple->getCoordinate()->getY()) {
                output << '@';
            }
            else {
                    output << ' ';
            }

        }

        //Prints the leftmost side of board
        output << '|' << endl;

    }
    return output;
}

Coordinate::Coordinate(): x_pos(0), y_pos(0) {}

Coordinate::Coordinate(int x, int y): x_pos(x), y_pos(y) {}

Coordinate::Coordinate(const Coordinate& coor): x_pos(coor.x_pos), y_pos(coor.y_pos) {}

Coordinate::~Coordinate() {}

Coordinate& Coordinate::operator=(const Coordinate &coor) {

    if (this == &coor) {
        return *this;
    }

    this->x_pos = coor.x_pos;
    this->y_pos = coor.y_pos;

    return *this;
}

ostream& operator<<(ostream& output, const Coordinate& coor) {
    output << '(' << coor.x_pos << ", " << coor.y_pos << ')';
    return output;
}