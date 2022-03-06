//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_CONTROLLER_H
#define CONSOLE_APP_SNAKE_GAME_CONTROLLER_H

#include <iostream>
using std::ostream;

class Snake;

class Controller {
    public:
        Controller();
        Controller(const Controller& controller);
        ~Controller();

        Controller& operator=(const Controller& controller);
        friend ostream& operator<<(ostream& output, const Controller& controller);

        void readInput(Snake* snake);
};


#endif //CONSOLE_APP_SNAKE_GAME_CONTROLLER_H
