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
const int VERTICAL_LENGTH = 30;


class Board {
    private:
        Snake* snake;
        Apple* apple;


    public:
        Board();
        Board(const Board& board);
        ~Board();

        Board& operator=(const Board& board);
        friend ostream& operator<<(ostream& output, const Board& board);

};


#endif //CONSOLE_APP_SNAKE_GAME_BOARD_H
