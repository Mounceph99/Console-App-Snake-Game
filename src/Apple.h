//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_APPLE_H
#define CONSOLE_APP_SNAKE_GAME_APPLE_H

#include "Board.h"

#include <iostream>
using std::ostream;

class Apple  {
    private:
    Coordinate* coor;

    public:
        Apple();
        Apple(const Apple& apple);
        ~Apple();

        Apple& operator=(const Apple& apple);
        friend ostream& operator<<(ostream& output, const Apple& apple);

        Coordinate* getCoordinate() {return coor;};
        void generateNewFood();
};


#endif //CONSOLE_APP_SNAKE_GAME_APPLE_H
