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
            } else {
                output << ' ';
            }

        }

        //Prints the leftmost side of board
        output << '|' << endl;

    }
    return output;
}