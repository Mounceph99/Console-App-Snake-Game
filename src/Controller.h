//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_CONTROLLER_H
#define CONSOLE_APP_SNAKE_GAME_CONTROLLER_H

#include <iostream>
using std::ostream;

class Controller {
    public:
        Controller();
        Controller(const Controller& unit);
        ~Controller();

        Controller& operator=(const Controller& unit);
        friend ostream& operator<<(ostream& output, const Controller& unit);
};


#endif //CONSOLE_APP_SNAKE_GAME_CONTROLLER_H
