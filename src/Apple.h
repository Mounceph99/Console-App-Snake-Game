//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_APPLE_H
#define CONSOLE_APP_SNAKE_GAME_APPLE_H

#include <iostream>
using std::ostream;

class Apple {
    public:
        Apple();
        Apple(const Apple& apple);
        ~Apple();

        Apple& operator=(const Apple& apple);
        friend ostream& operator<<(ostream& output, const Apple& apple);
};


#endif //CONSOLE_APP_SNAKE_GAME_APPLE_H
