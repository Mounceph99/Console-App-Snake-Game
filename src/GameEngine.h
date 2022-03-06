//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H
#define CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H


#include <iostream>
using std::ostream;

class GameEngine {
public:
    GameEngine();
    GameEngine(const GameEngine& ge);
    ~GameEngine();

    GameEngine& operator=(const GameEngine& ge);
    friend ostream& operator<<(ostream& output, const GameEngine& ge);
};


#endif //CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H
